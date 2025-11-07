#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <sstream>
#include "templates_exercises.h"
#include "templates_solutions.h"

namespace cpp_primer {

// Test fixture for Templates exercises
class TemplatesBasicsTest : public ::testing::Test {
protected:
    // No specific setup needed for this test fixture
};

// Test function templates
TEST_F(TemplatesBasicsTest, TestFunctionTemplates) {
    // Test max function template
    EXPECT_EQ(max(5, 3), 5);
    EXPECT_EQ(max(2.5, 3.7), 3.7);
    EXPECT_EQ(max(std::string("abc"), std::string("def")), "def");
    
    EXPECT_EQ(max(5, 3), 5);
    EXPECT_EQ(max(2.5, 3.7), 3.7);
    EXPECT_EQ(max(std::string("abc"), std::string("def")), "def");
    
    // Test swap function template
    int a = 10, b = 20;
    swap(a, b);
    EXPECT_EQ(a, 20);
    EXPECT_EQ(b, 10);
    
    double x = 1.5, y = 2.5;
    swap(x, y);
    EXPECT_DOUBLE_EQ(x, 2.5);
    EXPECT_DOUBLE_EQ(y, 1.5);
    
    std::string s1 = "hello", s2 = "world";
    swap(s1, s2);
    EXPECT_EQ(s1, "world");
    EXPECT_EQ(s2, "hello");
    
    int sol_a = 10, sol_b = 20;
    swap(sol_a, sol_b);
    EXPECT_EQ(sol_a, 20);
    EXPECT_EQ(sol_b, 10);
    
    double sol_x = 1.5, sol_y = 2.5;
    swap(sol_x, sol_y);
    EXPECT_DOUBLE_EQ(sol_x, 2.5);
    EXPECT_DOUBLE_EQ(sol_y, 1.5);
    
    std::string sol_s1 = "hello", sol_s2 = "world";
    swap(sol_s1, sol_s2);
    EXPECT_EQ(sol_s1, "world");
    EXPECT_EQ(sol_s2, "hello");
}

// Test Stack class template
TEST_F(TemplatesBasicsTest, TestStackClassTemplate) {
    // Test Stack<int>
    Stack<int> ex_stack;
    StackSolutions<int> sol_stack;
    
    EXPECT_TRUE(ex_stack.empty());
    EXPECT_TRUE(sol_stack.empty());
    
    EXPECT_EQ(ex_stack.size(), 0);
    EXPECT_EQ(sol_stack.size(), 0);
    
    // Test push and top
    ex_stack.push(10);
    ex_stack.push(20);
    sol_stack.push(10);
    sol_stack.push(20);
    
    EXPECT_FALSE(ex_stack.empty());
    EXPECT_FALSE(sol_stack.empty());
    
    EXPECT_EQ(ex_stack.size(), 2);
    EXPECT_EQ(sol_stack.size(), 2);
    
    EXPECT_EQ(ex_stack.top(), 20);
    EXPECT_EQ(sol_stack.top(), 20);
    
    // Test pop
    ex_stack.pop();
    sol_stack.pop();
    
    EXPECT_EQ(ex_stack.size(), 1);
    EXPECT_EQ(sol_stack.size(), 1);
    
    EXPECT_EQ(ex_stack.top(), 10);
    EXPECT_EQ(sol_stack.top(), 10);
    
    // Test clear
    ex_stack.clear();
    sol_stack.clear();
    
    EXPECT_TRUE(ex_stack.empty());
    EXPECT_TRUE(sol_stack.empty());
    
    EXPECT_EQ(ex_stack.size(), 0);
    EXPECT_EQ(sol_stack.size(), 0);
    
    // Test Stack<std::string>
    Stack<std::string> ex_string_stack;
    StackSolutions<std::string> sol_string_stack;
    
    ex_string_stack.push("hello");
    ex_string_stack.push("world");
    sol_string_stack.push("hello");
    sol_string_stack.push("world");
    
    EXPECT_EQ(ex_string_stack.top(), "world");
    EXPECT_EQ(sol_string_stack.top(), "world");
    
    ex_string_stack.pop();
    sol_string_stack.pop();
    
    EXPECT_EQ(ex_string_stack.top(), "hello");
    EXPECT_EQ(sol_string_stack.top(), "hello");
}

// Test Pair class template
TEST_F(TemplatesBasicsTest, TestPairClassTemplate) {
    // Test Pair<int, double>
    Pair<int, double> ex_pair(5, 3.14);
    PairSolutions<int, double> sol_pair(5, 3.14);
    
    EXPECT_EQ(ex_pair.get_first(), 5);
    EXPECT_EQ(sol_pair.get_first(), 5);
    
    EXPECT_DOUBLE_EQ(ex_pair.get_second(), 3.14);
    EXPECT_DOUBLE_EQ(sol_pair.get_second(), 3.14);
    
    // Test setters
    ex_pair.set_first(10);
    ex_pair.set_second(2.71);
    sol_pair.set_first(10);
    sol_pair.set_second(2.71);
    
    EXPECT_EQ(ex_pair.get_first(), 10);
    EXPECT_EQ(sol_pair.get_first(), 10);
    
    EXPECT_DOUBLE_EQ(ex_pair.get_second(), 2.71);
    EXPECT_DOUBLE_EQ(sol_pair.get_second(), 2.71);
    
    // Test Pair<std::string, std::string>
    Pair<std::string, std::string> ex_string_pair("hello", "world");
    PairSolutions<std::string, std::string> sol_string_pair("hello", "world");
    
    EXPECT_EQ(ex_string_pair.get_first(), "hello");
    EXPECT_EQ(sol_string_pair.get_first(), "hello");
    
    EXPECT_EQ(ex_string_pair.get_second(), "world");
    EXPECT_EQ(sol_string_pair.get_second(), "world");
    
    // Test swap_pair (only works when both types are the same)
    Pair<int, int> ex_int_pair(1, 2);
    PairSolutions<int, int> sol_int_pair(1, 2);
    
    ex_int_pair.swap_pair();
    sol_int_pair.swap_pair();
    
    EXPECT_EQ(ex_int_pair.get_first(), 2);
    EXPECT_EQ(ex_int_pair.get_second(), 1);
    
    EXPECT_EQ(sol_int_pair.get_first(), 2);
    EXPECT_EQ(sol_int_pair.get_second(), 1);
}

// Test algorithm function templates
TEST_F(TemplatesBasicsTest, TestAlgorithmFunctionTemplates) {
    // Test sum function template
    std::vector<int> ex_vec = {1, 2, 3, 4, 5};
    std::vector<int> sol_vec = {1, 2, 3, 4, 5};
    
    auto ex_result = sum(ex_vec.begin(), ex_vec.end());
    auto sol_result = sum(sol_vec.begin(), sol_vec.end());
    
    EXPECT_EQ(ex_result, 15);
    EXPECT_EQ(sol_result, 15);
    
    // Test with doubles
    std::vector<double> ex_double_vec = {1.1, 2.2, 3.3};
    std::vector<double> sol_double_vec = {1.1, 2.2, 3.3};
    
    auto ex_double_result = sum(ex_double_vec.begin(), ex_double_vec.end());
    auto sol_double_result = sum(sol_double_vec.begin(), sol_double_vec.end());
    
    EXPECT_NEAR(ex_double_result, 6.6, 1e-9);
    EXPECT_NEAR(sol_double_result, 6.6, 1e-9);
    
    // Test find function template
    std::vector<int> ex_find_vec = {10, 20, 30, 40, 50};
    std::vector<int> sol_find_vec = {10, 20, 30, 40, 50};
    
    auto ex_it = find(ex_find_vec.begin(), ex_find_vec.end(), 30);
    auto sol_it = find(sol_find_vec.begin(), sol_find_vec.end(), 30);
    
    EXPECT_NE(ex_it, ex_find_vec.end());
    EXPECT_NE(sol_it, sol_find_vec.end());
    
    EXPECT_EQ(*ex_it, 30);
    EXPECT_EQ(*sol_it, 30);
    
    // Test with element not found
    auto ex_not_found = find(ex_find_vec.begin(), ex_find_vec.end(), 99);
    auto sol_not_found = find(sol_find_vec.begin(), sol_find_vec.end(), 99);
    
    EXPECT_EQ(ex_not_found, ex_find_vec.end());
    EXPECT_EQ(sol_not_found, sol_find_vec.end());
    
    // Test for_each function template
    std::vector<int> ex_foreach_vec = {1, 2, 3, 4, 5};
    std::vector<int> sol_foreach_vec = {1, 2, 3, 4, 5};
    
    // Lambda to square each element
    auto square_lambda = [](int& x) { x = x * x; };
    
    for_each(ex_foreach_vec.begin(), ex_foreach_vec.end(), square_lambda);
    for_each(sol_foreach_vec.begin(), sol_foreach_vec.end(), square_lambda);
    
    EXPECT_EQ(ex_foreach_vec[0], 1);
    EXPECT_EQ(ex_foreach_vec[1], 4);
    EXPECT_EQ(ex_foreach_vec[2], 9);
    EXPECT_EQ(ex_foreach_vec[3], 16);
    EXPECT_EQ(ex_foreach_vec[4], 25);
    
    EXPECT_EQ(sol_foreach_vec[0], 1);
    EXPECT_EQ(sol_foreach_vec[1], 4);
    EXPECT_EQ(sol_foreach_vec[2], 9);
    EXPECT_EQ(sol_foreach_vec[3], 16);
    EXPECT_EQ(sol_foreach_vec[4], 25);
}

// Test Stack<bool> specialization
TEST_F(TemplatesBasicsTest, TestStackBoolSpecialization) {
    Stack<bool> ex_bool_stack;
    StackSolutions<bool> sol_bool_stack;
    
    EXPECT_TRUE(ex_bool_stack.empty());
    EXPECT_TRUE(sol_bool_stack.empty());
    
    // Test push and top
    ex_bool_stack.push(true);
    ex_bool_stack.push(false);
    ex_bool_stack.push(true);
    sol_bool_stack.push(true);
    sol_bool_stack.push(false);
    sol_bool_stack.push(true);
    
    EXPECT_FALSE(ex_bool_stack.empty());
    EXPECT_FALSE(sol_bool_stack.empty());
    
    EXPECT_EQ(ex_bool_stack.size(), 3);
    EXPECT_EQ(sol_bool_stack.size(), 3);
    
    EXPECT_TRUE(ex_bool_stack.top());
    EXPECT_TRUE(sol_bool_stack.top());
    
    // Test pop
    ex_bool_stack.pop();
    sol_bool_stack.pop();
    
    EXPECT_FALSE(ex_bool_stack.top());
    EXPECT_FALSE(sol_bool_stack.top());
    
    ex_bool_stack.pop();
    sol_bool_stack.pop();
    
    EXPECT_TRUE(ex_bool_stack.top());
    EXPECT_TRUE(sol_bool_stack.top());
    
    // Test clear
    ex_bool_stack.clear();
    sol_bool_stack.clear();
    
    EXPECT_TRUE(ex_bool_stack.empty());
    EXPECT_TRUE(sol_bool_stack.empty());
}

} // namespace cpp_primer