// Solution 8.1c: File Streams
// This exercise demonstrates file input/output operations in C++.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    // Solution: Read data from text files
    std::cout << "Testing file reading..." << std::endl;
    
    // Create a test file first
    std::ofstream outFile("test_input.txt");
    if (outFile.is_open()) {
        outFile << "Line 1: This is the first line" << std::endl;
        outFile << "Line 2: This is the second line" << std::endl;
        outFile << "Line 3: This is the third line" << std::endl;
        outFile.close();
    }
    
    // Read data from text file line by line
    std::ifstream inFile("test_input.txt");
    if (inFile.is_open()) {
        std::string line;
        int lineNumber = 1;
        while (std::getline(inFile, line)) {
            std::cout << "Line " << lineNumber << ": " << line << std::endl;
            lineNumber++;
        }
        inFile.close();
    } else {
        std::cout << "Failed to open file for reading" << std::endl;
    }
    std::cout << std::endl;

    // Solution: Write data to text files
    std::cout << "Testing file writing..." << std::endl;
    std::ofstream outFile2("test_output.txt");
    if (outFile2.is_open()) {
        outFile2 << "This is line 1" << std::endl;
        outFile2 << "This is line 2" << std::endl;
        outFile2 << "This is line 3" << std::endl;
        outFile2.close();
        std::cout << "Data written to test_output.txt" << std::endl;
    } else {
        std::cout << "Failed to open file for writing" << std::endl;
    }
    std::cout << std::endl;

    // Solution: Work with binary files
    std::cout << "Testing binary file operations..." << std::endl;
    
    // Write binary data
    std::vector<int> data = {1, 2, 3, 4, 5};
    std::ofstream binOut("test_binary.dat", std::ios::binary);
    if (binOut.is_open()) {
        binOut.write(reinterpret_cast<const char*>(data.data()), data.size() * sizeof(int));
        binOut.close();
        std::cout << "Binary data written successfully" << std::endl;
    } else {
        std::cout << "Failed to open binary file for writing" << std::endl;
    }
    
    // Read binary data
    std::vector<int> readData(5);
    std::ifstream binIn("test_binary.dat", std::ios::binary);
    if (binIn.is_open()) {
        binIn.read(reinterpret_cast<char*>(readData.data()), readData.size() * sizeof(int));
        binIn.close();
        
        std::cout << "Binary data read: ";
        for (int value : readData) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Failed to open binary file for reading" << std::endl;
    }

    return 0;
}