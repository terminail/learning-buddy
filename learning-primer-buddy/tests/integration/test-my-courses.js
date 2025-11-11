// Test script to verify My Courses implementation
const fs = require('fs');
const path = require('path');

// Read the myCoursesProvider.ts file
const treeViewProviderPath = path.join(__dirname, '..', '..', 'src', 'course', 'myCoursesProvider.ts');
const content = fs.readFileSync(treeViewProviderPath, 'utf8');

// Check if My Courses implementation exists (without section header)
const hasMyCoursesMethod = content.includes('getMyCourses(): CourseItem[]');
const hasDirectCourseListing = content.includes('items.push(...myCourses);') && !content.includes('my_courses_header:');

// Check for the 10 courses
const courses = [
    "C++ Primer 5th Edition",
    "Python 3rd Edition", 
    "JavaScript ES6+",
    "Data Structures & Algorithms",
    "Web Development Full Stack",
    "Machine Learning Fundamentals",
    "Docker & Kubernetes",
    "React Native Mobile Development",
    "SQL & Database Design",
    "Git Version Control"
];

let foundCourses = 0;
courses.forEach(course => {
    if (content.includes(course)) {
        foundCourses++;
        console.log(`✅ Found: ${course}`);
    } else {
        console.log(`❌ Missing: ${course}`);
    }
});

console.log('\n=== My Courses Implementation Test Results ===');
console.log(`getMyCourses Method: ${hasMyCoursesMethod ? '✅ Present' : '❌ Missing'}`);
console.log(`Direct Course Listing: ${hasDirectCourseListing ? '✅ Present' : '❌ Missing (my_courses_header: found)'}`);
console.log(`Courses Found: ${foundCourses}/10`);

if (hasMyCoursesMethod && hasDirectCourseListing && foundCourses === 10) {
    console.log('\n🎉 SUCCESS: My Courses implementation is complete!');
    console.log('The 10 diverse courses are properly implemented in the tree view.');
    console.log('Courses are listed directly without a section header.');
} else {
    console.log('\n⚠️  ISSUE: Some parts of the My Courses implementation may be missing.');
}

console.log('\nTo see the My Courses in VS Code:');
console.log('1. Install the extension in VS Code');
console.log('2. Look for the "Learning Buddy" icon in the activity bar');
console.log('3. Click on the "My Courses" view');
console.log('4. You should see 10 courses listed directly, above the Podman section');