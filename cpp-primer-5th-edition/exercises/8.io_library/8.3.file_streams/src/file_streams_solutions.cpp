// Exercise 8.1c: File Streams - Solution
// This exercise demonstrates file input/output operations in C++.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    // Write data to a text file
    std::ofstream output_file("example.txt");
    if (output_file.is_open()) {
        output_file << "This is line 1\n";
        output_file << "This is line 2\n";
        output_file << "This is line 3 with a number: 42\n";
        output_file.close();
        std::cout << "Data written to example.txt successfully!" << std::endl;
    } else {
        std::cout << "Failed to open file for writing!" << std::endl;
    }
    
    // Read data from the text file
    std::ifstream input_file("example.txt");
    if (input_file.is_open()) {
        std::string line;
        std::cout << "Reading from example.txt:" << std::endl;
        while (std::getline(input_file, line)) {
            std::cout << line << std::endl;
        }
        input_file.close();
    } else {
        std::cout << "Failed to open file for reading!" << std::endl;
    }
    
    // Work with binary files
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    // Write binary data
    std::ofstream binary_output("numbers.bin", std::ios::binary);
    if (binary_output.is_open()) {
        binary_output.write(reinterpret_cast<const char*>(numbers.data()), 
                           numbers.size() * sizeof(int));
        binary_output.close();
        std::cout << "Binary data written to numbers.bin successfully!" << std::endl;
    } else {
        std::cout << "Failed to open binary file for writing!" << std::endl;
    }
    
    // Read binary data
    std::vector<int> read_numbers(5);
    std::ifstream binary_input("numbers.bin", std::ios::binary);
    if (binary_input.is_open()) {
        binary_input.read(reinterpret_cast<char*>(read_numbers.data()), 
                         read_numbers.size() * sizeof(int));
        binary_input.close();
        
        std::cout << "Reading binary data from numbers.bin:" << std::endl;
        for (int num : read_numbers) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Failed to open binary file for reading!" << std::endl;
    }
    
    return 0;
}