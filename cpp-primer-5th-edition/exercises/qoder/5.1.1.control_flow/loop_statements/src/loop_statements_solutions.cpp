// Solution 5.1.2: Loop Statements
// This exercise demonstrates loop statements in C++.

#include <iostream>

int main() {
    // Solution: Print numbers from 1 to 10 using a for loop
    std::cout << "Numbers from 1 to 10: ";
    for (int i = 1; i <= 10; i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    // Solution: Calculate the sum of numbers from 1 to n using a while loop
    int n, sum = 0, i = 1;
    std::cout << "Enter a number: ";
    std::cin >> n;
    
    while (i <= n) {
        sum += i;
        i++;
    }
    std::cout << "Sum of numbers from 1 to " << n << " is: " << sum << std::endl;
    
    // Solution: Repeatedly ask for input until the user enters 0 using a do-while loop
    int number;
    std::cout << "Enter numbers (enter 0 to stop):" << std::endl;
    do {
        std::cout << "Enter a number: ";
        std::cin >> number;
        if (number != 0) {
            std::cout << "You entered: " << number << std::endl;
        }
    } while (number != 0);
    std::cout << "Program ended." << std::endl;
    
    return 0;
}