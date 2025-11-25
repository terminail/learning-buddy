#include <gtest/gtest.h>
#include <string>

// Create test namespaces
namespace TestCompany {
    namespace DepartmentA {
        int getValue() {
            return 42;
        }
        
        class TestClass {
        public:
            std::string getName() const {
                return "DepartmentA::TestClass";
            }
        };
    }
    
    namespace DepartmentB {
        int getValue() {
            return 100;
        }
        
        class TestClass {
        public:
            std::string getName() const {
                return "DepartmentB::TestClass";
            }
        };
    }
}

// Test for nested namespaces
TEST(NamespacesTest, NestedNamespaces) {
    EXPECT_EQ(TestCompany::DepartmentA::getValue(), 42);
    EXPECT_EQ(TestCompany::DepartmentB::getValue(), 100);
    
    TestCompany::DepartmentA::TestClass objA;
    TestCompany::DepartmentB::TestClass objB;
    
    EXPECT_EQ(objA.getName(), "DepartmentA::TestClass");
    EXPECT_EQ(objB.getName(), "DepartmentB::TestClass");
}

// Test for namespace aliases
TEST(NamespacesTest, NamespaceAliases) {
    namespace DA = TestCompany::DepartmentA;
    namespace DB = TestCompany::DepartmentB;
    
    EXPECT_EQ(DA::getValue(), 42);
    EXPECT_EQ(DB::getValue(), 100);
    
    DA::TestClass objA;
    DB::TestClass objB;
    
    EXPECT_EQ(objA.getName(), "DepartmentA::TestClass");
    EXPECT_EQ(objB.getName(), "DepartmentB::TestClass");
}

// Test for namespace scope resolution
TEST(NamespacesTest, ScopeResolution) {
    // Test that we can access nested namespace members correctly
    EXPECT_EQ(TestCompany::DepartmentA::getValue(), 42);
    EXPECT_EQ(TestCompany::DepartmentB::getValue(), 100);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}