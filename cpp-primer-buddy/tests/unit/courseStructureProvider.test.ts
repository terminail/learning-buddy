import { CourseStructureProvider } from '../../src/course/courseStructureProvider';
import { ContentProtectionManager } from '../../src/contentProtection';
import * as vscode from 'vscode';

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
    
    return {
        window: {
            showErrorMessage: jest.fn(),
            showInformationMessage: jest.fn()
        },
        extensions: {
            all: [
                {
                    id: 'test.cpp-primer-buddy'
                }
            ]
        },
        TreeItem: jest.fn(),
        TreeItemCollapsibleState: {
            None: 0,
            Collapsed: 1
        },
        EventEmitter: EventEmitter,
        ThemeIcon: ThemeIcon,
        ViewColumn: {
            One: 1
        }
    };
});

// Mock ContentProtectionManager
jest.mock('../../src/contentProtection');

describe('CourseStructureProvider', () => {
    let courseStructureProvider: CourseStructureProvider;
    let mockContext: vscode.ExtensionContext;
    let mockProtectionManager: ContentProtectionManager;

    beforeEach(() => {
        // Create a mock context
        mockContext = {
            globalState: {
                get: jest.fn(),
                update: jest.fn()
            },
            extensionPath: '/test/path'
        } as any;

        // Create a mock protection manager
        mockProtectionManager = new ContentProtectionManager(mockContext);

        courseStructureProvider = new CourseStructureProvider(mockContext, mockProtectionManager);
    });

    afterEach(() => {
        jest.clearAllMocks();
    });

    test('should create CourseStructureProvider instance', () => {
        expect(courseStructureProvider).toBeInstanceOf(CourseStructureProvider);
    });

    test('should have refresh method', () => {
        expect(typeof courseStructureProvider.refresh).toBe('function');
    });

    test('should have setPodmanNotAvailable method', () => {
        expect(typeof courseStructureProvider.setPodmanNotAvailable).toBe('function');
    });

    test('should have getTreeItem method', () => {
        expect(typeof courseStructureProvider.getTreeItem).toBe('function');
    });

    test('should have getChildren method', () => {
        expect(typeof courseStructureProvider.getChildren).toBe('function');
    });

    test('should set podman not available status', () => {
        const initialFireCount = (courseStructureProvider as any)._onDidChangeTreeData.fire.mock?.calls?.length || 0;
        courseStructureProvider.setPodmanNotAvailable(true);
        const finalFireCount = (courseStructureProvider as any)._onDidChangeTreeData.fire.mock?.calls?.length || 0;
        
        expect(finalFireCount).toBe(initialFireCount + 1);
    });

    test('should refresh course structure', async () => {
        const initialFireCount = (courseStructureProvider as any)._onDidChangeTreeData.fire.mock?.calls?.length || 0;
        await courseStructureProvider.refresh();
        const finalFireCount = (courseStructureProvider as any)._onDidChangeTreeData.fire.mock?.calls?.length || 0;
        
        expect(finalFireCount).toBe(initialFireCount + 1);
    });

    test('should get tree item', () => {
        // Create a mock course item
        const mockCourseItem = {
            label: 'Test Chapter',
            collapsibleState: 0 // None
        };
        
        const result = courseStructureProvider.getTreeItem(mockCourseItem as any);
        expect(result).toBe(mockCourseItem);
    });

    test('should get root children when podman is not available', async () => {
        // Set mock podman status to not available
        (courseStructureProvider as any).mockPodmanInstalled = false;
        
        const children = await courseStructureProvider.getChildren();
        expect(children).toBeDefined();
        expect(Array.isArray(children)).toBe(true);
    });

    test('should get root children when podman is available', async () => {
        // Set mock podman status to available
        (courseStructureProvider as any).mockPodmanInstalled = true;
        
        const children = await courseStructureProvider.getChildren();
        expect(children).toBeDefined();
        expect(Array.isArray(children)).toBe(true);
    });

    test('should get child items for a chapter', async () => {
        // Create a mock chapter item
        const mockChapterItem = {
            label: 'Test Chapter',
            fullPath: '1_getting_started',
            collapsibleState: 1 // Collapsed
        };
        
        const children = await courseStructureProvider.getChildren(mockChapterItem as any);
        expect(children).toBeDefined();
        expect(Array.isArray(children)).toBe(true);
    });

    test('should toggle mock podman status', () => {
        const initialStatus = courseStructureProvider.getMockPodmanStatus();
        courseStructureProvider.toggleMockPodmanStatus();
        const toggledStatus = courseStructureProvider.getMockPodmanStatus();
        
        expect(toggledStatus).toBe(!initialStatus);
    });

    test('should get current mock podman status', () => {
        const status = courseStructureProvider.getMockPodmanStatus();
        expect(typeof status).toBe('boolean');
    });
});