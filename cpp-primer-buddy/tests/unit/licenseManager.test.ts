import { LicenseManager } from '../../src/licenseManager';
import * as vscode from 'vscode';

// Mock the VS Code API
jest.mock('vscode', () => {
    return {
        window: {
            showErrorMessage: jest.fn(),
            showInformationMessage: jest.fn(),
            createWebviewPanel: jest.fn().mockReturnValue({
                webview: {
                    html: '',
                    onDidReceiveMessage: jest.fn(),
                    postMessage: jest.fn()
                },
                dispose: jest.fn()
            })
        },
        commands: {
            executeCommand: jest.fn()
        },
        ViewColumn: {
            One: 1
        }
    };
});

describe('LicenseManager', () => {
    let licenseManager: LicenseManager;
    let mockProtectionManager: any;

    beforeEach(() => {
        // Create a mock protection manager
        mockProtectionManager = {
            getValidLicenses: jest.fn().mockReturnValue([]),
            removeLicense: jest.fn(),
            addLicense: jest.fn().mockResolvedValue(true)
        };

        licenseManager = new LicenseManager(mockProtectionManager);
    });

    afterEach(() => {
        jest.clearAllMocks();
    });

    test('should create LicenseManager instance', () => {
        expect(licenseManager).toBeInstanceOf(LicenseManager);
    });

    test('should have showLicenseInfoPage method', () => {
        expect(typeof licenseManager.showLicenseInfoPage).toBe('function');
    });

    test('should have showLicensePurchasePage method', () => {
        expect(typeof licenseManager.showLicensePurchasePage).toBe('function');
    });

    test('should have showLicensePage method', () => {
        expect(typeof licenseManager.showLicensePage).toBe('function');
    });

    test('should have showLicensePanel method', () => {
        expect(typeof licenseManager.showLicensePanel).toBe('function');
    });

    test('should have dispose method', () => {
        expect(typeof licenseManager.dispose).toBe('function');
    });

    test('should call protectionManager.getValidLicenses when showing license info page', async () => {
        await licenseManager.showLicenseInfoPage();
        expect(mockProtectionManager.getValidLicenses).toHaveBeenCalled();
    });

    test('should call protectionManager.getValidLicenses when showing license panel', async () => {
        await licenseManager.showLicensePanel();
        expect(mockProtectionManager.getValidLicenses).toHaveBeenCalled();
    });

    test('should call protectionManager.removeLicense when removing a license', async () => {
        const licenseId = 'test-license-id';
        mockProtectionManager.getValidLicenses.mockReturnValue([
            { id: licenseId, createdAt: '2023-01-01', expiresAt: '2024-01-01' }
        ]);
        
        await licenseManager.showLicensePanel();
        // Simulate message from webview
        const messageHandler = (vscode.window.createWebviewPanel as jest.Mock).mock.results[0].value.webview.onDidReceiveMessage.mock.calls[0][0];
        await messageHandler({ command: 'removeLicense', licenseId });
        
        expect(mockProtectionManager.removeLicense).toHaveBeenCalledWith(licenseId);
    });

    test('should call protectionManager.addLicense when adding a license', async () => {
        const licenseKey = 'test-license-key';
        await licenseManager.showLicensePanel();
        // Simulate message from webview
        const messageHandler = (vscode.window.createWebviewPanel as jest.Mock).mock.results[0].value.webview.onDidReceiveMessage.mock.calls[0][0];
        await messageHandler({ command: 'addLicense', licenseKey });
        
        expect(mockProtectionManager.addLicense).toHaveBeenCalledWith(licenseKey);
    });

    test('should show error message when adding invalid license', async () => {
        const licenseKey = 'invalid-license-key';
        mockProtectionManager.addLicense.mockResolvedValue(false);
        
        await licenseManager.showLicensePanel();
        // Simulate message from webview
        const messageHandler = (vscode.window.createWebviewPanel as jest.Mock).mock.results[0].value.webview.onDidReceiveMessage.mock.calls[0][0];
        await messageHandler({ command: 'addLicense', licenseKey });
        
        expect(vscode.window.showErrorMessage).toHaveBeenCalled();
    });

    test('should show info message when license is added successfully', async () => {
        const licenseKey = 'valid-license-key';
        mockProtectionManager.addLicense.mockResolvedValue(true);
        
        await licenseManager.showLicensePanel();
        // Simulate message from webview
        const messageHandler = (vscode.window.createWebviewPanel as jest.Mock).mock.results[0].value.webview.onDidReceiveMessage.mock.calls[0][0];
        await messageHandler({ command: 'addLicense', licenseKey });
        
        expect(vscode.window.showInformationMessage).toHaveBeenCalledWith('License added successfully!');
    });

    test('should dispose of resources correctly', () => {
        // Create a license panel first
        licenseManager.showLicensePanel();
        const mockPanel = (vscode.window.createWebviewPanel as jest.Mock).mock.results[0].value;
        
        // Dispose the license manager
        licenseManager.dispose();
        
        // Check that the panel's dispose method was called
        expect(mockPanel.dispose).toHaveBeenCalledTimes(1);
    });
});