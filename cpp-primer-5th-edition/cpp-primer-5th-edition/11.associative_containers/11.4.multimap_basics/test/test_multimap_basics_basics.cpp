#include <gtest/gtest.h>
#include <map>
#include <string>

// Basic tests for multimap operations

// TODO: Test multimap creation and initialization
// Requirements:
// 1. Create multimaps with different types
// 2. Initialize multimaps with values
// 3. Verify element insertion

// TODO: Test multimap element access
// Requirements:
// 1. Use iterators to traverse multimaps
// 2. Find elements with specific keys
// 3. Count occurrences of keys
// 4. Access value ranges for keys

// TODO: Test multimap modification operations
// Requirements:
// 1. Insert elements using different methods
// 2. Erase elements by key or iterator
// 3. Check multimap size and empty status

TEST(MultimapBasics, CreationAndInitialization) {
    // Test default construction
    std::multimap<int, std::string> mm1;
    EXPECT_TRUE(mm1.empty());
    
    // Test initialization with values
    std::multimap<int, std::string> mm2 = {
        {1, "one"},
        {2, "two"},
        {1, "another one"}
    };
    EXPECT_EQ(mm2.size(), 3);
    
    // Test insertion methods
    mm1.insert({3, "three"});
    mm1.insert(std::make_pair(4, "four"));
    EXPECT_EQ(mm1.size(), 2);
    
    // Verify duplicate keys are allowed
    mm1.insert({3, "third"});
    EXPECT_EQ(mm1.size(), 3);
    EXPECT_EQ(mm1.count(3), 2);
}

TEST(MultimapBasics, ElementAccess) {
    std::multimap<int, std::string> mm = {
        {1, "one"},
        {2, "two"},
        {1, "another one"},
        {3, "three"},
        {1, "yet another"}
    };
    
    // Test counting elements with specific keys
    EXPECT_EQ(mm.count(1), 3);
    EXPECT_EQ(mm.count(2), 1);
    EXPECT_EQ(mm.count(4), 0);
    
    // Test finding ranges
    auto range = mm.equal_range(1);
    int count = 0;
    for (auto it = range.first; it != range.second; ++it) {
        ++count;
    }
    EXPECT_EQ(count, 3);
    
    // Test iterator traversal
    int total_count = 0;
    for (const auto& pair : mm) {
        ++total_count;
    }
    EXPECT_EQ(total_count, 5);
}

TEST(MultimapBasics, ModificationOperations) {
    std::multimap<int, std::string> mm = {
        {1, "one"},
        {2, "two"},
        {1, "another one"}
    };
    
    // Test element insertion
    mm.insert({3, "three"});
    EXPECT_EQ(mm.size(), 4);
    
    // Test element erasure by key
    size_t erased = mm.erase(1);
    EXPECT_EQ(erased, 2);
    EXPECT_EQ(mm.size(), 2);
    EXPECT_EQ(mm.count(1), 0);
    
    // Test clearing all elements
    mm.clear();
    EXPECT_TRUE(mm.empty());
    EXPECT_EQ(mm.size(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
