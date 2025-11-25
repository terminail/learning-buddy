import * as vscode from 'vscode';
import { CppPrimerTreeViewProvider } from './treeViewProvider';
import * as fs from 'fs';
import * as path from 'path';
import * as os from 'os';

export function activate(context: vscode.ExtensionContext) {
    console.log('C++ Primer 5th Edition Buddy is now active!');

    // Try to restore the download path from global state
    const savedDownloadPath = context.globalState.get<string>('cppPrimer5thEditionBuddy.downloadPath');
    
    // Create the tree view provider with the saved download path
    const treeViewProvider = new CppPrimerTreeViewProvider(savedDownloadPath || undefined);

    // Register the tree view
    const treeView = vscode.window.createTreeView('cppPrimer5thEditionBuddyView', {
        treeDataProvider: treeViewProvider,
        showCollapseAll: true
    });

    // Register refresh command
    const refreshCommand = vscode.commands.registerCommand('cppPrimer5thEditionBuddy.refresh', () => {
        treeViewProvider.refresh();
        vscode.window.showInformationMessage('C++ Primer 5th Edition content refreshed!');
    });
    
    // Register download chapter command
    const downloadChapterCommand = vscode.commands.registerCommand('cppPrimer5thEditionBuddy.downloadChapter', async (item) => {
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
            openLabel: 'Select Download Folder'
        });
        
        if (folder && folder.length > 0) {
            const downloadPath = folder[0].fsPath;
            treeViewProvider.setDownloadPath(downloadPath);
            // Save the download path to global state
            await context.globalState.update('cppPrimer5thEditionBuddy.downloadPath', downloadPath);
            vscode.window.showInformationMessage(`Download folder set to: ${downloadPath}`);
        }
    });
    
    // Register open file command that copies content to a new document with the same name
    const openFileCommand = vscode.commands.registerCommand('cppPrimer5thEditionBuddy.openReadOnlyFile', async (uri: vscode.Uri) => {
        try {
            // Read the file content
            const fileContent = fs.readFileSync(uri.fsPath, 'utf8');
            
            // Get the file name and extension
            const fileName = path.basename(uri.fsPath);
            const fileExt = path.extname(uri.fsPath);
            
            // Determine the language based on file extension
            let language = 'plaintext';
            
            if (fileExt === '.cpp' || fileExt === '.cc' || fileExt === '.cxx') {
                language = 'cpp';
            } else if (fileExt === '.h' || fileExt === '.hpp') {
                language = 'cpp';
            } else if (fileExt === '.md') {
                language = 'markdown';
            } else if (fileExt === '.txt') {
                language = 'plaintext';
            }
            
            // Create a unique temporary file to avoid conflicts
            const workspaceFolders = vscode.workspace.workspaceFolders;
            const workspacePath = workspaceFolders && workspaceFolders.length > 0 ? workspaceFolders[0].uri.fsPath : null;
            const tempDir = workspacePath || os.tmpdir();
            const uniqueFileName = `${Date.now()}_${Math.random().toString(36).substring(2, 10)}_${fileName}`;
            const tempFilePath = path.join(tempDir, uniqueFileName);
            
            // Write the content to the temporary file
            fs.writeFileSync(tempFilePath, fileContent);
            
            // Open the temporary file
            const tempUri = vscode.Uri.file(tempFilePath);
            const document = await vscode.workspace.openTextDocument(tempUri);
            
            // Show the document in a new editor
            await vscode.window.showTextDocument(document, {
                preview: false
            });
        } catch (error) {
            console.error('Failed to open file:', error);
            vscode.window.showErrorMessage(`Failed to open file: ${error instanceof Error ? error.message : 'Unknown error'}`);
        }
    });

    context.subscriptions.push(treeView);
    context.subscriptions.push(refreshCommand);
    context.subscriptions.push(downloadChapterCommand);
    context.subscriptions.push(selectDownloadWorkspaceCommand);
    context.subscriptions.push(openFileCommand);
}

export function deactivate() {}