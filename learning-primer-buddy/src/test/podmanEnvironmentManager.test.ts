import { PodmanEnvironmentManager } from '../podmanEnvironmentManager';
import * as vscode from 'vscode';

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

describe('PodmanEnvironmentManager', () => {
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

        podmanManager = new PodmanEnvironmentManager(mockContext);
    });

    afterEach(() => {
        jest.clearAllMocks();
    });

    test('should create PodmanEnvironmentManager instance', () => {
        expect(podmanManager).toBeInstanceOf(PodmanEnvironmentManager);
    });

    test('should have isInitialized method', () => {
        expect(typeof podmanManager.isInitialized).toBe('function');
    });

    test('should have getPodmanExecutable method', () => {
        expect(typeof podmanManager.getPodmanExecutable).toBe('function');
    });

    test('should have getContainerId method', () => {
        expect(typeof podmanManager.getContainerId).toBe('function');
    });

    test('should have dispose method', () => {
        expect(typeof podmanManager.dispose).toBe('function');
    });
});