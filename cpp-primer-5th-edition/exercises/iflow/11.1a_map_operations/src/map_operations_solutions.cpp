#include "map_operations_solutions.h"

namespace cpp_primer {

// ========== CONSTRUCTORS ==========

MapOperationsSolutions::MapOperationsSolutions() {
    // Default constructor implementation
}

// ========== MAP CREATION AND INITIALIZATION ==========

std::map<std::string, int> MapOperationsSolutions::create_empty_map() {
    // Create and return an empty map
    return std::map<std::string, int>();
}

std::map<std::string, int> MapOperationsSolutions::create_map_with_pairs(const std::vector<std::pair<std::string, int>>& pairs) {
    // Create a map with initial key-value pairs
    std::map<std::string, int> m;
    for (const auto& pair : pairs) {
        m.insert(pair);
    }
    return m;
}

template<typename Iterator>
std::map<std::string, int> MapOperationsSolutions::create_map_with_range(Iterator begin, Iterator end) {
    // Create a map with a range of elements
    return std::map<std::string, int>(begin, end);
}

// ========== MAP INSERTION ==========

void MapOperationsSolutions::insert_pair(std::map<std::string, int>& m, const std::string& key, int value) {
    // Insert a key-value pair into a map
    m[key] = value;
}

bool MapOperationsSolutions::insert_if_not_present(std::map<std::string, int>& m, const std::string& key, int value) {
    // Insert a key-value pair only if the key doesn't exist
    auto result = m.insert({key, value});
    return result.second;  // second element of pair indicates if insertion happened
}

// ========== MAP LOOKUP ==========

int MapOperationsSolutions::get_value(const std::map<std::string, int>& m, const std::string& key) {
    // Get a value from a map by key
    auto it = m.find(key);
    if (it != m.end()) {
        return it->second;
    }
    return 0;  // Key not found
}

bool MapOperationsSolutions::key_exists(const std::map<std::string, int>& m, const std::string& key) {
    // Check if a key exists in a map
    return m.find(key) != m.end();
}

int MapOperationsSolutions::count_key(const std::map<std::string, int>& m, const std::string& key) {
    // Count occurrences of a key in a map (0 or 1 for map)
    return m.count(key);
}

// ========== MAP MODIFICATION ==========

bool MapOperationsSolutions::update_value(std::map<std::string, int>& m, const std::string& key, int new_value) {
    // Update a value in a map by key
    auto it = m.find(key);
    if (it != m.end()) {
        it->second = new_value;
        return true;
    }
    return false;
}

bool MapOperationsSolutions::remove_key(std::map<std::string, int>& m, const std::string& key) {
    // Remove a key-value pair from a map
    return m.erase(key) > 0;
}

// ========== MAP ITERATION ==========

std::vector<std::string> MapOperationsSolutions::get_all_keys(const std::map<std::string, int>& m) {
    // Get all keys from a map
    std::vector<std::string> keys;
    for (const auto& pair : m) {
        keys.push_back(pair.first);
    }
    return keys;
}

std::vector<int> MapOperationsSolutions::get_all_values(const std::map<std::string, int>& m) {
    // Get all values from a map
    std::vector<int> values;
    for (const auto& pair : m) {
        values.push_back(pair.second);
    }
    return values;
}

size_t MapOperationsSolutions::get_size(const std::map<std::string, int>& m) {
    // Count the number of elements in a map
    return m.size();
}

// Explicit template instantiation to avoid linker errors
template std::map<std::string, int> MapOperationsSolutions::create_map_with_range<std::vector<std::pair<std::string, int>>::const_iterator>(
    std::vector<std::pair<std::string, int>>::const_iterator, 
    std::vector<std::pair<std::string, int>>::const_iterator);

} // namespace cpp_primer