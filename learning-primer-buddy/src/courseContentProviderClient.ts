import * as vscode from 'vscode';
import * as https from 'https';
import { defaultCourseCatalog } from './course/defaultCourseCatalog';
import { LicenseInfo } from './license/types';

/**
 * CourseContentProviderClient handles communication with the Course Content Provider
 * that runs within the Learning Buddy Podman Environment.
 * 
 * This client implements the specification requirements where all content delivery,
 * license verification, and usage tracking happens within the Podman container.
 */
export class CourseContentProviderClient {
    private context: vscode.ExtensionContext;
    private providerBaseUrl: string;

    constructor(context: vscode.ExtensionContext) {
        this.context = context;
        // Default URL for the Course Content Provider running in the Podman environment
        this.providerBaseUrl = 'http://localhost:8000';
    }

    /**
     * Fetch content from the Course Content Provider
     * @param licenseInfo License information for content access
     * @param contentPath Path to the content in the course repository
     * @param courseId The course identifier
     * @returns Content as string, or null if failed
     */
    public async fetchContent(licenseInfo: LicenseInfo, contentPath: string, courseId: string = 'cpp-primer-5th'): Promise<string | null> {
        try {
            // Check if the Podman environment is running
            const isPodmanRunning = await this.checkPodmanEnvironment();
            if (!isPodmanRunning) {
                vscode.window.showErrorMessage(
                    'Learning Buddy Podman Environment is not running. ' +
                    'Please ensure Podman is installed and the Learning Buddy environment is started. ' +
                    'Refer to the installation guide for more information.'
                );
                return null;
            }
            
            // Make request to Course Content Provider API to fetch content
            const url = `${this.providerBaseUrl}/content/${courseId}/${contentPath}`;
            const response = await this.makeRequest(url, {
                method: 'GET',
                headers: {
                    'Authorization': `Bearer ${licenseInfo.key}`,
                    'X-Course-Id': courseId,
                    'Accept': 'text/plain'
                }
            });
            
            if (response.ok) {
                return await response.text();
            } else {
                console.error(`Failed to fetch content: ${response.status} ${response.statusText}`);
                return null;
            }
        } catch (error) {
            console.error('Error communicating with Course Content Provider:', error);
            vscode.window.showErrorMessage(`Failed to communicate with Course Content Provider: ${error}`);
            return null;
        }
    }

    /**
     * Get course structure from the Course Content Provider
     * @param courseId The course identifier
     * @returns Course structure, or null if failed
     */
    public async getCourseStructure(courseId: string = 'cpp-primer-5th'): Promise<any | null> {
        try {
            // Check if the Podman environment is running
            const isPodmanRunning = await this.checkPodmanEnvironment();
            if (!isPodmanRunning) {
                vscode.window.showErrorMessage(
                    'Learning Buddy Podman Environment is not running. ' +
                    'Please ensure Podman is installed and the Learning Buddy environment is started.'
                );
                return null;
            }
            
            // Make request to Course Content Provider API to get course structure
            const url = `${this.providerBaseUrl}/courses/${courseId}/structure`;
            const response = await this.makeRequest(url, {
                method: 'GET',
                headers: {
                    'Accept': 'application/json'
                }
            });
            
            if (response.ok) {
                return await response.json();
            } else {
                console.error(`Failed to fetch course structure: ${response.status} ${response.statusText}`);
                return null;
            }
        } catch (error) {
            console.error('Error fetching course structure from Course Content Provider:', error);
            return null;
        }
    }

    /**
     * Get the course catalog from the Course Content Provider
     * @returns Course catalog data, or null if failed
     */
    public async getCourseCatalog(): Promise<any | null> {
        try {
            // Check if the Podman environment is running
            const isPodmanRunning = await this.checkPodmanEnvironment();
            if (!isPodmanRunning) {
                // If Podman is not running, use the default course catalog for testing
                console.log('Using default course catalog for testing');
                return defaultCourseCatalog;
            }
            
            // Make request to Course Content Provider API to get course catalog
            const url = `${this.providerBaseUrl}/catalog`;
            const response = await this.makeRequest(url, {
                method: 'GET',
                headers: {
                    'Accept': 'application/json'
                }
            });
            
            if (response.ok) {
                return await response.json();
            } else {
                console.error(`Failed to fetch course catalog: ${response.status} ${response.statusText}`);
                // Fallback to default course catalog if API request fails
                return defaultCourseCatalog;
            }
        } catch (error) {
            console.error('Error fetching course catalog from Course Content Provider:', error);
            // Fallback to default course catalog if there's an error
            return defaultCourseCatalog;
        }
    }

    /**
     * Search for courses in the Course Content Provider
     * @param searchTerm The term to search for
     * @returns Search results, or null if failed
     */
    public async searchCourses(searchTerm: string): Promise<any | null> {
        try {
            // Check if the Podman environment is running
            const isPodmanRunning = await this.checkPodmanEnvironment();
            if (!isPodmanRunning) {
                // If Podman is not running, search within the default course catalog for testing
                console.log('Searching within default course catalog for testing');
                const filteredCourses = defaultCourseCatalog.courses.filter(course => 
                    course.title.toLowerCase().includes(searchTerm.toLowerCase()) ||
                    course.description.toLowerCase().includes(searchTerm.toLowerCase())
                );
                return { courses: filteredCourses };
            }
            
            // Make request to Course Content Provider API to search courses
            const url = `${this.providerBaseUrl}/catalog/search?q=${encodeURIComponent(searchTerm)}`;
            const response = await this.makeRequest(url, {
                method: 'GET',
                headers: {
                    'Accept': 'application/json'
                }
            });
            
            if (response.ok) {
                return await response.json();
            } else {
                console.error(`Failed to search courses: ${response.status} ${response.statusText}`);
                // Fallback to searching within default course catalog if API request fails
                const filteredCourses = defaultCourseCatalog.courses.filter(course => 
                    course.title.toLowerCase().includes(searchTerm.toLowerCase()) ||
                    course.description.toLowerCase().includes(searchTerm.toLowerCase())
                );
                return { courses: filteredCourses };
            }
        } catch (error) {
            console.error('Error searching courses from Course Content Provider:', error);
            // Fallback to searching within default course catalog if there's an error
            const filteredCourses = defaultCourseCatalog.courses.filter(course => 
                course.title.toLowerCase().includes(searchTerm.toLowerCase()) ||
                course.description.toLowerCase().includes(searchTerm.toLowerCase())
            );
            return { courses: filteredCourses };
        }
    }

    /**
     * Check if the Learning Buddy Podman Environment is running
     * This is a critical requirement as specified in the specifications
     * @returns true if Podman environment is running, false otherwise
     */
    private async checkPodmanEnvironment(): Promise<boolean> {
        try {
            // Check if the Course Content Provider service is available
            return await this.isServiceAvailable();
        } catch (error) {
            console.error('Error checking Podman environment:', error);
            return false;
        }
    }

    /**
     * Check if the Course Content Provider service is available
     * @returns true if service is available, false otherwise
     */
    private async isServiceAvailable(): Promise<boolean> {
        try {
            // Make a simple request to the health check endpoint
            const url = `${this.providerBaseUrl}/health`;
            const response = await this.makeRequest(url, {
                method: 'GET',
                timeout: 5000 // 5 second timeout
            });
            
            return response.ok;
        } catch (error) {
            console.error('Course Content Provider service is not available:', error);
            return false;
        }
    }

    /**
     * Verify a license through the Course Content Provider
     * @param licenseKey The license key to verify
     * @param courseId The course identifier
     * @returns License verification result
     */
    public async verifyLicense(licenseKey: string, courseId: string = 'cpp-primer-5th'): Promise<any> {
        try {
            // Check if the Podman environment is running
            const isPodmanRunning = await this.checkPodmanEnvironment();
            if (!isPodmanRunning) {
                vscode.window.showErrorMessage(
                    'Learning Buddy Podman Environment is not running. ' +
                    'Please ensure Podman is installed and the Learning Buddy environment is started.'
                );
                return { valid: false, error: 'Podman environment not running' };
            }
            
            // Make request to Course Content Provider API to verify license
            const url = `${this.providerBaseUrl}/licenses/${licenseKey}`;
            const response = await this.makeRequest(url, {
                method: 'GET',
                headers: {
                    'X-Course-Id': courseId,
                    'Accept': 'application/json'
                }
            });
            
            if (response.ok) {
                const licenseData = await response.json();
                return { valid: true, data: licenseData };
            } else if (response.status === 404) {
                return { valid: false, error: 'License not found' };
            } else {
                return { valid: false, error: `Verification failed: ${response.status} ${response.statusText}` };
            }
        } catch (error) {
            console.error('Error verifying license through Course Content Provider:', error);
            return { valid: false, error: `Verification failed: ${error}` };
        }
    }

    /**
     * Make an HTTP request with promise-based handling
     * @param url The URL to request
     * @param options Request options
     * @returns Response object
     */
    private makeRequest(url: string, options: any = {}): Promise<any> {
        return new Promise((resolve, reject) => {
            const urlObj = new URL(url);
            const requestOptions = {
                hostname: urlObj.hostname,
                port: urlObj.port,
                path: urlObj.pathname + urlObj.search,
                method: options.method || 'GET',
                headers: options.headers || {},
                timeout: options.timeout || 10000 // 10 second default timeout
            };

            const req = https.request(requestOptions, (res) => {
                let data = '';
                
                res.on('data', (chunk) => {
                    data += chunk;
                });
                
                res.on('end', () => {
                    try {
                        const jsonData = JSON.parse(data);
                        resolve({
                            ok: (res.statusCode || 0) >= 200 && (res.statusCode || 0) < 300,
                            status: res.statusCode || 0,
                            statusText: res.statusMessage || '',
                            json: () => Promise.resolve(jsonData),
                            text: () => Promise.resolve(data)
                        });
                    } catch (error) {
                        resolve({
                            ok: (res.statusCode || 0) >= 200 && (res.statusCode || 0) < 300,
                            status: res.statusCode || 0,
                            statusText: res.statusMessage || '',
                            text: () => Promise.resolve(data)
                        });
                    }
                });
            });
            
            req.on('error', (error) => {
                reject(error);
            });
            
            req.on('timeout', () => {
                req.destroy();
                reject(new Error('Request timeout'));
            });
            
            if (options.body) {
                req.write(options.body);
            }
            
            req.end();
        });
    }
}