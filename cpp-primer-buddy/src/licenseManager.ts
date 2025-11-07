import * as vscode from 'vscode';
import * as crypto from 'crypto';
import * as fs from 'fs';
import * as path from 'path';
import { LicenseInfo } from './contentProtection';

/**
 * LicenseManager provides UI for managing license keys
 */
export class LicenseManager {
    private disposables: vscode.Disposable[] = [];

    constructor(private protectionManager: any) {
    }

    /**
     * Show the license management panel
     */
    public async showLicensePanel(): Promise<void> {
        const panel = vscode.window.createWebviewPanel(
            'licenseManager',
            'License Manager',
            vscode.ViewColumn.One,
            {
                enableScripts: true,
                retainContextWhenHidden: true
            }
        );

        // Get valid licenses from the protection manager
        const licenses = this.protectionManager.getValidLicenses();
        let licensesHtml = '';
        
        if (licenses.length > 0) {
            licensesHtml = licenses.map((license: any) => `
                <div class="license-item">
                    <div class="license-info">
                        <div><strong>ID:</strong> ${license.id.substring(0, 8)}...</div>
                        <div><strong>Created:</strong> ${license.createdAt.toLocaleDateString()}</div>
                        <div><strong>Expires:</strong> ${license.expiresAt.toLocaleDateString()}</div>
                    </div>
                    <button onclick="removeLicense('${license.id}')">Remove</button>
                </div>
            `).join('');
        }

        panel.webview.html = this.getWebviewContent(licensesHtml);

        // Handle messages from the webview
        panel.webview.onDidReceiveMessage(
            async (message) => {
                switch (message.command) {
                    case 'addLicense':
                        const success = await this.protectionManager.addLicense(message.licenseKey);
                        if (success) {
                            vscode.window.showInformationMessage('License added successfully!');
                            // Refresh the tree view to show unlocked content
                            vscode.commands.executeCommand('cppPrimerBuddy.refresh');
                        } else {
                            vscode.window.showErrorMessage('Invalid license key. Please check your key and try again.');
                        }
                        break;
                    case 'removeLicense':
                        this.protectionManager.removeLicense(message.licenseId);
                        vscode.window.showInformationMessage('License removed successfully!');
                        // Refresh the tree view to show locked content again
                        vscode.commands.executeCommand('cppPrimerBuddy.refresh');
                        break;
                }
            },
            undefined,
            this.disposables
        );
    }

    /**
     * Generate the HTML content for the webview
     * @param licensesHtml HTML string for the licenses list
     * @returns HTML string for the webview
     */
    private getWebviewContent(licensesHtml: string): string {
        return `
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>License Manager</title>
    <style>
        body {
            font-family: var(--vscode-font-family);
            padding: 20px;
            color: var(--vscode-foreground);
            background-color: var(--vscode-editor-background);
        }
        .container {
            max-width: 800px;
            margin: 0 auto;
        }
        h1 {
            color: var(--vscode-foreground);
        }
        h2 {
            color: var(--vscode-foreground);
            border-bottom: 1px solid var(--vscode-input-border);
            padding-bottom: 5px;
        }
        .form-group {
            margin-bottom: 20px;
        }
        label {
            display: block;
            margin-bottom: 5px;
            font-weight: bold;
        }
        textarea {
            width: 100%;
            padding: 8px;
            border: 1px solid var(--vscode-input-border);
            background-color: var(--vscode-input-background);
            color: var(--vscode-input-foreground);
            border-radius: 4px;
            box-sizing: border-box;
            font-family: monospace;
            resize: vertical;
            min-height: 100px;
        }
        input[type="text"] {
            width: 100%;
            padding: 8px;
            border: 1px solid var(--vscode-input-border);
            background-color: var(--vscode-input-background);
            color: var(--vscode-input-foreground);
            border-radius: 4px;
            box-sizing: border-box;
        }
        button {
            background-color: var(--vscode-button-background);
            color: var(--vscode-button-foreground);
            border: none;
            padding: 8px 16px;
            border-radius: 4px;
            cursor: pointer;
            margin-top: 10px;
        }
        button:hover {
            background-color: var(--vscode-button-hoverBackground);
        }
        .license-list {
            margin-top: 30px;
        }
        .license-item {
            display: flex;
            justify-content: space-between;
            align-items: center;
            padding: 15px;
            margin-bottom: 10px;
            background-color: var(--vscode-list-hoverBackground);
            border-radius: 4px;
        }
        .license-info div {
            margin-bottom: 5px;
        }
        .instructions {
            background-color: var(--vscode-textBlockQuote-background);
            padding: 15px;
            border-radius: 4px;
            margin-bottom: 20px;
        }
        .test-license-section {
            background-color: var(--vscode-textBlockQuote-background);
            padding: 15px;
            border-radius: 4px;
            margin-bottom: 20px;
        }
        .code {
            font-family: monospace;
            background-color: var(--vscode-textCodeBlock-background);
            padding: 2px 4px;
            border-radius: 3px;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>License Manager</h1>
        
        <div class="instructions">
            <h2>How to Get a License</h2>
            <p>To access protected content, you need to purchase a license:</p>
            <ol>
                <li>Scan the WeChat QR code in the extension</li>
                <li>Contact the instructor to purchase access</li>
                <li>Receive your license key via WeChat</li>
                <li>Enter your license key below</li>
            </ol>
        </div>
        
        <div class="test-license-section">
            <h2>Development Testing</h2>
            <p>For development and testing purposes, you can generate a test license by running the following command in your terminal:</p>
            <p><span class="code">node generate-test-license.js</span></p>
            <p>This will output a properly signed test license key that you can paste below.</p>
        </div>
        
        <div class="form-group">
            <label for="licenseKey">Enter License Key:</label>
            <textarea id="licenseKey" placeholder="Enter your license key here"></textarea>
            <button onclick="addLicense()">Add License</button>
        </div>
        
        <div class="license-list">
            <h2>Active Licenses</h2>
            ${licensesHtml || '<p>No active licenses found.</p>'}
        </div>
    </div>
    
    <script>
        const vscode = acquireVsCodeApi();
        
        function addLicense() {
            const licenseKey = document.getElementById('licenseKey').value;
            if (licenseKey) {
                vscode.postMessage({
                    command: 'addLicense',
                    licenseKey: licenseKey
                });
                // Clear the input field
                document.getElementById('licenseKey').value = '';
            }
        }
        
        function removeLicense(licenseId) {
            vscode.postMessage({
                command: 'removeLicense',
                licenseId: licenseId
            });
        }
        
        // Allow Ctrl+Enter to submit license
        document.getElementById('licenseKey').addEventListener('keydown', function(e) {
            if (e.ctrlKey && e.key === 'Enter') {
                addLicense();
            }
        });
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