#include <gtest/gtest.h>
#include <string>

// Simple implementation for testing
class TestResource {
private:
    std::string* data;
    static int destructorCount;

public:
    TestResource(const std::string& value) : data(new std::string(value)) {}
    
    ~TestResource() {
        delete data;
        destructorCount++;
    }
    
    const std::string& getData() const { return *data; }
    
    static int getDestructorCount() { return destructorCount; }
    static void resetDestructorCount() { destructorCount = 0; }
};

int TestResource::destructorCount = 0;

// Basic test for destructor
TEST(DestructorBasicsTest, BasicDestruction) {
    TestResource::resetDestructorCount();
    
    {
        TestResource obj("test");
        EXPECT_EQ(obj.getData(), "test");
    }
    
    // Destructor should have been called when obj went out of scope
    EXPECT_EQ(TestResource::getDestructorCount(), 1);
}

// Test multiple objects
TEST(DestructorBasicsTest, MultipleDestruction) {
    TestResource::resetDestructorCount();
    
    {
        TestResource obj1("test1");
        TestResource obj2("test2");
        TestResource obj3("test3");
    }
    
    // All three destructors should have been called
    EXPECT_EQ(TestResource::getDestructorCount(), 3);
}