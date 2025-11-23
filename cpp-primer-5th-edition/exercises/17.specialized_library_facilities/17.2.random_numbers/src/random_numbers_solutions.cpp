// Exercise 17.1b: Random Number Generation - Solution
// This exercise demonstrates random number generation in C++.

#include <iostream>
#include <random>

int main() {
    // Create random number generators
    std::random_device rd;  // Non-deterministic seed
    std::mt19937 gen(rd()); // Mersenne Twister generator
    
    // Use different distributions
    // Uniform integer distribution
    std::uniform_int_distribution<int> int_dist(1, 100);
    std::cout << "Random integers between 1 and 100: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << int_dist(gen) << " ";
    }
    std::cout << std::endl;
    
    // Uniform real distribution
    std::uniform_real_distribution<double> real_dist(0.0, 1.0);
    std::cout << "Random doubles between 0.0 and 1.0: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << real_dist(gen) << " ";
    }
    std::cout << std::endl;
    
    // Normal distribution
    std::normal_distribution<double> normal_dist(0.0, 1.0);
    std::cout << "Normally distributed numbers (mean=0, stddev=1): ";
    for (int i = 0; i < 5; ++i) {
        std::cout << normal_dist(gen) << " ";
    }
    std::cout << std::endl;
    
    // Generate random numbers with different distributions
    // Dice roll simulation (1-6)
    std::uniform_int_distribution<int> dice(1, 6);
    std::cout << "Dice rolls: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << dice(gen) << " ";
    }
    std::cout << std::endl;
    
    // Probability distribution (0.0-1.0)
    std::cout << "Probability values: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << real_dist(gen) << " ";
    }
    std::cout << std::endl;
    
    return 0;
}