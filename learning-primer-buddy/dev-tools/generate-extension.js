#!/usr/bin/env node

/**
 * Development Tool: Extension Generator (Podman Edition)
 * 
 * This script demonstrates how developers can generate both generic learning buddy
 * and course learning buddy extensions using the development tools with Podman support.
 */

const fs = require('fs');
const path = require('path');
const { execSync } = require('child_process');

/**
 * Generate a generic learning buddy extension
 * @param {Object} config - Configuration for the generic extension
 */
function generateGenericExtension(config) {
    console.log('Generating Generic Learning Buddy Extension...');
    
    // Create a temporary configuration file
    const configPath = path.join(__dirname, '..', 'temp-generic-config.json');
    fs.writeFileSync(configPath, JSON.stringify(config, null, 2));
    
    try {
        // Use the existing build script to generate the extension
        execSync(`node build-buddy.js ${configPath}`, { 
            stdio: 'inherit',
            cwd: path.join(__dirname, '..')
        });
        
        console.log('Generic Learning Buddy Extension generated successfully!');
    } catch (error) {
        console.error('Error generating generic extension:', error.message);
    } finally {
        // Clean up temporary configuration file
        if (fs.existsSync(configPath)) {
            fs.unlinkSync(configPath);
        }
    }
}

/**
 * Generate a course learning buddy extension
 * @param {Object} config - Configuration for the course extension
 */
function generateCourseExtension(config) {
    console.log('Generating Course Learning Buddy Extension...');
    
    // Create a temporary configuration file
    const configPath = path.join(__dirname, '..', 'temp-course-config.json');
    fs.writeFileSync(configPath, JSON.stringify(config, null, 2));
    
    try {
        // Use the existing build script to generate the extension
        execSync(`node build-buddy.js ${configPath}`, { 
            stdio: 'inherit',
            cwd: path.join(__dirname, '..')
        });
        
        console.log('Course Learning Buddy Extension generated successfully!');
    } catch (error) {
        console.error('Error generating course extension:', error.message);
    } finally {
        // Clean up temporary configuration file
        if (fs.existsSync(configPath)) {
            fs.unlinkSync(configPath);
        }
    }
}

/**
 * Build both generic and course extensions
 */
function buildBothExtensions() {
    console.log('=== Building Both Learning Buddy Extensions ===\n');
    
    // Build generic extension
    const genericConfigPath = path.join(__dirname, '..', 'learning-buddy-generic-config.json');
    if (fs.existsSync(genericConfigPath)) {
        console.log('Building Generic Learning Buddy Extension...');
        try {
            execSync(`node build-buddy.js ${genericConfigPath}`, { 
                stdio: 'inherit',
                cwd: path.join(__dirname, '..')
            });
            console.log('Generic Learning Buddy Extension generated successfully!');
        } catch (error) {
            console.error('Error generating generic extension:', error.message);
        }
    } else {
        console.error('Generic Learning Buddy configuration file not found!');
    }
    
    // Build C++ Primer 5th Edition extension
    const courseConfigPath = path.join(__dirname, '..', 'examples', 'cpp-primer-5th-config.json');
    if (fs.existsSync(courseConfigPath)) {
        console.log('\nBuilding C++ Primer 5th Edition Buddy Extension...');
        try {
            execSync(`node build-buddy.js ${courseConfigPath}`, { 
                stdio: 'inherit',
                cwd: path.join(__dirname, '..')
            });
            console.log('C++ Primer 5th Edition Buddy Extension generated successfully!');
        } catch (error) {
            console.error('Error generating C++ Primer 5th Edition extension:', error.message);
        }
    } else {
        console.error('C++ Primer 5th Edition configuration file not found!');
    }
    
    console.log('\n=== Build Process Complete ===');
}

// Run the build process
if (require.main === module) {
    buildBothExtensions();
}

module.exports = {
    generateGenericExtension,
    generateCourseExtension,
    buildBothExtensions
};