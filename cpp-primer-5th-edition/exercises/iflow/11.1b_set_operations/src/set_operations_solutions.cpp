#include "set_operations_solutions.h"
#include <algorithm>

// Exercise 1: Create and return an empty set of integers
std::set<int> SetOperationsSolutions::createEmptySet() {
    return std::set<int>();
}

// Exercise 2: Create and return a set containing the given elements
std::set<int> SetOperationsSolutions::createSetWithElements(const std::vector<int>& elements) {
    return std::set<int>(elements.begin(), elements.end());
}

// Exercise 3: Insert an element into the set and return true if it was added (not already present)
bool SetOperationsSolutions::insertElement(std::set<int>& mySet, int element) {
    auto result = mySet.insert(element);
    return result.second;  // insert returns a pair, second is true if element was inserted
}

// Exercise 4: Check if an element exists in the set
bool SetOperationsSolutions::containsElement(const std::set<int>& mySet, int element) {
    return mySet.find(element) != mySet.end();
}

// Exercise 5: Remove an element from the set and return true if it existed
bool SetOperationsSolutions::removeElement(std::set<int>& mySet, int element) {
    size_t oldSize = mySet.size();
    mySet.erase(element);
    return mySet.size() < oldSize;  // If size decreased, element existed
}

// Exercise 6: Get the size of the set
size_t SetOperationsSolutions::setSize(const std::set<int>& mySet) {
    return mySet.size();
}

// Exercise 7: Check if the set is empty
bool SetOperationsSolutions::isSetEmpty(const std::set<int>& mySet) {
    return mySet.empty();
}

// Exercise 8: Clear all elements from the set
void SetOperationsSolutions::clearSet(std::set<int>& mySet) {
    mySet.clear();
}

// Exercise 9: Find an element in the set and return an iterator to it, or set::end() if not found
std::set<int>::iterator SetOperationsSolutions::findElement(std::set<int>& mySet, int element) {
    return mySet.find(element);
}

// Exercise 10: Get all elements from the set as a vector (in sorted order)
std::vector<int> SetOperationsSolutions::setToVector(const std::set<int>& mySet) {
    return std::vector<int>(mySet.begin(), mySet.end());
}

// Exercise 11: Create and return a set containing elements from two input sets (union)
std::set<int> SetOperationsSolutions::setUnion(const std::set<int>& set1, const std::set<int>& set2) {
    std::set<int> result;
    std::set_union(set1.begin(), set1.end(),
                   set2.begin(), set2.end(),
                   std::inserter(result, result.begin()));
    return result;
}

// Exercise 12: Create and return a set containing only elements present in both input sets (intersection)
std::set<int> SetOperationsSolutions::setIntersection(const std::set<int>& set1, const std::set<int>& set2) {
    std::set<int> result;
    std::set_intersection(set1.begin(), set1.end(),
                          set2.begin(), set2.end(),
                          std::inserter(result, result.begin()));
    return result;
}