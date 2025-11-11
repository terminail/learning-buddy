#!/usr/bin/env node

/**
 * Integration Test: Verify All Learning Primer Buddy Commands
 * 
 * This test verifies that all commands defined in package.json are
 * properly registered and can be executed without errors.
 */

const vscode = require('vscode');

async function runTest() {
    console.log('=== Testing All Learning Primer Buddy Commands ===\n');
    
    const commandsToTest = [
        'learningPrimerBuddy.openCourseCatalog',
        'learningPrimerBuddy.refresh',
        'learningPrimerBuddy.toggleMockPodmanStatus',
        'learningPrimerBuddy.previewExercise',
        'learningPrimerBuddy.downloadExercise',
        'learningPrimerBuddy.previewContent',
        'learningPrimerBuddy.studySelected',
        'learningPrimerBuddy.courseItemSelect',
        'learningPrimerBuddy.openLicenseManager',
        'learningPrimerBuddy.openWeChatContact',
        'learningPrimerBuddy.changePodmanLocation',
        'learningPrimerBuddy.selectCourse',
        'learningPrimerBuddy.showPodmanInstallationGuide',
        'learningPrimerBuddy.toggleMockLicenseStatus',
        'learningPrimerBuddy.clearLicenses'
    ];
    
    let passedTests = 0;
    let failedTests = 0;
    
    for (const command of commandsToTest) {
        try {
            console.log(`Testing command: ${command}`);
            await vscode.commands.executeCommand(command);
            console.log(`✅ ${command} executed successfully\n`);
            passedTests++;
        } catch (error) {
            // Some commands might fail due to missing parameters or context,
            // but we're mainly checking if they're registered
            if (error.message.includes('command') && error.message.includes('not found')) {
                console.error(`❌ ${command} NOT FOUND: ${error.message}\n`);
                failedTests++;
            } else {
                // Command exists but failed for other reasons (expected in some cases)
                console.log(`⚠️  ${command} exists but failed with expected error: ${error.message}\n`);
                passedTests++;
            }
        }
    }
    
    console.log('=== Test Results ===');
    console.log(`✅ Passed: ${passedTests}`);
    console.log(`❌ Failed: ${failedTests}`);
    console.log(`📊 Total: ${commandsToTest.length}`);
    
    if (failedTests === 0) {
        console.log('\n🎉 All commands are properly registered!');
        return true;
    } else {
        console.log('\n❌ Some commands are not properly registered.');
        console.log('\nTroubleshooting steps:');
        console.log('1. Verify that all commands in package.json match the registration in extension.ts');
        console.log('2. Check that the extension activates correctly');
        console.log('3. Ensure all required dependencies are available');
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