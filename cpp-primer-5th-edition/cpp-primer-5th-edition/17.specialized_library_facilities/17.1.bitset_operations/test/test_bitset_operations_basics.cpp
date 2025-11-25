#include <gtest/gtest.h>
#include <bitset>

// Test for bitset creation and initialization
TEST(BitsetOperationsTest, BitsetCreation) {
    std::bitset<8> bits1;
    EXPECT_EQ(bits1.size(), 8);
    EXPECT_EQ(bits1.count(), 0);
    
    std::bitset<8> bits2(std::string("10101010"));
    EXPECT_EQ(bits2.size(), 8);
    EXPECT_EQ(bits2.count(), 4);
    EXPECT_EQ(bits2.to_string(), "10101010");
    
    std::bitset<4> bits3(0b1010);
    EXPECT_EQ(bits3.size(), 4);
    EXPECT_EQ(bits3.count(), 2);
    EXPECT_EQ(bits3.to_ulong(), 10);
}

// Test for bitwise operations
TEST(BitsetOperationsTest, BitwiseOperations) {
    std::bitset<4> bits1(std::string("1010"));
    std::bitset<4> bits2(std::string("1100"));
    
    // Test AND operation
    std::bitset<4> and_result = bits1 & bits2;
    EXPECT_EQ(and_result.to_string(), "1000");
    
    // Test OR operation
    std::bitset<4> or_result = bits1 | bits2;
    EXPECT_EQ(or_result.to_string(), "1110");
    
    // Test XOR operation
    std::bitset<4> xor_result = bits1 ^ bits2;
    EXPECT_EQ(xor_result.to_string(), "0110");
    
    // Test NOT operation
    std::bitset<4> not_result = ~bits1;
    EXPECT_EQ(not_result.to_string(), "0101");
}

// Test for bitset member functions
TEST(BitsetOperationsTest, MemberFunctions) {
    std::bitset<8> bits;
    
    // Test set function
    bits.set(0);
    bits.set(2);
    EXPECT_TRUE(bits.test(0));
    EXPECT_TRUE(bits.test(2));
    EXPECT_FALSE(bits.test(1));
    
    // Test reset function
    bits.reset(0);
    EXPECT_FALSE(bits.test(0));
    
    // Test flip function
    bits.flip(1);
    EXPECT_TRUE(bits.test(1));
    
    // Test count and any functions
    EXPECT_EQ(bits.count(), 2);
    EXPECT_TRUE(bits.any());
    
    // Test all and none functions
    EXPECT_FALSE(bits.all());
    bits.set(); // Set all bits
    EXPECT_TRUE(bits.all());
    bits.reset(); // Reset all bits
    EXPECT_TRUE(bits.none());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}