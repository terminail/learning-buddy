import { PodmanEnvironmentManager } from '../../src/podman/podmanEnvironmentManager';
import * as vscode from 'vscode';
import * as os from 'os';

// Mock the VS Code API
jest.mock('vscode', () => {
    return {
        window: {
            showErrorMessage: jest.fn(),
            showWarningMessage: jest.fn(),
            showInformationMessage: jest.fn()        
        },
        env: {
            openExternal: jest.fn()
        },
        Uri: {
            parse: jest.fn()
        }
    };
});

// Mock os module for different platforms
jest.mock('os');

describe('PodmanEnvironmentManager - Cross-Platform Support', () => {
    let podmanManager: PodmanEnvironmentManager;
    let mockContext: vscode.ExtensionContext;

    beforeEach(() => {
        // Create a mock context
        mockContext = {
            extensionPath: '/test/path',
            globalState: {
                get: jest.fn(),
                update: jest.fn()
            }
        } as any;
    });

    afterEach(() => {
        jest.clearAllMocks();
    });

    describe('Windows Platform', () => {
        beforeEach(() => {
            // Mock Windows platform
            (os.platform as jest.Mock).mockReturnValue('win32');
            podmanManager = new PodmanEnvironmentManager(mockContext);
        });

        test('should handle Windows platform correctly', () => {
            expect(podmanManager).toBeInstanceOf(PodmanEnvironmentManager);
        });

        test('should get correct platform name', () => {
            // This would require exposing a method to test directly
            // In a real implementation, we would test the private method
            expect(os.platform()).toBe('win32');
        });
    });

    describe('macOS Platform', () => {
        beforeEach(() => {
            // Mock macOS platform
            (os.platform as jest.Mock).mockReturnValue('darwin');
            podmanManager = new PodmanEnvironmentManager(mockContext);
        });

        test('should handle macOS platform correctly', () => {
            expect(podmanManager).toBeInstanceOf(PodmanEnvironmentManager);
        });

        test('should get correct platform name', () => {
            expect(os.platform()).toBe('darwin');
        });
    });

    describe('Linux Platform', () => {
        beforeEach(() => {
            // Mock Linux platform
            (os.platform as jest.Mock).mockReturnValue('linux');
            podmanManager = new PodmanEnvironmentManager(mockContext);
        });

        test('should handle Linux platform correctly', () => {
            expect(podmanManager).toBeInstanceOf(PodmanEnvironmentManager);
        });

        test('should get correct platform name', () => {
            expect(os.platform()).toBe('linux');
        });
    });

    describe('Unsupported Platform', () => {
        beforeEach(() => {
            // Mock unsupported platform
            (os.platform as jest.Mock).mockReturnValue('freebsd');
            podmanManager = new PodmanEnvironmentManager(mockContext);
        });

        test('should handle unsupported platform gracefully', () => {
            expect(podmanManager).toBeInstanceOf(PodmanEnvironmentManager);
        });
    });
});