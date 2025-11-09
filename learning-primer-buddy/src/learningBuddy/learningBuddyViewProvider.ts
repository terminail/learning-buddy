import * as vscode from 'vscode';
import { templateEngine } from '../templates/index';

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
                vscode.Uri.joinPath(this._extensionUri, 'media')
            ]
        };

        this._updateWebview();

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

    private async _getHtmlForWebview(webview: vscode.Webview): Promise<string> {
        return await templateEngine.renderMainTemplate(webview, this._extensionUri, this._currentUrl);
    }

    private async _updateWebview() {
        if (this._view) {
            this._view.webview.html = await this._getHtmlForWebview(this._view.webview);
        }
    }
}