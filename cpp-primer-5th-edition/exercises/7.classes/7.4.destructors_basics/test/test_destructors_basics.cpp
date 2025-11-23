#include <gtest/gtest.h>
#include <string>

// Simple class for testing destructors
class TestClass {
private:
    static int instanceCount;
    std::string name;
    
public:
    // Constructor
    TestClass(const std::string& n) : name(n) {
        instanceCount++;
    }
    
    // Destructor
    ~TestClass() {
        instanceCount--;
    }
    
    static int getInstanceCount() { return instanceCount; }
    std::string getName() const { return name; }
};

// Initialize static member
int TestClass::instanceCount = 0;

// Test destructor is called
TEST(DestructorsTest, DestructorCalled) {
    int initialCount = TestClass::getInstanceCount();
    
    {
        TestClass obj("test");
        EXPECT_EQ(initialCount + 1, TestClass::getInstanceCount());
    } // obj goes out of scope, destructor called
    
    EXPECT_EQ(initialCount, TestClass::getInstanceCount());
}

// Test multiple objects
TEST(DestructorsTest, MultipleObjects) {
    int initialCount = TestClass::getInstanceCount();
    
    {
        TestClass obj1("obj1");
        TestClass obj2("obj2");
        TestClass obj3("obj3");
        EXPECT_EQ(initialCount + 3, TestClass::getInstanceCount());
    } // All objects go out of scope, destructors called
    
    EXPECT_EQ(initialCount, TestClass::getInstanceCount());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}