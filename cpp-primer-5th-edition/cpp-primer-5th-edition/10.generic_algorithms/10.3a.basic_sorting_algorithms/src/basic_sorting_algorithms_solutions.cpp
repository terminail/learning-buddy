// Exercise 10.3a: Basic Sorting Algorithms - Solution
// This exercise demonstrates basic sorting algorithms in C++ STL.

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>

int main() {
    // Use std::sort to sort containers
    std::vector<int> numbers = {64, 34, 25, 12, 22, 11, 90};
    
    std::cout << "Original numbers: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;
    
    // Sort in ascending order
    std::sort(numbers.begin(), numbers.end());
    
    std::cout << "Sorted in ascending order: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;
    
    // Sort in descending order
    std::sort(numbers.begin(), numbers.end(), std::greater<int>());
    
    std::cout << "Sorted in descending order: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;
    
    // Sort containers of custom objects
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
    
    std::cout << "People sorted by age:" << std::endl;
    for (const auto& person : people) {
        std::cout << person.name << " (" << person.age << ")" << std::endl;
    }
    
    // Use std::stable_sort
    std::vector<std::pair<int, char>> pairs = {
        {1, 'a'}, {2, 'b'}, {1, 'c'}, {2, 'd'}, {1, 'e'}
    };
    
    std::cout << "Original pairs:" << std::endl;
    for (const auto& p : pairs) {
        std::cout << "(" << p.first << ", " << p.second << ") ";
    }
    std::cout << std::endl;
    
    // Sort by first element (unstable)
    std::vector<std::pair<int, char>> unstable_sorted = pairs;
    std::sort(unstable_sorted.begin(), unstable_sorted.end());
    
    std::cout << "Unstable sorted:" << std::endl;
    for (const auto& p : unstable_sorted) {
        std::cout << "(" << p.first << ", " << p.second << ") ";
    }
    std::cout << std::endl;
    
    // Stable sort by first element
    std::vector<std::pair<int, char>> stable_sorted = pairs;
    std::stable_sort(stable_sorted.begin(), stable_sorted.end());
    
    std::cout << "Stable sorted:" << std::endl;
    for (const auto& p : stable_sorted) {
        std::cout << "(" << p.first << ", " << p.second << ") ";
    }
    std::cout << std::endl;
    
    return 0;
}