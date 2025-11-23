#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <random>

// Practice test for performance comparison
TEST(SortingAlgorithmsPractice, PerformanceComparison) {
    // Create large dataset
    std::vector<int> data(10000);
    std::iota(data.begin(), data.end(), 1);
    
    // Shuffle the data
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(data.begin(), data.end(), g);
    
    // Test std::sort performance
    std::vector<int> sort_data = data;
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(sort_data.begin(), sort_data.end());
    auto end = std::chrono::high_resolution_clock::now();
    auto sort_duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    // Verify sorting worked
    EXPECT_TRUE(std::is_sorted(sort_data.begin(), sort_data.end()));
    
    // Test std::stable_sort performance
    std::vector<int> stable_data = data;
    start = std::chrono::high_resolution_clock::now();
    std::stable_sort(stable_data.begin(), stable_data.end());
    end = std::chrono::high_resolution_clock::now();
    auto stable_duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    // Verify sorting worked
    EXPECT_TRUE(std::is_sorted(stable_data.begin(), stable_data.end()));
    
    // Both should produce the same result
    EXPECT_EQ(sort_data, stable_data);
    
    std::cout << "std::sort time: " << sort_duration.count() << " microseconds" << std::endl;
    std::cout << "std::stable_sort time: " << stable_duration.count() << " microseconds" << std::endl;
}

// Practice test for complex sorting scenarios
TEST(SortingAlgorithmsPractice, ComplexScenarios) {
    // Sort custom objects
    struct Person {
        std::string name;
        int age;
        double salary;
    };
    
    std::vector<Person> people = {
        {"Alice", 30, 50000.0},
        {"Bob", 25, 60000.0},
        {"Charlie", 30, 55000.0},
        {"Diana", 25, 50000.0}
    };
    
    // Sort by age, then by salary (descending), then by name
    std::sort(people.begin(), people.end(),
              [](const Person& a, const Person& b) {
                  if (a.age != b.age) return a.age < b.age;
                  if (a.salary != b.salary) return a.salary > b.salary;
                  return a.name < b.name;
              });
    
    // Expected order: Diana(25,50000), Bob(25,60000), Charlie(30,55000), Alice(30,50000)
    EXPECT_EQ("Diana", people[0].name);
    EXPECT_EQ("Bob", people[1].name);
    EXPECT_EQ("Charlie", people[2].name);
    EXPECT_EQ("Alice", people[3].name);
    
    // Test with equal elements
    std::vector<int> equal_elements = {5, 5, 5, 5, 5};
    std::sort(equal_elements.begin(), equal_elements.end());
    EXPECT_EQ(5, equal_elements[0]);
    EXPECT_EQ(5, equal_elements[4]);
    
    std::stable_sort(equal_elements.begin(), equal_elements.end());
    EXPECT_EQ(5, equal_elements[0]);
    EXPECT_EQ(5, equal_elements[4]);
}

// Practice test for edge cases
TEST(SortingAlgorithmsPractice, EdgeCases) {
    // Test with empty container
    std::vector<int> empty;
    std::sort(empty.begin(), empty.end());
    EXPECT_TRUE(empty.empty());
    
    // Test with single element
    std::vector<int> single = {42};
    std::sort(single.begin(), single.end());
    EXPECT_EQ(42, single[0]);
    
    // Test with two elements
    std::vector<int> two = {2, 1};
    std::sort(two.begin(), two.end());
    EXPECT_EQ(1, two[0]);
    EXPECT_EQ(2, two[1]);
    
    // Test with already sorted data
    std::vector<int> sorted = {1, 2, 3, 4, 5};
    std::sort(sorted.begin(), sorted.end());
    EXPECT_EQ(1, sorted[0]);
    EXPECT_EQ(5, sorted[4]);
    
    // Test with reverse sorted data
    std::vector<int> reverse = {5, 4, 3, 2, 1};
    std::sort(reverse.begin(), reverse.end());
    EXPECT_EQ(1, reverse[0]);
    EXPECT_EQ(5, reverse[4]);
}