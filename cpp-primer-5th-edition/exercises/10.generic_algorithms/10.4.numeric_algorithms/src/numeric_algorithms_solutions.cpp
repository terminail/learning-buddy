// Exercise 10.1d: Numeric Algorithms - Solution
// This exercise demonstrates numeric algorithms in C++ STL.

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <string>

int main() {
    // Use std::accumulate to sum elements in containers
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    // Calculate sum using std::accumulate
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "Sum of numbers: " << sum << std::endl;
    
    // Calculate product using std::accumulate with custom operation
    int product = std::accumulate(numbers.begin(), numbers.end(), 1, 
                                [](int a, int b) { return a * b; });
    std::cout << "Product of numbers: " << product << std::endl;
    
    // Calculate sum with initial value
    int sum_with_initial = std::accumulate(numbers.begin(), numbers.end(), 10);
    std::cout << "Sum with initial value 10: " << sum_with_initial << std::endl;
    
    // Work with floating point numbers
    std::vector<double> doubles = {1.1, 2.2, 3.3, 4.4, 5.5};
    double double_sum = std::accumulate(doubles.begin(), doubles.end(), 0.0);
    std::cout << "Sum of doubles: " << double_sum << std::endl;
    
    // Use std::inner_product to calculate dot products
    std::vector<int> first = {1, 2, 3};
    std::vector<int> second = {4, 5, 6};
    
    // Calculate dot product
    int dot_product = std::inner_product(first.begin(), first.end(), second.begin(), 0);
    std::cout << "Dot product: " << dot_product << std::endl;
    
    // Calculate sum of products with custom operations
    int custom_inner = std::inner_product(first.begin(), first.end(), second.begin(), 0,
                                        [](int a, int b) { return a + b; },  // addition op
                                        [](int a, int b) { return a * b; }); // multiplication op
    std::cout << "Custom inner product: " << custom_inner << std::endl;
    
    // Use std::partial_sum and related algorithms
    std::vector<int> values = {1, 2, 3, 4, 5};
    std::vector<int> partial_sums(values.size());
    
    // Calculate partial sums
    std::partial_sum(values.begin(), values.end(), partial_sums.begin());
    
    std::cout << "Original values: ";
    for (int n : values) std::cout << n << " ";
    std::cout << std::endl;
    
    std::cout << "Partial sums: ";
    for (int n : partial_sums) std::cout << n << " ";
    std::cout << std::endl;
    
    // Calculate adjacent differences
    std::vector<int> differences(values.size());
    std::adjacent_difference(values.begin(), values.end(), differences.begin());
    
    std::cout << "Adjacent differences: ";
    for (int n : differences) std::cout << n << " ";
    std::cout << std::endl;
    
    // Work with strings using numeric algorithms
    std::vector<std::string> words = {"Hello", " ", "World", "!"};
    std::string concatenated = std::accumulate(words.begin(), words.end(), std::string(""));
    std::cout << "Concatenated string: " << concatenated << std::endl;
    
    return 0;
}