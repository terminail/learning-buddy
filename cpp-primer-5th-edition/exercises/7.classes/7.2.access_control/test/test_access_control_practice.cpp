#include <gtest/gtest.h>
#include <string>

// Base class for inheritance testing
class Base {
protected:
    std::string protectedData;
    int protectedValue;
    
private:
    std::string privateData;
    
public:
    Base(const std::string& prot, int protVal, const std::string& priv)
        : protectedData(prot), protectedValue(protVal), privateData(priv) {}
    
    std::string getPrivateData() const { return privateData; }
};

// Derived class for inheritance testing
class Derived : public Base {
public:
    Derived(const std::string& prot, int protVal, const std::string& priv)
        : Base(prot, protVal, priv) {}
    
    // Can access protected members from base class
    std::string getProtectedData() const { return protectedData; }
    int getProtectedValue() const { return protectedValue; }
    
    // Cannot access privateData directly - would be compilation error
};

// Class with friend function for practice
class FriendTest {
private:
    std::string secret;
    int number;
    
public:
    FriendTest(const std::string& s, int n) : secret(s), number(n) {}
    
    // Friend function declaration
    friend void accessFriendTest(const FriendTest& ft);
    
    std::string getSecret() const { return secret; }
    int getNumber() const { return number; }
};

// Friend function implementation
void accessFriendTest(const FriendTest& ft) {
    // Can access private members
    std::string secretCopy = ft.secret;
    int numberCopy = ft.number;
    // Use the values (in a real test, we might verify them)
}

// Practice test for inheritance access control
TEST(AccessControlPractice, InheritanceAccess) {
    Derived obj("protected data", 42, "private data");
    
    // Can access protected members through public interface
    EXPECT_EQ("protected data", obj.getProtectedData());
    EXPECT_EQ(42, obj.getProtectedValue());
    
    // Cannot access private members of base class directly
    // Must use public interface
    EXPECT_EQ("private data", obj.getPrivateData());
}

// Practice test for friend functions
TEST(AccessControlPractice, FriendFunction) {
    FriendTest obj("secret message", 123);
    
    // Can access private members through getters
    EXPECT_EQ("secret message", obj.getSecret());
    EXPECT_EQ(123, obj.getNumber());
    
    // Friend function can also access private members
    accessFriendTest(obj);
    // The function executes without error, demonstrating friend access
}

// Practice test for encapsulation benefits
TEST(AccessControlPractice, EncapsulationBenefits) {
    class Encapsulated {
    private:
        int value;
        
    public:
        Encapsulated(int v) : value(v) {}
        
        // Setter with validation
        void setValue(int v) {
            if (v >= 0) {  // Only non-negative values allowed
                value = v;
            }
            // Negative values are ignored
        }
        
        int getValue() const { return value; }
    };
    
    Encapsulated obj(10);
    EXPECT_EQ(10, obj.getValue());
    
    obj.setValue(20);
    EXPECT_EQ(20, obj.getValue());
    
    obj.setValue(-5);  // Should be ignored due to validation
    EXPECT_EQ(20, obj.getValue());  // Still 20, not -5
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}