import * as vscode from 'vscode';
import { CourseContentProviderClient } from '../courseContentProviderClient';
import { TemplateEngine } from '../templates/index';
import { CourseContentProtectionManager } from '../courseContentProtectionManager';
import { LicenseManager } from '../license/licenseManager';
import { MyCoursesProvider } from './myCoursesProvider';

export class CourseCatalogWebview {
    public static currentPanel: CourseCatalogWebview | undefined;
    private readonly _panel: vscode.WebviewPanel;
    private readonly _extensionUri: vscode.Uri;
    private _disposables: vscode.Disposable[] = [];
    private courseContentProvider: CourseContentProviderClient;
    private context: vscode.ExtensionContext;
    private protectionManager: CourseContentProtectionManager;
    private myCoursesProvider: MyCoursesProvider;

    public static createOrShow(extensionUri: vscode.Uri, context: vscode.ExtensionContext): void {
        const column = vscode.window.activeTextEditor
            ? vscode.window.activeTextEditor.viewColumn
            : undefined;

        // If we already have a panel, show it
        if (CourseCatalogWebview.currentPanel) {
            CourseCatalogWebview.currentPanel._panel.reveal(column);
            return;
        }

        // Otherwise, create a new panel
        const panel = vscode.window.createWebviewPanel(
            'courseCatalog',
            'Course Catalog',
            column || vscode.ViewColumn.One,
            {
                // Enable JavaScript in the webview
                enableScripts: true,
                // Restrict the webview to only loading content from our extension's directory
                localResourceRoots: [
                    vscode.Uri.joinPath(extensionUri, 'media'),
                    vscode.Uri.joinPath(extensionUri, 'out')
                ]
            }
        );

        CourseCatalogWebview.currentPanel = new CourseCatalogWebview(panel, extensionUri, context);
    }

    private constructor(panel: vscode.WebviewPanel, extensionUri: vscode.Uri, context: vscode.ExtensionContext) {
        this._panel = panel;
        this._extensionUri = extensionUri;
        this.context = context;
        this.courseContentProvider = new CourseContentProviderClient(context);
        
        // Create protection manager and my courses provider for license checking
        this.protectionManager = new CourseContentProtectionManager(context);
        this.myCoursesProvider = new MyCoursesProvider(context, this.protectionManager);

        // Set the webview's initial HTML content
        this._update();

        // Listen for when the panel is disposed
        this._panel.onDidDispose(() => this.dispose(), null, this._disposables);

        // Handle messages from the webview
        this._panel.webview.onDidReceiveMessage(
            async (message) => {
                switch (message.command) {
                    case 'selectCourse':
                        if (message.openLicensePage) {
                            // For licensed courses, open the license purchase page
                            const licenseManager = new LicenseManager(this.protectionManager);
                            await licenseManager.showLicensePurchasePage();
                        } else {
                            // For free courses, select the course directly
                            vscode.commands.executeCommand('learningPrimerBuddy.selectCourse', 
                                message.courseId, message.courseName, message.hasProtectedContent);
                        }
                        return;
                    case 'searchCourses':
                        // Handle search
                        await this.handleSearch(message.searchTerm);
                        return;
                }
            },
            null,
            this._disposables
        );
    }

    private async _update(): Promise<void> {
        const webview = this._panel.webview;
        this._panel.webview.html = await this._getHtmlForWebview(webview);
    }

    private async _getHtmlForWebview(webview: vscode.Webview): Promise<string> {
        // Get the course catalog data
        const catalog = await this.courseContentProvider.getCourseCatalog();
        const courses = catalog?.courses || [];
        
        // Get the currently selected course ID from global state
        const currentCourseId = this.context.globalState.get<string>('currentCourseId', '');

        // Use the template engine to render the HTML with course selection information
        const templateEngine = TemplateEngine.getInstance();
        return await templateEngine.renderCourseCatalogTemplate(webview, this._extensionUri, courses, currentCourseId);
    }

    private async handleSearch(searchTerm: string): Promise<void> {
        let courses;
        
        if (searchTerm) {
            const searchResults = await this.courseContentProvider.searchCourses(searchTerm);
            courses = searchResults?.courses || [];
        } else {
            const catalog = await this.courseContentProvider.getCourseCatalog();
            courses = catalog?.courses || [];
        }

        // Update the webview with search results
        const webview = this._panel.webview;
        this._panel.webview.html = await this._getHtmlForWebview(webview);
    }

    public dispose(): void {
        CourseCatalogWebview.currentPanel = undefined;

        // Clean up our resources
        this._panel.dispose();

        while (this._disposables.length) {
            const disposable = this._disposables.pop();
            if (disposable) {
                disposable.dispose();
            }
        }
    }
}