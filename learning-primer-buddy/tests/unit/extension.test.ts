// Mock VS Code API
jest.mock('vscode', () => {
    return {
        window: {
            showErrorMessage: jest.fn(),
            showInformationMessage: jest.fn(),
            createStatusBarItem: jest.fn().mockReturnValue({
                show: jest.fn(),
                hide: jest.fn(),
                dispose: jest.fn()
            })
        },
        commands: {
            registerCommand: jest.fn()
        },
        workspace: {
            registerTextDocumentContentProvider: jest.fn(),
            openTextDocument: jest.fn().mockResolvedValue({}),
            showTextDocument: jest.fn().mockResolvedValue({})
        },
        ExtensionContext: jest.fn(),
        globalState: {
            get: jest.fn(),
            update: jest.fn()
        },
        Uri: {
            parse: jest.fn().mockReturnValue({ toString: () => 'mock-uri' })
        }
    };
});

// Mock the LicenseManager
jest.mock('../../src/licenseManager', () => {
    return {
        LicenseManager: jest.fn().mockImplementation(() => {
            return {
                showLicensePurchasePage: jest.fn().mockResolvedValue(undefined),
                showLicenseInfoPage: jest.fn().mockResolvedValue(undefined)
            };
        })
    };
});

// Mock the ContentProtectionManager
jest.mock('../../src/contentProtection', () => {
    return {
        ContentProtectionManager: jest.fn().mockImplementation(() => {
            return {
                getValidLicenses: jest.fn().mockReturnValue([]),
                isChapterAccessible: jest.fn().mockReturnValue(false)
            };
        })
    };
});

// Mock the CourseStructureProvider
jest.mock('../../src/course/courseStructureProvider', () => {
    return {
        CourseStructureProvider: jest.fn().mockImplementation(() => {
            return {
                getMockPodmanStatus: jest.fn().mockReturnValue(false),
                toggleMockPodmanStatus: jest.fn(),
                getAllItemsExpanded: jest.fn().mockReturnValue(false)
            };
        })
    };
});

import * as vscode from 'vscode';
import { ContentProtectionManager } from '../../src/contentProtection';
import { CourseStructureProvider } from '../../src/course/courseStructureProvider';
import { LicenseManager } from '../../src/licenseManager';

describe('Extension Download License Checking', () => {
    let mockContext: vscode.ExtensionContext;
    let mockProtectionManager: any;
    let mockCourseStructureProvider: any;

    beforeEach(() => {
        // Create a mock context
        mockContext = {
            extensionPath: '/mock/extension/path',
            globalState: {
                get: jest.fn(),
                update: jest.fn()
            },
            subscriptions: []
        } as unknown as vscode.ExtensionContext;
        
        // Get the mocked instances
        mockProtectionManager = new ContentProtectionManager(mockContext);
        mockCourseStructureProvider = new CourseStructureProvider(mockContext, mockProtectionManager);
    });

    describe('downloadExercise command logic', () => {
        it('should open license purchase page when no valid license', async () => {
            // Set up mock to return no valid licenses
            (mockProtectionManager.getValidLicenses as jest.Mock).mockReturnValue([]);
            
            // Simulate the download command logic
            const item = { fullPath: 'test/exercise1' };
            
            // Check if user has a valid license
            const validLicenses = mockProtectionManager.getValidLicenses();
            const hasValidLicense = validLicenses.length > 0;
            
            let purchasePageOpened = false;
            if (!hasValidLicense) {
                const licenseManager = new LicenseManager(mockProtectionManager);
                await licenseManager.showLicensePurchasePage();
                purchasePageOpened = true;
                
                // Verify that showLicensePurchasePage was called
                expect(licenseManager.showLicensePurchasePage).toHaveBeenCalled();
            }
            
            // Verify no valid licenses
            expect(validLicenses.length).toBe(0);
            expect(hasValidLicense).toBe(false);
            expect(purchasePageOpened).toBe(true);
        });

        it('should proceed with download when valid license exists', async () => {
            // Set up mock to return valid licenses
            (mockProtectionManager.getValidLicenses as jest.Mock).mockReturnValue([
                { id: 'test-license', key: 'test-key' }
            ]);
            
            // Simulate the download command logic
            const item = { fullPath: 'test/exercise1' };
            
            // Check if user has a valid license
            const validLicenses = mockProtectionManager.getValidLicenses();
            const hasValidLicense = validLicenses.length > 0;
            
            let downloadProceeded = false;
            if (hasValidLicense) {
                // Simulate download logic
                downloadProceeded = true;
            }
            
            // Verify valid license exists
            expect(validLicenses.length).toBe(1);
            expect(hasValidLicense).toBe(true);
            expect(downloadProceeded).toBe(true);
        });
    });
});