#!/usr/bin/env node

/**
 * Build Tool: Learning Buddy Extension Builder
 * 
 * This script builds customized Learning Buddy extensions by:
 * 1. Updating package.json with extension-specific metadata
 * 2. Updating extension display names in source files
 * 3. Compiling TypeScript to JavaScript
 * 4. Packaging the extension into a VSIX file
 */

const fs = require('fs');
const path = require('path');
const { execSync } = require('child_process');

/**
 * Build a Learning Buddy extension with the provided configuration
 * @param {string} configPath - Path to the configuration JSON file
 */
function buildLearningBuddy(configPath) {
    try {
        // Read configuration
        const config = JSON.parse(fs.readFileSync(configPath, 'utf8'));
        const extensionType = config.name.includes('generic') ? 'Generic Learning Buddy' : 'Course Learning Buddy';
        
        console.log(`Building ${extensionType} extension: ${config.displayName}`);
        
        // Backup original package.json
        const packagePath = path.join(__dirname, 'package.json');
        const backupPackagePath = path.join(__dirname, 'package.json.backup');
        fs.copyFileSync(packagePath, backupPackagePath);
        
        // Update package.json with new configuration
        const packageJson = JSON.parse(fs.readFileSync(packagePath, 'utf8'));
        packageJson.name = config.name;
        packageJson.displayName = config.displayName;
        packageJson.description = config.description;
        packageJson.publisher = config.publisher;
        packageJson.repository = config.repository;
        
        fs.writeFileSync(packagePath, JSON.stringify(packageJson, null, 2));
        
        // Update extension.ts
        const extensionPath = path.join(__dirname, 'src', 'extension.ts');
        let extensionContent = fs.readFileSync(extensionPath, 'utf8');
        extensionContent = extensionContent.replace(/6Learning Buddy/g, config.displayName);
        fs.writeFileSync(extensionPath, extensionContent);
        
        // Update other TypeScript files with correct paths
        const licenseManagerPath = path.join(__dirname, 'src', 'license', 'licenseManager.ts');
        if (fs.existsSync(licenseManagerPath)) {
            let licenseManagerContent = fs.readFileSync(licenseManagerPath, 'utf8');
            licenseManagerContent = licenseManagerContent.replace(/6Learning Buddy/g, config.displayName);
            fs.writeFileSync(licenseManagerPath, licenseManagerContent);
        }
        
        const wechatIntegrationPath = path.join(__dirname, 'src', 'wechat', 'wechatIntegration.ts');
        if (fs.existsSync(wechatIntegrationPath)) {
            let wechatIntegrationContent = fs.readFileSync(wechatIntegrationPath, 'utf8');
            wechatIntegrationContent = wechatIntegrationContent.replace(/6Learning Buddy/g, config.displayName);
            fs.writeFileSync(wechatIntegrationPath, wechatIntegrationContent);
        }
        
        // Compile TypeScript
        console.log('Compiling TypeScript...');
        execSync('npx tsc', { stdio: 'inherit' });
        
        // Package the extension
        console.log('Packaging extension...');
        // Use the --no-dependencies flag to avoid issues with unused file patterns
        execSync('npx vsce package --no-dependencies', { stdio: 'inherit' });
        
        // Restore original package.json
        fs.copyFileSync(backupPackagePath, packagePath);
        fs.unlinkSync(backupPackagePath);
        
        console.log(`Successfully built ${extensionType}: ${config.displayName} extension!`);
        console.log(`VSIX file created in ${__dirname}`);
        
    } catch (error) {
        console.error('Error building Learning Buddy extension:', error);
        
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
        console.error('Usage: node build-buddy.js <config-file-path>');
        process.exit(1);
    }
    
    buildLearningBuddy(configPath);
}

module.exports = { buildLearningBuddy };