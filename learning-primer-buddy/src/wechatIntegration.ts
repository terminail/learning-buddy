import * as vscode from 'vscode';
import * as path from 'path';

/**
 * WeChatIntegration provides a simple WeChat QR code display for license acquisition
 */
export class WeChatIntegration {
    private context: vscode.ExtensionContext;
    private disposables: vscode.Disposable[] = [];

    constructor(context: vscode.ExtensionContext) {
        this.context = context;
    }

    /**
     * Show the WeChat contact panel with QR code
     */
    public async showWeChatPanel(): Promise<void> {
        const panel = vscode.window.createWebviewPanel(
            'wechatContact',
            'Contact Instructor',
            vscode.ViewColumn.One,
            {
                enableScripts: true,
                retainContextWhenHidden: true
            }
        );

        // Get the path to the QR code image
        const qrCodePath = vscode.Uri.joinPath(this.context.extensionUri, 'media', 'wechat-qr.png');
        const qrCodeUri = panel.webview.asWebviewUri(qrCodePath);

        panel.webview.html = this.getWebviewContent(qrCodeUri);

        // Handle messages from the webview
        panel.webview.onDidReceiveMessage(
            (message) => {
                switch (message.command) {
                    case 'openLicenseManager':
                        vscode.commands.executeCommand('learningPrimerBuddy.openLicenseManager');
                        break;
                }
            },
            undefined,
            this.disposables
        );
    }

    /**
     * Generate the HTML content for the webview
     * @param qrCodeUri URI to the QR code image
     * @returns HTML string for the webview
     */
    private getWebviewContent(qrCodeUri: vscode.Uri): string {
        return `
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Contact Instructor</title>
    <style>
        body {
            font-family: var(--vscode-font-family);
            padding: 20px;
            color: var(--vscode-foreground);
            background-color: var(--vscode-editor-background);
            text-align: center;
        }
        .container {
            max-width: 600px;
            margin: 0 auto;
        }
        h1 {
            color: var(--vscode-foreground);
        }
        .qr-container {
            margin: 30px 0;
        }
        .qr-code {
            max-width: 300px;
            height: auto;
            border: 1px solid var(--vscode-input-border);
            border-radius: 8px;
            padding: 10px;
            background: white;
        }
        .instructions {
            background-color: var(--vscode-textBlockQuote-background);
            padding: 20px;
            border-radius: 8px;
            margin: 20px 0;
            text-align: left;
        }
        .instructions h2 {
            margin-top: 0;
        }
        .instructions ol {
            padding-left: 20px;
        }
        .instructions li {
            margin-bottom: 10px;
        }
        button {
            background-color: var(--vscode-button-background);
            color: var(--vscode-button-foreground);
            border: none;
            padding: 12px 24px;
            border-radius: 4px;
            cursor: pointer;
            font-size: 16px;
            margin: 10px;
        }
        button:hover {
            background-color: var(--vscode-button-hoverBackground);
        }
        .note {
            font-style: italic;
            color: var(--vscode-descriptionForeground);
            margin-top: 30px;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Contact Instructor</h1>
        
        <div class="instructions">
            <h2>How to Purchase Access</h2>
            <ol>
                <li>Scan the WeChat QR code below with your WeChat app</li>
                <li>Add the instructor as a contact</li>
                <li>Send a message expressing your interest in the C++ Primer course</li>
                <li>Complete the payment as instructed</li>
                <li>Receive your license key via WeChat</li>
                <li>Enter your license key in the License Manager</li>
            </ol>
        </div>
        
        <div class="qr-container">
            <img src="${qrCodeUri}" alt="WeChat QR Code" class="qr-code" />
            <p>Scan this QR code to contact the instructor</p>
        </div>
        
        <button onclick="openLicenseManager()">Open License Manager</button>
        
        <p class="note">
            Note: You can access free chapters without a license. 
            Protected chapters require a valid license key.
        </p>
    </div>
    
    <script>
        const vscode = acquireVsCodeApi();
        
        function openLicenseManager() {
            vscode.postMessage({
                command: 'openLicenseManager'
            });
        }
    </script>
</body>
</html>
        `;
    }

    /**
     * Dispose of resources
     */
    public dispose(): void {
        this.disposables.forEach(d => d.dispose());
    }
}