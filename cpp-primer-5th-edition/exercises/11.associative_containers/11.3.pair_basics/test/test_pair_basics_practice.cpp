#include <gtest/gtest.h>
#include <utility>
#include <string>
#include <vector>
#include <map>

// Practice exercises for pair operations

// TODO: Implement a function that creates a pair from two parameters
// Requirements:
// 1. Take two parameters of any type
// 2. Return a std::pair containing both values
// 3. Use template parameters for type safety
template<typename T, typename U>
std::pair<T, U> createPair(const T& first, const U& second) {
    // Student implementation goes here
    return std::pair<T, U>(); // Placeholder
}

// TODO: Implement a function that swaps the elements of a pair
// Requirements:
// 1. Take a pair as parameter
// 2. Return a new pair with elements swapped
// 3. Preserve the original pair unchanged
template<typename T, typename U>
std::pair<U, T> swapPair(const std::pair<T, U>& p) {
    // Student implementation goes here
    return std::pair<U, T>(); // Placeholder
}

// TODO: Implement a function that extracts values from a map and returns them as pairs
// Requirements:
// 1. Take a std::map as parameter
// 2. Return a std::vector of pairs containing all key-value pairs
// 3. Preserve the order of elements from the map
template<typename Key, typename Value>
std::vector<std::pair<Key, Value>> extractPairs(const std::map<Key, Value>& m) {
    // Student implementation goes here
    return std::vector<std::pair<Key, Value>>(); // Placeholder
}

// Tests for pair creation function
TEST(PairPractice, CreatePairFunction) {
    auto p1 = createPair(1, 3.14);
    EXPECT_EQ(p1.first, 1);
    EXPECT_EQ(p1.second, 3.14);
    
    auto p2 = createPair(std::string("hello"), 42);
    EXPECT_EQ(p2.first, "hello");
    EXPECT_EQ(p2.second, 42);
    
    auto p3 = createPair('A', true);
    EXPECT_EQ(p3.first, 'A');
    EXPECT_EQ(p3.second, true);
}

// Tests for pair swapping function
TEST(PairPractice, SwapPairFunction) {
    std::pair<int, double> p1(1, 3.14);
    auto p2 = swapPair(p1);
    
    EXPECT_EQ(p1.first, p2.second);
    EXPECT_EQ(p1.second, p2.first);
    
    std::pair<std::string, int> p3("hello", 42);
    auto p4 = swapPair(p3);
    
    EXPECT_EQ(p3.first, "hello");
    EXPECT_EQ(p3.second, 42);
    EXPECT_EQ(p4.first, 42);
    EXPECT_EQ(p4.second, "hello");
}

// Tests for map pair extraction function
TEST(PairPractice, ExtractPairsFunction) {
    std::map<int, std::string> m1;
    m1[1] = "one";
    m1[2] = "two";
    m1[3] = "three";
    
    auto pairs = extractPairs(m1);
    
    ASSERT_EQ(pairs.size(), 3);
    EXPECT_EQ(pairs[0].first, 1);
    EXPECT_EQ(pairs[0].second, "one");
    EXPECT_EQ(pairs[1].first, 2);
    EXPECT_EQ(pairs[1].second, "two");
    EXPECT_EQ(pairs[2].first, 3);
    EXPECT_EQ(pairs[2].second, "three");
}