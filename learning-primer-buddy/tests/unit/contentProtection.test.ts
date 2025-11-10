// Mock VS Code API
jest.mock('vscode', () => {
    return {
        window: {
            showErrorMessage: jest.fn(),
            showInformationMessage: jest.fn()
        },
        ExtensionContext: jest.fn(),
        globalState: {
            get: jest.fn().mockImplementation((_, defaultValue) => {
                // Return the default value if provided, otherwise return undefined
                return defaultValue !== undefined ? defaultValue : undefined;
            }),
            update: jest.fn()
        }
    };
});

jest.mock('fs', () => {
    return {
        readFileSync: jest.fn(),
        existsSync: jest.fn()
    };
});

import { CourseContentProtectionManager } from '../../src/courseContentProtectionManager';
import { LicenseInfo } from '../../src/license/types';
import * as vscode from 'vscode';
import * as fs from 'fs';

describe('CourseContentProtectionManager', () => {
    let protectionManager: CourseContentProtectionManager;
    let mockContext: vscode.ExtensionContext;

    beforeEach(() => {
        // Mock file system
        (fs.readFileSync as jest.Mock).mockReturnValue('mock-public-key');
        (fs.existsSync as jest.Mock).mockReturnValue(true);
        
        // Create a mock context
        mockContext = {
            extensionPath: '/mock/extension/path',
            globalState: {
                get: jest.fn(),
                update: jest.fn()
            }
        } as unknown as vscode.ExtensionContext;
        
        protectionManager = new CourseContentProtectionManager(mockContext);
    });

    describe('LicenseInfo interface', () => {
        it('should support Gitee fields', () => {
            const licenseInfo: LicenseInfo = {
                id: 'test-id',
                key: 'test-key',
                createdAt: new Date(),
                expiresAt: new Date(Date.now() + 365 * 24 * 60 * 60 * 1000),
                contentPermissions: ['all_chapters'],
                gitee: {
                    accessToken: 'test-access-token',
                    contentRepo: 'test-content-repo',
                    trackingRepo: 'test-tracking-repo',
                    branch: 'main'
                },
                limits: {
                    maxDownloads: 5
                }
            };

            expect(licenseInfo.gitee).toBeDefined();
            expect(licenseInfo.gitee?.accessToken).toBe('test-access-token');
            expect(licenseInfo.gitee?.contentRepo).toBe('test-content-repo');
            expect(licenseInfo.gitee?.trackingRepo).toBe('test-tracking-repo');
            expect(licenseInfo.gitee?.branch).toBe('main');
            expect(licenseInfo.limits?.maxDownloads).toBe(5);
        });

        it('should work without Gitee fields', () => {
            const licenseInfo: LicenseInfo = {
                id: 'test-id',
                key: 'test-key',
                createdAt: new Date(),
                expiresAt: new Date(Date.now() + 365 * 24 * 60 * 60 * 1000),
                contentPermissions: ['all_chapters']
            };

            expect(licenseInfo.gitee).toBeUndefined();
            expect(licenseInfo.limits).toBeUndefined();
        });
    });

    describe('Mock license management', () => {
        it('should add a mock license', () => {
            const mockLicenseKey = 'mock-license-test';
            
            protectionManager.addMockLicense(mockLicenseKey);
            
            const licenses = protectionManager.getValidLicenses();
            expect(licenses.length).toBe(1);
            expect(licenses[0].id).toMatch(/^mock-license-/);
            expect(licenses[0].key).toBe(mockLicenseKey);
            expect(licenses[0].contentPermissions).toEqual(['all_chapters']);
        });

        it('should clear mock licenses', () => {
            // Add a mock license
            protectionManager.addMockLicense('mock-license-1');
            
            // Verify license was added
            let licenses = protectionManager.getValidLicenses();
            expect(licenses.length).toBe(1);
            
            // Clear mock licenses
            protectionManager.clearMockLicenses();
            
            // Verify license was cleared
            licenses = protectionManager.getValidLicenses();
            expect(licenses.length).toBe(0);
        });

        it('should clear only mock licenses', () => {
            // Add both mock and non-mock licenses
            protectionManager.addMockLicense('mock-license-1');
            
            // Simulate adding a non-mock license (using the internal validLicenses map)
            const nonMockLicense: LicenseInfo = {
                id: 'real-license-1',
                key: 'real-key-1',
                createdAt: new Date(),
                expiresAt: new Date(Date.now() + 365 * 24 * 60 * 60 * 1000),
                contentPermissions: ['all_chapters']
            };
            
            // Access the internal validLicenses map to add a non-mock license
            (protectionManager as any).validLicenses.set(nonMockLicense.id, nonMockLicense);
            
            // Verify both licenses exist
            let licenses = protectionManager.getValidLicenses();
            expect(licenses.length).toBe(2);
            
            // Clear mock licenses
            protectionManager.clearMockLicenses();
            
            // Verify only mock license was cleared
            licenses = protectionManager.getValidLicenses();
            expect(licenses.length).toBe(1);
            expect(licenses[0].id).toBe('real-license-1');
        });
    });
});