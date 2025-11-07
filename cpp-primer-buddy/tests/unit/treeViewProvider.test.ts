// Mock VS Code API
jest.mock('vscode', () => {
    return {
        window: {
            showErrorMessage: jest.fn(),
            showInformationMessage: jest.fn(),
            showOpenDialog: jest.fn(),
            createWebviewPanel: jest.fn().mockReturnValue({
                webview: {
                    html: '',
                    onDidReceiveMessage: jest.fn(),
                    postMessage: jest.fn()
                }
            })
        },
        workspace: {
            workspaceFolders: [],
            openTextDocument: jest.fn(),
            showTextDocument: jest.fn()
        },
        TreeItem: jest.fn(),
        TreeItemCollapsibleState: {
            None: 0,
            Collapsed: 1
        },
        Event: jest.fn(),
        EventEmitter: jest.fn().mockImplementation(() => {
            return {
                fire: jest.fn(),
                event: jest.fn()
            };
        }),
        ThemeIcon: jest.fn(),
        commands: {
            executeCommand: jest.fn()
        }
    };
});

jest.mock('fs', () => {
    return {
        readFileSync: jest.fn(),
        existsSync: jest.fn(),
        copyFileSync: jest.fn(),
        writeFileSync: jest.fn(),
        readdirSync: jest.fn()
    };
});

jest.mock('../../src/contentProtection', () => {
    return {
        ContentProtectionManager: jest.fn().mockImplementation(() => {
            return {
                isChapterAccessible: jest.fn().mockReturnValue(true),
                getValidLicenses: jest.fn().mockReturnValue([]),
                addLicense: jest.fn().mockResolvedValue(true),
                removeLicense: jest.fn()
            };
        }),
        LicenseInfo: jest.fn()
    };
});

jest.mock('../../src/giteeContentDelivery', () => {
    return {
        GiteeContentDelivery: jest.fn().mockImplementation(() => {
            return {
                fetchContent: jest.fn().mockResolvedValue('mock content')
            };
        })
    };
});

import { CppPrimerTreeViewProvider, StudyItem } from '../../src/treeViewProvider';
import * as vscode from 'vscode';
import * as fs from 'fs';

describe('CppPrimerTreeViewProvider', () => {
    let treeViewProvider: CppPrimerTreeViewProvider;
    let mockContext: vscode.ExtensionContext;

    beforeEach(() => {
        // Mock file system
        (fs.existsSync as jest.Mock).mockReturnValue(true);
        (fs.readdirSync as jest.Mock).mockReturnValue(['main.cpp', 'solution.cpp']);
        
        // Create a mock context
        mockContext = {
            extensionPath: '/mock/extension/path',
            globalState: {
                get: jest.fn().mockReturnValue('/mock/working/dir'),
                update: jest.fn()
            }
        } as unknown as vscode.ExtensionContext;
        
        treeViewProvider = new CppPrimerTreeViewProvider(mockContext);
    });

    describe('StudyItem', () => {
        it('should create a study item with correct properties', () => {
            const item = new StudyItem('Test Item', vscode.TreeItemCollapsibleState.None, 'test/path', false, false, 'exercise');
            
            expect(item.label).toBe('Test Item');
            expect(item.collapsibleState).toBe(vscode.TreeItemCollapsibleState.None);
            expect(item.fullPath).toBe('test/path');
            expect(item.isLocked).toBe(false);
            expect(item.isDirectory).toBe(false);
            expect(item.itemType).toBe('exercise');
        });
    });
});