// Mock VS Code API
jest.mock('vscode', () => {
    return {
        window: {
            showErrorMessage: jest.fn(),
            showInformationMessage: jest.fn()
        },
        ExtensionContext: jest.fn(),
        globalState: {
            get: jest.fn(),
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

import { ContentProtectionManager, LicenseInfo } from '../../src/contentProtection';
import * as vscode from 'vscode';
import * as fs from 'fs';

describe('ContentProtectionManager', () => {
    let protectionManager: ContentProtectionManager;
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
        
        protectionManager = new ContentProtectionManager(mockContext);
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
});