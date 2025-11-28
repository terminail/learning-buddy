import * as vscode from 'vscode';
import * as fs from 'fs';
import * as path from 'path';

export class PythonTreeViewProvider implements vscode.TreeDataProvider<Dependency> {
    private _onDidChangeTreeData: vscode.EventEmitter<Dependency | undefined | void> = new vscode.EventEmitter<Dependency | undefined | void>();
    readonly onDidChangeTreeData: vscode.Event<Dependency | undefined | void> = this._onDidChangeTreeData.event;

    private rootPath: string;
    private downloadPath: string | undefined;

    constructor(downloadPath?: string) {
        this.downloadPath = downloadPath;
        
        // Get the path to the embedded python-3rd-edition directory
        const extensionPath = vscode.extensions.getExtension('python-3rd-edition-buddy')?.extensionPath || __dirname;
        this.rootPath = path.join(extensionPath, 'python-3rd-edition');
        
        // If we can't find it relative to the extension, try the expected embedded path
        if (!fs.existsSync(this.rootPath)) {
            // Try alternative paths where the content might be embedded
            const possiblePaths = [
                path.join(__dirname, '..', 'python-3rd-edition'),
                path.join(__dirname, '..', '..', 'python-3rd-edition'),
                path.join(extensionPath, '..', 'python-3rd-edition', 'python-3rd-edition'),
                path.join(extensionPath, 'python-3rd-edition')
            ];
            
            for (const possiblePath of possiblePaths) {
                if (fs.existsSync(possiblePath)) {
                    this.rootPath = possiblePath;
                    break;
                }
            }
        }
        
        // If no download path was provided, try to get it from settings
        if (!this.downloadPath) {
            const config = vscode.workspace.getConfiguration('python3rdEditionBuddy');
            let configuredPath = config.get<string>('downloadPath');
            
            // If the configured path is the default placeholder, expand it to the user's home directory
            if (configuredPath === '~/python-crash-course-3rd-edition-buddy') {
                const homeDir = require('os').homedir();
                configuredPath = path.join(homeDir, 'python-crash-course-3rd-edition-buddy');
            }
            
            if (configuredPath) {
                this.downloadPath = configuredPath;
            }
        }
        
        console.log('Python Crash Course 3rd Edition root path:', this.rootPath);
    }

    refresh(): void {
        this._onDidChangeTreeData.fire();
    }

    public setDownloadPath(path: string | undefined): void {
        this.downloadPath = path;
        this.refresh(); // Refresh the tree view to update the download workspace item
    }

    public getDownloadPath(): string | undefined {
        return this.downloadPath;
    }

    getTreeItem(element: Dependency): vscode.TreeItem {
        return element;
    }

    getChildren(element?: Dependency): Promise<Dependency[]> {
        if (!this.rootPath) {
            vscode.window.showInformationMessage('No root path found for Python Crash Course 3rd Edition content');
            return Promise.resolve([]);
        }

        if (element) {
            return Promise.resolve(this.getDependencies(element.path));
        } else {
            const result = this.getDependencies(this.rootPath);
            // Add a separator before the download workspace item
            result.push(new SeparatorItem());
            // Add the download workspace item at the end
            result.push(new DownloadWorkspaceItem(this.downloadPath || ''));
            return Promise.resolve(result);
        }
    }

    /**
     * Given the path to a directory, return all its child files and directories
     */
    private getDependencies(dirPath: string): Dependency[] {
        if (!fs.existsSync(dirPath)) {
            return [];
        }

        const result: Dependency[] = [];
        const dirContents = fs.readdirSync(dirPath);
        
        // Separate folders and files
        const folders: string[] = [];
        const files: string[] = [];
        
        dirContents.forEach((fileName: string) => {
            // Skip hidden files and node_modules
            if (fileName.startsWith('.') || fileName === 'node_modules' || fileName === 'out') {
                return;
            }
            
            const filePath = path.join(dirPath, fileName);
            const stat = fs.statSync(filePath);
            
            if (stat.isDirectory()) {
                folders.push(fileName);
            } else {
                files.push(fileName);
            }
        });
        
        // Sort folders numerically by their prefix number
        folders.sort((a, b) => {
            // Extract the numeric prefix from both filenames
            const aMatch = a.match(/^(\d+)/);
            const bMatch = b.match(/^(\d+)/);
            
            if (aMatch && bMatch) {
                // Both have numeric prefixes, sort numerically
                const aNum = parseInt(aMatch[1], 10);
                const bNum = parseInt(bMatch[1], 10);
                return aNum - bNum;
            } else if (aMatch) {
                // Only a has a numeric prefix, it comes first
                return -1;
            } else if (bMatch) {
                // Only b has a numeric prefix, it comes first
                return 1;
            } else {
                // Neither has a numeric prefix, sort alphabetically
                return a.localeCompare(b);
            }
        });
        
        // Sort files alphabetically
        files.sort((a, b) => a.localeCompare(b));

        // Process folders first
        folders.forEach((fileName: string) => {
            const filePath = path.join(dirPath, fileName);
            const stat = fs.statSync(filePath);

            const dependency = new ChapterItem(
                fileName,
                filePath,
                vscode.TreeItemCollapsibleState.Collapsed,
                this.downloadPath
            );
            dependency.iconPath = vscode.ThemeIcon.Folder;
            
            result.push(dependency);
        });
        
        // Then process files
        files.forEach((fileName: string) => {
            const filePath = path.join(dirPath, fileName);
            const stat = fs.statSync(filePath);

            const dependency = new Dependency(
                fileName,
                filePath,
                vscode.TreeItemCollapsibleState.None
            );
            
            // Set icon based on file extension
            if (fileName.endsWith('.py')) {
                dependency.iconPath = new vscode.ThemeIcon('symbol-class');
            } else if (fileName.endsWith('.md')) {
                dependency.iconPath = new vscode.ThemeIcon('markdown');
            } else if (fileName.endsWith('.txt')) {
                dependency.iconPath = new vscode.ThemeIcon('note');
            } else {
                dependency.iconPath = new vscode.ThemeIcon('file');
            }
            
            result.push(dependency);
        });

        return result;
    }
    
    /**
     * Download a chapter to the selected download workspace
     */
    async downloadChapter(chapterPath: string): Promise<void> {
        if (!this.downloadPath) {
            vscode.window.showErrorMessage('Please select a download workspace first.');
            return;
        }
        
        try {
            const chapterName = path.basename(chapterPath);
            const destinationPath = path.join(this.downloadPath, chapterName);
            
            // Check if destination already exists
            if (fs.existsSync(destinationPath)) {
                const overwrite = await vscode.window.showWarningMessage(
                    `Chapter ${chapterName} already exists in the download workspace. Do you want to overwrite it?`,
                    'Yes', 'No'
                );
                
                if (overwrite !== 'Yes') {
                    return;
                }
            }
            
            // Copy the chapter folder
            await this.copyFolderRecursive(chapterPath, destinationPath);
            
            vscode.window.showInformationMessage(`Chapter ${chapterName} downloaded successfully to ${this.downloadPath}`);
        } catch (error) {
            vscode.window.showErrorMessage(`Failed to download chapter: ${error}`);
        }
    }
    
    /**
     * Recursively copy a folder
     */
    private async copyFolderRecursive(source: string, destination: string): Promise<void> {
        if (!fs.existsSync(destination)) {
            fs.mkdirSync(destination, { recursive: true });
        }
        
        const files = fs.readdirSync(source);
        
        for (const file of files) {
            const sourcePath = path.join(source, file);
            const destPath = path.join(destination, file);
            
            const stat = fs.statSync(sourcePath);
            
            if (stat.isDirectory()) {
                await this.copyFolderRecursive(sourcePath, destPath);
            } else {
                fs.copyFileSync(sourcePath, destPath);
            }
        }
    }
}

class Dependency extends vscode.TreeItem {
    iconPath?: vscode.ThemeIcon | vscode.Uri | { light: vscode.Uri; dark: vscode.Uri } | undefined;

    constructor(
        public readonly label: string,
        public readonly path: string,
        public readonly collapsibleState: vscode.TreeItemCollapsibleState
    ) {
        super(label, collapsibleState);
        
        this.tooltip = this.path;
        // Extract filename from path
        const parts = this.path.split(/[/\\]/);
        this.description = parts[parts.length - 1];
        
        // Add command to open file when clicked
        if (collapsibleState === vscode.TreeItemCollapsibleState.None) {
            this.command = {
                command: 'python3rdEditionBuddy.openReadOnlyFile',
                title: 'Open File',
                arguments: [vscode.Uri.file(this.path)]
            };
        }
    }
}

class ChapterItem extends Dependency {
    constructor(
        public readonly label: string,
        public readonly path: string,
        public readonly collapsibleState: vscode.TreeItemCollapsibleState,
        private downloadPath: string | undefined
    ) {
        super(label, path, collapsibleState);
        
        // Add context value for tree item menu
        this.contextValue = 'chapter';
    }
}

class SeparatorItem extends Dependency {
    constructor() {
        // Call parent constructor with dummy values
        super('', '', vscode.TreeItemCollapsibleState.None);
        this.tooltip = '';
        this.description = '';
        // Remove command to prevent interaction
        this.command = undefined;
    }
}

class DownloadWorkspaceItem extends Dependency {
    constructor(public downloadPath: string) {
        // Call parent constructor with updated label
        super('Select Download Folder', '', vscode.TreeItemCollapsibleState.None);
        
        // Use a different icon to indicate downloaded content
        this.iconPath = new vscode.ThemeIcon('cloud-download');
        
        // Set color to indicate it's downloaded content (using CSS class)
        this.contextValue = 'downloadWorkspace';
        
        this.description = downloadPath || 'Click to select folder';
        this.tooltip = downloadPath ? `Current download folder: ${downloadPath}` : 'Click to select download folder';
        
        this.command = {
            command: 'python3rdEditionBuddy.selectDownloadWorkspace',
            title: 'Select Download Folder',
            arguments: [this]
        };
    }
}