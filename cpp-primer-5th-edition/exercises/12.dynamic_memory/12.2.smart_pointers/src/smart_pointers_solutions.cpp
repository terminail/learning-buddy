// Exercise 12.1b: Smart Pointers - Solution
// This exercise demonstrates smart pointers in C++.

#include <iostream>
#include <memory>

int main() {
    // Use std::unique_ptr for single object management
    std::unique_ptr<int> unique_int = std::make_unique<int>(42);
    std::cout << "Unique pointer value: " << *unique_int << std::endl;
    // Automatic deallocation when unique_int goes out of scope
    
    // Use std::unique_ptr for array management
    std::unique_ptr<int[]> unique_array = std::make_unique<int[]>(5);
    for (int i = 0; i < 5; i++) {
        unique_array[i] = (i + 1) * 10;
    }
    std::cout << "Unique array elements: ";
    for (int i = 0; i < 5; i++) {
        std::cout << unique_array[i] << " ";
    }
    std::cout << std::endl;
    // Automatic deallocation when unique_array goes out of scope
    
    // Use std::shared_ptr for shared ownership
    std::shared_ptr<int> shared_int1 = std::make_shared<int>(100);
    std::cout << "Shared pointer value: " << *shared_int1 << std::endl;
    std::cout << "Reference count: " << shared_int1.use_count() << std::endl;
    
    {
        std::shared_ptr<int> shared_int2 = shared_int1; // Shared ownership
        std::cout << "Reference count after sharing: " << shared_int1.use_count() << std::endl;
        std::cout << "Shared pointer value from second reference: " << *shared_int2 << std::endl;
    } // shared_int2 goes out of scope here
    
    std::cout << "Reference count after second reference destroyed: " << shared_int1.use_count() << std::endl;
    // Automatic deallocation when all shared_ptr objects are destroyed
    
    return 0;
}