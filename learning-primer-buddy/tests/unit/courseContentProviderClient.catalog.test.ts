import * as vscode from 'vscode';
import { CourseContentProviderClient } from '../../src/courseContentProviderClient';

// Mock vscode
jest.mock('vscode', () => {
    return {
        window: {
            showErrorMessage: jest.fn()
        }
    };
});

// Mock https to simulate HTTP requests
jest.mock('https', () => {
    return {
        request: jest.fn()
    };
});

describe('CourseContentProviderClient - Catalog', () => {
    let client: CourseContentProviderClient;
    let context: vscode.ExtensionContext;

    beforeEach(() => {
        context = {
            globalState: {
                get: jest.fn().mockReturnValue(undefined),
                update: jest.fn()
            }
        } as unknown as vscode.ExtensionContext;

        client = new CourseContentProviderClient(context);
    });

    afterEach(() => {
        jest.clearAllMocks();
    });

    describe('getCourseCatalog', () => {
        it('should return course catalog data when request is successful', async () => {
            const mockCatalogData = {
                courses: [
                    {
                        id: 'test-course',
                        name: 'Test Course',
                        description: 'A test course'
                    }
                ]
            };

            // Mock the checkPodmanEnvironment to return true
            (client as any).checkPodmanEnvironment = jest.fn().mockResolvedValue(true);

            const mockRequest = {
                on: jest.fn(),
                end: jest.fn().mockImplementation(function (this: any) {
                    // Simulate successful response
                    const callback = this.on.mock.calls.find((call: any) => call[0] === 'response')[1];
                    if (callback) {
                        const res = {
                            statusCode: 200,
                            statusMessage: 'OK',
                            on: jest.fn().mockImplementation(function (event, handler) {
                                if (event === 'data') {
                                    handler(JSON.stringify(mockCatalogData));
                                } else if (event === 'end') {
                                    handler();
                                }
                            })
                        };
                        callback(res);
                    }
                })
            };

            const https = require('https');
            (https.request as jest.Mock).mockImplementation((_, callback) => {
                if (callback) callback(mockRequest);
                return mockRequest;
            });

            const result = await client.getCourseCatalog();

            expect(result).toEqual(mockCatalogData);
        });

        it('should return null when request fails', async () => {
            // Mock the checkPodmanEnvironment to return true
            (client as any).checkPodmanEnvironment = jest.fn().mockResolvedValue(true);

            const mockRequest = {
                on: jest.fn(),
                end: jest.fn().mockImplementation(function (this: any) {
                    // Simulate error
                    const errorCallback = this.on.mock.calls.find((call: any) => call[0] === 'error')[1];
                    if (errorCallback) {
                        errorCallback(new Error('Network error'));
                    }
                })
            };

            const https = require('https');
            (https.request as jest.Mock).mockImplementation((_, callback) => {
                if (callback) callback(mockRequest);
                return mockRequest;
            });

            const result = await client.getCourseCatalog();

            expect(result).toBeNull();
        });

        it('should return null when response is not ok', async () => {
            // Mock the checkPodmanEnvironment to return true
            (client as any).checkPodmanEnvironment = jest.fn().mockResolvedValue(true);

            const mockRequest = {
                on: jest.fn(),
                end: jest.fn().mockImplementation(function (this: any) {
                    // Simulate unsuccessful response
                    const callback = this.on.mock.calls.find((call: any) => call[0] === 'response')[1];
                    if (callback) {
                        const res = {
                            statusCode: 500,
                            statusMessage: 'Internal Server Error',
                            on: jest.fn().mockImplementation(function (event, handler) {
                                if (event === 'data') {
                                    handler('Internal Server Error');
                                } else if (event === 'end') {
                                    handler();
                                }
                            })
                        };
                        callback(res);
                    }
                })
            };

            const https = require('https');
            (https.request as jest.Mock).mockImplementation((_, callback) => {
                if (callback) callback(mockRequest);
                return mockRequest;
            });

            const result = await client.getCourseCatalog();

            expect(result).toBeNull();
        });
    });

    describe('searchCourses', () => {
        it('should return search results when request is successful', async () => {
            // Mock the checkPodmanEnvironment to return true
            (client as any).checkPodmanEnvironment = jest.fn().mockResolvedValue(true);

            const mockSearchResults = {
                courses: [
                    {
                        id: 'searched-course',
                        name: 'Searched Course',
                        description: 'A searched course'
                    }
                ]
            };

            const mockRequest = {
                on: jest.fn(),
                end: jest.fn().mockImplementation(function (this: any) {
                    // Simulate successful response
                    const callback = this.on.mock.calls.find((call: any) => call[0] === 'response')[1];
                    if (callback) {
                        const res = {
                            statusCode: 200,
                            statusMessage: 'OK',
                            on: jest.fn().mockImplementation(function (event, handler) {
                                if (event === 'data') {
                                    handler(JSON.stringify(mockSearchResults));
                                } else if (event === 'end') {
                                    handler();
                                }
                            })
                        };
                        callback(res);
                    }
                })
            };

            const https = require('https');
            (https.request as jest.Mock).mockImplementation((_, callback) => {
                if (callback) callback(mockRequest);
                return mockRequest;
            });

            const result = await client.searchCourses('test');

            expect(result).toEqual(mockSearchResults);
        });

        it('should return null when Podman environment is not running', async () => {
            // Mock the checkPodmanEnvironment to return false
            (client as any).checkPodmanEnvironment = jest.fn().mockResolvedValue(false);

            const result = await client.searchCourses('test');

            expect(result).toBeNull();
            expect(vscode.window.showErrorMessage).toHaveBeenCalledWith(
                'Learning Buddy Podman Environment is not running. ' +
                'Please ensure Podman is installed and the Learning Buddy environment is started.'
            );
        });

        it('should return null when search request fails', async () => {
            // Mock the checkPodmanEnvironment to return true
            (client as any).checkPodmanEnvironment = jest.fn().mockResolvedValue(true);

            const mockRequest = {
                on: jest.fn(),
                end: jest.fn().mockImplementation(function (this: any) {
                    // Simulate error
                    const errorCallback = this.on.mock.calls.find((call: any) => call[0] === 'error')[1];
                    if (errorCallback) {
                        errorCallback(new Error('Network error'));
                    }
                })
            };

            const https = require('https');
            (https.request as jest.Mock).mockImplementation((_, callback) => {
                if (callback) callback(mockRequest);
                return mockRequest;
            });

            const result = await client.searchCourses('test');

            expect(result).toBeNull();
        });
    });
});