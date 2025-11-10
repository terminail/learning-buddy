// Debug script to check tree view structure
const vscode = require('vscode');

// Simulate the tree view structure based on MyCoursesProvider
function debugTreeView() {
    console.log('=== Tree View Structure Debug ===');
    
    // Simulate the items array from myCoursesProvider.ts
    const items = [];
    
    // Direct list of 10 My Courses (no section header)
    const myCourses = [
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
    
    myCourses.forEach((course, index) => {
        items.push({
            label: `📖 ${course}`,
            collapsibleState: vscode.TreeItemCollapsibleState.Collapsed,
            fullPath: `my_course_${index}`
        });
    });
    
    // Separator
    items.push({
        label: '',
        collapsibleState: vscode.TreeItemCollapsibleState.None,
        fullPath: 'separator'
    });
    
    // Podman Environment section
    items.push({
        label: '🔧 Podman Environment',
        collapsibleState: vscode.TreeItemCollapsibleState.Expanded,
        fullPath: 'podman_section_header'
    });
    
    // Podman info
    items.push({
        label: '✅ Podman: /usr/bin/podman',
        collapsibleState: vscode.TreeItemCollapsibleState.None,
        fullPath: 'podman_location'
    });
    
    console.log('Total items in tree view:', items.length);
    console.log('\n=== Tree View Items ===');
    items.forEach((item, index) => {
        console.log(`${index + 1}. ${item.label} (${item.fullPath})`);
    });
    
    console.log('\n=== Expected Structure ===');
    console.log('1. 10 My Courses (directly listed, no section header)');
    console.log('2. Separator');
    console.log('3. 🔧 Podman Environment (with podman info)');
    
    console.log('\n=== Issue Analysis ===');
    console.log('The 10 My Courses should be visible directly at the top of the tree view.');
    console.log('If you don\'t see them, the issue might be:');
    console.log('- The tree view panel is too small and needs scrolling');
    console.log('- There\'s a rendering issue in VS Code');
    console.log('- The extension needs to be reloaded');
}
debugTreeView();