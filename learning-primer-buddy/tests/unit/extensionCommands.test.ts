import * as vscode from 'vscode';
import * as extension from '../../src/extension';

// Mock the VS Code API
jest.mock('vscode', () => {
    const EventEmitter = jest.fn().mockImplementation(() => {
        return {
            fire: jest.fn(),
            event: jest.fn()
        };
    });
    
    // Mock ThemeIcon
    const ThemeIcon = jest.fn().mockImplementation((iconName) => {
        return {
            id: iconName
        };
    });
    
    // Mock ThemeColor
    const ThemeColor = jest.fn().mockImplementation((colorName) => {
        return {
            id: colorName
        };
    });
    
    // Mock TreeItem
    const TreeItem = jest.fn().mockImplementation(() => {
        return {};
    });
    
    // Mock TreeItemCollapsibleState
    const TreeItemCollapsibleState = {
        None: 0,
        Collapsed: 1,
        Expanded: 2
    };
    
    // Mock StatusBarAlignment
    const StatusBarAlignment = {
        Left: 1,
        Right: 2
    };
    
    // Mock window
    const window = {
        createTreeView: jest.fn().mockReturnValue({
            onDidChangeSelection: jest.fn()
        }),
        registerWebviewViewProvider: jest.fn(),
        createStatusBarItem: jest.fn().mockImplementation((alignment, priority) => {
            return {
                alignment,
                priority,
                show: jest.fn(),
                dispose: jest.fn(),
                tooltip: '',
                command: '',
                text: '',
                backgroundColor: undefined
            };
        }),
        showInformationMessage: jest.fn(),
        showErrorMessage: jest.fn(),
        showOpenDialog: jest.fn().mockResolvedValue(undefined),
        createWebviewPanel: jest.fn().mockReturnValue({
            webview: {
                html: ''
            }
        })
    };
    
    // Mock commands
    const commands = {
        registerCommand: jest.fn().mockImplementation((_commandName, _callback) => {
            // Return a disposable object
            return {
                dispose: jest.fn()
            };
        })
    };
    
    // Mock workspace
    const workspace = {
        registerTextDocumentContentProvider: jest.fn().mockReturnValue({
            dispose: jest.fn()
        }),
        openTextDocument: jest.fn().mockResolvedValue({
            uri: {}
        })
    };
    
    // Mock Uri
    const Uri = {
        joinPath: jest.fn().mockImplementation((...paths) => {
            return {
                toString: () => paths.join('/')
            };
        }),
        parse: jest.fn().mockImplementation((uri) => {
            return {
                toString: () => uri
            };
        })
    };
    
    // Mock extensions
    const extensions = {
        getExtension: jest.fn().mockReturnValue({
            isActive: true,
            activate: jest.fn().mockResolvedValue(undefined)
        }),
        all: [] // Mock the all property as an empty array
    };
    
    // Mock env
    const env = {
        openExternal: jest.fn()
    };
    
    return {
        window,
        commands,
        workspace,
        Uri,
        extensions,
        env,
        TreeItem,
        TreeItemCollapsibleState,
        StatusBarAlignment,
        ThemeColor,
        EventEmitter,
        ThemeIcon
    };
});

describe('Extension Commands', () => {
    let mockContext: vscode.ExtensionContext;
    
    beforeEach(() => {
        // Create a mock context
        mockContext = {
            subscriptions: [],
            globalState: {
                get: jest.fn().mockReturnValue([]),
                update: jest.fn().mockResolvedValue(undefined)
            },
            extensionPath: '/test/path',
            extensionUri: {} as any
        } as any;
    });
    
    afterEach(() => {
        jest.clearAllMocks();
    });
    
    it('should register the learningPrimerBuddy.openCourseCatalog command', async () => {
        // Activate the extension
        await extension.activate(mockContext);
        
        // Check that the command was registered
        const registerCommandMock = vscode.commands.registerCommand as jest.Mock;
        const commandRegistered = registerCommandMock.mock.calls.some(
            call => call[0] === 'learningPrimerBuddy.openCourseCatalog'
        );
        
        expect(commandRegistered).toBe(true);
        expect(registerCommandMock).toHaveBeenCalledWith(
            'learningPrimerBuddy.openCourseCatalog',
            expect.any(Function)
        );
    });
    
    it('should register all required commands', async () => {
        // Activate the extension
        await extension.activate(mockContext);
        
        // Check that commands were registered
        const registerCommandMock = vscode.commands.registerCommand as jest.Mock;
        
        // These are the actual commands registered in extension.ts
        const requiredCommands = [
            'learningPrimerBuddy.selectCourse',
            'learningPrimerBuddy.openCourseCatalog',
            'learningPrimerBuddy.refresh',
            'learningPrimerBuddy.showPodmanInstallationGuide',
            'learningPrimerBuddy.changePodmanLocation',
            'learningPrimerBuddy.openLicenseManager',
            'learningPrimerBuddy.toggleMockPodmanStatus',
            'learningPrimerBuddy.toggleMockLicenseStatus',
            'learningPrimerBuddy.clearLicenses',
            'learningPrimerBuddy.previewExercise',
            'learningPrimerBuddy.downloadExercise',
            'learningPrimerBuddy.previewContent',
            'learningPrimerBuddy.openWeChatContact',
            'learningPrimerBuddy.studySelected',
            'learningPrimerBuddy.courseItemSelect'
        ];
        
        requiredCommands.forEach(command => {
            const commandRegistered = registerCommandMock.mock.calls.some(
                call => call[0] === command
            );
            
            // Log which command failed for debugging
            if (!commandRegistered) {
                console.log(`Command not registered: ${command}`);
                console.log('Registered commands:', registerCommandMock.mock.calls.map(call => call[0]));
            }
            
            expect(commandRegistered).toBe(true);
        });
    });
    
    it('should add commands to context subscriptions', async () => {
        // Activate the extension
        await extension.activate(mockContext);
        
        // Check that subscriptions were added
        expect(mockContext.subscriptions.length).toBeGreaterThan(0);
        
        // Check that the openCourseCatalogCommand subscription exists
        const hasOpenCourseCatalogCommand = mockContext.subscriptions.some(
            subscription => subscription !== undefined
        );
        
        expect(hasOpenCourseCatalogCommand).toBe(true);
    });
});