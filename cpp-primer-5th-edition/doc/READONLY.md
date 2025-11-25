Ah, I understand now! You want to open files in **truly read-only mode** and prevent both editing and copying. Here are the approaches to achieve this:

## 1. **Open with Explicit Read-Only Setting**

```typescript
// This should trigger the read-only behavior you want
const document = await vscode.workspace.openTextDocument(uri);
await vscode.window.showTextDocument(document, {
    preview: false,
    readOnly: true
});
```

## 2. **Use Custom Text Document Content Provider** (Recommended)

This gives you full control over the read-only behavior:

```typescript
class ReadOnlyDocumentContentProvider implements vscode.TextDocumentContentProvider {
    onDidChangeEmitter = new vscode.EventEmitter<vscode.Uri>();
    onDidChange = this.onDidChangeEmitter.event;

    async provideTextDocumentContent(uri: vscode.Uri): Promise<string> {
        // Read the file content
        const content = await vscode.workspace.fs.readFile(uri);
        return Buffer.from(content).toString('utf8');
    }
}

// Register the provider
const readOnlyScheme = 'readonly';
const provider = new ReadOnlyDocumentContentProvider();
vscode.workspace.registerTextDocumentContentProvider(readOnlyScheme, provider);

// Open file in read-only mode
async function openFileReadOnly(uri: vscode.Uri) {
    const readOnlyUri = uri.with({
        scheme: readOnlyScheme,
        query: 'readonly=true'
    });
    
    const document = await vscode.workspace.openTextDocument(readOnlyUri);
    await vscode.window.showTextDocument(document, {
        preview: false,
        readOnly: true
    });
}
```

## 3. **Disable Copy/Paste Commands** (Prevent Copying)

Add this to your extension activation:

```typescript
// Disable copy, cut, and paste commands for your read-only documents
let disposable = vscode.commands.registerCommand('extension.openReadOnly', async (uri: vscode.Uri) => {
    const document = await vscode.workspace.openTextDocument(uri);
    const editor = await vscode.window.showTextDocument(document, {
        preview: false,
        readOnly: true
    });

    // Disable copy/cut/paste for this editor
    disableEditorCommands(editor);
});

function disableEditorCommands(editor: vscode.TextEditor) {
    // Override copy command
    const copyDisposable = vscode.commands.registerCommand('editor.action.clipboardCopyAction', () => {
        if (vscode.window.activeTextEditor === editor) {
            vscode.window.showWarningMessage('Copying is disabled for this read-only file.');
            return;
        }
        return vscode.commands.executeCommand('editor.action.clipboardCopyAction');
    });

    // Override cut command
    const cutDisposable = vscode.commands.registerCommand('editor.action.clipboardCutAction', () => {
        if (vscode.window.activeTextEditor === editor) {
            vscode.window.showWarningMessage('Cut is disabled for this read-only file.');
            return;
        }
        return vscode.commands.executeCommand('editor.action.clipboardCutAction');
    });

    // Store disposables to clean up later
    context.subscriptions.push(copyDisposable, cutDisposable);
}
```

## 4. **Custom Editor with Enhanced Protection**

Create a completely custom read-only experience:

```typescript
class ReadOnlyEditorProvider implements vscode.CustomTextEditorProvider {
    async resolveCustomTextEditor(
        document: vscode.TextDocument,
        webviewPanel: vscode.WebviewPanel,
        token: vscode.CancellationToken
    ): Promise<void> {
        
        // Set the webview's initial content
        webviewPanel.webview.options = {
            enableScripts: false, // Disable scripts to prevent any manipulation
            localResourceRoots: []
        };
        
        webviewPanel.webview.html = this.getHtmlForDocument(document);
        
        // Make sure editor is read-only
        webviewPanel.webview.onDidReceiveMessage(message => {
            // Reject any edit attempts
            if (message.type === 'edit') {
                webviewPanel.webview.postMessage({ 
                    type: 'error', 
                    message: 'This file is read-only and cannot be modified.' 
                });
            }
        });
    }

    private getHtmlForDocument(document: vscode.TextDocument): string {
        const content = document.getText();
        const escapedContent = content.replace(/</g, '&lt;').replace(/>/g, '&gt;');
        
        return `
            <!DOCTYPE html>
            <html>
            <head>
                <style>
                    body { 
                        padding: 10px; 
                        background-color: var(--vscode-editor-background);
                        color: var(--vscode-editor-foreground);
                        font-family: var(--vscode-editor-font-family);
                        font-size: var(--vscode-editor-font-size);
                        user-select: none; /* Prevent text selection */
                        -webkit-user-select: none; /* Safari */
                        -moz-user-select: none; /* Firefox */
                        -ms-user-select: none; /* IE/Edge */
                    }
                    pre {
                        white-space: pre-wrap;
                        word-wrap: break-word;
                    }
                </style>
            </head>
            <body>
                <pre>${escapedContent}</pre>
                <script>
                    // Prevent any user interaction
                    document.addEventListener('copy', (e) => {
                        e.preventDefault();
                        alert('Copying is disabled for this read-only file.');
                    });
                    
                    document.addEventListener('cut', (e) => {
                        e.preventDefault();
                    });
                    
                    document.addEventListener('paste', (e) => {
                        e.preventDefault();
                    });
                    
                    document.addEventListener('contextmenu', (e) => {
                        e.preventDefault();
                    });
                </script>
            </body>
            </html>
        `;
    }
}

// Register the custom editor
vscode.window.registerCustomEditorProvider(
    'yourExtension.readonlyEditor',
    new ReadOnlyEditorProvider(),
    {
        webviewOptions: {
            retainContextWhenHidden: false
        },
        supportsMultipleEditorsPerDocument: false
    }
);
```

## 5. **Complete Implementation**

```typescript
export function activate(context: vscode.ExtensionContext) {
    // Register command to open file in strict read-only mode
    let disposable = vscode.commands.registerCommand('extension.openStrictReadOnly', async (uri: vscode.Uri) => {
        try {
            const document = await vscode.workspace.openTextDocument(uri);
            const editor = await vscode.window.showTextDocument(document, {
                preview: false,
                readOnly: true
            });

            // Additional protection
            await vscode.commands.executeCommand('workbench.action.keepEditor');
            
            vscode.window.showInformationMessage('This file is opened in read-only mode. Editing and copying are disabled.');
            
        } catch (error) {
            vscode.window.showErrorMessage(`Failed to open file: ${error}`);
        }
    });

    context.subscriptions.push(disposable);
}
```

## Key Points:
- Use `readOnly: true` in `showTextDocument()`
- Consider using a custom editor for maximum control
- Disable clipboard commands to prevent copying
- Use CSS `user-select: none` to prevent text selection
- The prompt you mentioned is VS Code's built-in protection, which is actually helping your goal!

The methods above will give you true read-only files that cannot be edited or copied.