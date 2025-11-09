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

    test('should generate HTML for webview', () => {
        const mockWebview = {
            cspSource: 'vscode-webview://test',
            asWebviewUri: jest.fn().mockImplementation((uri) => uri)
        } as any;

        // Access private method through instance
        const html = (learningBuddyViewProvider as any)._getHtmlForWebview(mockWebview);
        
        expect(typeof html).toBe('string');
        expect(html.length).toBeGreaterThan(0);
        expect(html).toContain('<!DOCTYPE html>');
        expect(html).toContain('<html');
        expect(html).toContain('</html>');
    });

    test('should generate contact list HTML', () => {
        // Access private method through instance
        const contactListHtml = (learningBuddyViewProvider as any)._getContactListHtml();
        
        expect(typeof contactListHtml).toBe('string');
        expect(contactListHtml.length).toBeGreaterThan(0);
        // Check for some expected content
        expect(contactListHtml).toContain('Doubao');
        expect(contactListHtml).toContain('Qwen');
        expect(contactListHtml).toContain('ChatGPT');
    });

    test('should generate icon HTML', () => {
        // Access private method through instance
        const iconHtml = (learningBuddyViewProvider as any)._getIconHtml('heart');
        
        expect(typeof iconHtml).toBe('string');
        expect(iconHtml.length).toBeGreaterThan(0);
        
        // Test with unknown icon
        const unknownIconHtml = (learningBuddyViewProvider as any)._getIconHtml('unknown');
        expect(typeof unknownIconHtml).toBe('string');
    });

    test('should update webview', () => {
        // Access private method through instance
        const updateWebview = (learningBuddyViewProvider as any)._updateWebview;
        expect(typeof updateWebview).toBe('function');
        
        // This should not throw any errors
        expect(() => updateWebview.call(learningBuddyViewProvider)).not.toThrow();
    });

    test('should generate nonce', () => {
        // Access private method through instance
        const nonce = (learningBuddyViewProvider as any)._getNonce();
        
        expect(typeof nonce).toBe('string');
        expect(nonce.length).toBe(32);
    });
});