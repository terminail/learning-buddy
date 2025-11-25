#include <gtest/gtest.h>
#include <string>

// Test copy initialization
TEST(VariableInitializationTest, CopyInitialization) {
    int copyInit = 42;
    double copyInitDouble = 3.14;
    std::string copyInitString = "test";
    
    EXPECT_EQ(42, copyInit);
    EXPECT_DOUBLE_EQ(3.14, copyInitDouble);
    EXPECT_EQ("test", copyInitString);
}

// Test direct initialization
TEST(VariableInitializationTest, DirectInitialization) {
    int directInit(100);
    double directInitDouble(2.718);
    std::string directInitString("direct");
    
    EXPECT_EQ(100, directInit);
    EXPECT_DOUBLE_EQ(2.718, directInitDouble);
    EXPECT_EQ("direct", directInitString);
}

// Test list initialization
TEST(VariableInitializationTest, ListInitialization) {
    int listInit{200};
    double listInitDouble{1.414};
    std::string listInitString{"list"};
    std::vector<int> listInitVector{1, 2, 3, 4, 5};
    
    EXPECT_EQ(200, listInit);
    EXPECT_DOUBLE_EQ(1.414, listInitDouble);
    EXPECT_EQ("list", listInitString);
    EXPECT_EQ(5, listInitVector.size());
    EXPECT_EQ(1, listInitVector[0]);
    EXPECT_EQ(5, listInitVector[4]);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}