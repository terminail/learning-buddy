#!/usr/bin/env node

/**
 * Integration Test: Verify learningPrimerBuddy.openCourseCatalog Command
 * 
 * This test verifies that the learningPrimerBuddy.openCourseCatalog command
 * is properly registered and can be executed without errors.
 */

const vscode = require('vscode');

async function runTest() {
    console.log('=== Testing learningPrimerBuddy.openCourseCatalog Command ===\n');
    
    try {
        // Try to execute the command
        console.log('1. Executing learningPrimerBuddy.openCourseCatalog command...');
        await vscode.commands.executeCommand('learningPrimerBuddy.openCourseCatalog');
        console.log('✅ Command executed successfully\n');
        
        // Try to execute with parameters
        console.log('2. Executing command with parameters...');
        await vscode.commands.executeCommand('learningPrimerBuddy.openCourseCatalog', 'test-param');
        console.log('✅ Command with parameters executed successfully\n');
        
        console.log('🎉 All command tests passed!');
        console.log('\nSummary:');
        console.log('- learningPrimerBuddy.openCourseCatalog command is properly registered');
        console.log('- Command can be executed without throwing errors');
        console.log('- Command accepts parameters correctly');
        
        return true;
        
    } catch (error) {
        console.error('❌ Command test failed:', error.message);
        console.log('\nTroubleshooting steps:');
        console.log('1. Verify that the command is registered in package.json');
        console.log('2. Verify that the command is registered in extension.ts with the exact same name');
        console.log('3. Check that the extension activates correctly');
        console.log('4. Ensure all required dependencies are available');
        
        return false;
    }
}

// Run the test if called directly
if (require.main === module) {
    runTest().then(success => {
        process.exit(success ? 0 : 1);
    }).catch(error => {
        console.error('Test execution error:', error);
        process.exit(1);
    });
}

module.exports = { runTest };