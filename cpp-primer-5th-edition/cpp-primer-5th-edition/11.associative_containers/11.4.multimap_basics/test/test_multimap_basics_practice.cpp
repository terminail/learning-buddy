#include <gtest/gtest.h>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

// Practice exercises for multimap operations

// TODO: Implement a function that groups values by key in a multimap
// Requirements:
// 1. Take a vector of pairs as input
// 2. Return a multimap with keys grouped with their values
// 3. Handle duplicate keys correctly
std::multimap<int, std::string> groupByKey(const std::vector<std::pair<int, std::string>>& pairs) {
    // Student implementation goes here
    std::multimap<int, std::string> result;
    for (const auto& pair : pairs) {
        result.insert(pair);
    }
    return result; // Fixed implementation
}

// TODO: Implement a function that finds all values for a key and returns them as a vector
// Requirements:
// 1. Take a multimap and a key as parameters
// 2. Return a vector containing all values associated with that key
// 3. Return empty vector if key not found
std::vector<std::string> findAllValues(const std::multimap<int, std::string>& mm, int key) {
    // Student implementation goes here
    std::vector<std::string> result;
    auto range = mm.equal_range(key);
    for (auto it = range.first; it != range.second; ++it) {
        result.push_back(it->second);
    }
    return result; // Fixed implementation
}

// TODO: Implement a function that removes duplicate value entries for each key
// Requirements:
// 1. Take a multimap as parameter
// 2. Return a new multimap with duplicates removed
// 3. Keep only the first occurrence of each value for each key
std::multimap<int, std::string> removeDuplicateValues(const std::multimap<int, std::string>& mm) {
    // Student implementation goes here
    std::multimap<int, std::string> result;
    std::map<std::pair<int, std::string>, bool> seen;
    
    for (const auto& pair : mm) {
        std::pair<int, std::string> key_value_pair = {pair.first, pair.second};
        if (seen.find(key_value_pair) == seen.end()) {
            seen[key_value_pair] = true;
            result.insert(pair);
        }
    }
    return result; // Fixed implementation
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// Tests for grouping function
TEST(MultimapPractice, GroupByKeyFunction) {
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

// Tests for find all values function
TEST(MultimapPractice, FindAllValuesFunction) {
    std::multimap<int, std::string> mm = {
        {1, "one"},
        {2, "two"},
        {1, "first"},
        {3, "three"},
        {1, "uno"}
    };
    
    auto values1 = findAllValues(mm, 1);
    EXPECT_EQ(values1.size(), 3);
    EXPECT_TRUE(std::find(values1.begin(), values1.end(), "one") != values1.end());
    EXPECT_TRUE(std::find(values1.begin(), values1.end(), "first") != values1.end());
    EXPECT_TRUE(std::find(values1.begin(), values1.end(), "uno") != values1.end());
    
    auto values2 = findAllValues(mm, 2);
    EXPECT_EQ(values2.size(), 1);
    EXPECT_EQ(values2[0], "two");
    
    auto values3 = findAllValues(mm, 4);
    EXPECT_TRUE(values3.empty());
}

// Tests for remove duplicates function
TEST(MultimapPractice, RemoveDuplicateValuesFunction) {
    std::multimap<int, std::string> mm = {
        {1, "one"},
        {2, "two"},
        {1, "one"},  // duplicate
        {3, "three"},
        {1, "first"},
        {2, "two"}   // duplicate
    };
    
    auto result = removeDuplicateValues(mm);
    
    EXPECT_EQ(result.size(), 4);  // Should have removed 2 duplicates
    EXPECT_EQ(result.count(1), 2);  // "one" appears once, "first" appears once
    EXPECT_EQ(result.count(2), 1);  // "two" appears once
    EXPECT_EQ(result.count(3), 1);  // "three" appears once
}