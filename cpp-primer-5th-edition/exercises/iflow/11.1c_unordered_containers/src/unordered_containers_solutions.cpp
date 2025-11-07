#include "unordered_containers_solutions.h"

// Exercise 1: Create and return an empty unordered_set of integers
std::unordered_set<int> UnorderedContainersSolutions::createEmptyUnorderedSet() {
    return std::unordered_set<int>();
}

// Exercise 2: Create and return an unordered_set containing the given elements
std::unordered_set<int> UnorderedContainersSolutions::createUnorderedSetWithElements(const std::vector<int>& elements) {
    return std::unordered_set<int>(elements.begin(), elements.end());
}

// Exercise 3: Insert an element into the unordered_set and return true if it was added (not already present)
bool UnorderedContainersSolutions::insertElement(std::unordered_set<int>& mySet, int element) {
    auto result = mySet.insert(element);
    return result.second;  // insert returns a pair, second is true if element was inserted
}

// Exercise 4: Check if an element exists in the unordered_set
bool UnorderedContainersSolutions::containsElement(const std::unordered_set<int>& mySet, int element) {
    return mySet.find(element) != mySet.end();
}

// Exercise 5: Remove an element from the unordered_set and return true if it existed
bool UnorderedContainersSolutions::removeElement(std::unordered_set<int>& mySet, int element) {
    size_t oldSize = mySet.size();
    mySet.erase(element);
    return mySet.size() < oldSize;  // If size decreased, element existed
}

// Exercise 6: Get the size of the unordered_set
size_t UnorderedContainersSolutions::setSize(const std::unordered_set<int>& mySet) {
    return mySet.size();
}

// Exercise 7: Check if the unordered_set is empty
bool UnorderedContainersSolutions::isSetEmpty(const std::unordered_set<int>& mySet) {
    return mySet.empty();
}

// Exercise 8: Clear all elements from the unordered_set
void UnorderedContainersSolutions::clearSet(std::unordered_set<int>& mySet) {
    mySet.clear();
}

// Exercise 9: Find an element in the unordered_set and return an iterator to it, or unordered_set::end() if not found
std::unordered_set<int>::iterator UnorderedContainersSolutions::findElement(std::unordered_set<int>& mySet, int element) {
    return mySet.find(element);
}

// Exercise 10: Get all elements from the unordered_set as a vector
std::vector<int> UnorderedContainersSolutions::unorderedSetToVector(const std::unordered_set<int>& mySet) {
    return std::vector<int>(mySet.begin(), mySet.end());
}

// Exercise 11: Create and return an empty unordered_map with string keys and int values
std::unordered_map<std::string, int> UnorderedContainersSolutions::createEmptyUnorderedMap() {
    return std::unordered_map<std::string, int>();
}

// Exercise 12: Insert a key-value pair into the unordered_map
// Return true if the key was inserted (not already present), false otherwise
bool UnorderedContainersSolutions::insertKeyValue(std::unordered_map<std::string, int>& myMap, const std::string& key, int value) {
    auto result = myMap.insert({key, value});
    return result.second;  // insert returns a pair, second is true if key was inserted
}

// Exercise 13: Get the value associated with a key in the unordered_map
// Return true if the key exists and set the value parameter, false otherwise
bool UnorderedContainersSolutions::getValue(const std::unordered_map<std::string, int>& myMap, const std::string& key, int& value) {
    auto it = myMap.find(key);
    if (it != myMap.end()) {
        value = it->second;
        return true;
    }
    return false;
}

// Exercise 14: Check if a key exists in the unordered_map
bool UnorderedContainersSolutions::containsKey(const std::unordered_map<std::string, int>& myMap, const std::string& key) {
    return myMap.find(key) != myMap.end();
}

// Exercise 15: Remove a key-value pair from the unordered_map and return true if it existed
bool UnorderedContainersSolutions::removeKeyValue(std::unordered_map<std::string, int>& myMap, const std::string& key) {
    size_t oldSize = myMap.size();
    myMap.erase(key);
    return myMap.size() < oldSize;  // If size decreased, key existed
}

// Exercise 16: Get the size of the unordered_map
size_t UnorderedContainersSolutions::mapSize(const std::unordered_map<std::string, int>& myMap) {
    return myMap.size();
}

// Exercise 17: Check if the unordered_map is empty
bool UnorderedContainersSolutions::isMapEmpty(const std::unordered_map<std::string, int>& myMap) {
    return myMap.empty();
}

// Exercise 18: Clear all elements from the unordered_map
void UnorderedContainersSolutions::clearMap(std::unordered_map<std::string, int>& myMap) {
    myMap.clear();
}