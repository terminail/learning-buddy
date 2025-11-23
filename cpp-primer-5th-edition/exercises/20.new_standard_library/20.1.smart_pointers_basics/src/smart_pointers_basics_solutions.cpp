#include <iostream>
#include <memory>
#include <string>

// Simple class to demonstrate constructor/destructor calls
class DemoClass {
public:
    DemoClass(const std::string& name) : name_(name) {
        std::cout << "DemoClass constructed: " << name_ << std::endl;
    }
    
    ~DemoClass() {
        std::cout << "DemoClass destructed: " << name_ << std::endl;
    }
    
    void setName(const std::string& name) { name_ = name; }
    const std::string& getName() const { return name_; }
    
private:
    std::string name_;
};

// Solution: Work with std::unique_ptr for exclusive ownership
void unique_ptr_exercises() {
    std::cout << "=== Unique Pointer Exercises ===" << std::endl;
    
    // Solution 1: Create a std::unique_ptr to an integer
    auto ptr1 = std::make_unique<int>(42);
    std::cout << "Value: " << *ptr1 << std::endl;
    *ptr1 = 100;
    std::cout << "Modified value: " << *ptr1 << std::endl;
    
    // Solution 2: Transfer ownership of a unique_ptr
    auto ptr2 = std::move(ptr1);
    std::cout << "ptr2 value: " << *ptr2 << std::endl;
    std::cout << "ptr1 is " << (ptr1 ? "not null" : "null") << std::endl;
    
    // Solution 3: Create a unique_ptr to a custom object
    {
        auto obj_ptr = std::make_unique<DemoClass>("UniqueObject");
        obj_ptr->setName("ModifiedUniqueObject");
        std::cout << "Object name: " << obj_ptr->getName() << std::endl;
        // Destructor will be called when obj_ptr goes out of scope
    }
    
    // Solution 4: Use unique_ptr with arrays
    auto array_ptr = std::make_unique<int[]>(5);
    for (int i = 0; i < 5; ++i) {
        array_ptr[i] = i * 10;
    }
    std::cout << "Array elements: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << array_ptr[i] << " ";
    }
    std::cout << std::endl;
}

// Solution: Work with std::shared_ptr for shared ownership
void shared_ptr_exercises() {
    std::cout << "\n=== Shared Pointer Exercises ===" << std::endl;
    
    // Solution 1: Create a std::shared_ptr to a string
    auto shared1 = std::make_shared<std::string>("Hello World");
    std::cout << "Value: " << *shared1 << std::endl;
    std::cout << "Reference count: " << shared1.use_count() << std::endl;
    
    // Solution 2: Share ownership with multiple shared_ptr instances
    {
        auto shared2 = shared1;
        std::cout << "Reference count after sharing: " << shared1.use_count() << std::endl;
        
        auto shared3 = shared1;
        std::cout << "Reference count with 3 pointers: " << shared1.use_count() << std::endl;
        
        // shared2 and shared3 will be destroyed here, decrementing reference count
    }
    std::cout << "Reference count after scope exit: " << shared1.use_count() << std::endl;
    
    // Solution 3: Use shared_ptr with custom objects
    {
        std::cout << "Creating shared object:" << std::endl;
        auto obj_shared = std::make_shared<DemoClass>("SharedObject");
        std::cout << "Reference count: " << obj_shared.use_count() << std::endl;
        
        {
            auto another_shared = obj_shared;
            std::cout << "Reference count with 2 pointers: " << obj_shared.use_count() << std::endl;
        }
        std::cout << "Reference count after inner scope: " << obj_shared.use_count() << std::endl;
        // Object will be destroyed when obj_shared goes out of scope
    }
    
    // Solution 4: Compare performance of make_shared vs shared_ptr constructor
    // make_shared allocates memory for both the object and control block in one allocation
    auto efficient_shared = std::make_shared<DemoClass>("EfficientShared");
    // Regular constructor allocates memory separately for object and control block
    std::shared_ptr<DemoClass> regular_shared(new DemoClass("RegularShared"));
}

// Solution: Practice with factory functions
void factory_function_exercises() {
    std::cout << "\n=== Factory Function Exercises ===" << std::endl;
    
    // Solution 1: Use std::make_unique
    auto unique_int = std::make_unique<int>(42);
    auto unique_string = std::make_unique<std::string>("Hello", 3); // "Hel"
    std::cout << "Unique int: " << *unique_int << std::endl;
    std::cout << "Unique string: " << *unique_string << std::endl;
    
    // Solution 2: Use std::make_shared
    auto shared_int = std::make_shared<int>(42);
    auto shared_string = std::make_shared<std::string>(5, 'A'); // "AAAAA"
    std::cout << "Shared int: " << *shared_int << std::endl;
    std::cout << "Shared string: " << *shared_string << std::endl;
    
    // Solution 3: Work with custom classes and factory functions
    auto demo1 = std::make_unique<DemoClass>("FactoryUnique");
    auto demo2 = std::make_shared<DemoClass>("FactoryShared");
    
    // Exception safety example
    // make_unique provides exception safety because it's a single operation
    // If an exception occurs during construction, no memory leak occurs
}

int main() {
    std::cout << "Chapter 20.1: Smart Pointers Basics Solution" << std::endl;
    std::cout << "============================================" << std::endl;
    
    unique_ptr_exercises();
    shared_ptr_exercises();
    factory_function_exercises();
    
    std::cout << "\nSolution completed!" << std::endl;
    return 0;
}