/**
 * End-to-End Test: Command Registration Verification
 * 
 * This test verifies that all commands defined in package.json are
 * properly registered in the extension.
 */

const assert = require('assert');
const fs = require('fs');
const path = require('path');

async function testCommandRegistration() {
    console.log('=== Command Registration End-to-End Test ===');
    
    try {
        // 1. Verify package.json contains all required commands
        console.log('1. Verifying package.json command definitions...');
        
        const projectRoot = path.resolve(__dirname, '..', '..');
        const packageJsonPath = path.join(projectRoot, 'package.json');
        const packageJson = JSON.parse(fs.readFileSync(packageJsonPath, 'utf8'));
        
        // Get all commands from package.json
        const commands = packageJson.contributes.commands;
        const commandIds = commands.map(cmd => cmd.command);
        
        console.log(`Found ${commandIds.length} commands in package.json`);
        
        // Required commands
        const requiredCommands = [
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
            'learningPrimerBuddy.changePodmanLocation'
        ];
        
        // Check that all required commands are defined
        for (const command of requiredCommands) {
            if (!commandIds.includes(command)) {
                throw new Error(`Required command not found in package.json: ${command}`);
            }
            console.log(`✅ Found command in package.json: ${command}`);
        }
        
        console.log('✅ All required commands defined in package.json');
        
        // 2. Verify extension.ts registers all commands with correct names
        console.log('2. Verifying extension.ts command registrations...');
        
        const extensionPath = path.join(projectRoot, 'src', 'extension.ts');
        const extensionContent = fs.readFileSync(extensionPath, 'utf8');
        
        // Check that all required commands are registered with correct names
        for (const command of requiredCommands) {
            // Create a regex pattern to match the command registration
            const commandPattern = `registerCommand\\(['"]${command}['"]`;
            const regex = new RegExp(commandPattern);
            
            if (!regex.test(extensionContent)) {
                throw new Error(`Command not properly registered in extension.ts: ${command}`);
            }
            console.log(`✅ Found command registration in extension.ts: ${command}`);
        }
        
        console.log('✅ All required commands properly registered in extension.ts');
        
        // 3. Verify menu configurations reference correct commands
        console.log('3. Verifying menu configurations...');
        
        // Check view/title menus
        const viewTitleMenus = packageJson.contributes.menus['view/title'];
        if (viewTitleMenus) {
            for (const menu of viewTitleMenus) {
                if (!commandIds.includes(menu.command)) {
                    throw new Error(`Menu references undefined command: ${menu.command}`);
                }
                console.log(`✅ View/title menu references valid command: ${menu.command}`);
            }
        }
        
        // Check view/item/context menus
        const viewItemMenus = packageJson.contributes.menus['view/item/context'];
        if (viewItemMenus) {
            for (const menu of viewItemMenus) {
                if (!commandIds.includes(menu.command)) {
                    throw new Error(`Menu references undefined command: ${menu.command}`);
                }
                console.log(`✅ View/item/context menu references valid command: ${menu.command}`);
            }
        }
        
        // Check commandPalette menus
        const commandPaletteMenus = packageJson.contributes.menus.commandPalette;
        if (commandPaletteMenus) {
            for (const menu of commandPaletteMenus) {
                if (!commandIds.includes(menu.command)) {
                    throw new Error(`Menu references undefined command: ${menu.command}`);
                }
                console.log(`✅ CommandPalette menu references valid command: ${menu.command}`);
            }
        }
        
        console.log('✅ All menu configurations reference valid commands');
        
        // 4. Verify that command names match between package.json and extension.ts
        console.log('4. Verifying command name consistency...');
        
        // Extract command registrations from extension.ts
        const commandRegistrationPattern = /registerCommand\(['"]([^'"]+)['"]/g;
        const extensionCommandMatches = extensionContent.matchAll(commandRegistrationPattern);
        const extensionCommands = Array.from(extensionCommandMatches).map(match => match[1]);
        
        console.log(`Found ${extensionCommands.length} command registrations in extension.ts`);
        
        // Check that all package.json commands are registered in extension.ts
        for (const command of commandIds) {
            // Skip commands that might be registered elsewhere or are external
            if (command.startsWith('learningPrimerBuddy.')) {
                if (!extensionCommands.includes(command)) {
                    throw new Error(`Command defined in package.json but not registered in extension.ts: ${command}`);
                }
                console.log(`✅ Command consistency verified: ${command}`);
            }
        }
        
        console.log('✅ Command names are consistent between package.json and extension.ts');
        
        console.log('\n🎉 Command Registration End-to-End Test PASSED!');
        console.log('\nSummary of verified functionality:');
        console.log('- All required commands defined in package.json');
        console.log('- All commands properly registered in extension.ts');
        console.log('- Menu configurations reference valid commands');
        console.log('- Command names are consistent between package.json and extension.ts');
        
        return true;
        
    } catch (error) {
        console.error('❌ Command Registration End-to-End Test FAILED:', error.message);
        throw error;
    }
}

module.exports = { testCommandRegistration };