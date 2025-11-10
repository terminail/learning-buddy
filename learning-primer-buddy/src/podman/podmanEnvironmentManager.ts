import * as vscode from 'vscode';
import * as cp from 'child_process';
import * as path from 'path';
import * as fs from 'fs';
import * as os from 'os';

/**
 * PodmanEnvironmentManager handles the initialization, management, and monitoring
 * of the embedded Podman environment for the Learning Buddy extension.
 * 
 * This implements the specification requirements from feature 010-podman-environment:
 * - Embedded Podman functionality for lightweight, daemonless operation
 * - Comprehensive Podman environment checks at startup
 * - Verification that embedded Podman is initialized and actively running
 * - Clear error messages when Podman is not available
 */
export class PodmanEnvironmentManager {
    private context: vscode.ExtensionContext;
    private podmanExecutable: string | null = null;
    private isPodmanInitialized: boolean = false;
    private podmanContainerId: string | null = null;
    private disposables: vscode.Disposable[] = [];
    private platform: NodeJS.Platform;
    private onPodmanNotAvailable: (() => void) | null = null;

    constructor(context: vscode.ExtensionContext) {
        this.context = context;
        this.platform = os.platform();
    }

    /**

     * Set callback for when Podman is not available

     */

    public setOnPodmanNotAvailableCallback(callback: () => void): void {

        this.onPodmanNotAvailable = callback;

    }

    /**

     * Initialize the Podman environment

     * This is the main entry point that should be called during extension activation

     */

    public async initialize(): Promise<boolean> {

        try {

            console.log('Checking Podman availability...');

            // Check if Podman is available

            if (!await this.checkPodmanAvailability()) {

                console.log('Podman not found in system PATH, checking embedded Podman...');

                // Try to use embedded Podman

                if (!await this.initializeEmbeddedPodman()) {

                    console.log('Embedded Podman not found, showing installation guide...');

                    // Always notify the tree view provider when Podman is not available

                    if (this.onPodmanNotAvailable) {

                        this.onPodmanNotAvailable();

                    }

                    return false;

                }

            }



            console.log('Podman found, checking Course Content Provider container...');

            // Check if the Course Content Provider container is running

            if (!await this.checkCourseContentProviderContainer()) {

                console.log('Course Content Provider container not running, trying to start it...');

                // Try to start the container

                if (!await this.startCourseContentProviderContainer()) {

                    console.log('Failed to start Course Content Provider container, showing installation guide...');

                    // Always notify the tree view provider when Podman is not available

                    if (this.onPodmanNotAvailable) {

                        this.onPodmanNotAvailable();

                    }

                    return false;

                }

            }



            this.isPodmanInitialized = true;

            console.log('Podman environment initialized successfully');

            return true;

        } catch (error) {

            console.error('Error initializing Podman environment:', error);

            // Always notify the tree view provider when Podman is not available

            if (this.onPodmanNotAvailable) {

                this.onPodmanNotAvailable();

            }

            return false;

        }

    }

    /**
     * Check if Podman is available on the system
     */
    private async checkPodmanAvailability(): Promise<boolean> {
        try {
            // Try to find Podman executable
            const podmanPath = await this.findPodmanExecutable();
            if (podmanPath) {
                this.podmanExecutable = podmanPath;
                return true;
            }
            
            // If not found, check common installation paths
            return await this.verifyPodmanInstallation();
        } catch (error) {
            console.error('Error checking Podman availability:', error);
            return false;
        }
    }

    /**
     * Find the Podman executable in the system PATH
     */
    private async findPodmanExecutable(): Promise<string | null> {
        return new Promise((resolve) => {
            // Use platform-specific command to find Podman
            let command: string;
            if (this.platform === 'win32') {
                command = 'where podman';
            } else {
                command = 'which podman';
            }
            
            cp.exec(command, (error, stdout) => {
                if (error) {
                    resolve(null);
                } else {
                    if (this.platform === 'win32') {
                        // On Windows, 'where' might return multiple paths, take the first one
                        const paths = stdout.trim().split('\n');
                        resolve(paths[0].trim());
                    } else {
                        resolve(stdout.trim());
                    }
                }
            });
        });
    }

    /**
     * Verify Podman installation by checking common paths
     */
    private async verifyPodmanInstallation(): Promise<boolean> {
        let commonPaths: string[] = [];
        
        // Platform-specific paths
        switch (this.platform) {
            case 'win32':
                commonPaths = [
                    'C:\\Program Files\\Podman\\podman.exe',
                    'C:\\Program Files\\RedHat\\Podman\\podman.exe',
                    path.join(os.homedir(), 'podman', 'podman.exe'),
                    path.join(process.env.LOCALAPPDATA || '', 'podman', 'podman.exe')
                ];
                break;
            case 'darwin':
                commonPaths = [
                    '/opt/podman/bin/podman',
                    '/usr/local/bin/podman',
                    '/opt/homebrew/bin/podman',
                    path.join(os.homedir(), 'podman', 'bin', 'podman')
                ];
                break;
            case 'linux':
                commonPaths = [
                    '/usr/bin/podman',
                    '/usr/local/bin/podman',
                    '/opt/podman/bin/podman',
                    path.join(os.homedir(), '.local/bin/podman')
                ];
                break;
            default:
                console.warn(`Unsupported platform: ${this.platform}`);
                return false;
        }

        for (const podmanPath of commonPaths) {
            if (podmanPath && fs.existsSync(podmanPath)) {
                this.podmanExecutable = podmanPath;
                return true;
            }
        }

        return false;
    }

    /**
     * Ask user to provide a custom Podman installation folder
     * Instead of showing popup dialogs, we'll return false to let the tree view provider handle it
     */
    private async askForPodmanInstallationFolder(): Promise<boolean> {
        // Instead of showing popup dialogs, notify the tree view provider
        if (this.onPodmanNotAvailable) {
            this.onPodmanNotAvailable();
        }
        return false;
    }

    /**
     * Get the Podman executable path in a given directory
     */
    private getPodmanExecutableInDirectory(directory: string): string | null {
        let podmanPath: string;
        
        switch (this.platform) {
            case 'win32':
                podmanPath = path.join(directory, 'podman.exe');
                break;
            case 'darwin':
            case 'linux':
                podmanPath = path.join(directory, 'podman');
                break;
            default:
                return null;
        }
        
        return podmanPath;
    }

    /**
     * Initialize embedded Podman if system Podman is not available
     */
    private async initializeEmbeddedPodman(): Promise<boolean> {
        try {
            // Check if embedded Podman exists
            const embeddedPodmanPath = this.getEmbeddedPodmanPath();
            if (embeddedPodmanPath && fs.existsSync(embeddedPodmanPath)) {
                this.podmanExecutable = embeddedPodmanPath;
                return true;
            }
            
            // Check if user previously specified a custom path
            const customPodmanPath = this.context.globalState.get<string>('customPodmanPath');
            if (customPodmanPath && fs.existsSync(customPodmanPath)) {
                this.podmanExecutable = customPodmanPath;
                return true;
            }
            
            return false;
        } catch (error) {
            console.error('Error initializing embedded Podman:', error);
            return false;
        }
    }

    /**
     * Get the path to the embedded Podman executable
     */
    private getEmbeddedPodmanPath(): string | null {
        const extensionPath = this.context.extensionPath;
        let embeddedPath: string;
        
        switch (this.platform) {
            case 'win32':
                embeddedPath = path.join(extensionPath, '..', 'embedded-tools', 'podman.exe');
                break;
            case 'darwin':
                embeddedPath = path.join(extensionPath, '..', 'embedded-tools', 'podman');
                break;
            case 'linux':
                embeddedPath = path.join(extensionPath, '..', 'embedded-tools', 'podman');
                break;
            default:
                return null;
        }
        
        return embeddedPath;
    }

    /**
     * Check if the Course Content Provider container is running
     */
    private async checkCourseContentProviderContainer(): Promise<boolean> {
        try {
            if (!this.podmanExecutable) {
                return false;
            }

            // Check if container with name 'course-content-provider' is running
            // Use platform-specific command syntax
            let command: string;
            if (this.platform === 'win32') {
                command = `"${this.podmanExecutable}" ps --filter "name=course-content-provider" --format "{{.ID}}"`;
            } else {
                command = `${this.podmanExecutable} ps --filter "name=course-content-provider" --format "{{.ID}}"`;
            }
            
            return new Promise((resolve) => {
                cp.exec(command, (error, stdout) => {
                    if (error) {
                        resolve(false);
                    } else {
                        const containerId = stdout.trim();
                        if (containerId) {
                            this.podmanContainerId = containerId;
                            resolve(true);
                        } else {
                            resolve(false);
                        }
                    }
                });
            });
        } catch (error) {
            console.error('Error checking Course Content Provider container:', error);
            return false;
        }
    }

    /**
     * Start the Course Content Provider container
     */
    private async startCourseContentProviderContainer(): Promise<boolean> {
        try {
            if (!this.podmanExecutable) {
                return false;
            }

            // First check if image exists
            const imageExists = await this.checkImageExists('course-content-provider');
            if (!imageExists) {
                // Try to build the image
                if (!await this.buildCourseContentProviderImage()) {
                    return false;
                }
            }

            // Start the container with platform-specific command
            let command: string;
            if (this.platform === 'win32') {
                command = `"${this.podmanExecutable}" run -d --name course-content-provider -p 8000:8000 course-content-provider`;
            } else {
                command = `${this.podmanExecutable} run -d --name course-content-provider -p 8000:8000 course-content-provider`;
            }
            
            return new Promise((resolve) => {
                cp.exec(command, (error, stdout) => {
                    if (error) {
                        console.error('Error starting container:', error);
                        resolve(false);
                    } else {
                        this.podmanContainerId = stdout.trim();
                        resolve(true);
                    }
                });
            });
        } catch (error) {
            console.error('Error starting Course Content Provider container:', error);
            return false;
        }
    }

    /**
     * Check if a Podman image exists
     */
    private async checkImageExists(imageName: string): Promise<boolean> {
        try {
            if (!this.podmanExecutable) {
                return false;
            }

            // Use platform-appropriate command
            let command: string;
            if (this.platform === 'win32') {
                command = `"${this.podmanExecutable}" images --format "{{.Repository}}" | findstr "${imageName}"`;
            } else {
                command = `${this.podmanExecutable} images --format "{{.Repository}}" | grep "${imageName}"`;
            }
            
            return new Promise((resolve) => {
                cp.exec(command, (error) => {
                    resolve(!error);
                });
            });
        } catch (error) {
            return false;
        }
    }

    /**
     * Build the Course Content Provider image
     */
    private async buildCourseContentProviderImage(): Promise<boolean> {
        try {
            if (!this.podmanExecutable) {
                return false;
            }

            // Get the path to the course-content-provider directory
            const ccpPath = path.join(this.context.extensionPath, '..', 'course-content-provider');
            if (!fs.existsSync(ccpPath)) {
                console.error('Course Content Provider directory not found:', ccpPath);
                return false;
            }

            // Use platform-appropriate command
            let command: string;
            if (this.platform === 'win32') {
                command = `cd /d "${ccpPath}" && "${this.podmanExecutable}" build -t course-content-provider -f Podmanfile .`;
            } else {
                command = `cd "${ccpPath}" && ${this.podmanExecutable} build -t course-content-provider -f Podmanfile .`;
            }
            
            return new Promise((resolve) => {
                cp.exec(command, (error) => {
                    if (error) {
                        console.error('Error building Course Content Provider image:', error);
                        resolve(false);
                    } else {
                        resolve(true);
                    }
                });
            });
        } catch (error) {
            console.error('Error building Course Content Provider image:', error);
            return false;
        }
    }

    /**
     * Show error message for Podman installation issues
     * Instead of showing popup dialogs, we'll notify the tree view provider
     */
    private async showPodmanInstallationError(): Promise<void> {
        // Instead of showing popup dialogs, notify the tree view provider
        if (this.onPodmanNotAvailable) {
            this.onPodmanNotAvailable();
        }
    }

    /**
     * Show error message for container startup issues
     * Instead of showing popup dialogs, we'll notify the tree view provider
     */
    private async showContainerStartupError(): Promise<void> {
        // Instead of showing popup dialogs, notify the tree view provider
        if (this.onPodmanNotAvailable) {
            this.onPodmanNotAvailable();
        }
    }

    /**
     * Show error message for initialization issues
     * Instead of showing popup dialogs, we'll notify the tree view provider
     */
    private async showInitializationError(_error: any): Promise<void> {
        // Instead of showing popup dialogs, notify the tree view provider
        if (this.onPodmanNotAvailable) {
            this.onPodmanNotAvailable();
        }
    }

    /**
     * Get Podman version information
     */
    public async getPodmanVersion(): Promise<string | null> {
        try {
            if (!this.podmanExecutable) {
                return null;
            }

            // Use platform-appropriate command
            let command: string;
            if (this.platform === 'win32') {
                command = `"${this.podmanExecutable}" version --format json`;
            } else {
                command = `${this.podmanExecutable} version --format json`;
            }
            
            return new Promise((resolve) => {
                cp.exec(command, (error, stdout) => {
                    if (error) {
                        // Try without JSON format
                        const simpleCommand = this.platform === 'win32' ? 
                            `"${this.podmanExecutable}" --version` : 
                            `${this.podmanExecutable} --version`;
                        
                        cp.exec(simpleCommand, (error2, stdout2) => {
                            if (error2) {
                                resolve(null);
                            } else {
                                resolve(stdout2.trim());
                            }
                        });
                    } else {
                        try {
                            const versionInfo = JSON.parse(stdout);
                            resolve(`Podman ${versionInfo.Client.Version}`);
                        } catch {
                            resolve(stdout.trim());
                        }
                    }
                });
            });
        } catch (error) {
            console.error('Error getting Podman version:', error);
            return null;
        }
    }

    /**
     * Get list of installed course containers
     */
    public async getInstalledCourseContainers(): Promise<string[]> {
        try {
            if (!this.podmanExecutable) {
                return [];
            }

            // List all containers with "course" in their name
            let command: string;
            if (this.platform === 'win32') {
                command = `"${this.podmanExecutable}" ps -a --format "{{.Names}}" | findstr course`;
            } else {
                command = `${this.podmanExecutable} ps -a --format "{{.Names}}" | grep course`;
            }
            
            return new Promise((resolve) => {
                cp.exec(command, (error, stdout) => {
                    if (error) {
                        resolve([]);
                    } else {
                        const containers = stdout.trim().split('\n').filter(name => name.trim() !== '');
                        resolve(containers);
                    }
                });
            });
        } catch (error) {
            console.error('Error getting installed course containers:', error);
            return [];
        }
    }

    /**
     * Check if the Podman environment is properly initialized
     */
    public isInitialized(): boolean {
        return this.isPodmanInitialized;
    }

    /**
     * Get the Podman executable path
     */
    public getPodmanExecutable(): string | null {
        return this.podmanExecutable;
    }

    /**
     * Get the Course Content Provider container ID
     */
    public getContainerId(): string | null {
        return this.podmanContainerId;
    }

    /**
     * Dispose of resources
     */
    public dispose(): void {
        this.disposables.forEach(d => d.dispose());
        
        // Stop the container if it's running
        if (this.podmanContainerId && this.podmanExecutable) {
            try {
                let command: string;
                if (this.platform === 'win32') {
                    command = `"${this.podmanExecutable}" stop ${this.podmanContainerId}`;
                } else {
                    command = `${this.podmanExecutable} stop ${this.podmanContainerId}`;
                }
                
                cp.exec(command, (error) => {
                    if (error) {
                        console.error('Error stopping container:', error);
                    }
                });
            } catch (error) {
                console.error('Error stopping container:', error);
            }
        }
    }
}