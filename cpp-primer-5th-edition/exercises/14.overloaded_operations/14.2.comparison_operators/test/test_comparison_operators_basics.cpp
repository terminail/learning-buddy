#include <gtest/gtest.h>
#include <string>

// Simple implementation for testing
class TestStudent {
private:
    std::string name;
    double gpa;

public:
    TestStudent() : name(""), gpa(0.0) {}
    TestStudent(const std::string& n, double g) : name(n), gpa(g) {}
    
    bool operator==(const TestStudent& other) const {
        return name == other.name && gpa == other.gpa;
    }
    
    bool operator!=(const TestStudent& other) const {
        return !(*this == other);
    }
    
    bool operator<(const TestStudent& other) const {
        if (gpa != other.gpa) {
            return gpa < other.gpa;
        }
        return name < other.name;
    }
    
    bool operator>(const TestStudent& other) const {
        return other < *this;
    }
    
    bool operator<=(const TestStudent& other) const {
        return !(*this > other);
    }
    
    bool operator>=(const TestStudent& other) const {
        return !(*this < other);
    }
    
    const std::string& getName() const { return name; }
    double getGpa() const { return gpa; }
};

// Basic test for equality operators
TEST(ComparisonOperatorsTest, Equality) {
    TestStudent s1("Alice", 3.8);
    TestStudent s2("Alice", 3.8);
    TestStudent s3("Bob", 3.8);
    
    EXPECT_TRUE(s1 == s2);
    EXPECT_FALSE(s1 == s3);
    EXPECT_TRUE(s1 != s3);
    EXPECT_FALSE(s1 != s2);
}

// Basic test for relational operators
TEST(ComparisonOperatorsTest, Relational) {
    TestStudent s1("Alice", 3.5);
    TestStudent s2("Bob", 3.8);
    TestStudent s3("Charlie", 3.5);
    
    EXPECT_TRUE(s1 < s2);
    EXPECT_TRUE(s2 > s1);
    EXPECT_TRUE(s1 <= s2);
    EXPECT_TRUE(s2 >= s1);
    EXPECT_TRUE(s1 <= s3);
    EXPECT_TRUE(s1 >= s3);
}

// Test transitivity
TEST(ComparisonOperatorsTest, Transitivity) {
    TestStudent s1("Alice", 3.0);
    TestStudent s2("Bob", 3.5);
    TestStudent s3("Charlie", 4.0);
    
    // If s1 < s2 and s2 < s3, then s1 < s3
    EXPECT_TRUE(s1 < s2);
    EXPECT_TRUE(s2 < s3);
    EXPECT_TRUE(s1 < s3);
}