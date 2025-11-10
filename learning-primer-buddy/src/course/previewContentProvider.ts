import * as vscode from 'vscode';

/**
 * Custom text document content provider for read-only previews
 */
export class PreviewContentProvider implements vscode.TextDocumentContentProvider {
    private _onDidChange = new vscode.EventEmitter<vscode.Uri>();
    private contentMap: Map<string, string> = new Map();

    public readonly onDidChange = this._onDidChange.event;

    public provideTextDocumentContent(uri: vscode.Uri): string {
        return this.contentMap.get(uri.toString()) || '';
    }

    public setPreviewContent(uri: vscode.Uri, content: string) {
        this.contentMap.set(uri.toString(), content);
        this._onDidChange.fire(uri);
    }
}