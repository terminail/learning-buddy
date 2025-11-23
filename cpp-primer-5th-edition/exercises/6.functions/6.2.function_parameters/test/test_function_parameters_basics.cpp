#include <gtest/gtest.h>
#include <string>

// Test pass-by-value
TEST(FunctionParametersTest, PassByValue) {
    int value = 42;
    
    auto passByValue = [](int param) {
        param = 100;
        return param;
    };
    
    int result = passByValue(value);
    EXPECT_EQ(100, result);
    EXPECT_EQ(42, value);  // Original unchanged
}

// Test pass-by-reference
TEST(FunctionParametersTest, PassByReference) {
    int value = 42;
    
    auto passByReference = [](int& param) {
        param = 200;
    };
    
    passByReference(value);
    EXPECT_EQ(200, value);  // Original changed
}

// Test pass-by-pointer
TEST(FunctionParametersTest, PassByPointer) {
    int value = 42;
    
    auto passByPointer = [](int* param) {
        if (param != nullptr) {
            *param = 300;
        }
    };
    
    passByPointer(&value);
    EXPECT_EQ(300, value);  // Original changed
    
    // Test with null pointer
    passByPointer(nullptr);  // Should not crash
}

// Test const parameters
TEST(FunctionParametersTest, ConstParameters) {
    std::string message = "test";
    
    auto constParameter = [](const std::string& param) {
        // param = "modified";  // This would be a compilation error
        return param.length();
    };
    
    size_t length = constParameter(message);
    EXPECT_EQ(4, length);
    EXPECT_EQ("test", message);  // Original unchanged
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}