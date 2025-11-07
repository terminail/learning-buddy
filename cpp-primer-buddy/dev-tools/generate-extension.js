#!/usr/bin/env node

/**
 * Development Tool: Extension Generator
 * 
 * This script demonstrates how developers can generate both generic learning buddy
 * and course learning buddy extensions using the development tools.
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
        execSync(`node build-custom-extension.js ${configPath}`, { 
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
        execSync(`node build-custom-extension.js ${configPath}`, { 
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
 * Sample usage of the development tools
 */
function demonstrateUsage() {
    console.log('=== Learning Buddy Development Tools Demo ===\n');
    
    // Example 1: Generate a generic learning buddy extension
    const genericConfig = {
        "name": "java-fundamentals-buddy",
        "displayName": "Java Fundamentals Buddy",
        "description": "A VS Code extension that helps Java Fundamentals learners navigate their project files with a directory tree view",
        "publisher": "java-learning-dev",
        "repository": {
            "type": "git",
            "url": "https://github.com/learning-buddy/java-fundamentals.git"
        }
    };
    
    console.log('Example 1: Generating Generic Learning Buddy Extension');
    console.log('Configuration:', JSON.stringify(genericConfig, null, 2));
    console.log('');
    
    // Uncomment the next line to actually generate the extension
    // generateGenericExtension(genericConfig);
    
    // Example 2: Generate a course learning buddy extension
    const courseConfig = {
        "name": "python-data-science-buddy",
        "displayName": "Python Data Science Buddy",
        "description": "A VS Code extension for Python Data Science learners",
        "publisher": "data-science-dev",
        "repository": {
            "type": "git",
            "url": "https://github.com/learning-buddy/python-data-science.git"
        },
        "content": {
            "source": "github",
            "repository": "https://github.com/learning-buddy/python-data-science",
            "branch": "main"
        },
        "chapters": [
            {
                "id": "1_introduction",
                "title": "1. Introduction to Data Science",
                "protected": false
            },
            {
                "id": "2_data_analysis",
                "title": "2. Data Analysis with Pandas",
                "protected": false
            },
            {
                "id": "3_visualization",
                "title": "3. Data Visualization",
                "protected": true
            }
        ],
        "protectedChapters": [
            "3_visualization"
        ],
        "extension": {
            "name": "Python Data Science Buddy",
            "displayName": "Python Data Science Buddy",
            "description": "Learning Buddy extension for Python Data Science by Jake VanderPlas",
            "icon": "icons/python-ds-icon.png"
        },
        "course": {
            "defaultId": "python-data-science",
            "defaultName": "Python Data Science",
            "repository": "https://gitee.com/learning-buddy/python-data-science-course",
            "dockerfile": "Dockerfile"
        },
        "branding": {
            "primaryColor": "#3776ab",
            "promotionalBanner": "icons/python-ds-banner.png"
        }
    };
    
    console.log('Example 2: Generating Course Learning Buddy Extension');
    console.log('Configuration:', JSON.stringify(courseConfig, null, 2));
    console.log('');
    
    // Uncomment the next line to actually generate the extension
    // generateCourseExtension(courseConfig);
    
    console.log('=== End of Demo ===');
    console.log('\nTo generate actual extensions, uncomment the generate functions above and provide valid configurations.');
}

// Run the demonstration
if (require.main === module) {
    demonstrateUsage();
}

module.exports = {
    generateGenericExtension,
    generateCourseExtension
};