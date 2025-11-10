//@ts-check
const vscode = require('vscode');

async function run() {
    // Run the dedicated MyCoursesView verification test
    const verifyMyCoursesView = require('./verify-mycourses-view');
    await verifyMyCoursesView.run();
    
    console.log('🎉 All real integration tests passed!');
}

module.exports = {
    run
};