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

// Mock os module
jest.mock('os');

// Mock child_process
jest.mock('child_process', () => {
    return {
        exec: jest.fn().mockImplementation((command, callback) => {
            // Mock different responses based on command
            if (command.includes('which podman') || command.includes('where podman')) {
                callback(null, '/usr/local/bin/podman');
            } else if (command.includes('podman version')) {
                callback(null, '{"Client": {"Version": "4.0.0"}}');
            } else if (command.includes('podman ps')) {
                callback(null, 'container123');
            } else {
                callback(new Error('Command not found'), '');
            }
        })
    };
});

// Mock fs
jest.mock('fs', () => {
    return {
        existsSync: jest.fn().mockReturnValue(true),
        readFileSync: jest.fn()
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

    test('should have initialize method', () => {
        expect(typeof podmanManager.initialize).toBe('function');
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

    test('should have setOnPodmanNotAvailableCallback method', () => {
        expect(typeof podmanManager.setOnPodmanNotAvailableCallback).toBe('function');
    });

    test('should have getPodmanVersion method', async () => {
        expect(typeof podmanManager.getPodmanVersion).toBe('function');
        const version = await podmanManager.getPodmanVersion();
        expect(version).toBeDefined();
    });

    test('should have getInstalledCourseContainers method', async () => {
        expect(typeof podmanManager.getInstalledCourseContainers).toBe('function');
        const containers = await podmanManager.getInstalledCourseContainers();
        expect(containers).toBeDefined();
        expect(Array.isArray(containers)).toBe(true);
    });

    test('should initialize correctly', async () => {
        const result = await podmanManager.initialize();
        expect(typeof result).toBe('boolean');
    });

    test('should return correct initialization status', () => {
        const status = podmanManager.isInitialized();
        expect(typeof status).toBe('boolean');
    });

    test('should return podman executable path', () => {
        const executable = podmanManager.getPodmanExecutable();
        expect(executable === null || typeof executable === 'string').toBe(true);
    });

    test('should return container ID', () => {
        const containerId = podmanManager.getContainerId();
        expect(containerId === null || typeof containerId === 'string').toBe(true);
    });

    test('should set onPodmanNotAvailable callback', () => {
        const callback = jest.fn();
        podmanManager.setOnPodmanNotAvailableCallback(callback);
        expect(typeof (podmanManager as any).onPodmanNotAvailable).toBe('function');
    });

    test('should handle different platforms', () => {
        // Test Windows platform
        (os.platform as jest.Mock).mockReturnValue('win32');
        const winManager = new PodmanEnvironmentManager(mockContext);
        expect(winManager).toBeInstanceOf(PodmanEnvironmentManager);

        // Test macOS platform
        (os.platform as jest.Mock).mockReturnValue('darwin');
        const macManager = new PodmanEnvironmentManager(mockContext);
        expect(macManager).toBeInstanceOf(PodmanEnvironmentManager);

        // Test Linux platform
        (os.platform as jest.Mock).mockReturnValue('linux');
        const linuxManager = new PodmanEnvironmentManager(mockContext);
        expect(linuxManager).toBeInstanceOf(PodmanEnvironmentManager);
    });

    test('should dispose correctly', () => {
        // This should not throw any errors
        expect(() => podmanManager.dispose()).not.toThrow();
    });
});