import * as vscode from 'vscode';
import { CourseCatalogWebview } from '../../src/course/courseCatalogWebview';

// Mock the modules
jest.mock('vscode', () => {
    return {
        window: {
            createWebviewPanel: jest.fn().mockImplementation(() => {
                return {
                    webview: {
                        html: '',
                        onDidReceiveMessage: jest.fn(),
                        asWebviewUri: jest.fn().mockImplementation((uri) => uri.toString())
                    },
                    onDidDispose: jest.fn(),
                    dispose: jest.fn(),
                    reveal: jest.fn()
                };
            }),
            showErrorMessage: jest.fn(),
            activeTextEditor: undefined
        },
        Uri: {
            joinPath: jest.fn().mockImplementation((...paths) => {
                return {
                    fsPath: paths.join('/'),
                    toString: () => paths.join('/')
                };
            }),
            file: jest.fn().mockImplementation((path) => {
                return {
                    fsPath: path,
                    toString: () => path
                };
            })
        },
        TreeItem: class MockTreeItem {
            constructor(public label: string, public collapsibleState: any) {}
        },
        TreeItemCollapsibleState: {
            None: 0,
            Collapsed: 1,
            Expanded: 2
        },
        ViewColumn: {
            One: 1,
            Two: 2
        },
        commands: {
            executeCommand: jest.fn().mockResolvedValue(undefined)
        }
    };
});

// Mock the CourseContentProviderClient
jest.mock('../../src/courseContentProviderClient', () => {
    return {
        CourseContentProviderClient: jest.fn().mockImplementation(() => {
            return {
                getCourseCatalog: jest.fn().mockResolvedValue({
                    courses: [
                        {
                            id: 'test-course',
                            title: 'Test Course',
                            description: 'A test course'
                        }
                    ]
                }),
                searchCourses: jest.fn().mockResolvedValue({
                    courses: [
                        {
                            id: 'searched-course',
                            title: 'Searched Course',
                            description: 'A searched course'
                        }
                    ]
                })
            };
        })
    };
});

// Mock the TemplateEngine
jest.mock('../../src/templates/index', () => {
    return {
        TemplateEngine: {
            getInstance: jest.fn().mockImplementation(() => {
                return {
                    renderCourseCatalogTemplate: jest.fn().mockResolvedValue('<html>Mocked HTML</html>')
                };
            })
        }
    };
});

// Mock the CourseContentProtectionManager
jest.mock('../../src/courseContentProtectionManager', () => {
    return {
        CourseContentProtectionManager: jest.fn().mockImplementation(() => {
            return {
                getValidLicenses: jest.fn().mockReturnValue([]),
                clearMockLicenses: jest.fn(),
                addMockLicense: jest.fn()
            };
        })
    };
});

// Mock the LicenseManager
jest.mock('../../src/license/licenseManager', () => {
    return {
        LicenseManager: jest.fn().mockImplementation(() => {
            return {
                showLicensePurchasePage: jest.fn().mockResolvedValue(undefined),
                updateLicenseStatusBar: jest.fn()
            };
        })
    };
});

// Mock the MyCoursesProvider
jest.mock('../../src/course/myCoursesProvider', () => {
    return {
        MyCoursesProvider: jest.fn().mockImplementation(() => {
            return {
                setCurrentCourse: jest.fn().mockResolvedValue(undefined),
                refresh: jest.fn(),
                getCurrentCourseStructure: jest.fn().mockReturnValue(null),
                getMockPodmanStatus: jest.fn().mockReturnValue(false),
                toggleMockPodmanStatus: jest.fn()
            };
        })
    };
});

describe('CourseCatalogWebview', () => {
    let context: vscode.ExtensionContext;
    
    beforeEach(() => {
        context = {
            subscriptions: [],
            globalState: {
                get: jest.fn().mockReturnValue(''),
                update: jest.fn()
            }
        } as unknown as vscode.ExtensionContext;
        
        // Reset the currentPanel
        CourseCatalogWebview.currentPanel = undefined;
    });

    afterEach(() => {
        jest.clearAllMocks();
    });

    describe('createOrShow', () => {
        it('should create a new panel when none exists', () => {
            const extensionUri = vscode.Uri.file('/test/path');
            
            CourseCatalogWebview.createOrShow(extensionUri, context);
            
            expect(vscode.window.createWebviewPanel).toHaveBeenCalledWith(
                'courseCatalog',
                'Course Catalog',
                1, // ViewColumn.One
                expect.objectContaining({
                    enableScripts: true
                })
            );
            
            expect(CourseCatalogWebview.currentPanel).toBeDefined();
        });

        it('should reveal existing panel when one exists', () => {
            const extensionUri = vscode.Uri.file('/test/path');
            
            // Create first panel
            CourseCatalogWebview.createOrShow(extensionUri, context);
            
            // Try to create another panel
            CourseCatalogWebview.createOrShow(extensionUri, context);
            
            // Should have only been called once
            expect(vscode.window.createWebviewPanel).toHaveBeenCalledTimes(1);
        });
    });

    describe('message handling', () => {
        it('should handle selectCourse message for free course', async () => {
            const extensionUri = vscode.Uri.file('/test/path');
            
            // Mock vscode.commands.executeCommand
            const executeCommandSpy = jest.spyOn(vscode.commands, 'executeCommand').mockResolvedValue(undefined);
            
            // Create the webview
            CourseCatalogWebview.createOrShow(extensionUri, context);
            
            // Get the created panel and simulate message
            const mockPanel = (vscode.window.createWebviewPanel as jest.Mock).mock.results[0].value;
            
            // Call the message handler directly
            const messageHandler = (mockPanel.webview.onDidReceiveMessage as jest.Mock).mock.calls[0][0];
            await messageHandler({
                command: 'selectCourse',
                courseId: 'test-course',
                courseName: 'Test Course',
                hasProtectedContent: false,
                openLicensePage: false
            });
            
            expect(executeCommandSpy).toHaveBeenCalledWith(
                'learningPrimerBuddy.selectCourse',
                'test-course',
                'Test Course',
                false
            );
        });

        it('should handle selectCourse message for licensed course', async () => {
            const extensionUri = vscode.Uri.file('/test/path');
            
            // Create the webview
            CourseCatalogWebview.createOrShow(extensionUri, context);
            
            // Get the created panel and simulate message
            const mockPanel = (vscode.window.createWebviewPanel as jest.Mock).mock.results[0].value;
            
            // Mock the LicenseManager.showLicensePurchasePage method
            const licenseManagerShowSpy = jest.fn();
            const LicenseManagerMock = require('../../src/license/licenseManager').LicenseManager;
            LicenseManagerMock.mockImplementation(() => {
                return {
                    showLicensePurchasePage: licenseManagerShowSpy
                };
            });
            
            // Call the message handler directly
            const messageHandler = (mockPanel.webview.onDidReceiveMessage as jest.Mock).mock.calls[0][0];
            await messageHandler({
                command: 'selectCourse',
                courseId: 'test-course',
                courseName: 'Test Course',
                hasProtectedContent: true,
                openLicensePage: true
            });
            
            expect(licenseManagerShowSpy).toHaveBeenCalled();
        });

        it('should handle searchCourses message', async () => {
            const extensionUri = vscode.Uri.file('/test/path');
            
            // Create the webview
            CourseCatalogWebview.createOrShow(extensionUri, context);
            
            // Get the created panel and simulate message
            const mockPanel = (vscode.window.createWebviewPanel as jest.Mock).mock.results[0].value;
            
            // Mock the _getHtmlForWebview method
            const currentPanel = CourseCatalogWebview.currentPanel;
            const getHtmlSpy = jest.spyOn(currentPanel as any, '_getHtmlForWebview').mockResolvedValue('<html>Search Results</html>');
            
            // Call the message handler directly
            const messageHandler = (mockPanel.webview.onDidReceiveMessage as jest.Mock).mock.calls[0][0];
            await messageHandler({
                command: 'searchCourses',
                searchTerm: 'test'
            });
            
            expect(getHtmlSpy).toHaveBeenCalled();
        });
    });

    describe('dispose', () => {
        it('should dispose correctly', () => {
            const extensionUri = vscode.Uri.file('/test/path');
            
            // Create the webview
            CourseCatalogWebview.createOrShow(extensionUri, context);
            
            // Get reference to current panel
            const currentPanel = CourseCatalogWebview.currentPanel;
            
            // Dispose
            currentPanel?.dispose();
            
            expect(CourseCatalogWebview.currentPanel).toBeUndefined();
        });
    });
});