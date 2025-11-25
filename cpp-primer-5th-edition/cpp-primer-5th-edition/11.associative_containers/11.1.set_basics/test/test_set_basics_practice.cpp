#include <gtest/gtest.h>
#include <set>
#include <string>

// Practice test for set operations - students need to implement these
TEST(SetBasicsPracticeTest, IterationAndOrdering) {
    std::set<std::string> unique_words;
    unique_words.insert("zebra");
    unique_words.insert("apple");
    unique_words.insert("banana");
    unique_words.insert("orange");
    
    // TODO: Implement a test that verifies iteration through the set
    // Check that elements are in sorted order
    
    // TODO: Implement a test that verifies the uniqueness property
    // Add duplicate elements and verify the set size doesn't change
    
    SUCCEED(); // Placeholder - replace with actual tests
}

TEST(SetBasicsPracticeTest, SetOperations) {
    std::set<std::string> set1;
    set1.insert("apple");
    set1.insert("banana");
    set1.insert("orange");
    
    std::set<std::string> set2;
    set2.insert("banana");
    set2.insert("grape");
    set2.insert("kiwi");
    
    // TODO: Implement tests for set operations like:
    // - Union (inserting elements from one set to another)
    // - Intersection (finding common elements)
    // - Difference (finding elements in one set but not the other)
    
    SUCCEED(); // Placeholder - replace with actual tests
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
