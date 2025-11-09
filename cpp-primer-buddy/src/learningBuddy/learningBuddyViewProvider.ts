import * as vscode from 'vscode';

// Define the structure for AI contacts
export interface AIContact {
    id: string;
    name: string;
    url: string;
    icon: string;
}

export class LearningBuddyViewProvider implements vscode.WebviewViewProvider {
    public static readonly viewType = 'learning-buddy.chat';
    
    private _view?: vscode.WebviewView;
    private _currentUrl?: string;

    constructor(
        private readonly _extensionUri: vscode.Uri,
    ) { }

    public resolveWebviewView(
        webviewView: vscode.WebviewView,
        // eslint-disable-next-line @typescript-eslint/no-unused-vars
        _context: vscode.WebviewViewResolveContext,
        // eslint-disable-next-line @typescript-eslint/no-unused-vars
        _token: vscode.CancellationToken,
    ) {
        this._view = webviewView;

        webviewView.webview.options = {
            // Allow scripts in the webview
            enableScripts: true,
            localResourceRoots: [
                this._extensionUri
            ]
        };

        webviewView.webview.html = this._getHtmlForWebview(webviewView.webview);

        // Handle messages from the webview
        webviewView.webview.onDidReceiveMessage(
            message => {
                switch (message.command) {
                    case 'openAIWebsite':
                        this._currentUrl = message.url;
                        this._updateWebview();
                        return;
                }
            },
            undefined,
            []
        );
    }

    private _getHtmlForWebview(webview: vscode.Webview) {
        // Uri to load styles into webview
        const styleResetUri = webview.asWebviewUri(vscode.Uri.joinPath(this._extensionUri, 'media', 'reset.css'));
        const styleVSCodeUri = webview.asWebviewUri(vscode.Uri.joinPath(this._extensionUri, 'media', 'vscode.css'));
        const styleMainUri = webview.asWebviewUri(vscode.Uri.joinPath(this._extensionUri, 'media', 'learningBuddyView.css'));

        // Use a nonce to only allow specific scripts to be run
        const nonce = this._getNonce();

        return `<!DOCTYPE html>
            <html lang="en">
            <head>
                <meta charset="UTF-8">
                <meta http-equiv="Content-Security-Policy" content="default-src 'none'; style-src ${webview.cspSource}; script-src 'nonce-${nonce}';">
                <meta name="viewport" content="width=device-width, initial-scale=1.0">
                <link href="${styleResetUri}" rel="stylesheet">
                <link href="${styleVSCodeUri}" rel="stylesheet">
                <link href="${styleMainUri}" rel="stylesheet">
                <title>Learning Buddy</title>
            </head>
            <body>
                <div class="container">
                    <div class="sidebar">
                        <h2>AI Assistants</h2>
                        <ul class="contact-list">
                            ${this._getContactListHtml()}
                        </ul>
                    </div>
                    <div class="content">
                        ${this._currentUrl ? `<iframe src="${this._currentUrl}" frameborder="0"></iframe>` : '<div class="welcome-message">Select an AI assistant from the list to get started</div>'}
                    </div>
                </div>
                <script nonce="${nonce}">
                    const vscode = acquireVsCodeApi();
                    
                    document.addEventListener('DOMContentLoaded', () => {
                        document.querySelectorAll('.contact-item').forEach(item => {
                            item.addEventListener('click', () => {
                                const url = item.getAttribute('data-url');
                                vscode.postMessage({
                                    command: 'openAIWebsite',
                                    url: url
                                });
                            });
                        });
                    });
                </script>
            </body>
            </html>`;
    }

    private _getContactListHtml(): string {
        const contacts: AIContact[] = [
            // Chinese AI websites from major domestic companies (prioritized as requested)
            {
                id: 'doubao',
                name: 'Doubao',
                url: 'https://www.doubao.com',
                icon: 'heart'
            },
            {
                id: 'yuanbao',
                name: 'Yuanbao (Tencent)',
                url: 'https://yuanbao.tencent.com',
                icon: 'windows'
            },
            {
                id: 'qwen',
                name: 'Qwen (Alibaba)',
                url: 'https://tongyi.aliyun.com',
                icon: 'cloud'
            },
            {
                id: 'ernie',
                name: 'ERNIE Bot (Baidu)',
                url: 'https://yiyan.baidu.com',
                icon: 'search'
            },
            {
                id: 'deepseek',
                name: 'DeepSeek',
                url: 'https://chat.deepseek.com',
                icon: 'hubot'
            },
            {
                id: 'kimi',
                name: 'Kimi',
                url: 'https://kimi.com',
                icon: 'robot'
            },
            // International popular AI websites
            {
                id: 'chatgpt',
                name: 'ChatGPT',
                url: 'https://chatgpt.com',
                icon: 'comment'
            },
            {
                id: 'claude',
                name: 'Claude',
                url: 'https://claude.ai',
                icon: 'hubot'
            },
            {
                id: 'gemini',
                name: 'Gemini',
                url: 'https://gemini.google.com',
                icon: 'google'
            },
            {
                id: 'copilot',
                name: 'Microsoft Copilot',
                url: 'https://copilot.microsoft.com',
                icon: 'windows'
            },
            {
                id: 'perplexity',
                name: 'Perplexity AI',
                url: 'https://perplexity.ai',
                icon: 'search'
            }
        ];

        return contacts.map(contact => `
            <li class="contact-item" data-url="${contact.url}">
                <span class="contact-icon">${this._getIconHtml(contact.icon)}</span>
                <span class="contact-name">${contact.name}</span>
            </li>
        `).join('');
    }

    private _getIconHtml(iconName: string): string {
        // Simple mapping of icon names to emojis or characters
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

    private _updateWebview() {
        if (this._view) {
            this._view.webview.html = this._getHtmlForWebview(this._view.webview);
        }
    }

    private _getNonce() {
        let text = '';
        const possible = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';
        for (let i = 0; i < 32; i++) {
            text += possible.charAt(Math.floor(Math.random() * possible.length));
        }
        return text;
    }
}