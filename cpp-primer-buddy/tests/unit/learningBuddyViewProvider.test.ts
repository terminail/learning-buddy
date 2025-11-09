import { LearningBuddyViewProvider } from '../../src/learningBuddy/learningBuddyViewProvider';
import * as vscode from 'vscode';

// Mock the VS Code API
jest.mock('vscode', () => {
    return {
        Uri: {
            joinPath: jest.fn().mockImplementation((...paths) => {
                return {
                    toString: () => paths.join('/')
                };
            })
        },
        Webview: {
            asWebviewUri: jest.fn().mockImplementation((uri) => uri)
        }
    };
});

// Mock the template engine
jest.mock('../../src/templates/index', () => ({
    templateEngine: {
        renderMainTemplate: jest.fn().mockResolvedValue('<!DOCTYPE html><html><head></head><body>Mock HTML</body></html>')
    }
}));

describe('LearningBuddyViewProvider', () => {
    let learningBuddyViewProvider: LearningBuddyViewProvider;
    let mockExtensionUri: vscode.Uri;

    beforeEach(() => {
        // Create a mock extension URI
        mockExtensionUri = {
            toString: () => '/test/extension/path'
        } as any;

        learningBuddyViewProvider = new LearningBuddyViewProvider(mockExtensionUri);
    });

    afterEach(() => {
        jest.clearAllMocks();
    });

    test('should create LearningBuddyViewProvider instance', () => {
        expect(learningBuddyViewProvider).toBeInstanceOf(LearningBuddyViewProvider);
    });

    test('should have correct viewType', () => {
        expect(LearningBuddyViewProvider.viewType).toBe('learning-buddy.chat');
    });

    test('should have resolveWebviewView method', () => {
        expect(typeof learningBuddyViewProvider.resolveWebviewView).toBe('function');
    });

    test('should resolve webview view correctly', () => {
        const mockWebviewView = {
            webview: {
                options: {},
                html: '',
                onDidReceiveMessage: jest.fn(),
                asWebviewUri: jest.fn().mockImplementation((uri) => uri)
            }
        } as any;

        const mockContext = {} as any;
        const mockToken = {} as any;

        // This should not throw any errors
        expect(() => learningBuddyViewProvider.resolveWebviewView(
            mockWebviewView,
            mockContext,
            mockToken
        )).not.toThrow();

        // Check that webview options were set
        expect(mockWebviewView.webview.options).toBeDefined();
        expect(mockWebviewView.webview.options.enableScripts).toBe(true);
    });

    test('should generate HTML for webview', async () => {
        const mockWebview = {
            cspSource: 'vscode-webview://test',
            asWebviewUri: jest.fn().mockImplementation((uri) => uri)
        } as any;

        // Access private method through instance
        const html = await (learningBuddyViewProvider as any)._getHtmlForWebview(mockWebview);
        
        expect(typeof html).toBe('string');
        expect(html.length).toBeGreaterThan(0);
        expect(html).toContain('<!DOCTYPE html>');
        expect(html).toContain('<html');
        expect(html).toContain('</html>');
    });

    test('should update webview', async () => {
        // Access private method through instance
        const updateWebview = (learningBuddyViewProvider as any)._updateWebview;
        expect(typeof updateWebview).toBe('function');
        
        // This should not throw any errors
        await expect(updateWebview.call(learningBuddyViewProvider)).resolves.not.toThrow();
    });
});