#include <gtest/gtest.h>

// Practice Problem 1: Variadic templates
TEST(FunctionTemplatesPracticeTest, VariadicTemplates) {
    // Practice: Implement variadic templates for functions with variable arguments
    SUCCEED() << "Practice: Create functions that accept variable number of arguments";
}

// Practice Problem 2: Template metaprogramming
TEST(FunctionTemplatesPracticeTest, TemplateMetaprogramming) {
    // Practice: Use templates for compile-time computations
    SUCCEED() << "Practice: Implement compile-time calculations with templates";
}

// Practice Problem 3: SFINAE (Substitution Failure Is Not An Error)
TEST(FunctionTemplatesPracticeTest, SFINAE) {
    // Practice: Use SFINAE for type checking and function overloading
    SUCCEED() << "Practice: Implement type traits with SFINAE";
}

// Practice Problem 4: Perfect forwarding
TEST(FunctionTemplatesPracticeTest, PerfectForwarding) {
    // Practice: Implement perfect forwarding with std::forward
    SUCCEED() << "Practice: Create functions that perfectly forward arguments";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}