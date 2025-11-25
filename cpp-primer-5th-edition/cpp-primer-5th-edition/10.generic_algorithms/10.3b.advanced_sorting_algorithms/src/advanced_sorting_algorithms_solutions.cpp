// Exercise 10.3b: Advanced Sorting Algorithms - Solution
// This exercise demonstrates advanced sorting algorithms in C++ STL.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <chrono>

int main() {
    // Generate a large vector of random integers for testing
    std::vector<int> numbers(10000);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100000);
    
    for (int& n : numbers) {
        n = dis(gen);
    }
    
    // Use std::partial_sort for partial ordering
    std::vector<int> partial_sorted = numbers;
    
    std::cout << "Finding smallest 10 elements using partial_sort:" << std::endl;
    std::partial_sort(partial_sorted.begin(), partial_sorted.begin() + 10, partial_sorted.end());
    
    for (int i = 0; i < 10; ++i) {
        std::cout << partial_sorted[i] << " ";
    }
    std::cout << std::endl;
    
    // Use std::nth_element for selection algorithms
    std::vector<int> nth_test = numbers;
    
    std::cout << "\nFinding median element using nth_element:" << std::endl;
    std::nth_element(nth_test.begin(), nth_test.begin() + nth_test.size()/2, nth_test.end());
    std::cout << "Median element: " << nth_test[nth_test.size()/2] << std::endl;
    
    // Find the 100th smallest element
    std::vector<int> nth_test2 = numbers;
    std::nth_element(nth_test2.begin(), nth_test2.begin() + 99, nth_test2.end());
    std::cout << "100th smallest element: " << nth_test2[99] << std::endl;
    
    // Performance comparison
    std::vector<int> full_sort_test = numbers;
    std::vector<int> partial_sort_test = numbers;
    std::vector<int> nth_element_test = numbers;
    
    // Measure full sort performance
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(full_sort_test.begin(), full_sort_test.end());
    auto end = std::chrono::high_resolution_clock::now();
    auto full_sort_duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    // Measure partial sort performance
    start = std::chrono::high_resolution_clock::now();
    std::partial_sort(partial_sort_test.begin(), partial_sort_test.begin() + 100, partial_sort_test.end());
    end = std::chrono::high_resolution_clock::now();
    auto partial_sort_duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    // Measure nth_element performance
    start = std::chrono::high_resolution_clock::now();
    std::nth_element(nth_element_test.begin(), nth_element_test.begin() + 99, nth_element_test.end());
    end = std::chrono::high_resolution_clock::now();
    auto nth_element_duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    std::cout << "\nPerformance comparison (microseconds):" << std::endl;
    std::cout << "Full sort: " << full_sort_duration.count() << std::endl;
    std::cout << "Partial sort (100 elements): " << partial_sort_duration.count() << std::endl;
    std::cout << "Nth element (100th): " << nth_element_duration.count() << std::endl;
    
    return 0;
}