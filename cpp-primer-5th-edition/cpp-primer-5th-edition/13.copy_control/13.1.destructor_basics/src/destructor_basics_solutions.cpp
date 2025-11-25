#include <iostream>
#include <string>
#include <vector>

// Solution: Implement a class with proper destructor
class ResourceHolder {
private:
    std::string* data;
    int id;
    static int nextId;

public:
    // Solution: Implement constructor
    ResourceHolder(const std::string& value) : data(new std::string(value)), id(nextId++) {
        std::cout << "Constructor called for object #" << id << " with data: " << *data << std::endl;
    }
    
    // Solution: Implement destructor
    ~ResourceHolder() {
        std::cout << "Destructor called for object #" << id << " with data: " << *data << std::endl;
        delete data;
    }
    
    // Solution: Implement getters for data and id (for testing)
    const std::string& getData() const { return *data; }
    int getId() const { return id; }
    
    // Solution: Implement a method to display object information
    void display() const {
        std::cout << "Object #" << id << ": " << *data << std::endl;
    }
};

int ResourceHolder::nextId = 0;

int main() {
    // Solution: Create objects and observe when destructors are called
    std::cout << "Creating stack object:" << std::endl;
    ResourceHolder obj1("Stack Object");
    
    std::cout << "\nCreating heap object:" << std::endl;
    ResourceHolder* obj2 = new ResourceHolder("Heap Object");
    
    std::cout << "\nCreating vector of objects:" << std::endl;
    std::vector<ResourceHolder> vec;
    vec.push_back(ResourceHolder("Vector Object 1"));
    vec.push_back(ResourceHolder("Vector Object 2"));
    
    std::cout << "\nAbout to delete heap object:" << std::endl;
    delete obj2;
    
    std::cout << "\nEnd of main - stack objects and vector will be destroyed:" << std::endl;
    
    return 0;
}