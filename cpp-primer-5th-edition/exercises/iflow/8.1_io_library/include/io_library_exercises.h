#ifndef IO_LIBRARY_EXERCISES_H
#define IO_LIBRARY_EXERCISES_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

namespace cpp_primer {

/**
 * @class IOLibrary
 * @brief Student implementation for C++ IO library exercise
 * 
 * This exercise focuses on input/output operations in C++.
 * 
 * Learning Objectives:
 * - Understand basic input/output using streams
 * - Practice file input/output operations
 * - Learn stream manipulators and formatting
 * - Understand error handling with streams
 */
class IOLibrary {
public:
    // ========== CONSTRUCTORS ==========
    
    /**
     * @brief Default constructor
     */
    IOLibrary();
    
    // ========== CONSOLE I/O ==========
    
    /**
     * @brief Read a string from standard input
     * @return The string read from input
     */
    std::string read_string_from_console();
    
    /**
     * @brief Read an integer from standard input
     * @return The integer read from input
     */
    int read_integer_from_console();
    
    /**
     * @brief Write a string to standard output
     * @param text The string to write
     */
    void write_string_to_console(const std::string& text);
    
    /**
     * @brief Write an integer to standard output
     * @param number The integer to write
     */
    void write_integer_to_console(int number);
    
    // ========== FILE I/O ==========
    
    /**
     * @brief Write content to a file
     * @param filename Name of the file to write to
     * @param content Content to write
     * @return True if successful, false otherwise
     */
    bool write_to_file(const std::string& filename, const std::string& content);
    
    /**
     * @brief Read content from a file
     * @param filename Name of the file to read from
     * @return Content of the file as a string
     */
    std::string read_from_file(const std::string& filename);
    
    /**
     * @brief Append content to a file
     * @param filename Name of the file to append to
     * @param content Content to append
     * @return True if successful, false otherwise
     */
    bool append_to_file(const std::string& filename, const std::string& content);
    
    // ========== STREAM MANIPULATORS ==========
    
    /**
     * @brief Format and output a double with specified precision
     * @param value The double value to format
     * @param precision The number of decimal places
     * @return Formatted string representation
     */
    std::string format_double(double value, int precision);
    
    /**
     * @brief Write formatted output to a stream
     * @param os Output stream to write to
     * @param text Text to write
     * @param number Number to write
     */
    void write_formatted_output(std::ostream& os, const std::string& text, int number);
    
private:
    // Member variables can be added here if needed
};

} // namespace cpp_primer

#endif // IO_LIBRARY_EXERCISES_H