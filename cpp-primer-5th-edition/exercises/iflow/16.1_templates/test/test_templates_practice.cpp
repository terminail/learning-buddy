#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <streambuf>
#include "templates_exercises.h"
#include "templates_solutions.h"

namespace cpp_primer {

// Test fixture for Templates practice exercises
class TemplatesPracticeTest : public ::testing::Test {
protected:
    // No specific setup needed for this test fixture
};

// Test variadic template functions
TEST_F(TemplatesPracticeTest, TestVariadicTemplateFunctions) {
    // Capture std::cout output for testing
    std::stringstream ex_buffer;
    std::streambuf* ex_orig_cout = std::cout.rdbuf(ex_buffer.rdbuf());
    
    std::stringstream sol_buffer;
    std::streambuf* sol_orig_cout = std::cout.rdbuf(sol_buffer.rdbuf());
    
    // Test print with single value
    print(42);
    print(42);
    
    std::cout.rdbuf(ex_orig_cout);  // Restore original buffer
    std::cout.rdbuf(sol_orig_cout); // Restore original buffer
    
    // Check that output was produced (we can't easily compare the exact output)
    EXPECT_FALSE(ex_buffer.str().empty());
    EXPECT_FALSE(sol_buffer.str().empty());
    
    // Test print with multiple values
    ex_buffer.str("");  // Clear buffer
    sol_buffer.str(""); // Clear buffer
    
    ex_orig_cout = std::cout.rdbuf(ex_buffer.rdbuf());
    sol_orig_cout = std::cout.rdbuf(sol_buffer.rdbuf());
    
    print(1, 2.5, "hello", 'c');
    print(1, 2.5, "hello", 'c');
    
    std::cout.rdbuf(ex_orig_cout);  // Restore original buffer
    std::cout.rdbuf(sol_orig_cout); // Restore original buffer
    
    // Check that output was produced
    EXPECT_FALSE(ex_buffer.str().empty());
    EXPECT_FALSE(sol_buffer.str().empty());
}

// Test Wrapper class template with type traits
TEST_F(TemplatesPracticeTest, TestWrapperClassTemplate) {
    // Test Wrapper with arithmetic type (int)
    Wrapper<int> ex_int_wrapper(5);
    WrapperSolutions<int> sol_int_wrapper(5);
    
    EXPECT_EQ(ex_int_wrapper.get_value(), 5);
    EXPECT_EQ(sol_int_wrapper.get_value(), 5);
    
    // Test get_squared (only available for arithmetic types)
    EXPECT_EQ(ex_int_wrapper.get_squared(), 25);
    EXPECT_EQ(sol_int_wrapper.get_squared(), 25);
    
    // Test multiply_by (only available for arithmetic types)
    ex_int_wrapper.multiply_by(3);
    sol_int_wrapper.multiply_by(3);
    
    EXPECT_EQ(ex_int_wrapper.get_value(), 15);
    EXPECT_EQ(sol_int_wrapper.get_value(), 15);
    
    // Test Wrapper with string type
    Wrapper<std::string> ex_string_wrapper("hello");
    WrapperSolutions<std::string> sol_string_wrapper("hello");
    
    EXPECT_EQ(ex_string_wrapper.get_value(), "hello");
    EXPECT_EQ(sol_string_wrapper.get_value(), "hello");
    
    // Test append (only available for string type)
    ex_string_wrapper.append(" world");
    sol_string_wrapper.append(" world");
    
    EXPECT_EQ(ex_string_wrapper.get_value(), "hello world");
    EXPECT_EQ(sol_string_wrapper.get_value(), "hello world");
    
    // Test setters
    ex_int_wrapper.set_value(100);
    sol_int_wrapper.set_value(100);
    
    EXPECT_EQ(ex_int_wrapper.get_value(), 100);
    EXPECT_EQ(sol_int_wrapper.get_value(), 100);
    
    ex_string_wrapper.set_value("new value");
    sol_string_wrapper.set_value("new value");
    
    EXPECT_EQ(ex_string_wrapper.get_value(), "new value");
    EXPECT_EQ(sol_string_wrapper.get_value(), "new value");
}

// Test comprehensive template scenarios
TEST_F(TemplatesPracticeTest, TestComprehensiveTemplateScenarios) {
    // Test Stack with various types
    Stack<double> ex_double_stack;
    StackSolutions<double> sol_double_stack;
    
    // Push several values
    for (int i = 1; i <= 5; ++i) {
        ex_double_stack.push(i * 1.5);
        sol_double_stack.push(i * 1.5);
    }
    
    EXPECT_EQ(ex_double_stack.size(), 5);
    EXPECT_EQ(sol_double_stack.size(), 5);
    
    // Check values in LIFO order
    for (int i = 5; i >= 1; --i) {
        double expected = i * 1.5;
        EXPECT_DOUBLE_EQ(ex_double_stack.top(), expected);
        EXPECT_DOUBLE_EQ(sol_double_stack.top(), expected);
        ex_double_stack.pop();
        sol_double_stack.pop();
    }
    
    EXPECT_TRUE(ex_double_stack.empty());
    EXPECT_TRUE(sol_double_stack.empty());
    
    // Test Pair with complex types
    Pair<std::vector<int>, std::string> ex_complex_pair({1, 2, 3}, "numbers");
    PairSolutions<std::vector<int>, std::string> sol_complex_pair({1, 2, 3}, "numbers");
    
    auto ex_first = ex_complex_pair.get_first();
    auto sol_first = sol_complex_pair.get_first();
    
    EXPECT_EQ(ex_first.size(), 3);
    EXPECT_EQ(sol_first.size(), 3);
    
    EXPECT_EQ(ex_first[0], 1);
    EXPECT_EQ(ex_first[1], 2);
    EXPECT_EQ(ex_first[2], 3);
    
    EXPECT_EQ(sol_first[0], 1);
    EXPECT_EQ(sol_first[1], 2);
    EXPECT_EQ(sol_first[2], 3);
    
    EXPECT_EQ(ex_complex_pair.get_second(), "numbers");
    EXPECT_EQ(sol_complex_pair.get_second(), "numbers");
    
    // Test algorithm templates with complex data
    std::vector<std::string> ex_string_vec = {"apple", "banana", "cherry"};
    std::vector<std::string> sol_string_vec = {"apple", "banana", "cherry"};
    
    // Find element
    auto ex_string_it = find(ex_string_vec.begin(), ex_string_vec.end(), "banana");
    auto sol_string_it = find(sol_string_vec.begin(), sol_string_vec.end(), "banana");
    
    EXPECT_NE(ex_string_it, ex_string_vec.end());
    EXPECT_NE(sol_string_it, sol_string_vec.end());
    
    EXPECT_EQ(*ex_string_it, "banana");
    EXPECT_EQ(*sol_string_it, "banana");
    
    // Apply function to each element (convert to uppercase)
    auto uppercase_lambda = [](std::string& s) {
        for (auto& c : s) {
            c = std::toupper(c);
        }
    };
    
    for_each(ex_string_vec.begin(), ex_string_vec.end(), uppercase_lambda);
    for_each(sol_string_vec.begin(), sol_string_vec.end(), uppercase_lambda);
    
    EXPECT_EQ(ex_string_vec[0], "APPLE");
    EXPECT_EQ(ex_string_vec[1], "BANANA");
    EXPECT_EQ(ex_string_vec[2], "CHERRY");
    
    EXPECT_EQ(sol_string_vec[0], "APPLE");
    EXPECT_EQ(sol_string_vec[1], "BANANA");
    EXPECT_EQ(sol_string_vec[2], "CHERRY");
}

// Test template specialization differences
TEST_F(TemplatesPracticeTest, TestTemplateSpecializationDifferences) {
    // Compare regular Stack<int> with specialized Stack<bool>
    Stack<int> ex_int_stack;
    Stack<bool> ex_bool_stack;
    
    StackSolutions<int> sol_int_stack;
    StackSolutions<bool> sol_bool_stack;
    
    // Push values to int stack
    ex_int_stack.push(1);
    ex_int_stack.push(0);
    ex_int_stack.push(1);
    
    sol_int_stack.push(1);
    sol_int_stack.push(0);
    sol_int_stack.push(1);
    
    // Push values to bool stack
    ex_bool_stack.push(true);
    ex_bool_stack.push(false);
    ex_bool_stack.push(true);
    
    sol_bool_stack.push(true);
    sol_bool_stack.push(false);
    sol_bool_stack.push(true);
    
    // Both should work correctly
    EXPECT_EQ(ex_int_stack.size(), 3);
    EXPECT_EQ(sol_int_stack.size(), 3);
    
    EXPECT_EQ(ex_bool_stack.size(), 3);
    EXPECT_EQ(sol_bool_stack.size(), 3);
    
    // Check top values
    EXPECT_EQ(ex_int_stack.top(), 1);
    EXPECT_EQ(sol_int_stack.top(), 1);
    
    EXPECT_TRUE(ex_bool_stack.top());
    EXPECT_TRUE(sol_bool_stack.top());
    
    // Pop and check again
    ex_int_stack.pop();
    sol_int_stack.pop();
    ex_bool_stack.pop();
    sol_bool_stack.pop();
    
    EXPECT_EQ(ex_int_stack.top(), 0);
    EXPECT_EQ(sol_int_stack.top(), 0);
    
    EXPECT_FALSE(ex_bool_stack.top());
    EXPECT_FALSE(sol_bool_stack.top());
}

// Test advanced template features
TEST_F(TemplatesPracticeTest, TestAdvancedTemplateFeatures) {
    // Test max function with custom types
    struct Point {
        int x, y;
        bool operator>(const Point& other) const {
            return (x * x + y * y) > (other.x * other.x + other.y * other.y);
        }
    };
    
    Point p1{3, 4}; // distance squared = 25
    Point p2{5, 0}; // distance squared = 25
    
    // These points have the same distance, so max should return the second one (p2)
    Point result = max(p1, p2);
    Point sol_result = max(p1, p2);
    
    EXPECT_EQ(result.x, 5);
    EXPECT_EQ(result.y, 0);
    
    EXPECT_EQ(sol_result.x, 5);
    EXPECT_EQ(sol_result.y, 0);
    
    // Test sum with custom iterator
    struct CustomIterator {
        int* ptr;
        CustomIterator(int* p) : ptr(p) {}
        int& operator*() { return *ptr; }
        CustomIterator& operator++() { ++ptr; return *this; }
        bool operator!=(const CustomIterator& other) const { return ptr != other.ptr; }
    };
    
    int arr[] = {10, 20, 30};
    auto ex_sum_result = sum(CustomIterator(arr), CustomIterator(arr + 3));
    auto sol_sum_result = sum(CustomIterator(arr), CustomIterator(arr + 3));
    
    EXPECT_EQ(ex_sum_result, 60);
    EXPECT_EQ(sol_sum_result, 60);
    
    // Test Wrapper with custom arithmetic type
    Wrapper<float> ex_float_wrapper(3.5f);
    WrapperSolutions<float> sol_float_wrapper(3.5f);
    
    EXPECT_FLOAT_EQ(ex_float_wrapper.get_value(), 3.5f);
    EXPECT_FLOAT_EQ(sol_float_wrapper.get_value(), 3.5f);
    
    EXPECT_FLOAT_EQ(ex_float_wrapper.get_squared(), 12.25f);
    EXPECT_FLOAT_EQ(sol_float_wrapper.get_squared(), 12.25f);
    
    ex_float_wrapper.multiply_by(2.0f);
    sol_float_wrapper.multiply_by(2.0f);
    
    EXPECT_FLOAT_EQ(ex_float_wrapper.get_value(), 7.0f);
    EXPECT_FLOAT_EQ(sol_float_wrapper.get_value(), 7.0f);
}

// Test complex scenario combining multiple template concepts
TEST_F(TemplatesPracticeTest, TestComplexTemplateScenario) {
    // Create a vector of different types of Stacks
    std::vector<Stack<int>> ex_int_stacks(3);
    std::vector<StackSolutions<int>> sol_int_stacks(3);
    
    // Fill each stack with different data
    for (size_t i = 0; i < ex_int_stacks.size(); ++i) {
        for (int j = 1; j <= static_cast<int>(i + 1); ++j) {
            ex_int_stacks[i].push(j * 10);
            sol_int_stacks[i].push(j * 10);
        }
    }
    
    // Verify each stack has the correct data
    for (size_t i = 0; i < ex_int_stacks.size(); ++i) {
        EXPECT_EQ(ex_int_stacks[i].size(), i + 1);
        EXPECT_EQ(sol_int_stacks[i].size(), i + 1);
        
        // Check top value
        EXPECT_EQ(ex_int_stacks[i].top(), static_cast<int>(i + 1) * 10);
        EXPECT_EQ(sol_int_stacks[i].top(), static_cast<int>(i + 1) * 10);
    }
    
    // Create Pairs of Stacks
    Pair<Stack<int>, Stack<double>> ex_stack_pair;
    PairSolutions<Stack<int>, Stack<double>> sol_stack_pair;
    
    // Fill the stacks in the pair
    for (int i = 1; i <= 3; ++i) {
        ex_stack_pair.get_first().push(i);
        ex_stack_pair.get_second().push(i * 1.5);
        
        sol_stack_pair.get_first().push(i);
        sol_stack_pair.get_second().push(i * 1.5);
    }
    
    // Verify the stacks in the pair
    EXPECT_EQ(ex_stack_pair.get_first().size(), 3);
    EXPECT_EQ(ex_stack_pair.get_second().size(), 3);
    
    EXPECT_EQ(sol_stack_pair.get_first().size(), 3);
    EXPECT_EQ(sol_stack_pair.get_second().size(), 3);
    
    EXPECT_EQ(ex_stack_pair.get_first().top(), 3);
    EXPECT_DOUBLE_EQ(ex_stack_pair.get_second().top(), 4.5);
    
    EXPECT_EQ(sol_stack_pair.get_first().top(), 3);
    EXPECT_DOUBLE_EQ(sol_stack_pair.get_second().top(), 4.5);
    
    // Use algorithm templates on containers of custom types
    std::vector<Pair<int, std::string>> ex_pair_vec;
    std::vector<PairSolutions<int, std::string>> sol_pair_vec;
    
    ex_pair_vec.emplace_back(1, "one");
    ex_pair_vec.emplace_back(2, "two");
    ex_pair_vec.emplace_back(3, "three");
    
    sol_pair_vec.emplace_back(1, "one");
    sol_pair_vec.emplace_back(2, "two");
    sol_pair_vec.emplace_back(3, "three");
    
    // Sum the first elements of the pairs
    auto ex_sum_lambda = [](const Pair<int, std::string>& p) { return p.get_first(); };
    auto sol_sum_lambda = [](const PairSolutions<int, std::string>& p) { return p.get_first(); };
    
    int ex_total = 0;
    int sol_total = 0;
    
    for (const auto& p : ex_pair_vec) {
        ex_total += ex_sum_lambda(p);
    }
    
    for (const auto& p : sol_pair_vec) {
        sol_total += sol_sum_lambda(p);
    }
    
    EXPECT_EQ(ex_total, 6);  // 1 + 2 + 3 = 6
    EXPECT_EQ(sol_total, 6); // 1 + 2 + 3 = 6
    
    // Test with Wrapper containing a Stack
    Wrapper<Stack<int>> ex_wrapper_stack;
    WrapperSolutions<Stack<int>> sol_wrapper_stack;
    
    // Push values to the stack inside the wrapper
    for (int i = 1; i <= 4; ++i) {
        ex_wrapper_stack.get_value().push(i * 5);
        sol_wrapper_stack.get_value().push(i * 5);
    }
    
    // Verify the stack inside the wrapper
    EXPECT_EQ(ex_wrapper_stack.get_value().size(), 4);
    EXPECT_EQ(sol_wrapper_stack.get_value().size(), 4);
    
    EXPECT_EQ(ex_wrapper_stack.get_value().top(), 20);
    EXPECT_EQ(sol_wrapper_stack.get_value().top(), 20);
}

} // namespace cpp_primer