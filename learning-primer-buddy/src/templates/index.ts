import * as vscode from 'vscode';
import * as fs from 'fs';
import * as path from 'path';

/**
 * Template engine for rendering HTML templates with dynamic content
 */
export class TemplateEngine {
    private static _instance: TemplateEngine;
    private _templateCache: Map<string, string> = new Map();

    private constructor() {}

    /**
     * Get the singleton instance of TemplateEngine
     */
    public static getInstance(): TemplateEngine {
        if (!TemplateEngine._instance) {
            TemplateEngine._instance = new TemplateEngine();
        }
        return TemplateEngine._instance;
    }

    /**
     * Render the main learning buddy template
     */
    public async renderMainTemplate(
        webview: vscode.Webview,
        extensionUri: vscode.Uri,
        currentUrl?: string
    ): Promise<string> {
        const templatePath = vscode.Uri.joinPath(extensionUri, 'media', 'learningBuddyTemplate.html');
        const templateContent = await this._readTemplateFile(templatePath);
        
        // Get CSS URIs
        const styleResetUri = webview.asWebviewUri(vscode.Uri.joinPath(extensionUri, 'media', 'reset.css'));
        const styleVSCodeUri = webview.asWebviewUri(vscode.Uri.joinPath(extensionUri, 'media', 'vscode.css'));
        const styleMainUri = webview.asWebviewUri(vscode.Uri.joinPath(extensionUri, 'media', 'learningBuddyView.css'));
        
        // Generate nonce for CSP
        const nonce = this._generateNonce();
        
        // Replace placeholders
        let html = templateContent
            .replace(/{{STYLE_RESET_URI}}/g, styleResetUri.toString())
            .replace(/{{STYLE_VSCODE_URI}}/g, styleVSCodeUri.toString())
            .replace(/{{STYLE_MAIN_URI}}/g, styleMainUri.toString())
            .replace(/{{NONCE}}/g, nonce)
            .replace(/{{CSP_SOURCE}}/g, webview.cspSource)
            .replace(/{{CONTACT_LIST}}/g, await this.renderContactList())
            .replace(/{{CONTENT_AREA}}/g, currentUrl 
                ? `<iframe src="${currentUrl}" frameborder="0"></iframe>` 
                : '<div class="welcome-message">Select an AI assistant from the list to get started</div>')
            .replace(/{{JAVASCRIPT}}/g, await this.renderJavaScript());

        return html;
    }

    /**
     * Render the contact list component
     */
    public async renderContactList(): Promise<string> {
        const contacts = this.getAIContacts();
        const contactItems = contacts.map(contact => 
            `<li class="contact-item" data-url="${contact.url}" title="${contact.url}">
                <span class="contact-icon">${this.getIconHtml(contact.icon)}</span>
                <span class="contact-name">${contact.name}</span>
            </li>`
        ).join('\n');
        
        return contactItems;
    }

    /**
     * Render the JavaScript component
     */
    public async renderJavaScript(): Promise<string> {
        const jsPath = vscode.Uri.joinPath(vscode.Uri.file(__dirname), '..', '..', 'media', 'learningBuddyScript.js');
        try {
            return await this._readTemplateFile(jsPath);
        } catch (error) {
            // Fallback to inline JavaScript if file doesn't exist
            return this.getDefaultJavaScript();
        }
    }

    /**
     * Get the list of AI contacts
     */
    private getAIContacts(): Array<{id: string, name: string, url: string, icon: string}> {
        return [
            // Chinese AI websites from major domestic companies (prioritized as requested)
            { id: 'doubao', name: 'Doubao', url: 'https://www.doubao.com', icon: 'heart' },
            { id: 'yuanbao', name: 'Yuanbao (Tencent)', url: 'https://yuanbao.tencent.com', icon: 'windows' },
            { id: 'qwen', name: 'Qwen (Alibaba)', url: 'https://tongyi.aliyun.com', icon: 'cloud' },
            { id: 'ernie', name: 'ERNIE Bot (Baidu)', url: 'https://yiyan.baidu.com', icon: 'search' },
            { id: 'deepseek', name: 'DeepSeek', url: 'https://chat.deepseek.com', icon: 'hubot' },
            { id: 'kimi', name: 'Kimi', url: 'https://kimi.com', icon: 'robot' },
            // International popular AI websites
            { id: 'chatgpt', name: 'ChatGPT', url: 'https://chatgpt.com', icon: 'comment' },
            { id: 'claude', name: 'Claude', url: 'https://claude.ai', icon: 'hubot' },
            { id: 'gemini', name: 'Gemini', url: 'https://gemini.google.com', icon: 'google' },
            { id: 'copilot', name: 'Microsoft Copilot', url: 'https://copilot.microsoft.com', icon: 'windows' },
            { id: 'perplexity', name: 'Perplexity AI', url: 'https://perplexity.ai', icon: 'search' }
        ];
    }

    /**
     * Get icon HTML based on icon name
     */
    private getIconHtml(iconName: string): string {
        const iconMap: { [key: string]: string } = {
            'heart': '❤️',
            'windows': '🪟',
            'cloud': '☁️',
            'search': '🔍',
            'hubot': '🤖',
            'robot': '🦾',
            'comment': '💬',
            'google': '🇬'
        };
        
        return iconMap[iconName] || '🔹';
    }

    /**
     * Get default JavaScript content
     */
    private getDefaultJavaScript(): string {
        return `
const vscode = acquireVsCodeApi();

function initializeComponents() {
    console.log("Initializing components...");

    // Set up resizer
    const resizer = document.getElementById('resizer');
    const sidebar = document.querySelector('.sidebar');
    if (resizer && sidebar) {
        let isResizing = false;

        resizer.addEventListener('mousedown', function(e) {
            console.log("Resizer mousedown");
            isResizing = true;
            resizer.classList.add('dragging');
            document.body.style.cursor = 'col-resize';
            document.body.style.userSelect = 'none';
            e.preventDefault();
        });

        document.addEventListener('mousemove', function(e) {
            if (!isResizing) return;
            console.log("Resizer mousemove");

            const containerRect = document.querySelector('.container').getBoundingClientRect();
            const newWidth = e.clientX - containerRect.left;

            if (newWidth > 200 && newWidth < 500) {
                sidebar.style.width = newWidth + 'px';
            }
        });

        document.addEventListener('mouseup', function() {
            if (isResizing) {
                console.log("Resizer mouseup");
                isResizing = false;
                resizer.classList.remove('dragging');
                document.body.style.cursor = '';
                document.body.style.userSelect = '';
            }
        });
    }

    // Set up contact item click handlers
    const contactItems = document.querySelectorAll('.contact-item');
    console.log("Found " + contactItems.length + " contact items");
    contactItems.forEach(item => {
        item.addEventListener('click', function(e) {
            console.log("Contact item clicked:", item.textContent);
            // Remove active class from all items
            contactItems.forEach(i => {
                i.classList.remove('active');
            });

            // Add active class to clicked item
            item.classList.add('active');

            // Send message to extension
            const url = item.getAttribute('data-url');
            console.log("Sending message to VSCode with URL:", url);
            vscode.postMessage({
                command: 'openAIWebsite',
                url: url
            });
        });
    });
}

// Wait for DOM to be fully loaded
if (document.readyState === 'loading') {
    document.addEventListener('DOMContentLoaded', initializeComponents);
} else {
    setTimeout(initializeComponents, 100); // Small delay to ensure DOM is ready
}
`;
    }

    /**
     * Read template file from disk with caching
     */
    private async _readTemplateFile(fileUri: vscode.Uri): Promise<string> {
        const filePath = fileUri.fsPath;
        
        // Check cache first
        if (this._templateCache.has(filePath)) {
            return this._templateCache.get(filePath)!;
        }

        try {
            const content = await vscode.workspace.fs.readFile(fileUri);
            const contentStr = Buffer.from(content).toString('utf8');
            
            // Cache the content
            this._templateCache.set(filePath, contentStr);
            
            return contentStr;
        } catch (error) {
            console.error(`Error reading template file: ${filePath}`, error);
            throw error;
        }
    }

    /**
     * Generate a nonce for Content Security Policy
     */
    private _generateNonce(): string {
        let text = '';
        const possible = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';
        for (let i = 0; i < 32; i++) {
            text += possible.charAt(Math.floor(Math.random() * possible.length));
        }
        return text;
    }
}

export const templateEngine = TemplateEngine.getInstance();