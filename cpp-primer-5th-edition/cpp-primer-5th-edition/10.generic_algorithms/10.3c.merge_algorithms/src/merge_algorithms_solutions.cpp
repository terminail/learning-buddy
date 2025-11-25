// Exercise 10.3c: Merge Algorithms - Solution
// This exercise demonstrates merging algorithms in C++ STL.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    // Use std::merge to combine sorted sequences
    std::vector<int> first = {1, 3, 5, 7, 9};
    std::vector<int> second = {2, 4, 6, 8, 10};
    std::vector<int> merged(first.size() + second.size());
    
    std::cout << "First sequence: ";
    for (int n : first) std::cout << n << " ";
    std::cout << std::endl;
    
    std::cout << "Second sequence: ";
    for (int n : second) std::cout << n << " ";
    std::cout << std::endl;
    
    // Merge two sorted sequences
    std::merge(first.begin(), first.end(), second.begin(), second.end(), merged.begin());
    
    std::cout << "Merged sequence: ";
    for (int n : merged) std::cout << n << " ";
    std::cout << std::endl;
    
    // Use std::inplace_merge
    std::vector<int> sequence = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    
    std::cout << "\nBefore sorting second half: ";
    for (int n : sequence) std::cout << n << " ";
    std::cout << std::endl;
    
    // First, sort the second half
    std::sort(sequence.begin() + 5, sequence.end());
    
    std::cout << "After sorting second half: ";
    for (int n : sequence) std::cout << n << " ";
    std::cout << std::endl;
    
    // Merge the two sorted halves
    std::inplace_merge(sequence.begin(), sequence.begin() + 5, sequence.end());
    
    std::cout << "After inplace_merge: ";
    for (int n : sequence) std::cout << n << " ";
    std::cout << std::endl;
    
    // Example with custom objects
    struct Person {
        std::string name;
        int age;
    };
    
    std::vector<Person> team1 = {
        {"Alice", 25}, {"Charlie", 30}, {"Eve", 35}
    };
    
    std::vector<Person> team2 = {
        {"Bob", 28}, {"David", 32}, {"Frank", 38}
    };
    
    std::vector<Person> merged_teams(team1.size() + team2.size());
    
    // Merge by age
    std::merge(team1.begin(), team1.end(), team2.begin(), team2.end(),
               merged_teams.begin(),
               [](const Person& a, const Person& b) { return a.age < b.age; });
    
    std::cout << "\nMerged teams sorted by age:" << std::endl;
    for (const auto& person : merged_teams) {
        std::cout << person.name << " (" << person.age << ")" << std::endl;
    }
    
    return 0;
}