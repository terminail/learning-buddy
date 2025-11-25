// Exercise: Access Control - Solution
// This exercise demonstrates access specifiers in C++ classes.

#include <iostream>
#include <string>

// Solution: Define a class with public members
class PublicClass {
public:
    std::string name;  // Public data member
    int value;         // Public data member
    
    // Public member functions
    void display() {
        std::cout << "Name: " << name << ", Value: " << value << std::endl;
    }
    
    void setName(const std::string& n) { name = n; }
    void setValue(int v) { value = v; }
};

// Solution: Define a class with private members
class PrivateClass {
private:
    std::string name;  // Private data member
    int value;         // Private data member
    
public:
    // Public member functions to access private data
    void display() const {
        std::cout << "Name: " << name << ", Value: " << value << std::endl;
    }
    
    // Getters
    std::string getName() const { return name; }
    int getValue() const { return value; }
    
    // Setters
    void setName(const std::string& n) { name = n; }
    void setValue(int v) { 
        if (v >= 0) {  // Validation
            value = v; 
        }
    }
};

// Solution: Define a class with protected members
class BaseClass {
protected:
    std::string protectedData;  // Protected member - accessible in derived classes
    int protectedValue;
    
private:
    std::string privateData;    // Private member - not accessible in derived classes
    
public:
    BaseClass(const std::string& data, int value) 
        : protectedData(data), protectedValue(value), privateData("private") {}
    
    std::string getPrivateData() const { return privateData; }
    std::string getProtectedData() const { return protectedData; }
    int getProtectedValue() const { return protectedValue; }
};

class DerivedClass : public BaseClass {
public:
    DerivedClass(const std::string& data, int value) : BaseClass(data, value) {}
    
    void displayProtected() {
        // Can access protected members from base class
        std::cout << "Protected data: " << protectedData << std::endl;
        std::cout << "Protected value: " << protectedValue << std::endl;
        // Cannot access privateData directly - would cause compilation error
        // std::cout << "Private data: " << privateData << std::endl;  // Error!
    }
    
    void accessBasePrivate() {
        // Must use public interface to access private members of base class
        std::cout << "Base private data (via public method): " << getPrivateData() << std::endl;
    }
};

// Solution: Friend function
class FriendClass {
private:
    std::string secret;
    int number;
    
public:
    FriendClass(const std::string& s, int n) : secret(s), number(n) {}
    
    // Friend function declaration
    friend void displayFriendClass(const FriendClass& fc);
    
    // Friend class declaration
    friend class TrustedClass;
    
    std::string getSecret() const { return secret; }
    int getNumber() const { return number; }
};

// Friend function implementation - can access private members
void displayFriendClass(const FriendClass& fc) {
    std::cout << "Friend function accessing private members:" << std::endl;
    std::cout << "Secret: " << fc.secret << ", Number: " << fc.number << std::endl;
}

// Friend class - all member functions can access private members of FriendClass
class TrustedClass {
public:
    void accessFriendClass(const FriendClass& fc) {
        std::cout << "TrustedClass accessing FriendClass private members:" << std::endl;
        std::cout << "Secret: " << fc.secret << ", Number: " << fc.number << std::endl;
    }
};

int main() {
    // Solution: Create objects and test access control
    
    // Public class - direct access to members
    std::cout << "=== Public Class ===" << std::endl;
    PublicClass publicObj;
    publicObj.name = "Public Object";
    publicObj.value = 42;
    publicObj.display();
    
    std::cout << std::endl;
    
    // Private class - controlled access through getters/setters
    std::cout << "=== Private Class ===" << std::endl;
    PrivateClass privateObj;
    privateObj.setName("Private Object");
    privateObj.setValue(99);
    privateObj.display();
    
    std::cout << "Accessing through getters:" << std::endl;
    std::cout << "Name: " << privateObj.getName() << std::endl;
    std::cout << "Value: " << privateObj.getValue() << std::endl;
    
    std::cout << std::endl;
    
    // Inheritance and access control
    std::cout << "=== Inheritance and Access Control ===" << std::endl;
    DerivedClass derivedObj("Derived Data", 123);
    derivedObj.displayProtected();
    derivedObj.accessBasePrivate();
    
    std::cout << std::endl;
    
    // Friend functions and classes
    std::cout << "=== Friend Functions and Classes ===" << std::endl;
    FriendClass friendObj("Secret Data", 777);
    
    // Friend function can access private members
    displayFriendClass(friendObj);
    
    // Friend class can access private members
    TrustedClass trustedObj;
    trustedObj.accessFriendClass(friendObj);
    
    return 0;
}