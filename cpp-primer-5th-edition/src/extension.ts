import * as vscode from 'vscode';
import * as fs from 'fs';
import * as path from 'path';
import * as os from 'os';

// Import the tree view provider
import { CppPrimerTreeViewProvider } from './treeViewProvider';

// Custom Text Document Content Provider for truly read-only files
class ReadOnlyDocumentContentProvider implements vscode.TextDocumentContentProvider {
    onDidChangeEmitter = new vscode.EventEmitter<vscode.Uri>();
    onDidChange = this.onDidChangeEmitter.event;

    async provideTextDocumentContent(uri: vscode.Uri): Promise<string> {
        try {
            // Extract the original file path from the query
            const originalPath = uri.query;
            if (!originalPath) {
                return '// Error: Invalid file path';
            }
            
            // Read the file content
            const content = fs.readFileSync(originalPath, 'utf8');
            
            // Get the file name for the header
            const fileName = path.basename(originalPath);
            
            // Add a clear header indicating this is a read-only preview
            const header = `// READ-ONLY PREVIEW of: ${fileName}

// This is a read-only preview of the original file.
// To work with this file, download the chapter to your workspace using the download button.
// Any changes made here will not be saved and cannot be executed.

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
// READ-ONLY PREVIEW of: ${fileName}<br><br>
// This is a read-only preview of the original file.<br>
// To work with this file, download the chapter to your workspace using the download button.<br>
// Any changes made here will not be saved and cannot be executed.<br>
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
// Error reading file: ${error instanceof Error ? error.message : 'Unknown error'}
</body>
</html>`;
        }
    }
}

let treeView: vscode.TreeView<any>;

export function activate(context: vscode.ExtensionContext) {
    // Load saved download path from workspace state (takes precedence over settings)
    let savedDownloadPath = context.workspaceState.get<string>('cppPrimerDownloadPath');
    
    // If no saved download path, try to get it from settings
    if (!savedDownloadPath) {
        const config = vscode.workspace.getConfiguration('cppPrimer5thEditionBuddy');
        savedDownloadPath = config.get<string>('downloadPath');
    }
    
    // Create the tree view provider
    const treeViewProvider = new CppPrimerTreeViewProvider(savedDownloadPath || undefined);
    
    // Create the tree view
    treeView = vscode.window.createTreeView('cppPrimer5thEditionBuddyView', { treeDataProvider: treeViewProvider });
    
    // Register refresh command
    const refreshCommand = vscode.commands.registerCommand('cppPrimer5thEditionBuddy.refresh', () => {
        treeViewProvider.refresh();
    });
    
    // Register download chapter command
    const downloadChapterCommand = vscode.commands.registerCommand('cppPrimer5thEditionBuddy.downloadChapter', async (item: any) => {
        if (item && item.path) {
            await treeViewProvider.downloadChapter(item.path);
        }
    });
    
    // Register select download workspace command
    const selectDownloadWorkspaceCommand = vscode.commands.registerCommand('cppPrimer5thEditionBuddy.selectDownloadWorkspace', async () => {
        const folder = await vscode.window.showOpenDialog({
            canSelectFolders: true,
            canSelectFiles: false,
            canSelectMany: false,
            openLabel: 'Select Download Workspace'
        });
        
        if (folder && folder.length > 0) {
            const downloadPath = folder[0].fsPath;
            // Save to workspace state (takes precedence)
            context.workspaceState.update('cppPrimerDownloadPath', downloadPath);
            // Also update the global setting to keep them in sync
            await vscode.workspace.getConfiguration('cppPrimer5thEditionBuddy').update('downloadPath', downloadPath, vscode.ConfigurationTarget.Global);
            treeViewProvider.setDownloadPath(downloadPath);
        }
    });

    // Register configuration change listener
    const configChangeListener = vscode.workspace.onDidChangeConfiguration(async (event) => {
        if (event.affectsConfiguration('cppPrimer5thEditionBuddy.downloadPath')) {
            // Only update if there's no saved download path (workspace state takes precedence)
            const savedPath = context.workspaceState.get<string>('cppPrimerDownloadPath');
            if (!savedPath) {
                const config = vscode.workspace.getConfiguration('cppPrimer5thEditionBuddy');
                let newPath = config.get<string>('downloadPath');
                
                // If the configured path is the default placeholder, expand it to the user's home directory
                if (newPath === '~/cpp-primer-5th-edition-buddy') {
                    const homeDir = require('os').homedir();
                    newPath = path.join(homeDir, 'cpp-primer-5th-edition-buddy');
                }
                
                treeViewProvider.setDownloadPath(newPath || undefined);
            }
            // If there is a saved path, we still want to update the setting to match
            // This handles the case where the user changed via tree view but setting wasn't updated
            else {
                // Update the global setting to match the workspace state
                await vscode.workspace.getConfiguration('cppPrimer5thEditionBuddy').update('downloadPath', savedPath, vscode.ConfigurationTarget.Global);
            }
        }
    });

    // Register the custom text document content provider
    const readOnlyScheme = 'cppprimer-readonly';
    const provider = new ReadOnlyDocumentContentProvider();
    const providerRegistration = vscode.workspace.registerTextDocumentContentProvider(readOnlyScheme, provider);
    
    // Register open file command that opens files in truly read-only mode
    const openFileCommand = vscode.commands.registerCommand('cppPrimer5thEditionBuddy.openReadOnlyFile', async (uri: vscode.Uri) => {
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
                'cppPrimerReadOnlyView',
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
                const tempDir = path.join(homeDir, '_cpp_primer_temp');
                
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
    context.subscriptions.push(configChangeListener);
    context.subscriptions.push(openFileCommand);
    context.subscriptions.push(providerRegistration);
}

export function deactivate() {}