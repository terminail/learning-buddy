#include <gtest/gtest.h>
#include "copy_control_exercises.h"
#include "copy_control_solutions.h"

namespace cpp_primer {

// Test fixture for CopyControl exercises
class CopyControlBasicsTest : public ::testing::Test {
protected:
    CopyControl exercises;
    CopyControlSolutions solutions;
};

// Test default constructor
TEST_F(CopyControlBasicsTest, TestDefaultConstructor) {
    EXPECT_TRUE(exercises.empty());
    EXPECT_EQ(exercises.get_size(), 0);
    
    EXPECT_TRUE(solutions.empty());
    EXPECT_EQ(solutions.get_size(), 0);
}

// Test constructor with string parameter
TEST_F(CopyControlBasicsTest, TestStringConstructor) {
    std::string test_str = "Hello, World!";
    CopyControl ex_with_str(test_str);
    CopyControlSolutions sol_with_str(test_str);
    
    EXPECT_FALSE(ex_with_str.empty());
    EXPECT_EQ(ex_with_str.get_size(), test_str.size());
    // Add more assertions as needed
}

// Test copy constructor
TEST_F(CopyControlBasicsTest, TestCopyConstructor) {
    std::string test_str = "Copy Test";
    CopyControl original(test_str);
    CopyControl copy(original);
    
    CopyControlSolutions sol_original(test_str);
    CopyControlSolutions sol_copy(sol_original);
    
    // Both should have the same data
    EXPECT_FALSE(copy.empty());
    EXPECT_EQ(copy.get_size(), original.get_size());
    // Add more assertions as needed
}

// Test move constructor
TEST_F(CopyControlBasicsTest, TestMoveConstructor) {
    std::string test_str = "Move Test";
    CopyControl original(test_str);
    CopyControl moved(std::move(original));
    
    CopyControlSolutions sol_original(test_str);
    CopyControlSolutions sol_moved(std::move(sol_original));
    
    // Original should be in a valid but unspecified state
    // Moved should have the data
    EXPECT_FALSE(moved.empty());
    EXPECT_EQ(moved.get_size(), test_str.size());
    // Add more assertions as needed
}

// Test copy assignment operator
TEST_F(CopyControlBasicsTest, TestCopyAssignment) {
    std::string test_str1 = "Original";
    std::string test_str2 = "Assigned";
    
    CopyControl original(test_str1);
    CopyControl assigned(test_str2);
    assigned = original;
    
    CopyControlSolutions sol_original(test_str1);
    CopyControlSolutions sol_assigned(test_str2);
    sol_assigned = sol_original;
    
    // Both should have the same data as original
    EXPECT_FALSE(assigned.empty());
    EXPECT_EQ(assigned.get_size(), original.get_size());
    // Add more assertions as needed
}

// Test move assignment operator
TEST_F(CopyControlBasicsTest, TestMoveAssignment) {
    std::string test_str1 = "Original";
    std::string test_str2 = "Assigned";
    
    CopyControl original(test_str1);
    CopyControl assigned(test_str2);
    assigned = std::move(original);
    
    CopyControlSolutions sol_original(test_str1);
    CopyControlSolutions sol_assigned(test_str2);
    sol_assigned = std::move(sol_original);
    
    // Assigned should have original's data
    EXPECT_FALSE(assigned.empty());
    EXPECT_EQ(assigned.get_size(), test_str1.size());
    // Add more assertions as needed
}

// Test destructor (indirectly through scope)
TEST_F(CopyControlBasicsTest, TestDestructor) {
    {
        CopyControl* ptr = new CopyControl("Test");
        CopyControlSolutions* sol_ptr = new CopyControlSolutions("Test");
        // Objects should be properly destructed when deleted
        delete ptr;
        delete sol_ptr;
    }
    // If we reach here without issues, destructor worked
    SUCCEED();
}

// Test accessor methods
TEST_F(CopyControlBasicsTest, TestAccessors) {
    std::string test_str = "Accessor Test";
    CopyControl ex(test_str);
    CopyControlSolutions sol(test_str);
    
    EXPECT_EQ(ex.get_size(), test_str.size());
    EXPECT_EQ(sol.get_size(), test_str.size());
    // Add more assertions as needed
}

// Test modifier methods
TEST_F(CopyControlBasicsTest, TestModifiers) {
    std::string initial_str = "Initial";
    std::string new_str = "New Value";
    
    CopyControl ex(initial_str);
    ex.set_data(new_str);
    
    CopyControlSolutions sol(initial_str);
    sol.set_data(new_str);
    
    EXPECT_EQ(ex.get_size(), new_str.size());
    EXPECT_EQ(sol.get_size(), new_str.size());
    // Add more assertions as needed
}

// Test utility methods
TEST_F(CopyControlBasicsTest, TestUtilities) {
    CopyControl ex;
    CopyControlSolutions sol;
    
    EXPECT_TRUE(ex.empty());
    EXPECT_TRUE(sol.empty());
    
    std::string test_str = "Not Empty";
    ex.set_data(test_str);
    sol.set_data(test_str);
    
    EXPECT_FALSE(ex.empty());
    EXPECT_FALSE(sol.empty());
    
    ex.clear();
    sol.clear();
    
    EXPECT_TRUE(ex.empty());
    EXPECT_TRUE(sol.empty());
}

} // namespace cpp_primer