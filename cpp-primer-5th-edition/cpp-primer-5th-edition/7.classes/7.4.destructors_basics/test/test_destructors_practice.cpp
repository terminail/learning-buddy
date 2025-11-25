#include <gtest/gtest.h>
#include <string>

// Class with resource management for practice
class ResourceClass {
private:
    static int allocationCount;
    int* data;
    size_t size;
    
public:
    // Constructor
    ResourceClass(size_t s) : size(s) {
        data = new int[size];
        allocationCount++;
        for (size_t i = 0; i < size; i++) {
            data[i] = static_cast<int>(i);
        }
    }
    
    // Destructor - properly clean up resources
    ~ResourceClass() {
        delete[] data;
        allocationCount--;
    }
    
    // Copy constructor (Rule of Three)
    ResourceClass(const ResourceClass& other) : size(other.size) {
        data = new int[size];
        for (size_t i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
        allocationCount++;
    }
    
    // Getters
    size_t getSize() const { return size; }
    int getValue(size_t index) const { return data[index]; }
    
    static int getAllocationCount() { return allocationCount; }
};

// Initialize static member
int ResourceClass::allocationCount = 0;

// Practice test for resource management
TEST(DestructorsPractice, ResourceManager) {
    int initialAllocations = ResourceClass::getAllocationCount();
    
    {
        ResourceClass obj1(10);
        EXPECT_EQ(initialAllocations + 1, ResourceClass::getAllocationCount());
        
        {
            ResourceClass obj2(5);
            ResourceClass obj3 = obj1; // Copy constructor
            EXPECT_EQ(initialAllocations + 3, ResourceClass::getAllocationCount());
            
            EXPECT_EQ(10, obj1.getSize());
            EXPECT_EQ(5, obj2.getSize());
            EXPECT_EQ(10, obj3.getSize());
            
            EXPECT_EQ(0, obj1.getValue(0));
            EXPECT_EQ(4, obj2.getValue(4));
            EXPECT_EQ(9, obj3.getValue(9));
        } // obj2 and obj3 destructors called
        
        EXPECT_EQ(initialAllocations + 1, ResourceClass::getAllocationCount());
    } // obj1 destructor called
    
    EXPECT_EQ(initialAllocations, ResourceClass::getAllocationCount());
}

// Practice test for exception safety
TEST(DestructorsPractice, ExceptionSafety) {
    class ExceptionSafeClass {
    private:
        std::string* resource;
        
    public:
        ExceptionSafeClass() : resource(new std::string("safe")) {}
        
        // Destructor should not throw exceptions
        ~ExceptionSafeClass() {
            delete resource;
            // Never throw exceptions from destructors!
        }
        
        std::string getResource() const { return *resource; }
    };
    
    ExceptionSafeClass obj;
    EXPECT_EQ("safe", obj.getResource());
    // Destructor will be called safely when obj goes out of scope
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}