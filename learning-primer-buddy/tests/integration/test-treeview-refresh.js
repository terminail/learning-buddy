// Test script to verify tree view structure and trigger refresh
const vscode = require('vscode');

async function testTreeView() {
    console.log('Testing Learning Buddy Tree View...');
    
    // Get the Learning Buddy extension
    const extension = vscode.extensions.getExtension('learning-primer-buddy-dev.learning-primer-buddy');
    
    if (!extension) {
        console.log('❌ Learning Buddy extension not found');
        return;
    }
    
    console.log('✅ Learning Buddy extension found:', extension.id);
    
    // Check if extension is active
    if (!extension.isActive) {
        console.log('⚠️ Extension is not active, activating...');
        await extension.activate();
    }
    
    console.log('✅ Extension is active');
    
    // Try to trigger a tree view refresh
    console.log('🔄 Triggering tree view refresh...');
    
    // Execute command to refresh the tree view
    try {
        await vscode.commands.executeCommand('learningBuddy.refreshEntry');
        console.log('✅ Tree view refresh command executed');
    } catch (error) {
        console.log('⚠️ Could not execute refresh command:', error.message);
    }
    
    // Try alternative refresh method
    try {
        await vscode.commands.executeCommand('workbench.action.reloadWindow');
        console.log('✅ Window reload command executed');
    } catch (error) {
        console.log('⚠️ Could not execute window reload:', error.message);
    }
    
    console.log('\n📋 Troubleshooting steps:');
    console.log('1. The "📚 My Courses" section should be VISIBLE at the TOP of the tree view');
    console.log('2. Look for "📚 My Courses" header at the beginning of the tree view');
    console.log('3. Expand the "📚 My Courses" section by clicking the arrow');
    console.log('4. The "🔧 Podman Environment" section should be BELOW the My Courses section');
    console.log('5. If still not visible, try restarting VS Code');
    console.log('6. Check if the extension is enabled in Extensions view');
}

// Run the test
testTreeView().catch(console.error);