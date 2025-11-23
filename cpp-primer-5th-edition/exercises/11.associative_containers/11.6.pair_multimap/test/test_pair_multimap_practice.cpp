#include <gtest/gtest.h>
#include <map>
#include <string>
#include <vector>
#include <utility>

// Practice exercises for pair and multimap operations

// TODO: Implement a function that groups values by key using pairs
// Requirements:
// 1. Take a vector of pairs as input
// 2. Return a multimap with keys grouped with their values
// 3. Handle duplicate keys correctly
std::multimap<int, std::string> groupByKey(const std::vector<std::pair<int, std::string>>& pairs) {
    // Student implementation goes here
    return std::multimap<int, std::string>(); // Placeholder
}

// TODO: Implement a function that finds all values for a key and returns them as pairs
// Requirements:
// 1. Take a multimap and a key as parameters
// 2. Return a vector of pairs containing all key-value pairs for that key
// 3. Return empty vector if key not found
std::vector<std::pair<int, std::string>> findAllPairs(const std::multimap<int, std::string>& mm, int key) {
    // Student implementation goes here
    return std::vector<std::pair<int, std::string>>(); // Placeholder
}

// Tests for grouping function
TEST(PairMultimapPractice, GroupByKeyFunction) {
    std::vector<std::pair<int, std::string>> input = {
        {1, "one"},
        {2, "two"},
        {1, "first"},
        {3, "three"},
        {2, "second"}
    };
    
    auto result = groupByKey(input);
    
    EXPECT_EQ(result.size(), 5);
    EXPECT_EQ(result.count(1), 2);
    EXPECT_EQ(result.count(2), 2);
    EXPECT_EQ(result.count(3), 1);
    
    auto range = result.equal_range(1);
    std::vector<std::string> values;
    for (auto it = range.first; it != range.second; ++it) {
        values.push_back(it->second);
    }
    EXPECT_EQ(values.size(), 2);
    EXPECT_TRUE(std::find(values.begin(), values.end(), "one") != values.end());
    EXPECT_TRUE(std::find(values.begin(), values.end(), "first") != values.end());
}

// Tests for find all pairs function
TEST(PairMultimapPractice, FindAllPairsFunction) {
    std::multimap<int, std::string> mm = {
        {1, "one"},
        {2, "two"},
        {1, "first"},
        {3, "three"},
        {1, "uno"}
    };
    
    auto pairs = findAllPairs(mm, 1);
    EXPECT_EQ(pairs.size(), 3);
    
    // Check that all pairs have the correct key
    for (const auto& pair : pairs) {
        EXPECT_EQ(pair.first, 1);
    }
    
    auto pairs2 = findAllPairs(mm, 2);
    EXPECT_EQ(pairs2.size(), 1);
    EXPECT_EQ(pairs2[0].first, 2);
    EXPECT_EQ(pairs2[0].second, "two");
    
    auto pairs3 = findAllPairs(mm, 4);
    EXPECT_TRUE(pairs3.empty());
}