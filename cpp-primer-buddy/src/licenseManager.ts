import * as vscode from 'vscode';
import * as crypto from 'crypto';
import * as fs from 'fs';
import * as path from 'path';
import { LicenseInfo } from './contentProtection';

/**
 * LicenseManager provides UI for managing license keys
 * 
 * NOTE: License verification is now handled by the Course Content Provider running in the
 * Learning Buddy Podman Environment as per specification 014c-license-management.
 * This UI now coordinates with the ContentProtectionManager which uses the Course Content Provider.
 */
export class LicenseManager {
    private disposables: vscode.Disposable[] = [];

    constructor(private protectionManager: any) {
    }

    /**
     * Show the license information page (for users with valid licenses)
     */
    public async showLicenseInfoPage(): Promise<void> {
        const panel = vscode.window.createWebviewPanel(
            'licenseInfo',
            'License Information',
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
            licensesHtml = licenses.map((license: any) => {
                // Ensure dates are properly formatted
                let createdDate = '';
                let expiresDate = '';
                
                try {
                    if (license.createdAt) {
                        const created = new Date(license.createdAt);
                        createdDate = isNaN(created.getTime()) ? license.createdAt : created.toLocaleDateString();
                    }
                    if (license.expiresAt) {
                        const expires = new Date(license.expiresAt);
                        expiresDate = isNaN(expires.getTime()) ? license.expiresAt : expires.toLocaleDateString();
                    }
                } catch (e) {
                    // Fallback to original values if date parsing fails
                    createdDate = license.createdAt || '';
                    expiresDate = license.expiresAt || '';
                }
                
                return `
                <div class="license-item">
                    <div class="license-info">
                        <div><strong>ID:</strong> ${license.id ? license.id.substring(0, 8) + '...' : 'N/A'}</div>
                        <div><strong>Created:</strong> ${createdDate}</div>
                        <div><strong>Expires:</strong> ${expiresDate}</div>
                    </div>
                    <button onclick="removeLicense('${license.id || ''}')">Remove</button>
                </div>
            `}).join('');
        }

        panel.webview.html = this.getLicenseInfoWebviewContent(licensesHtml);

        // Handle messages from the webview
        panel.webview.onDidReceiveMessage(
            async (message) => {
                switch (message.command) {
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
     * Show the license purchase page (for users without valid licenses)
     */
    public async showLicensePurchasePage(): Promise<void> {
        const panel = vscode.window.createWebviewPanel(
            'licensePurchase',
            'Purchase License',
            vscode.ViewColumn.One,
            {
                enableScripts: true,
                retainContextWhenHidden: true
            }
        );

        panel.webview.html = this.getLicensePurchaseWebviewContent();

        // Handle messages from the webview
        panel.webview.onDidReceiveMessage(
            async (message) => {
                switch (message.command) {
                    case 'addLicense':
                        // Add license through the protection manager which now uses the Course Content Provider
                        const success = await this.protectionManager.addLicense(message.licenseKey);
                        if (success) {
                            vscode.window.showInformationMessage('License added successfully!');
                            // Refresh the tree view to show unlocked content
                            vscode.commands.executeCommand('cppPrimerBuddy.refresh');
                            // Close the purchase page
                            panel.dispose();
                        } else {
                            vscode.window.showErrorMessage(
                                'Invalid license key. Please check your key and try again. ' +
                                'Ensure the Learning Buddy Podman Environment is running for license verification.'
                            );
                        }
                        break;
                }
            },
            undefined,
            this.disposables
        );
    }

    /**
     * Show the license page (alias for showLicensePanel for backward compatibility)
     */
    public async showLicensePage(): Promise<void> {
        return this.showLicensePanel();
    }

    /**
     * Show the license management panel (backward compatibility)
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
            licensesHtml = licenses.map((license: any) => {
                // Ensure dates are properly formatted
                let createdDate = '';
                let expiresDate = '';
                
                try {
                    if (license.createdAt) {
                        const created = new Date(license.createdAt);
                        createdDate = isNaN(created.getTime()) ? license.createdAt : created.toLocaleDateString();
                    }
                    if (license.expiresAt) {
                        const expires = new Date(license.expiresAt);
                        expiresDate = isNaN(expires.getTime()) ? license.expiresAt : expires.toLocaleDateString();
                    }
                } catch (e) {
                    // Fallback to original values if date parsing fails
                    createdDate = license.createdAt || '';
                    expiresDate = license.expiresAt || '';
                }
                
                return `
                <div class="license-item">
                    <div class="license-info">
                        <div><strong>ID:</strong> ${license.id ? license.id.substring(0, 8) + '...' : 'N/A'}</div>
                        <div><strong>Created:</strong> ${createdDate}</div>
                        <div><strong>Expires:</strong> ${expiresDate}</div>
                    </div>
                    <button onclick="removeLicense('${license.id || ''}')">Remove</button>
                </div>
            `}).join('');
        }

        panel.webview.html = this.getWebviewContent(licensesHtml);

        // Handle messages from the webview
        panel.webview.onDidReceiveMessage(
            async (message) => {
                switch (message.command) {
                    case 'addLicense':
                        // Add license through the protection manager which now uses the Course Content Provider
                        const success = await this.protectionManager.addLicense(message.licenseKey);
                        if (success) {
                            vscode.window.showInformationMessage('License added successfully!');
                            // Refresh the tree view to show unlocked content
                            vscode.commands.executeCommand('cppPrimerBuddy.refresh');
                        } else {
                            vscode.window.showErrorMessage(
                                'Invalid license key. Please check your key and try again. ' +
                                'Ensure the Learning Buddy Podman Environment is running for license verification.'
                            );
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
     * Generate the HTML content for the license info webview
     * @param licensesHtml HTML string for the licenses list
     * @returns HTML string for the webview
     */
    private getLicenseInfoWebviewContent(licensesHtml: string): string {
        return `
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>License Information</title>
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
        .podman-notice {
            background-color: var(--vscode-editor-warning-foreground);
            color: var(--vscode-editor-background);
            padding: 15px;
            border-radius: 4px;
            margin-bottom: 20px;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>License Information</h1>
        
        <div class="podman-notice">
            <h2>Active License</h2>
            <p>You have an active license for Learning Buddy. Thank you for supporting our educational platform!</p>
        </div>
        
        <div class="instructions">
            <h2>Your Licenses</h2>
            <p>Below are your active licenses:</p>
        </div>
        
        <div class="license-list">
            ${licensesHtml || '<p>No active licenses found.</p>'}
        </div>
    </div>
    
    <script>
        const vscode = acquireVsCodeApi();
        
        function removeLicense(licenseId) {
            vscode.postMessage({
                command: 'removeLicense',
                licenseId: licenseId
            });
        }
    </script>
</body>
</html>
`;
    }

    /**
     * Generate the HTML content for the license purchase webview
     * @returns HTML string for the webview
     */
    private getLicensePurchaseWebviewContent(): string {
        return `
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Purchase License</title>
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
        .instructions {
            background-color: var(--vscode-textBlockQuote-background);
            padding: 15px;
            border-radius: 4px;
            margin-bottom: 20px;
        }
        .podman-notice {
            background-color: var(--vscode-editor-warning-foreground);
            color: var(--vscode-editor-background);
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
        <h1>Purchase License</h1>
        
        <div class="podman-notice">
            <h2>Important Notice</h2>
            <p>License verification is now handled by the Course Content Provider running in the Learning Buddy Podman Environment. 
            Please ensure the Learning Buddy Podman Environment is running for proper license verification.</p>
        </div>
        
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
        
        <div class="form-group">
            <label for="licenseKey">License Key:</label>
            <textarea id="licenseKey" placeholder="Paste your license key here..."></textarea>
        </div>
        
        <button onclick="addLicense()">Activate License</button>
    </div>
    
    <script>
        const vscode = acquireVsCodeApi();
        
        function addLicense() {
            const licenseKey = document.getElementById('licenseKey').value;
            if (!licenseKey) {
                alert('Please enter a license key');
                return;
            }
            
            vscode.postMessage({
                command: 'addLicense',
                licenseKey: licenseKey
            });
        }
    </script>
</body>
</html>
`;
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
        .podman-notice {
            background-color: var(--vscode-editor-warning-foreground);
            color: var(--vscode-editor-background);
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
        
        <div class="podman-notice">
            <h2>Important Notice</h2>
            <p>License verification is now handled by the Course Content Provider running in the Learning Buddy Podman Environment. 
            Please ensure the Learning Buddy Podman Environment is running for proper license verification.</p>
        </div>
        
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