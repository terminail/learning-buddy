const { testMyCoursesView } = require('../myCoursesView.test');
const { testCommandRegistration } = require('../verifyCommands.test');
const { testCourseCatalog } = require('../courseCatalog.test');

async function run() {
  // This is a simplified test runner that just runs our verification
  console.log('Starting end-to-end tests...');
  
  try {
    // Run the MyCoursesView verification
    await testMyCoursesView();
    
    // Run the command registration verification
    await testCommandRegistration();
    
    // Run the course catalog verification
    await testCourseCatalog();
    
    console.log('✅ All end-to-end tests passed!');
    return Promise.resolve();
  } catch (error) {
    console.error('❌ End-to-end tests failed:', error);
    return Promise.reject(error);
  }
}

module.exports = {
  run
};