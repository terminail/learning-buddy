// Exercise 10.1b: Transform and Copy Algorithms - Solution
// This exercise demonstrates modifying sequence algorithms in C++ STL.

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <iterator>

int main() {
    // Use std::transform to modify elements in containers
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::vector<int> squares(numbers.size());
    
    // Square each element and store in squares vector
    std::transform(numbers.begin(), numbers.end(), squares.begin(),
                  [](int n) { return n * n; });
    
    std::cout << "Original numbers: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;
    
    std::cout << "Squared numbers: ";
    for (int n : squares) std::cout << n << " ";
    std::cout << std::endl;
    
    // Transform with binary operation
    std::vector<int> multipliers = {2, 3, 4, 5, 6};
    std::vector<int> products(numbers.size());
    
    std::transform(numbers.begin(), numbers.end(), multipliers.begin(), products.begin(),
                  [](int a, int b) { return a * b; });
    
    std::cout << "Products: ";
    for (int n : products) std::cout << n << " ";
    std::cout << std::endl;
    
    // Use std::copy and related algorithms
    std::vector<int> source = {10, 20, 30, 40, 50};
    std::vector<int> destination(5);
    
    // Copy all elements
    std::copy(source.begin(), source.end(), destination.begin());
    
    std::cout << "Copied elements: ";
    for (int n : destination) std::cout << n << " ";
    std::cout << std::endl;
    
    // Copy only even numbers
    std::vector<int> even_numbers;
    std::copy_if(source.begin(), source.end(), std::back_inserter(even_numbers),
                [](int n) { return n % 2 == 0; });
    
    std::cout << "Even numbers: ";
    for (int n : even_numbers) std::cout << n << " ";
    std::cout << std::endl;
    
    // Copy first 3 elements
    std::vector<int> first_three;
    std::copy_n(source.begin(), 3, std::back_inserter(first_three));
    
    std::cout << "First three elements: ";
    for (int n : first_three) std::cout << n << " ";
    std::cout << std::endl;
    
    // Use std::replace and related algorithms
    std::vector<int> values = {1, 2, 3, 2, 4, 2, 5};
    
    // Replace all occurrences of 2 with 99
    std::replace(values.begin(), values.end(), 2, 99);
    
    std::cout << "After replacing 2 with 99: ";
    for (int n : values) std::cout << n << " ";
    std::cout << std::endl;
    
    // Replace elements greater than 90 with 0
    std::replace_if(values.begin(), values.end(), 
                   [](int n) { return n > 90; }, 0);
    
    std::cout << "After replacing > 90 with 0: ";
    for (int n : values) std::cout << n << " ";
    std::cout << std::endl;
    
    return 0;
}