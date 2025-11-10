import { LicenseManager } from '../../src/license/licenseManager';
import * as vscode from 'vscode';
import { CourseContentProtectionManager } from '../../src/courseContentProtectionManager';
import { MyCoursesProvider } from '../../src/course/myCoursesProvider';

// Mock the VS Code API
jest.mock('vscode', () => {
    return {
        window: {
            createStatusBarItem: jest.fn().mockReturnValue({
                text: '',
                backgroundColor: '',
                show: jest.fn(),
                hide: jest.fn(),
                dispose: jest.fn()
            })
        },
        ThemeColor: jest.fn().mockImplementation((color) => {
            // Return an object with a property to identify the color
            return { __mockThemeColor: color };
        }),
        StatusBarAlignment: {
            Left: 1
        }
    };
});

// Mock the CourseContentProtectionManager
jest.mock('../../src/courseContentProtectionManager', () => {
    return {
        CourseContentProtectionManager: jest.fn().mockImplementation(() => {
            return {
                getValidLicenses: jest.fn().mockReturnValue([])
            };
        })
    };
});

// Mock the MyCoursesProvider
jest.mock('../../src/course/myCoursesProvider', () => {
    return {
        MyCoursesProvider: jest.fn().mockImplementation(() => {
            return {
                getCurrentCourseStructure: jest.fn().mockReturnValue(null)
            };
        })
    };
});

describe('LicenseManager.updateLicenseStatusBar', () => {
    let mockProtectionManager: CourseContentProtectionManager;
    let mockCoursesProvider: MyCoursesProvider;
    let mockStatusBarItem: any;

    beforeEach(() => {
        // Create mock protection manager
        mockProtectionManager = new CourseContentProtectionManager({} as any);
        
        // Create mock courses provider
        mockCoursesProvider = new MyCoursesProvider({} as any, {} as any);
        
        // Create mock status bar item
        mockStatusBarItem = {
            text: '',
            backgroundColor: '',
            show: jest.fn(),
            hide: jest.fn(),
            dispose: jest.fn()
        };

        // Mock the createStatusBarItem function to return our mock
        (vscode.window.createStatusBarItem as jest.Mock).mockReturnValue(mockStatusBarItem);
    });

    afterEach(() => {
        jest.clearAllMocks();
    });

    test('should show "License: Valid" when user has valid licenses', () => {
        // Mock protection manager to return valid licenses
        mockProtectionManager.getValidLicenses = jest.fn().mockReturnValue([
            { id: 'test-license', key: 'test-key', createdAt: new Date(), expiresAt: new Date() }
        ]);

        // Mock courses provider to return course structure
        mockCoursesProvider.getCurrentCourseStructure = jest.fn().mockReturnValue({
            protectedChapters: ['chapter1', 'chapter2']
        });

        // Call the function
        LicenseManager.updateLicenseStatusBar(mockProtectionManager, mockCoursesProvider, mockStatusBarItem);

        // Verify the status bar item properties
        expect(mockStatusBarItem.text).toBe('$(verified) License: Valid');
        expect(mockStatusBarItem.backgroundColor.__mockThemeColor).toBe('statusBarItem.background');
        expect(mockStatusBarItem.show).toHaveBeenCalled();
    });

    test('should show "License: Required" when course has protected content but no valid license', () => {
        // Mock protection manager to return no valid licenses
        mockProtectionManager.getValidLicenses = jest.fn().mockReturnValue([]);

        // Mock courses provider to return course structure with protected chapters
        mockCoursesProvider.getCurrentCourseStructure = jest.fn().mockReturnValue({
            protectedChapters: ['chapter1', 'chapter2']
        });

        // Call the function
        LicenseManager.updateLicenseStatusBar(mockProtectionManager, mockCoursesProvider, mockStatusBarItem);

        // Verify the status bar item properties
        expect(mockStatusBarItem.text).toBe('$(warning) License: Required');
        expect(mockStatusBarItem.backgroundColor.__mockThemeColor).toBe('statusBarItem.warningBackground');
        expect(mockStatusBarItem.show).toHaveBeenCalled();
    });

    test('should show "License: Free" when no license is needed', () => {
        // Mock protection manager to return no valid licenses
        mockProtectionManager.getValidLicenses = jest.fn().mockReturnValue([]);

        // Mock courses provider to return course structure with no protected chapters
        mockCoursesProvider.getCurrentCourseStructure = jest.fn().mockReturnValue({
            protectedChapters: []
        });

        // Call the function
        LicenseManager.updateLicenseStatusBar(mockProtectionManager, mockCoursesProvider, mockStatusBarItem);

        // Verify the status bar item properties
        expect(mockStatusBarItem.text).toBe('$(check) License: Free');
        expect(mockStatusBarItem.backgroundColor.__mockThemeColor).toBe('statusBarItem.background');
        expect(mockStatusBarItem.show).toHaveBeenCalled();
    });

    test('should show "License: Free" when there is no course structure', () => {
        // Mock protection manager to return no valid licenses
        mockProtectionManager.getValidLicenses = jest.fn().mockReturnValue([]);

        // Mock courses provider to return null course structure
        mockCoursesProvider.getCurrentCourseStructure = jest.fn().mockReturnValue(null);

        // Call the function
        LicenseManager.updateLicenseStatusBar(mockProtectionManager, mockCoursesProvider, mockStatusBarItem);

        // Verify the status bar item properties
        expect(mockStatusBarItem.text).toBe('$(check) License: Free');
        expect(mockStatusBarItem.backgroundColor.__mockThemeColor).toBe('statusBarItem.background');
        expect(mockStatusBarItem.show).toHaveBeenCalled();
    });
});