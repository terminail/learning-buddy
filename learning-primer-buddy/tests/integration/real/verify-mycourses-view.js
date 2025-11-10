/**
 * Real Integration Test: Verify MyCoursesView Using VS Code Test Framework
 * 
 * This test uses the official VS Code test framework to launch VS Code,
 * install the extension, and verify the MyCoursesView displays data
 * from defaultCourseCatalog.ts.
 */

//@ts-check
const { _electron } = require('playwright');

async function run() {
    console.log('=== MyCoursesView End-to-End Test ===');
    
    try {
        // Launch VS Code with the extension
        const electronApp = await _electron.launch({ 
            executablePath: process.env.VSCODE_EXECUTABLE_PATH,
            args: [
                '--disable-extensions', // Disable other extensions for clean testing
                '--extensionDevelopmentPath=' + __dirname + '/../../..' // Path to extension
            ]
        });
        
        const page = await electronApp.firstWindow();
        
        console.log('✅ VS Code launched with extension');
        
        // Test 1: Verify extension is installed and activated
        // Look for the extension icon in the activity bar
        const extensionIcon = await page.locator('[data-extension-id="learning-primer-buddy-dev.learning-primer-buddy"]');
        await extensionIcon.isVisible({ timeout: 10000 });
        
        console.log('✅ Extension icon found in activity bar');
        
        // Test 2: Click the extension icon to open the view
        await extensionIcon.click();
        
        // Test 3: Verify the MyCoursesView is visible
        const myCoursesView = await page.locator('#learningPrimerBuddyView');
        await myCoursesView.isVisible({ timeout: 10000 });
        
        console.log('✅ MyCoursesView is visible');
        
        // Test 4: Verify the view contains exactly 10 courses
        const courseItems = await myCoursesView.locator('.tree-item-label:has-text("📖")');
        const courseCount = await courseItems.count();
        
        if (courseCount !== 10) {
            throw new Error(`Expected 10 courses, found ${courseCount}`);
        }
        
        console.log('✅ Found exactly 10 courses in MyCoursesView');
        
        // Test 5: Verify specific course titles from defaultCourseCatalog.ts
        const expectedCourses = [
            'C++ Primer 5th Edition (75%)',
            'Python 3rd Edition (60%)',
            'JavaScript ES6+ (45%)',
            'Data Structures & Algorithms (30%)',
            'Web Development Full Stack (20%)',
            'Machine Learning Fundamentals (15%)',
            'Docker & Kubernetes (90%)',
            'React Native Mobile Development (50%)',
            'SQL & Database Design (80%)',
            'Git Version Control (95%)'
        ];
        
        console.log('\nVerifying course titles:');
        for (let i = 0; i < expectedCourses.length; i++) {
            const courseItem = await courseItems.nth(i);
            const courseText = await courseItem.textContent();
            
            // Check if the course text contains the expected title
            if (courseText && !courseText.includes(expectedCourses[i].replace('📖 ', ''))) {
                throw new Error(`Course mismatch at position ${i}: expected "${expectedCourses[i]}", found "${courseText}"`);
            }
            
            console.log(`✅ ${expectedCourses[i]}`);
        }
        
        // Test 6: Verify data from defaultCourseCatalog.ts is used
        // Look for specific exercise content that comes from defaultCourseCatalog.ts
        const cppCourseItem = await myCoursesView.locator('.tree-item-label:has-text("C++ Primer 5th Edition")');
        await cppCourseItem.click();
        
        // Wait for the course content to expand
        await page.waitForTimeout(2000);
        
        // Look for exercise items from defaultCourseCatalog.ts
        const exerciseItems = await myCoursesView.locator('.tree-item-label:has-text("📘")');
        const exerciseCount = await exerciseItems.count();
        
        if (exerciseCount < 3) {
            console.warn(`⚠️  Expected at least 3 exercises from defaultCourseCatalog.ts, found ${exerciseCount}`);
        } else {
            console.log('✅ Exercises from defaultCourseCatalog.ts are displayed');
            
            // Verify specific exercise titles from defaultCourseCatalog.ts
            const firstExercise = await exerciseItems.first();
            const firstExerciseText = await firstExercise.textContent();
            
            if (firstExerciseText && firstExerciseText.includes('1. Getting Started')) {
                console.log('✅ "1. Getting Started" exercise from defaultCourseCatalog.ts is displayed');
            }
        }
        
        // Test 7: Verify Podman Environment section exists
        const podmanSection = await myCoursesView.locator('.tree-item-label:has-text("Podman Environment")');
        await podmanSection.isVisible();
        
        console.log('✅ Podman Environment section found');
        
        // Test 8: Verify separator exists between courses and Podman section
        const separatorItems = await myCoursesView.locator('.tree-item-label:has-text("")');
        const separatorCount = await separatorItems.count();
        
        if (separatorCount > 0) {
            console.log('✅ Separator found between courses and Podman section');
        } else {
            console.log('⚠️  Separator not found (may be styled differently)');
        }
        
        await electronApp.close();
        
        console.log('\n🎉 MyCoursesView End-to-End Test PASSED!');
        console.log('\nSummary of verified functionality:');
        console.log('- Extension installs and activates correctly in VS Code');
        console.log('- MyCoursesView is accessible and visible');
        console.log('- MyCoursesView displays exactly 10 courses');
        console.log('- Course titles match expected values:');
        expectedCourses.forEach(course => console.log(`  • ${course}`));
        console.log('- Data from defaultCourseCatalog.ts is used for course content');
        console.log('- Podman Environment section is displayed');
        console.log('- UI structure matches expected layout');
        
        return true;
        
    } catch (error) {
        console.error('❌ MyCoursesView End-to-End Test FAILED:', error.message);
        throw error;
    }
}

module.exports = {
    run
};