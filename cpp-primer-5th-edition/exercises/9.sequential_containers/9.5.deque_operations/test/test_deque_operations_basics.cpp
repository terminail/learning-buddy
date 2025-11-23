#include <gtest/gtest.h>
#include <deque>

// Test deque creation and initialization
TEST(DequeOperationsTest, CreationAndInitialization) {
    // Test empty deque
    std::deque<int> empty;
    EXPECT_TRUE(empty.empty());
    EXPECT_EQ(0, empty.size());
    
    // Test initialized deque
    std::deque<int> init = {1, 2, 3, 4, 5};
    EXPECT_FALSE(init.empty());
    EXPECT_EQ(5, init.size());
    EXPECT_EQ(1, init.front());
    EXPECT_EQ(5, init.back());
    
    // Test fill deque
    std::deque<int> fill(3, 42);
    EXPECT_EQ(3, fill.size());
    EXPECT_EQ(42, fill[0]);
    EXPECT_EQ(42, fill[1]);
    EXPECT_EQ(42, fill[2]);
}

// Test deque element access
TEST(DequeOperationsTest, ElementAccess) {
    std::deque<std::string> words = {"first", "second", "third"};
    
    // Test front and back
    EXPECT_EQ("first", words.front());
    EXPECT_EQ("third", words.back());
    
    // Test operator[] and at()
    EXPECT_EQ("second", words[1]);
    EXPECT_EQ("second", words.at(1));
    
    // Test bounds checking with at()
    EXPECT_THROW(words.at(10), std::out_of_range);
}

// Test deque modification operations
TEST(DequeOperationsTest, ModificationOperations) {
    std::deque<int> numbers;
    
    // Test push operations
    numbers.push_back(1);
    numbers.push_front(0);
    EXPECT_EQ(2, numbers.size());
    EXPECT_EQ(0, numbers.front());
    EXPECT_EQ(1, numbers.back());
    
    // Test pop operations
    numbers.pop_back();
    EXPECT_EQ(1, numbers.size());
    EXPECT_EQ(0, numbers.front());
    EXPECT_EQ(0, numbers.back());
    
    numbers.pop_front();
    EXPECT_TRUE(numbers.empty());
}

// Test deque iterators and algorithms
TEST(DequeOperationsTest, IteratorsAndAlgorithms) {
    std::deque<int> data = {3, 1, 4, 1, 5};
    
    // Test iterator operations
    EXPECT_EQ(3, *data.begin());
    EXPECT_EQ(5, *(data.end() - 1));
    
    // Test algorithm usage
    std::sort(data.begin(), data.end());
    EXPECT_EQ(1, data[0]);
    EXPECT_EQ(5, data[4]);
    
    // Test find algorithm
    auto it = std::find(data.begin(), data.end(), 4);
    EXPECT_NE(data.end(), it);
    EXPECT_EQ(4, *it);
}