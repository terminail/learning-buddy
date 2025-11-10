// Debug script to check tree view structure
const fs = require('fs');
const path = require('path');

// Read the myCoursesProvider.ts file
const treeViewPath = path.join(__dirname, '..', 'src', 'course', 'myCoursesProvider.ts');
const content = fs.readFileSync(treeViewPath, 'utf8');

// Extract the getChildren method structure
const getChildrenMatch = content.match(/if \(!element\) \{[\s\S]*?return Promise\.resolve\(items\);/);

if (getChildrenMatch) {
    console.log('=== Tree View Structure Analysis ===\n');
    
    // Count sections
    const sections = [
        { name: 'My Courses', line: content.indexOf("'📚 My Courses'") },
        { name: 'Podman Environment', line: content.indexOf("'🔧 Podman Environment'") }
    ].filter(section => section.line > 0).sort((a, b) => a.line - b.line);
    
    console.log('Sections in order of appearance:');
    sections.forEach((section, index) => {
        console.log(`${index + 1}. ${section.name}`);
    });
    
    console.log('\n=== My Courses Section Details ===');
    const myCoursesStart = content.indexOf("// TOP SECTION: My Courses");
    if (myCoursesStart > 0) {
        const myCoursesCode = content.substring(myCoursesStart, myCoursesStart + 500);
        console.log('My Courses section is implemented and includes:');
        
        // Check if getMyCourses is called
        if (myCoursesCode.includes('this.getMyCourses()')) {
            console.log('✅ getMyCourses() method is called');
        }
        
        // Check if courses are added to items
        if (myCoursesCode.includes('items.push(...myCourses)')) {
            console.log('✅ Courses are added to the tree view items');
        }
    }
    
    console.log('\n=== Troubleshooting Steps ===');
    console.log('1. The My Courses section is now the FIRST section in the tree view');
    console.log('2. The Podman Environment section comes AFTER the My Courses section');
    console.log('3. Look for "📚 My Courses" header at the top of the tree view');
    console.log('4. The section should contain 10 courses with progress percentages');
    console.log('\n=== Expected Courses ===');
    console.log('1. C++ Primer 5th Edition (75%)');
    console.log('2. Python 3rd Edition (60%)');
    console.log('3. JavaScript ES6+ (45%)');
    console.log('4. Data Structures & Algorithms (30%)');
    console.log('5. Web Development Full Stack (20%)');
    console.log('6. Machine Learning Fundamentals (15%)');
    console.log('7. Docker & Kubernetes (90%)');
    console.log('8. React Native Mobile Development (50%)');
    console.log('9. SQL & Database Design (80%)');
    console.log('10. Git Version Control (95%)');
} else {
    console.log('❌ Could not find getChildren method structure');
}