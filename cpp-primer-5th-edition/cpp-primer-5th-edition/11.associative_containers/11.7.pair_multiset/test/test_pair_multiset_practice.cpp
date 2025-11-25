#include <gtest/gtest.h>
#include <set>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

// Practice exercises for pair and multiset operations

// TODO: Implement a function that analyzes word frequency with position using pairs
// Requirements:
// 1. Take a vector of words and their positions as input
// 2. Return a multiset of pairs containing word and position
// 3. The multiset will preserve duplicates and sort them
std::multiset<std::pair<std::string, int>> analyzeWordPositions(const std::vector<std::pair<std::string, int>>& word_positions) {
    // Student implementation goes here
    return std::multiset<std::pair<std::string, int>>(word_positions.begin(), word_positions.end()); // Fixed implementation
}

// TODO: Implement a function that finds the most frequent word-position pairs
// Requirements:
// 1. Take a multiset of word-position pairs as parameter
// 2. Return a vector of the most frequent pairs
// 3. If multiple pairs have the same highest frequency, return all of them
std::vector<std::pair<std::string, int>> findMostFrequentPairs(const std::multiset<std::pair<std::string, int>>& ms) {
    // Student implementation goes here
    if (ms.empty()) {
        return std::vector<std::pair<std::string, int>>();
    }
    
    // Find the maximum frequency
    size_t max_frequency = 0;
    for (const auto& element : ms) {
        max_frequency = std::max(max_frequency, ms.count(element));
    }
    
    // Collect all pairs with maximum frequency
    std::vector<std::pair<std::string, int>> result;
    std::set<std::pair<std::string, int>> processed; // To avoid duplicates in result
    
    for (const auto& element : ms) {
        if (ms.count(element) == max_frequency && processed.find(element) == processed.end()) {
            result.push_back(element);
            processed.insert(element);
        }
    }
    
    return result; // Fixed implementation
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// Tests for word position analysis function
TEST(PairMultisetPractice, AnalyzeWordPositionsFunction) {
    std::vector<std::pair<std::string, int>> word_positions = {
        {"apple", 1},
        {"banana", 2},
        {"apple", 3},
        {"cherry", 4},
        {"banana", 5},
        {"apple", 6}
    };
    
    auto result = analyzeWordPositions(word_positions);
    
    EXPECT_EQ(result.size(), 6);
    EXPECT_EQ(result.count({"apple", 1}), 1);
    EXPECT_EQ(result.count({"apple", 3}), 1);
    EXPECT_EQ(result.count({"apple", 6}), 1);
    EXPECT_EQ(result.count({"banana", 2}), 1);
    EXPECT_EQ(result.count({"banana", 5}), 1);
    EXPECT_EQ(result.count({"cherry", 4}), 1);
}

// Tests for finding most frequent pairs function
TEST(PairMultisetPractice, FindMostFrequentPairsFunction) {
    std::multiset<std::pair<std::string, int>> ms = {
        {"apple", 1},
        {"banana", 2},
        {"apple", 1},  // Duplicate
        {"cherry", 3},
        {"apple", 1}   // Another duplicate
    };
    
    auto result = findMostFrequentPairs(ms);
    
    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[0].first, "apple");
    EXPECT_EQ(result[0].second, 1);  // ("apple", 1) appears 3 times, most frequent
    
    // Test with multiple pairs having same highest frequency
    std::multiset<std::pair<std::string, int>> ms2 = {
        {"apple", 1},
        {"banana", 2},
        {"apple", 1},  // Duplicate
        {"banana", 2}  // Duplicate
    };
    
    auto result2 = findMostFrequentPairs(ms2);
    
    EXPECT_EQ(result2.size(), 2);  // Both pairs appear twice
    // Check that both frequent pairs are in the result
    bool found_apple = false;
    bool found_banana = false;
    for (const auto& pair : result2) {
        if (pair.first == "apple" && pair.second == 1) found_apple = true;
        if (pair.first == "banana" && pair.second == 2) found_banana = true;
    }
    EXPECT_TRUE(found_apple);
    EXPECT_TRUE(found_banana);
}