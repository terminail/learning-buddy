import * as vscode from 'vscode';

/**
 * Real Integration Test Runner for VS Code Extension
 * 
 * This test runs in the actual VS Code extension host environment
 * and can verify the My Courses display programmatically.
 */

export async function run(): Promise<void> {
    // Run the dedicated MyCoursesView verification test
    const verifyMyCoursesView = require('./verify-mycourses-view');
    await verifyMyCoursesView.run();
    
    console.log('🎉 All real integration tests passed!');
}
