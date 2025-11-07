const fs = require('fs');
const path = require('path');
const { execSync } = require('child_process');

/**
 * Build a custom Learning Buddy extension based on configuration
 * @param {string} configPath - Path to the configuration JSON file
 */
function buildCustomExtension(configPath) {
    try {
        // Read the configuration file
        const configContent = fs.readFileSync(configPath, 'utf8');
        const config = JSON.parse(configContent);
        
        console.log(`Building custom Learning Buddy extension: ${config.displayName}`);
        
        // Backup original package.json
        const packagePath = path.join(__dirname, 'package.json');
        const backupPackagePath = path.join(__dirname, 'package.json.backup');
        fs.copyFileSync(packagePath, backupPackagePath);
        
        // Read the original package.json
        const packageContent = fs.readFileSync(packagePath, 'utf8');
        const packageJson = JSON.parse(packageContent);
        
        // Update package.json with custom configuration
        packageJson.name = config.name;
        packageJson.displayName = config.displayName;
        packageJson.description = config.description;
        packageJson.publisher = config.publisher;
        packageJson.repository = config.repository;
        
        // Update activation events and views to use the custom name
        const customId = config.name.replace(/[^a-zA-Z0-9]/g, '');
        packageJson.activationEvents = [`onView:${customId}View`];
        
        // Update views containers
        if (packageJson.contributes && packageJson.contributes.viewsContainers) {
            const activityBar = packageJson.contributes.viewsContainers.activitybar[0];
            activityBar.id = `${customId}-view`;
            activityBar.title = config.displayName.replace(' Buddy', '').replace(' Template', '');
        }
        
        // Update views
        if (packageJson.contributes && packageJson.contributes.views) {
            const oldViewKey = Object.keys(packageJson.contributes.views)[0];
            const newViewKey = `${customId}-view`;
            packageJson.contributes.views[newViewKey] = packageJson.contributes.views[oldViewKey];
            delete packageJson.contributes.views[oldViewKey];
            
            // Update view id
            packageJson.contributes.views[newViewKey][0].id = `${customId}View`;
            packageJson.contributes.views[newViewKey][0].name = "Study Plan";
        }
        
        // Update commands
        if (packageJson.contributes && packageJson.contributes.commands) {
            packageJson.contributes.commands = packageJson.contributes.commands.map(cmd => {
                // Update command names to use custom prefix
                cmd.command = cmd.command.replace('cppPrimerBuddy', customId);
                return cmd;
            });
        }
        
        // Update menus
        if (packageJson.contributes && packageJson.contributes.menus) {
            // Update view/item/context menu
            if (packageJson.contributes.menus['view/item/context']) {
                packageJson.contributes.menus['view/item/context'] = 
                    packageJson.contributes.menus['view/item/context'].map(menu => {
                        menu.command = menu.command.replace('cppPrimerBuddy', customId);
                        menu.when = menu.when.replace('cppPrimerBuddyView', `${customId}View`);
                        return menu;
                    });
            }
            
            // Update commandPalette menu
            if (packageJson.contributes.menus.commandPalette) {
                packageJson.contributes.menus.commandPalette = 
                    packageJson.contributes.menus.commandPalette.map(menu => {
                        menu.command = menu.command.replace('cppPrimerBuddy', customId);
                        return menu;
                    });
            }
        }
        
        // Write updated package.json
        fs.writeFileSync(packagePath, JSON.stringify(packageJson, null, 2));
        
        // Update extension.ts to use custom identifiers
        const extensionPath = path.join(__dirname, 'src', 'extension.ts');
        let extensionContent = fs.readFileSync(extensionPath, 'utf8');
        
        // Replace identifiers
        extensionContent = extensionContent.replace(/cppPrimerBuddy/g, customId);
        extensionContent = extensionContent.replace(/CppPrimer/g, getClassName(config.displayName));
        extensionContent = extensionContent.replace(/C\+\+ Primer Buddy/g, config.displayName);
        
        fs.writeFileSync(extensionPath, extensionContent);
        
        // Update treeViewProvider.ts to use custom identifiers and support dynamic structure
        const treeViewProviderPath = path.join(__dirname, 'src', 'treeViewProvider.ts');
        let treeViewProviderContent = fs.readFileSync(treeViewProviderPath, 'utf8');
        
        // Add import for dynamic structure loading
        if (!treeViewProviderContent.includes('import * as https from \'https\'')) {
            treeViewProviderContent = treeViewProviderContent.replace(
                "import * as fs from 'fs';",
                "import * as fs from 'fs';\nimport * as https from 'https';"
            );
        }
        
        // Replace identifiers
        treeViewProviderContent = treeViewProviderContent.replace(/cppPrimerBuddy/g, customId);
        treeViewProviderContent = treeViewProviderContent.replace(/CppPrimer/g, getClassName(config.displayName));
        treeViewProviderContent = treeViewProviderContent.replace(/C\+\+ Primer Buddy/g, config.displayName);
        
        fs.writeFileSync(treeViewProviderPath, treeViewProviderContent);
        
        // Update other TypeScript files
        const licenseManagerPath = path.join(__dirname, 'src', 'licenseManager.ts');
        let licenseManagerContent = fs.readFileSync(licenseManagerPath, 'utf8');
        licenseManagerContent = licenseManagerContent.replace(/C\+\+ Primer Buddy/g, config.displayName);
        fs.writeFileSync(licenseManagerPath, licenseManagerContent);
        
        const wechatIntegrationPath = path.join(__dirname, 'src', 'wechatIntegration.ts');
        let wechatIntegrationContent = fs.readFileSync(wechatIntegrationPath, 'utf8');
        wechatIntegrationContent = wechatIntegrationContent.replace(/C\+\+ Primer Buddy/g, config.displayName);
        fs.writeFileSync(wechatIntegrationPath, wechatIntegrationContent);
        
        // Compile TypeScript
        console.log('Compiling TypeScript...');
        execSync('npx tsc', { stdio: 'inherit' });
        
        // Package the extension
        console.log('Packaging extension...');
        execSync('npx vsce package', { stdio: 'inherit' });
        
        // Restore original package.json
        fs.copyFileSync(backupPackagePath, packagePath);
        fs.unlinkSync(backupPackagePath);
        
        console.log(`Successfully built ${config.displayName} extension!`);
        console.log(`VSIX file created in ${__dirname}`);
        
    } catch (error) {
        console.error('Error building custom extension:', error);
        
        // Restore original package.json if it exists
        const backupPackagePath = path.join(__dirname, 'package.json.backup');
        const packagePath = path.join(__dirname, 'package.json');
        if (fs.existsSync(backupPackagePath)) {
            fs.copyFileSync(backupPackagePath, packagePath);
            fs.unlinkSync(backupPackagePath);
        }
    }
}

/**
 * Convert display name to class name format
 * @param {string} displayName - The display name
 * @returns {string} - The class name
 */
function getClassName(displayName) {
    // Remove "Buddy" and convert to PascalCase
    return displayName.replace(' Buddy', '').replace(/\b\w/g, char => char.toUpperCase()).replace(/\s+/g, '');
}

// Run if called directly
if (require.main === module) {
    const configPath = process.argv[2];
    if (!configPath) {
        console.error('Usage: node build-custom-extension.js <config-file-path>');
        process.exit(1);
    }
    
    buildCustomExtension(configPath);
}

module.exports = { buildCustomExtension };