"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
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
const contentProtection_1 = require("../../src/contentProtection");
const fs = require("fs");
describe('ContentProtectionManager', () => {
    let protectionManager;
    let mockContext;
    beforeEach(() => {
        // Mock file system
        fs.readFileSync.mockReturnValue('mock-public-key');
        fs.existsSync.mockReturnValue(true);
        // Create a mock context
        mockContext = {
            extensionPath: '/mock/extension/path',
            globalState: {
                get: jest.fn(),
                update: jest.fn()
            }
        };
        protectionManager = new contentProtection_1.ContentProtectionManager(mockContext);
    });
    describe('LicenseInfo interface', () => {
        it('should support Gitee fields', () => {
            const licenseInfo = {
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
            const licenseInfo = {
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
//# sourceMappingURL=contentProtection.test.js.map