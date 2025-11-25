#include <gtest/gtest.h>
#include <random>

// Test for random number generator creation
TEST(RandomNumbersTest, GeneratorCreation) {
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Test that generator produces values
    std::uniform_int_distribution<int> dist(1, 10);
    int value = dist(gen);
    EXPECT_GE(value, 1);
    EXPECT_LE(value, 10);
    
    SUCCEED() << "Random number generator created and working";
}

// Test for uniform integer distribution
TEST(RandomNumbersTest, UniformIntDistribution) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 6); // Like a dice
    
    // Generate several values and check they're in range
    for (int i = 0; i < 100; ++i) {
        int value = dist(gen);
        EXPECT_GE(value, 1);
        EXPECT_LE(value, 6);
    }
}

// Test for uniform real distribution
TEST(RandomNumbersTest, UniformRealDistribution) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    
    // Generate several values and check they're in range
    for (int i = 0; i < 100; ++i) {
        double value = dist(gen);
        EXPECT_GE(value, 0.0);
        EXPECT_LE(value, 1.0);
    }
}

// Test for normal distribution
TEST(RandomNumbersTest, NormalDistribution) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<double> dist(0.0, 1.0);
    
    // Generate several values - most should be within a few standard deviations
    int within_three_stddev = 0;
    for (int i = 0; i < 1000; ++i) {
        double value = dist(gen);
        if (value >= -3.0 && value <= 3.0) {
            within_three_stddev++;
        }
    }
    
    // About 99.7% of values should be within 3 standard deviations
    EXPECT_GT(within_three_stddev, 950);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}