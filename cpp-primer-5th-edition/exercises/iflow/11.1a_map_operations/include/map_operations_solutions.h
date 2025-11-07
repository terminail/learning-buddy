#ifndef MAP_OPERATIONS_SOLUTIONS_H
#define MAP_OPERATIONS_SOLUTIONS_H

#include <string>
#include <map>
#include <vector>

namespace cpp_primer {

/**
 * @class MapOperationsSolutions
 * @brief Complete solution implementations for C++ map operations exercise
 * 
 * This class demonstrates proper usage of std::map operations.
 */
class MapOperationsSolutions {
public:
    // ========== CONSTRUCTORS ==========
    
    /**
     * @brief Default constructor
     */
    MapOperationsSolutions();
    
    // ========== MAP CREATION AND INITIALIZATION ==========
    
    /**
     * @brief Create an empty map
     * @return An empty map
     */
    std::map<std::string, int> create_empty_map();
    
    /**
     * @brief Create a map with initial key-value pairs
     * @param pairs Vector of key-value pairs to initialize the map with
     * @return A map initialized with the given pairs
     */
    std::map<std::string, int> create_map_with_pairs(const std::vector<std::pair<std::string, int>>& pairs);
    
    /**
     * @brief Create a map with a range of elements
     * @param begin Start iterator
     * @param end End iterator
     * @return A map initialized with elements from the range
     */
    template<typename Iterator>
    std::map<std::string, int> create_map_with_range(Iterator begin, Iterator end);
    
    // ========== MAP INSERTION ==========
    
    /**
     * @brief Insert a key-value pair into a map
     * @param m Reference to the map
     * @param key Key to insert
     * @param value Value to insert
     */
    void insert_pair(std::map<std::string, int>& m, const std::string& key, int value);
    
    /**
     * @brief Insert a key-value pair only if the key doesn't exist
     * @param m Reference to the map
     * @param key Key to insert
     * @param value Value to insert
     * @return True if insertion happened, false if key already existed
     */
    bool insert_if_not_present(std::map<std::string, int>& m, const std::string& key, int value);
    
    // ========== MAP LOOKUP ==========
    
    /**
     * @brief Get a value from a map by key
     * @param m Reference to the map
     * @param key Key to look up
     * @return Value associated with the key, or 0 if key not found
     */
    int get_value(const std::map<std::string, int>& m, const std::string& key);
    
    /**
     * @brief Check if a key exists in a map
     * @param m Reference to the map
     * @param key Key to check for
     * @return True if key exists, false otherwise
     */
    bool key_exists(const std::map<std::string, int>& m, const std::string& key);
    
    /**
     * @brief Count occurrences of a key in a map
     * @param m Reference to the map
     * @param key Key to count
     * @return 1 if key exists, 0 otherwise
     */
    int count_key(const std::map<std::string, int>& m, const std::string& key);
    
    // ========== MAP MODIFICATION ==========
    
    /**
     * @brief Update a value in a map by key
     * @param m Reference to the map
     * @param key Key to update
     * @param new_value New value to assign
     * @return True if key existed and was updated, false otherwise
     */
    bool update_value(std::map<std::string, int>& m, const std::string& key, int new_value);
    
    /**
     * @brief Remove a key-value pair from a map
     * @param m Reference to the map
     * @param key Key to remove
     * @return True if key existed and was removed, false otherwise
     */
    bool remove_key(std::map<std::string, int>& m, const std::string& key);
    
    // ========== MAP ITERATION ==========
    
    /**
     * @brief Get all keys from a map
     * @param m Reference to the map
     * @return Vector of keys in the map
     */
    std::vector<std::string> get_all_keys(const std::map<std::string, int>& m);
    
    /**
     * @brief Get all values from a map
     * @param m Reference to the map
     * @return Vector of values in the map
     */
    std::vector<int> get_all_values(const std::map<std::string, int>& m);
    
    /**
     * @brief Count the number of elements in a map
     * @param m Reference to the map
     * @return Number of key-value pairs in the map
     */
    size_t get_size(const std::map<std::string, int>& m);
    
private:
    // Member variables can be added here if needed
};

} // namespace cpp_primer

#endif // MAP_OPERATIONS_SOLUTIONS_H