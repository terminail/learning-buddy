#include <gtest/gtest.h>
#include "map_operations_exercises.h"
#include <map>
#include <vector>

using namespace cpp_primer;

class MapOperationsTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== CONSTRUCTOR TESTS ==========

TEST_F(MapOperationsTest, DefaultConstructor) {
    MapOperations exercise;
    // Constructor should not throw
    SUCCEED();
}

// ========== MAP CREATION TESTS ==========

TEST_F(MapOperationsTest, CreateMap) {
    MapOperations exercise;
    std::vector<std::pair<std::string, int>> pairs = {
        {"apple", 5}, {"banana", 3}, {"orange", 8}
    };
    
    // Test creating map with key-value pairs
    std::map<std::string, int> result = exercise.create_map(pairs);
    EXPECT_EQ(result.size(), 3) << "Expected map to have 3 elements";
    EXPECT_EQ(result["apple"], 5) << "Expected apple to have value 5";
    EXPECT_EQ(result["banana"], 3) << "Expected banana to have value 3";
    EXPECT_EQ(result["orange"], 8) << "Expected orange to have value 8";
}

// ========== MAP INSERTION TESTS ==========

TEST_F(MapOperationsTest, AddToMap) {
    MapOperations exercise;
    std::map<std::string, int> m = {{"apple", 5}};
    
    // Test adding key-value pair to map
    exercise.add_to_map(m, "banana", 3);
    EXPECT_EQ(m.size(), 2) << "Expected map to have 2 elements after adding";
    EXPECT_EQ(m["banana"], 3) << "Expected banana to have value 3";
}

// ========== MAP LOOKUP TESTS ==========

TEST_F(MapOperationsTest, GetFromMap) {
    MapOperations exercise;
    std::map<std::string, int> m = {{"apple", 5}, {"banana", 3}};
    
    // Test getting value from map by key
    int value = exercise.get_from_map(m, "apple");
    EXPECT_EQ(value, 5) << "Expected apple to have value 5";
    
    // Test getting value for non-existing key
    int value2 = exercise.get_from_map(m, "orange");
    EXPECT_EQ(value2, 0) << "Expected non-existing key to return 0";
}

// ========== MAP REMOVAL TESTS ==========

TEST_F(MapOperationsTest, RemoveFromMap) {
    MapOperations exercise;
    std::map<std::string, int> m = {{"apple", 5}, {"banana", 3}};
    
    // Test removing existing key
    bool removed = exercise.remove_from_map(m, "apple");
    EXPECT_TRUE(removed) << "Expected to successfully remove existing key";
    EXPECT_EQ(m.size(), 1) << "Expected map to have 1 element after removal";
    EXPECT_EQ(m.count("apple"), 0) << "Expected apple to not exist in map after removal";
    
    // Test removing non-existing key
    bool removed2 = exercise.remove_from_map(m, "orange");
    EXPECT_FALSE(removed2) << "Expected to not remove non-existing key";
}

// ========== MAP COUNT TESTS ==========

TEST_F(MapOperationsTest, CountKeyInMap) {
    MapOperations exercise;
    std::map<std::string, int> m = {{"apple", 5}, {"banana", 3}};
    
    // Test counting existing key
    int count = exercise.count_key_in_map(m, "apple");
    EXPECT_EQ(count, 1) << "Expected existing key to have count 1";
    
    // Test counting non-existing key
    int count2 = exercise.count_key_in_map(m, "orange");
    EXPECT_EQ(count2, 0) << "Expected non-existing key to have count 0";
}

// ========== MAP KEY RETRIEVAL TESTS ==========

TEST_F(MapOperationsTest, GetKeys) {
    MapOperations exercise;
    std::map<std::string, int> m = {{"apple", 5}, {"banana", 3}, {"orange", 8}};
    
    // Test getting all keys from map
    std::vector<std::string> keys = exercise.get_keys(m);
    EXPECT_EQ(keys.size(), 3) << "Expected to get 3 keys";
    
    // Since map is ordered, the keys should be in alphabetical order
    std::vector<std::string> expected_keys = {"apple", "banana", "orange"};
    for (size_t i = 0; i < keys.size(); ++i) {
        EXPECT_EQ(keys[i], expected_keys[i]) << "Expected key at position " << i;
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}