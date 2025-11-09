#!/usr/bin/env node

const fs = require('fs');
const path = require('path');
const { execSync } = require('child_process');

/**
 * Validate a course repository for Learning Buddy compliance
 * @param {string} repoPath - Path to the course repository
 */
function validateCourseRepository(repoPath) {
    console.log(`Validating course repository: ${repoPath}`);
    
    const results = {
        valid: true,
        errors: [],
        warnings: [],
        info: []
    };
    
    // Check if path exists
    if (!fs.existsSync(repoPath)) {
        results.valid = false;
        results.errors.push(`Repository path does not exist: ${repoPath}`);
        return results;
    }
    
    // Validate repository structure
    validateRepositoryStructure(repoPath, results);
    
    // Validate required files
    validateRequiredFiles(repoPath, results);
    
    // Validate course structure file
    validateCourseStructureFile(repoPath, results);
    
    // Validate Podmanfile
    validatePodmanfile(repoPath, results);
    
    return results;
}

/**
 * Validate repository structure
 * @param {string} repoPath - Path to the repository
 * @param {object} results - Validation results object
 */
function validateRepositoryStructure(repoPath, results) {
    results.info.push('Checking repository structure...');
    
    // Check for required directories
    const requiredDirs = ['chapters'];
    for (const dir of requiredDirs) {
        const dirPath = path.join(repoPath, dir);
        if (!fs.existsSync(dirPath)) {
            results.valid = false;
            results.errors.push(`Required directory missing: ${dir}`);
        } else if (!fs.statSync(dirPath).isDirectory()) {
            results.valid = false;
            results.errors.push(`Required directory is not a directory: ${dir}`);
        }
    }
    
    // Check for optional directories
    const optionalDirs = ['exercises'];
    for (const dir of optionalDirs) {
        const dirPath = path.join(repoPath, dir);
        if (fs.existsSync(dirPath) && !fs.statSync(dirPath).isDirectory()) {
            results.warnings.push(`Optional directory is not a directory: ${dir}`);
        }
    }
}

/**
 * Validate required files
 * @param {string} repoPath - Path to the repository
 * @param {object} results - Validation results object
 */
function validateRequiredFiles(repoPath, results) {
    results.info.push('Checking required files...');
    
    // Check for required files
    const requiredFiles = ['course-structure.json', 'Podmanfile'];
    for (const file of requiredFiles) {
        const filePath = path.join(repoPath, file);
        if (!fs.existsSync(filePath)) {
            results.valid = false;
            results.errors.push(`Required file missing: ${file}`);
        } else if (fs.statSync(filePath).isDirectory()) {
            results.valid = false;
            results.errors.push(`Required file is a directory: ${file}`);
        }
    }
    
    // Check for optional files
    const optionalFiles = ['README.md'];
    for (const file of optionalFiles) {
        const filePath = path.join(repoPath, file);
        if (fs.existsSync(filePath) && fs.statSync(filePath).isDirectory()) {
            results.warnings.push(`Optional file is a directory: ${file}`);
        }
    }
}

/**
 * Validate course structure file
 * @param {string} repoPath - Path to the repository
 * @param {object} results - Validation results object
 */
function validateCourseStructureFile(repoPath, results) {
    const courseStructurePath = path.join(repoPath, 'course-structure.json');
    
    if (!fs.existsSync(courseStructurePath)) {
        // Error already reported in validateRequiredFiles
        return;
    }
    
    results.info.push('Validating course-structure.json...');
    
    try {
        const content = fs.readFileSync(courseStructurePath, 'utf8');
        const courseStructure = JSON.parse(content);
        
        // Validate required top-level fields
        const requiredFields = ['version', 'title', 'description', 'chapters'];
        for (const field of requiredFields) {
            if (!(field in courseStructure)) {
                results.valid = false;
                results.errors.push(`Missing required field in course-structure.json: ${field}`);
            }
        }
        
        // Validate chapters structure
        if (Array.isArray(courseStructure.chapters)) {
            for (let i = 0; i < courseStructure.chapters.length; i++) {
                const chapter = courseStructure.chapters[i];
                const requiredChapterFields = ['id', 'title', 'protected'];
                for (const field of requiredChapterFields) {
                    if (!(field in chapter)) {
                        results.valid = false;
                        results.errors.push(`Chapter ${i} missing required field: ${field}`);
                    }
                }
                
                // Validate sections if present
                if (chapter.sections && Array.isArray(chapter.sections)) {
                    for (let j = 0; j < chapter.sections.length; j++) {
                        const section = chapter.sections[j];
                        const requiredSectionFields = ['id', 'title', 'type', 'file'];
                        for (const field of requiredSectionFields) {
                            if (!(field in section)) {
                                results.valid = false;
                                results.errors.push(`Chapter ${i} section ${j} missing required field: ${field}`);
                            }
                        }
                    }
                }
            }
        } else {
            results.valid = false;
            results.errors.push('chapters field must be an array');
        }
        
        // Validate protectedChapters if present
        if (courseStructure.protectedChapters && !Array.isArray(courseStructure.protectedChapters)) {
            results.valid = false;
            results.errors.push('protectedChapters field must be an array');
        }
        
    } catch (error) {
        results.valid = false;
        results.errors.push(`Invalid JSON in course-structure.json: ${error.message}`);
    }
}

/**
 * Validate Podmanfile
 * @param {string} repoPath - Path to the repository
 * @param {object} results - Validation results object
 */
function validatePodmanfile(repoPath, results) {
    const podmanfilePath = path.join(repoPath, 'Podmanfile');
    
    if (!fs.existsSync(podmanfilePath)) {
        // Error already reported in validateRequiredFiles
        return;
    }
    
    results.info.push('Validating Podmanfile...');
    
    try {
        const content = fs.readFileSync(podmanfilePath, 'utf8');
        
        // Check for required FROM instruction
        if (!content.includes('FROM ')) {
            results.valid = false;
            results.errors.push('Podmanfile missing FROM instruction');
        }
        
        // Check for common security issues
        if (content.includes('USER root') && !content.includes('USER ') || 
            (content.includes('USER root') && content.split('USER ').length < 2)) {
            results.warnings.push('Podmanfile uses root user, consider creating a non-root user');
        }
        
        // Check for basic best practices
        if (!content.includes('LABEL ') && !content.includes('MAINTAINER ')) {
            results.warnings.push('Podmanfile missing LABEL or MAINTAINER instruction');
        }
        
    } catch (error) {
        results.valid = false;
        results.errors.push(`Error reading Podmanfile: ${error.message}`);
    }
}

/**
 * Print validation results
 * @param {object} results - Validation results object
 */
function printResults(results) {
    console.log('\n=== Validation Results ===');
    
    if (results.valid) {
        console.log('✅ Repository is valid for Learning Buddy!');
    } else {
        console.log('❌ Repository has validation errors:');
        for (const error of results.errors) {
            console.log(`   - ${error}`);
        }
    }
    
    if (results.warnings.length > 0) {
        console.log('\n⚠️  Warnings:');
        for (const warning of results.warnings) {
            console.log(`   - ${warning}`);
        }
    }
    
    if (results.info.length > 0) {
        console.log('\nℹ️  Information:');
        for (const info of results.info) {
            console.log(`   - ${info}`);
        }
    }
}

// Run if called directly
if (require.main === module) {
    const repoPath = process.argv[2];
    if (!repoPath) {
        console.error('Usage: node validate-course.js <repository-path>');
        process.exit(1);
    }
    
    const results = validateCourseRepository(repoPath);
    printResults(results);
    
    // Exit with error code if validation failed
    if (!results.valid) {
        process.exit(1);
    }
}

module.exports = { validateCourseRepository };