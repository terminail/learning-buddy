#include "set_operations_exercises.h"
#include <set>
#include <vector>
#include <algorithm>

// TODO: Implement the functions according to the specifications below.
// Each function has a comment explaining what you need to implement.

// Exercise 1: Create and return an empty set of integers
std::set<int> SetOperations::createEmptySet() {
    // TODO: Create and return an empty set of integers
    // YOUR CODE HERE
}

// Exercise 2: Create and return a set containing the given elements
std::set<int> SetOperations::createSetWithElements(const std::vector<int>& elements) {
    // TODO: Create a set and insert all elements from the vector
    // Remember that sets automatically sort and remove duplicates
    // YOUR CODE HERE
}

// Exercise 3: Insert an element into the set and return true if it was added (not already present)
bool SetOperations::insertElement(std::set<int>& mySet, int element) {
    // TODO: Insert the element into the set and return true if it was actually added
    // (i.e., return false if the element was already in the set)
    // YOUR CODE HERE
}

// Exercise 4: Check if an element exists in the set
bool SetOperations::containsElement(const std::set<int>& mySet, int element) {
    // TODO: Return true if the element exists in the set, false otherwise
    // YOUR CODE HERE
}

// Exercise 5: Remove an element from the set and return true if it existed
bool SetOperations::removeElement(std::set<int>& mySet, int element) {
    // TODO: Remove the element from the set and return true if it existed
    // YOUR CODE HERE
}

// Exercise 6: Get the size of the set
size_t SetOperations::setSize(const std::set<int>& mySet) {
    // TODO: Return the number of elements in the set
    // YOUR CODE HERE
}

// Exercise 7: Check if the set is empty
bool SetOperations::isSetEmpty(const std::set<int>& mySet) {
    // TODO: Return true if the set has no elements, false otherwise
    // YOUR CODE HERE
}

// Exercise 8: Clear all elements from the set
void SetOperations::clearSet(std::set<int>& mySet) {
    // TODO: Remove all elements from the set
    // YOUR CODE HERE
}

// Exercise 9: Find an element in the set and return an iterator to it, or set::end() if not found
std::set<int>::iterator SetOperations::findElement(std::set<int>& mySet, int element) {
    // TODO: Find the element in the set and return an iterator to it
    // If the element is not found, return mySet.end()
    // YOUR CODE HERE
}

// Exercise 10: Get all elements from the set as a vector (in sorted order)
std::vector<int> SetOperations::setToVector(const std::set<int>& mySet) {
    // TODO: Convert the set to a vector, preserving the sorted order
    // YOUR CODE HERE
}

// Exercise 11: Create and return a set containing elements from two input sets (union)
std::set<int> SetOperations::setUnion(const std::set<int>& set1, const std::set<int>& set2) {
    // TODO: Create a new set that contains all elements from both sets
    // This is the union of the two sets
    // YOUR CODE HERE
}

// Exercise 12: Create and return a set containing only elements present in both input sets (intersection)
std::set<int> SetOperations::setIntersection(const std::set<int>& set1, const std::set<int>& set2) {
    // TODO: Create a new set that contains only elements present in both sets
    // This is the intersection of the two sets
    // YOUR CODE HERE
}