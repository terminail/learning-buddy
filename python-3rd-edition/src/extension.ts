import * as vscode from 'vscode';
import * as fs from 'fs';
import * as path from 'path';
import * as os from 'os';

// Import the tree view provider
import { PythonTreeViewProvider } from './treeViewProvider';

// Custom Text Document Content Provider for truly read-only files
class ReadOnlyDocumentContentProvider implements vscode.TextDocumentContentProvider {
    onDidChangeEmitter = new vscode.EventEmitter<vscode.Uri>();
    onDidChange = this.onDidChangeEmitter.event;

    async provideTextDocumentContent(uri: vscode.Uri): Promise<string> {
        try {
            // Extract the original file path from the query
            const originalPath = uri.query;
            if (!originalPath) {
                return '# Error: Invalid file path';
            }
            
            // Read the file content
            const content = fs.readFileSync(originalPath, 'utf8');
            
            // Get the file name for the header
            const fileName = path.basename(originalPath);
            
            // Add a clear header indicating this is a read-only preview
            const header = `# READ-ONLY PREVIEW of: ${fileName}

# This is a read-only preview of the original file.
# To work with this file, download the chapter to your workspace using the download button.
# Any changes made here will not be saved and cannot be executed.

`;
            
            // Escape HTML characters for display
            const escapedContent = content
                .replace(/&/g, '&amp;')
                .replace(/</g, '&lt;')
                .replace(/>/g, '&gt;');
            
            // Return HTML content with CSS to prevent text selection
            return `<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: var(--vscode-editor-font-family);
            font-size: var(--vscode-editor-font-size);
            background-color: var(--vscode-editor-background);
            color: var(--vscode-editor-foreground);
            margin: 0;
            padding: 20px;
            user-select: none;
            -webkit-user-select: none;
            -moz-user-select: none;
            -ms-user-select: none;
        }
        pre {
            white-space: pre-wrap;
            word-wrap: break-word;
            margin: 0;
            user-select: none;
            -webkit-user-select: none;
            -moz-user-select: none;
            -ms-user-select: none;
        }
        .header {
            color: var(--vscode-descriptionForeground);
            border-bottom: 1px solid var(--vscode-panel-border);
            padding-bottom: 10px;
            margin-bottom: 15px;
            user-select: none;
            -webkit-user-select: none;
            -moz-user-select: none;
            -ms-user-select: none;
        }
    </style>
</head>
<body>
    <div class="header">
# READ-ONLY PREVIEW of: ${fileName}<br><br>
# This is a read-only preview of the original file.<br>
# To work with this file, download the chapter to your workspace using the download button.<br>
# Any changes made here will not be saved and cannot be executed.<br>
    </div>
    <pre>${escapedContent}</pre>
</body>
</html>`;
        } catch (error) {
            console.error('Failed to read file:', error);
            return `<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <style>
        body {
            font-family: var(--vscode-editor-font-family);
            font-size: var(--vscode-editor-font-size);
            background-color: var(--vscode-editor-background);
            color: var(--vscode-editor-foreground);
            padding: 20px;
        }
    </style>
</head>
<body>
# Error reading file: ${error instanceof Error ? error.message : 'Unknown error'}
</body>
</html>`;
        }
    }
}

let treeView: vscode.TreeView<any>;

export function activate(context: vscode.ExtensionContext) {
    // Load saved download path from workspace state
    const savedDownloadPath = context.workspaceState.get<string>('python3rdEditionDownloadPath');
    
    // Create the tree view provider
    const treeViewProvider = new PythonTreeViewProvider(savedDownloadPath || undefined);
    
    // Create the tree view (matching the view ID from package.json)
    treeView = vscode.window.createTreeView('python3rdEditionBuddyView', { treeDataProvider: treeViewProvider });
    
    // Register refresh command
    const refreshCommand = vscode.commands.registerCommand('python3rdEditionBuddy.refresh', () => {
        treeViewProvider.refresh();
    });
    
    // Register download chapter command
    const downloadChapterCommand = vscode.commands.registerCommand('python3rdEditionBuddy.downloadChapter', async (item: any) => {
        if (item && item.path) {
            await treeViewProvider.downloadChapter(item.path);
        }
    });
    
    // Register select download workspace command
    const selectDownloadWorkspaceCommand = vscode.commands.registerCommand('python3rdEditionBuddy.selectDownloadWorkspace', async () => {
        const folder = await vscode.window.showOpenDialog({
            canSelectFolders: true,
            canSelectFiles: false,
            canSelectMany: false,
            openLabel: 'Select Download Workspace'
        });
        
        if (folder && folder.length > 0) {
            const downloadPath = folder[0].fsPath;
            context.workspaceState.update('python3rdEditionDownloadPath', downloadPath);
            treeViewProvider.setDownloadPath(downloadPath);
        }
    });

    // Register the custom text document content provider
    const readOnlyScheme = 'python3rd-readonly';
    const provider = new ReadOnlyDocumentContentProvider();
    const providerRegistration = vscode.workspace.registerTextDocumentContentProvider(readOnlyScheme, provider);
    
    // Register open file command that opens files in truly read-only mode
    const openFileCommand = vscode.commands.registerCommand('python3rdEditionBuddy.openReadOnlyFile', async (uri: vscode.Uri) => {
        try {
            // Get the file name and extension
            const fileName = path.basename(uri.fsPath);
            const fileExt = path.extname(uri.fsPath);
            
            // Create a custom URI for our read-only provider
            const readOnlyUri = uri.with({
                scheme: readOnlyScheme,
                path: '/' + fileName,
                query: uri.fsPath // Pass the original file path in the query
            });
            
            // Open the file in read-only mode using a webview panel for HTML content
            const panel = vscode.window.createWebviewPanel(
                'python3rdEditionReadOnlyView',
                fileName,
                vscode.ViewColumn.One,
                {
                    enableScripts: false,
                    retainContextWhenHidden: false
                }
            );
            
            // Set the HTML content
            panel.webview.html = await provider.provideTextDocumentContent(readOnlyUri);
            
            // Add a message to inform users about the read-only nature
            vscode.window.showInformationMessage(`Opened ${fileName} in read-only mode. This is a preview of the original file.`);
        } catch (error) {
            console.error('Failed to open file:', error);
            vscode.window.showErrorMessage(`Failed to open file: ${error instanceof Error ? error.message : 'Unknown error'}`);
        }
    });

    // Register a cleanup function to remove temporary files when extension is deactivated
    context.subscriptions.push({
        dispose: () => {
            try {
                const homeDir = os.homedir();
                const tempDir = path.join(homeDir, '_python_temp');
                
                // Remove the temporary directory and all its contents
                if (fs.existsSync(tempDir)) {
                    fs.rmSync(tempDir, { recursive: true, force: true });
                }
            } catch (error) {
                console.error('Failed to cleanup temporary files:', error);
            }
        }
    });
    
    // Register our commands and providers
    context.subscriptions.push(treeView);
    context.subscriptions.push(refreshCommand);
    context.subscriptions.push(downloadChapterCommand);
    context.subscriptions.push(selectDownloadWorkspaceCommand);
    context.subscriptions.push(openFileCommand);
    context.subscriptions.push(providerRegistration);
}

export function deactivate() {}