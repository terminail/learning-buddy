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

        // Create the HTML string with proper escaping for template literals
        return '<!DOCTYPE html>\n' +
'<html lang="en">\n' +
'<head>\n' +
    '<meta charset="UTF-8">\n' +
    '<meta http-equiv="Content-Security-Policy" content="default-src &apos;none&apos;; img-src ' + webview.cspSource + ' https:; script-src &apos;nonce-' + nonce + '&apos;; style-src ' + webview.cspSource + ' &apos;unsafe-inline&apos;; frame-src https:; child-src https:">\n' +
    '<meta name="viewport" content="width=device-width, initial-scale=1.0">\n' +
    '<link href="' + styleResetUri.toString() + '" rel="stylesheet">\n' +
    '<link href="' + styleVSCodeUri.toString() + '" rel="stylesheet">\n' +
    '<link href="' + styleMainUri.toString() + '" rel="stylesheet">\n' +
    '<title>Learning Buddy</title>\n' +
'</head>\n' +
'<body>\n' +
    '<div class="container">\n' +
        '<div class="sidebar">\n' +
            '<h2>AI Assistants</h2>\n' +
            '<ul class="contact-list">\n' +
                this._getContactListHtml() + '\n' +
            '</ul>\n' +
        '</div>\n' +
        '<div class="resizer" id="resizer"></div>\n' +
        '<div class="content">\n' +
            (this._currentUrl ? '<iframe src="' + this._currentUrl + '" frameborder="0"></iframe>' : '<div class="welcome-message">Select an AI assistant from the list to get started</div>') + '\n' +
        '</div>\n' +
    '</div>\n' +
    '<script nonce="' + nonce + '">\n' +
        'const vscode = acquireVsCodeApi();\n' +
        '\n' +
        'function initializeComponents() {\n' +
            'console.log("Initializing components...");\n' +
            '\n' +
            '// Set up resizer\n' +
            'const resizer = document.getElementById(\'resizer\');\n' +
            'const sidebar = document.querySelector(\'.sidebar\');\n' +
            'if (resizer && sidebar) {\n' +
                'let isResizing = false;\n' +
                '\n' +
                'resizer.addEventListener(\'mousedown\', function(e) {\n' +
                    'console.log("Resizer mousedown");\n' +
                    'isResizing = true;\n' +
                    'resizer.classList.add(\'dragging\');\n' +
                    'document.body.style.cursor = \'col-resize\';\n' +
                    'document.body.style.userSelect = \'none\';\n' +
                    'e.preventDefault();\n' +
                '});\n' +
                '\n' +
                'document.addEventListener(\'mousemove\', function(e) {\n' +
                    'if (!isResizing) return;\n' +
                    'console.log("Resizer mousemove");\n' +
                    '\n' +
                    'const containerRect = document.querySelector(\'.container\').getBoundingClientRect();\n' +
                    'const newWidth = e.clientX - containerRect.left;\n' +
                    '\n' +
                    'if (newWidth > 200 && newWidth < 500) {\n' +
                        'sidebar.style.width = newWidth + \'px\';\n' +
                    '}\n' +
                '});\n' +
                '\n' +
                'document.addEventListener(\'mouseup\', function() {\n' +
                    'if (isResizing) {\n' +
                        'console.log("Resizer mouseup");\n' +
                        'isResizing = false;\n' +
                        'resizer.classList.remove(\'dragging\');\n' +
                        'document.body.style.cursor = \'\';\n' +
                        'document.body.style.userSelect = \'\';\n' +
                    '}\n' +
                '});\n' +
            '}\n' +
            '\n' +
            '// Set up contact item click handlers\n' +
            'const contactItems = document.querySelectorAll(\'.contact-item\');\n' +
            'console.log("Found " + contactItems.length + " contact items");\n' +
            'contactItems.forEach(item => {\n' +
                'item.addEventListener(\'click\', function(e) {\n' +
                    'console.log("Contact item clicked:", item.textContent);\n' +
                    '// Remove active class from all items\n' +
                    'contactItems.forEach(i => {\n' +
                        'i.classList.remove(\'active\');\n' +
                    '});\n' +
                    '\n' +
                    '// Add active class to clicked item\n' +
                    'item.classList.add(\'active\');\n' +
                    '\n' +
                    '// Send message to extension\n' +
                    'const url = item.getAttribute(\'data-url\');\n' +
                    'console.log("Sending message to VSCode with URL:", url);\n' +
                    'vscode.postMessage({\n' +
                        'command: \'openAIWebsite\',\n' +
                        'url: url\n' +
                    '});\n' +
                '});\n' +
            '});\n' +
        '}\n' +
        '\n' +
        '// Wait for DOM to be fully loaded\n' +
        'if (document.readyState === \'loading\') {\n' +
            'document.addEventListener(\'DOMContentLoaded\', initializeComponents);\n' +
        '} else {\n' +
            'setTimeout(initializeComponents, 100); // Small delay to ensure DOM is ready\n' +
        '}\n' +
    '</script>\n' +
'</body>\n' +
'</html>';
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

        return contacts.map(contact => 
            '<li class="contact-item" data-url="' + contact.url + '" title="' + contact.url + '">' +
                '<span class="contact-icon">' + this._getIconHtml(contact.icon) + '</span>' +
                '<span class="contact-name">' + contact.name + '</span>' +
            '</li>'
        ).join('');
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