#include <gtest/gtest.h>
#include <vector>
#include <list>
#include <algorithm>
#include <string>

// Test for std::sort algorithm
TEST(BasicSortingAlgorithmsTest, SortAlgorithm) {
    std::vector<int> numbers = {64, 34, 25, 12, 22, 11, 90};
    
    // Test ascending sort
    std::sort(numbers.begin(), numbers.end());
    
    EXPECT_TRUE(std::is_sorted(numbers.begin(), numbers.end()));
    EXPECT_EQ(numbers[0], 11);
    EXPECT_EQ(numbers[6], 90);
}

// Test for std::sort with custom comparator
TEST(BasicSortingAlgorithmsTest, SortWithComparator) {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    // Test descending sort
    std::sort(numbers.begin(), numbers.end(), std::greater<int>());
    
    EXPECT_TRUE(std::is_sorted(numbers.begin(), numbers.end(), std::greater<int>()));
    EXPECT_EQ(numbers[0], 5);
    EXPECT_EQ(numbers[4], 1);
}

// Test for std::stable_sort algorithm
TEST(BasicSortingAlgorithmsTest, StableSortAlgorithm) {
    std::vector<std::pair<int, char>> pairs = {
        {1, 'a'}, {2, 'b'}, {1, 'c'}, {2, 'd'}, {1, 'e'}
    };
    
    // Test stable sort
    std::stable_sort(pairs.begin(), pairs.end());
    
    // Check that relative order is maintained for equal elements
    EXPECT_EQ(pairs[0].second, 'a');
    EXPECT_EQ(pairs[1].second, 'c');
    EXPECT_EQ(pairs[2].second, 'e');
    EXPECT_EQ(pairs[3].second, 'b');
    EXPECT_EQ(pairs[4].second, 'd');
}

// Test for sorting custom objects
TEST(BasicSortingAlgorithmsTest, SortCustomObjects) {
    struct Person {
        std::string name;
        int age;
    };
    
    std::vector<Person> people = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 35},
        {"Diana", 28}
    };
    
    // Sort by age
    std::sort(people.begin(), people.end(), 
             [](const Person& a, const Person& b) { return a.age < b.age; });
    
    EXPECT_EQ(people[0].name, "Bob");
    EXPECT_EQ(people[0].age, 25);
    EXPECT_EQ(people[3].name, "Charlie");
    EXPECT_EQ(people[3].age, 35);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}