#ifndef UNORDERED_CONTAINERS_SOLUTIONS_H
#define UNORDERED_CONTAINERS_SOLUTIONS_H

#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>

class UnorderedContainersSolutions {
public:
    // Exercise 1: Create and return an empty unordered_set of integers
    static std::unordered_set<int> createEmptyUnorderedSet();

    // Exercise 2: Create and return an unordered_set containing the given elements
    static std::unordered_set<int> createUnorderedSetWithElements(const std::vector<int>& elements);

    // Exercise 3: Insert an element into the unordered_set and return true if it was added (not already present)
    static bool insertElement(std::unordered_set<int>& mySet, int element);

    // Exercise 4: Check if an element exists in the unordered_set
    static bool containsElement(const std::unordered_set<int>& mySet, int element);

    // Exercise 5: Remove an element from the unordered_set and return true if it existed
    static bool removeElement(std::unordered_set<int>& mySet, int element);

    // Exercise 6: Get the size of the unordered_set
    static size_t setSize(const std::unordered_set<int>& mySet);

    // Exercise 7: Check if the unordered_set is empty
    static bool isSetEmpty(const std::unordered_set<int>& mySet);

    // Exercise 8: Clear all elements from the unordered_set
    static void clearSet(std::unordered_set<int>& mySet);

    // Exercise 9: Find an element in the unordered_set and return an iterator to it, or unordered_set::end() if not found
    static std::unordered_set<int>::iterator findElement(std::unordered_set<int>& mySet, int element);

    // Exercise 10: Get all elements from the unordered_set as a vector
    static std::vector<int> unorderedSetToVector(const std::unordered_set<int>& mySet);

    // Exercise 11: Create and return an empty unordered_map with string keys and int values
    static std::unordered_map<std::string, int> createEmptyUnorderedMap();

    // Exercise 12: Insert a key-value pair into the unordered_map
    // Return true if the key was inserted (not already present), false otherwise
    static bool insertKeyValue(std::unordered_map<std::string, int>& myMap, const std::string& key, int value);

    // Exercise 13: Get the value associated with a key in the unordered_map
    // Return true if the key exists and set the value parameter, false otherwise
    static bool getValue(const std::unordered_map<std::string, int>& myMap, const std::string& key, int& value);

    // Exercise 14: Check if a key exists in the unordered_map
    static bool containsKey(const std::unordered_map<std::string, int>& myMap, const std::string& key);

    // Exercise 15: Remove a key-value pair from the unordered_map and return true if it existed
    static bool removeKeyValue(std::unordered_map<std::string, int>& myMap, const std::string& key);

    // Exercise 16: Get the size of the unordered_map
    static size_t mapSize(const std::unordered_map<std::string, int>& myMap);

    // Exercise 17: Check if the unordered_map is empty
    static bool isMapEmpty(const std::unordered_map<std::string, int>& myMap);

    // Exercise 18: Clear all elements from the unordered_map
    static void clearMap(std::unordered_map<std::string, int>& myMap);
};

#endif // UNORDERED_CONTAINERS_SOLUTIONS_H