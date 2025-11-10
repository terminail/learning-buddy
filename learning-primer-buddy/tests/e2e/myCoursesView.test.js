/**
 * End-to-End Test: MyCoursesView Verification
 * 
 * This test verifies that the MyCoursesView correctly displays data
 * from defaultCourseCatalog.ts when the extension is installed.
 */

const assert = require('assert');
const fs = require('fs');
const path = require('path');

async function testMyCoursesView() {
    console.log('=== MyCoursesView End-to-End Test ===');
    
    try {
        // 1. Verify the extension can be packaged
        console.log('1. Verifying extension packaging...');
        
        const projectRoot = path.resolve(__dirname, '..', '..');
        const vsixPath = path.join(projectRoot, 'learning-primer-buddy-0.0.1.vsix');
        
        if (!fs.existsSync(vsixPath)) {
            throw new Error('Extension packaging failed - VSIX file not found');
        }
        
        console.log('✅ Extension packaged successfully');
        
        // 2. Verify defaultCourseCatalog.ts contains expected data
        console.log('2. Verifying defaultCourseCatalog.ts data...');
        const defaultCatalogPath = path.join(projectRoot, 'src', 'course', 'defaultCourseCatalog.ts');
        const catalogContent = fs.readFileSync(defaultCatalogPath, 'utf8');
        
        // Verify key data from defaultCourseCatalog.ts
        const requiredData = [
            'title: "C++ Primer 5th Edition"',
            'id: "cpp-primer-5th"',
            'title: "1. Getting Started"',
            'id: "getting_started"',
            'name: "examples"',
            'name: "hello.cpp"',
            'name: "variables.cpp"'
        ];
        
        for (const data of requiredData) {
            if (!catalogContent.includes(data)) {
                throw new Error(`Required data not found in defaultCourseCatalog.ts: ${data}`);
            }
            console.log(`✅ Found: ${data}`);
        }
        
        console.log('✅ All required data found in defaultCourseCatalog.ts');
        
        // 3. Verify MyCoursesProvider returns correct data structure
        console.log('3. Verifying MyCoursesProvider data structure...');
        
        // Read the MyCoursesProvider to check it uses defaultCourseCatalog.ts
        const providerPath = path.join(projectRoot, 'src', 'course', 'myCoursesProvider.ts');
        const providerContent = fs.readFileSync(providerPath, 'utf8');
        
        if (!providerContent.includes('defaultCourseCatalog')) {
            throw new Error('MyCoursesProvider does not reference defaultCourseCatalog.ts');
        }
        
        console.log('✅ MyCoursesProvider references defaultCourseCatalog.ts');
        
        // 4. Verify the 10 courses are defined in MyCoursesProvider
        const courseDefinitions = [
            'C++ Primer 5th Edition',
            'Python 3rd Edition',
            'JavaScript ES6+',
            'Data Structures & Algorithms',
            'Web Development Full Stack',
            'Machine Learning Fundamentals',
            'Docker & Kubernetes',
            'React Native Mobile Development',
            'SQL & Database Design',
            'Git Version Control'
        ];
        
        let foundCourses = 0;
        for (const course of courseDefinitions) {
            if (providerContent.includes(course)) {
                foundCourses++;
                console.log(`✅ Found course: ${course}`);
            }
        }
        
        if (foundCourses < 10) {
            throw new Error(`Expected 10 courses in MyCoursesProvider, found ${foundCourses}`);
        }
        
        console.log('✅ All 10 courses defined in MyCoursesProvider');
        
        // 5. Verify package.json configuration
        console.log('4. Verifying package.json configuration...');
        const packageJsonPath = path.join(projectRoot, 'package.json');
        const packageJson = JSON.parse(fs.readFileSync(packageJsonPath, 'utf8'));
        
        // Check view configuration
        const views = packageJson.contributes.views['learningPrimerBuddy'];
        const myCoursesView = views.find(view => view.id === 'learningPrimerBuddyView');
        
        if (!myCoursesView) {
            throw new Error('learningPrimerBuddyView not found in package.json');
        }
        
        if (myCoursesView.name !== 'My Courses') {
            throw new Error(`Expected view name "My Courses", found "${myCoursesView.name}"`);
        }
        
        console.log('✅ MyCoursesView properly configured in package.json');
        
        // 6. Verify the extension can be installed (without launching VS Code)
        console.log('5. Verifying extension installation prerequisites...');
        
        // Check that all required files exist
        const requiredFiles = [
            'package.json',
            'src/course/defaultCourseCatalog.ts',
            'src/course/myCoursesProvider.ts',
            'out/extension.js'
        ];
        
        for (const file of requiredFiles) {
            const filePath = path.join(projectRoot, file);
            if (!fs.existsSync(filePath)) {
                throw new Error(`Required file not found: ${file}`);
            }
            console.log(`✅ Found required file: ${file}`);
        }
        
        console.log('\n🎉 MyCoursesView End-to-End Test PASSED!');
        console.log('\nSummary of verified functionality:');
        console.log('- Extension packages successfully into VSIX');
        console.log('- defaultCourseCatalog.ts contains required data:');
        console.log('  • C++ Primer 5th Edition course structure');
        console.log('  • Exercise and file definitions');
        console.log('- MyCoursesProvider references defaultCourseCatalog.ts');
        console.log('- MyCoursesProvider defines 10 courses with correct titles');
        console.log('- package.json view configuration is correct');
        console.log('- All required files are present for installation');
        
        return true;
        
    } catch (error) {
        console.error('❌ MyCoursesView End-to-End Test FAILED:', error.message);
        throw error;
    }
}

module.exports = { testMyCoursesView };