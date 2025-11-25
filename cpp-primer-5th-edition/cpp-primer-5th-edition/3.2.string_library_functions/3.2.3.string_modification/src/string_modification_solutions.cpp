// Exercise: String Modification - Solution
// This exercise demonstrates string modification functions in C++.

#include <iostream>
#include <string>

int main() {
    // Solution: Use replace() to substitute parts of strings
    std::string text = "Hello, World! Welcome to C++!";
    
    // Replace "World" with "C++"
    text.replace(7, 5, "C++");
    std::cout << "After replace: " << text << std::endl;
    
    // Replace with different length string
    text.replace(0, 5, "Hi");
    std::cout << "After second replace: " << text << std::endl;
    
    // Replace single character
    text.replace(3, 1, 1, '!');
    std::cout << "After character replace: " << text << std::endl;

    // Solution: Use erase() to remove parts of strings
    std::string sentence = "The quick brown fox jumps over the lazy dog";
    
    // Erase "brown " (5 characters starting at position 10)
    sentence.erase(10, 6);
    std::cout << "After erase: " << sentence << std::endl;
    
    // Erase single character
    sentence.erase(3, 1);  // Remove space after "The"
    std::cout << "After single char erase: " << sentence << std::endl;
    
    // Erase from position to end
    sentence.erase(25);
    std::cout << "After partial erase: " << sentence << std::endl;

    // Solution: Use insert() to add content to strings
    std::string phrase = "Hello World";
    
    // Insert string at position
    phrase.insert(6, "Beautiful ");
    std::cout << "After insert: " << phrase << std::endl;
    
    // Insert multiple characters
    phrase.insert(0, 3, '>');
    std::cout << "After character insert: " << phrase << std::endl;
    
    // Insert at end
    phrase.insert(phrase.length(), "!");
    std::cout << "After end insert: " << phrase << std::endl;

    // Solution: Use append() and operator+= to add content
    std::string message = "Hello";
    
    // Append string
    message.append(" World");
    std::cout << "After append: " << message << std::endl;
    
    // Append with operator+=
    message += "!";
    std::cout << "After +=: " << message << std::endl;
    
    // Append multiple characters
    message.append(3, '!');
    std::cout << "After multi-char append: " << message << std::endl;
    
    return 0;
}