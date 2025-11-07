#include "io_library_solutions.h"
#include <iomanip>
#include <sstream>

namespace cpp_primer {

// ========== CONSTRUCTORS ==========

IOLibrarySolutions::IOLibrarySolutions() {
    // Default constructor implementation
}

// ========== CONSOLE I/O ==========

std::string IOLibrarySolutions::read_string_from_console() {
    // Read a string from standard input
    std::string input;
    std::getline(std::cin, input);
    return input;
}

int IOLibrarySolutions::read_integer_from_console() {
    // Read an integer from standard input
    int input;
    std::cin >> input;
    return input;
}

void IOLibrarySolutions::write_string_to_console(const std::string& text) {
    // Write a string to standard output
    std::cout << text;
}

void IOLibrarySolutions::write_integer_to_console(int number) {
    // Write an integer to standard output
    std::cout << number;
}

// ========== FILE I/O ==========

bool IOLibrarySolutions::write_to_file(const std::string& filename, const std::string& content) {
    // Write content to a file
    std::ofstream file(filename);
    if (file.is_open()) {
        file << content;
        file.close();
        return true;
    }
    return false;
}

std::string IOLibrarySolutions::read_from_file(const std::string& filename) {
    // Read content from a file
    std::ifstream file(filename);
    std::string content;
    if (file.is_open()) {
        std::stringstream buffer;
        buffer << file.rdbuf();
        content = buffer.str();
        file.close();
    }
    return content;
}

bool IOLibrarySolutions::append_to_file(const std::string& filename, const std::string& content) {
    // Append content to a file
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << content;
        file.close();
        return true;
    }
    return false;
}

// ========== STREAM MANIPULATORS ==========

std::string IOLibrarySolutions::format_double(double value, int precision) {
    // Format a double with specified precision
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(precision) << value;
    return oss.str();
}

void IOLibrarySolutions::write_formatted_output(std::ostream& os, const std::string& text, int number) {
    // Write formatted output to a stream
    os << std::setw(10) << text << " : " << std::setw(5) << number << std::endl;
}

} // namespace cpp_primer