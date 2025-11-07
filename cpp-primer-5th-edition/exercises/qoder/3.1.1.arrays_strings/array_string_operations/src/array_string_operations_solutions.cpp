// Solution 3.1.1c: Array and String Operations
// This exercise demonstrates combining arrays and strings to solve practical problems.

#include <iostream>
#include <string>
#include <cstring>

int main() {
    // Solution: Create an array of strings
    std::string fruits[5] = {"apple", "banana", "cherry", "date", "elderberry"};
    
    std::cout << "Fruit array:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "fruits[" << i << "] = \"" << fruits[i] << "\"" << std::endl;
    }
    
    // Solution: Process an array of strings
    // Find the longest string in the array
    std::string longest = fruits[0];
    for (int i = 1; i < 5; i++) {
        if (fruits[i].length() > longest.length()) {
            longest = fruits[i];
        }
    }
    std::cout << "Longest fruit name: \"" << longest << "\" (length: " << longest.length() << ")" << std::endl;
    
    // Count strings that start with a specific character
    char start_char = 'c';
    int count = 0;
    for (int i = 0; i < 5; i++) {
        if (!fruits[i].empty() && fruits[i][0] == start_char) {
            count++;
        }
    }
    std::cout << "Number of fruits starting with '" << start_char << "': " << count << std::endl;
    
    // Concatenate all strings in the array
    std::string all_fruits;
    for (int i = 0; i < 5; i++) {
        if (i > 0) {
            all_fruits += ", ";
        }
        all_fruits += fruits[i];
    }
    std::cout << "All fruits: \"" << all_fruits << "\"" << std::endl;
    
    // Solution: Work with character arrays (C-style strings)
    char c_string1[] = "Hello";
    char c_string2[20];
    
    // Calculate the length of the character array
    size_t len = strlen(c_string1);
    std::cout << "Length of \"" << c_string1 << "\": " << len << std::endl;
    
    // Copy one character array to another
    strcpy(c_string2, c_string1);
    std::cout << "Copied string: \"" << c_string2 << "\"" << std::endl;
    
    // Concatenate character arrays
    strcat(c_string2, " World");
    std::cout << "Concatenated string: \"" << c_string2 << "\"" << std::endl;
    
    // Solution: Convert between std::string and C-style strings
    std::string cpp_string = "C++ String";
    std::cout << "C++ string: \"" << cpp_string << "\"" << std::endl;
    
    // Convert std::string to C-style string
    const char* c_str = cpp_string.c_str();
    std::cout << "C-style string: \"" << c_str << "\"" << std::endl;
    
    // Create std::string from C-style string
    std::string new_cpp_string(c_str);
    std::cout << "New C++ string: \"" << new_cpp_string << "\"" << std::endl;
    
    // Solution: Compare string arrays
    std::string array1[3] = {"red", "green", "blue"};
    std::string array2[3] = {"red", "green", "blue"};
    std::string array3[3] = {"red", "yellow", "blue"};
    
    // Check if two string arrays are equal
    bool arrays_equal = true;
    for (int i = 0; i < 3; i++) {
        if (array1[i] != array2[i]) {
            arrays_equal = false;
            break;
        }
    }
    std::cout << "Array1 and Array2 are " << (arrays_equal ? "equal" : "not equal") << std::endl;
    
    // Find common strings between two arrays
    std::cout << "Common strings between Array1 and Array3:" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (array1[i] == array3[j]) {
                std::cout << "  \"" << array1[i] << "\"" << std::endl;
            }
        }
    }
    
    return 0;
}