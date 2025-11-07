#ifndef SET_OPERATIONS_EXERCISES_H
#define SET_OPERATIONS_EXERCISES_H

#include <set>
#include <string>
#include <vector>

// TODO: Complete the functions below according to the specifications.
// Follow C++17 standards and best practices for each exercise.

class SetOperations {
public:
    // Exercise 1: Create and return an empty set of integers
    static std::set<int> createEmptySet();

    // Exercise 2: Create and return a set containing the given elements
    static std::set<int> createSetWithElements(const std::vector<int>& elements);

    // Exercise 3: Insert an element into the set and return true if it was added (not already present)
    static bool insertElement(std::set<int>& mySet, int element);

    // Exercise 4: Check if an element exists in the set
    static bool containsElement(const std::set<int>& mySet, int element);

    // Exercise 5: Remove an element from the set and return true if it existed
    static bool removeElement(std::set<int>& mySet, int element);

    // Exercise 6: Get the size of the set
    static size_t setSize(const std::set<int>& mySet);

    // Exercise 7: Check if the set is empty
    static bool isSetEmpty(const std::set<int>& mySet);

    // Exercise 8: Clear all elements from the set
    static void clearSet(std::set<int>& mySet);

    // Exercise 9: Find an element in the set and return an iterator to it, or set::end() if not found
    static std::set<int>::iterator findElement(std::set<int>& mySet, int element);

    // Exercise 10: Get all elements from the set as a vector (in sorted order)
    static std::vector<int> setToVector(const std::set<int>& mySet);

    // Exercise 11: Create and return a set containing elements from two input sets (union)
    static std::set<int> setUnion(const std::set<int>& set1, const std::set<int>& set2);

    // Exercise 12: Create and return a set containing only elements present in both input sets (intersection)
    static std::set<int> setIntersection(const std::set<int>& set1, const std::set<int>& set2);
};

#endif // SET_OPERATIONS_EXERCISES_H