#include <gtest/gtest.h>
#include <typeinfo>
#include <memory>
#include <iostream>

// Base class with virtual function
class Base {
public:
    virtual ~Base() = default;
    virtual void display() const {
        std::cout << "Base class" << std::endl;
    }
};

// Derived classes
class Derived1 : public Base {
public:
    void display() const override {
        std::cout << "Derived1 class" << std::endl;
    }
};

class Derived2 : public Base {
public:
    void display() const override {
        std::cout << "Derived2 class" << std::endl;
    }
};

// Test for typeid operator
TEST(RTTITest, TypeidOperator) {
    Derived1 d1;
    Derived2 d2;
    Base* base_ptr = &d1;
    
    // Test that typeid returns correct type information
    EXPECT_EQ(typeid(d1).name(), typeid(Derived1).name());
    EXPECT_EQ(typeid(d2).name(), typeid(Derived2).name());
    EXPECT_EQ(typeid(*base_ptr).name(), typeid(Derived1).name());
    
    // Test type comparison
    EXPECT_TRUE(typeid(*base_ptr) == typeid(Derived1));
    EXPECT_TRUE(typeid(*base_ptr) != typeid(Derived2));
}

// Test for dynamic_cast
TEST(RTTITest, DynamicCast) {
    Derived1 d1;
    Base* base_ptr = &d1;
    
    // Test successful downcast
    Derived1* derived1_ptr = dynamic_cast<Derived1*>(base_ptr);
    EXPECT_NE(derived1_ptr, nullptr);
    
    // Test failed downcast
    Derived2* derived2_ptr = dynamic_cast<Derived2*>(base_ptr);
    EXPECT_EQ(derived2_ptr, nullptr);
}

// Test for polymorphic behavior
TEST(RTTITest, PolymorphicBehavior) {
    std::unique_ptr<Base> base1 = std::make_unique<Derived1>();
    std::unique_ptr<Base> base2 = std::make_unique<Derived2>();
    
    // Test that the correct derived class functions are called
    EXPECT_EQ(typeid(*base1).name(), typeid(Derived1).name());
    EXPECT_EQ(typeid(*base2).name(), typeid(Derived2).name());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}