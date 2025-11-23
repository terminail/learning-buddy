#include <gtest/gtest.h>
#include "exercise_name_exercises.h"

using namespace cpp_primer;

class ExerciseNameTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== CONSTRUCTOR TESTS ==========

TEST_F(ExerciseNameTest, DefaultConstructor) {
    ExerciseName exercise;
    EXPECT_EQ(exercise.get_value(), "default");
    EXPECT_EQ(exercise.get_length(), 7);
}

TEST_F(ExerciseNameTest, ParameterizedConstructor) {
    ExerciseName exercise("test");
    EXPECT_EQ(exercise.get_value(), "test");
    EXPECT_EQ(exercise.get_length(), 4);
}

TEST_F(ExerciseNameTest, ParameterizedConstructorEmptyString) {
    EXPECT_THROW(ExerciseName exercise(""), std::invalid_argument);
}

TEST_F(ExerciseNameTest, CopyConstructor) {
    ExerciseName original("original");
    ExerciseName copy(original);
    EXPECT_EQ(copy.get_value(), "original");
    EXPECT_EQ(copy.get_length(), 8);
}

// ========== BASIC OPERATION TESTS ==========

TEST_F(ExerciseNameTest, BasicOperation) {
    ExerciseName exercise;
    EXPECT_EQ(exercise.basic_operation("hello"), "hello_processed");
}

TEST_F(ExerciseNameTest, BasicOperationEmpty) {
    ExerciseName exercise;
    EXPECT_EQ(exercise.basic_operation(""), "empty");
}

TEST_F(ExerciseNameTest, CombineStrings) {
    ExerciseName exercise;
    EXPECT_EQ(exercise.combine_strings("Hello", "World"), "Hello World");
}

TEST_F(ExerciseNameTest, CombineStringsFirstEmpty) {
    ExerciseName exercise;
    EXPECT_EQ(exercise.combine_strings("", "World"), "World");
}

TEST_F(ExerciseNameTest, CombineStringsSecondEmpty) {
    ExerciseName exercise;
    EXPECT_EQ(exercise.combine_strings("Hello", ""), "Hello");
}

TEST_F(ExerciseNameTest, CombineStringsBothEmpty) {
    ExerciseName exercise;
    EXPECT_EQ(exercise.combine_strings("", ""), "");
}

// ========== INTERMEDIATE OPERATION TESTS ==========

TEST_F(ExerciseNameTest, CountCharacter) {
    ExerciseName exercise;
    EXPECT_EQ(exercise.count_character("hello world", 'l'), 3);
    EXPECT_EQ(exercise.count_character("HELLO", 'l'), 2);
}

TEST_F(ExerciseNameTest, CountCharacterEmpty) {
    ExerciseName exercise;
    EXPECT_EQ(exercise.count_character("", 'a'), 0);
}

TEST_F(ExerciseNameTest, CountCharacterNotFound) {
    ExerciseName exercise;
    EXPECT_EQ(exercise.count_character("hello", 'z'), 0);
}

TEST_F(ExerciseNameTest, ReverseString) {
    ExerciseName exercise;
    EXPECT_EQ(exercise.reverse_string("hello"), "olleh");
    EXPECT_EQ(exercise.reverse_string("racecar"), "racecar");
}

TEST_F(ExerciseNameTest, ReverseStringEmpty) {
    ExerciseName exercise;
    EXPECT_EQ(exercise.reverse_string(""), "");
}

TEST_F(ExerciseNameTest, RemoveDuplicates) {
    ExerciseName exercise;
    EXPECT_EQ(exercise.remove_duplicates("aabbcc"), "abc");
    EXPECT_EQ(exercise.remove_duplicates("hello"), "helo");
}

TEST_F(ExerciseNameTest, RemoveDuplicatesEmpty) {
    ExerciseName exercise;
    EXPECT_EQ(exercise.remove_duplicates(""), "");
}

TEST_F(ExerciseNameTest, RemoveDuplicatesNoDuplicates) {
    ExerciseName exercise;
    EXPECT_EQ(exercise.remove_duplicates("abc"), "abc");
}

// ========== ADVANCED OPERATION TESTS ==========

TEST_F(ExerciseNameTest, LongestCommonSubstring) {
    ExerciseName exercise;
    EXPECT_EQ(exercise.longest_common_substring("abcdef", "defghi"), "def");
    EXPECT_EQ(exercise.longest_common_substring("abc", "def"), "");
}

TEST_F(ExerciseNameTest, LongestCommonSubstringEmpty) {
    ExerciseName exercise;
    EXPECT_EQ(exercise.longest_common_substring("", "test"), "");
    EXPECT_EQ(exercise.longest_common_substring("test", ""), "");
}

TEST_F(ExerciseNameTest, AreAnagrams) {
    ExerciseName exercise;
    EXPECT_TRUE(exercise.are_anagrams("listen", "silent"));
    EXPECT_FALSE(exercise.are_anagrams("hello", "world"));
}

TEST_F(ExerciseNameTest, AreAnagramsCaseInsensitive) {
    ExerciseName exercise;
    EXPECT_TRUE(exercise.are_anagrams("Listen", "Silent"));
}

TEST_F(ExerciseNameTest, AreAnagramsDifferentLength) {
    ExerciseName exercise;
    EXPECT_FALSE(exercise.are_anagrams("hello", "hell"));
}

TEST_F(ExerciseNameTest, CompressString) {
    ExerciseName exercise;
    EXPECT_EQ(exercise.compress_string("aaabbbccc"), "a3b3c3");
    EXPECT_EQ(exercise.compress_string("abc"), "abc");  // Should return original if not shorter
}

TEST_F(ExerciseNameTest, CompressStringEmpty) {
    ExerciseName exercise;
    EXPECT_EQ(exercise.compress_string(""), "");
}

TEST_F(ExerciseNameTest, CompressStringSingleChar) {
    ExerciseName exercise;
    EXPECT_EQ(exercise.compress_string("aaaaa"), "a5");
}

// ========== GETTER/SETTER TESTS ==========

TEST_F(ExerciseNameTest, GetSetValue) {
    ExerciseName exercise;
    exercise.set_value("new value");
    EXPECT_EQ(exercise.get_value(), "new value");
    EXPECT_EQ(exercise.get_length(), 9);
}

TEST_F(ExerciseNameTest, SetValueEmpty) {
    ExerciseName exercise;
    EXPECT_THROW(exercise.set_value(""), std::invalid_argument);
}

TEST_F(ExerciseNameTest, GetLength) {
    ExerciseName exercise("testing");
    EXPECT_EQ(exercise.get_length(), 7);
}

// ========== INTEGRATION TESTS ==========

TEST_F(ExerciseNameTest, IntegrationTest) {
    ExerciseName exercise("integration");
    
    // Test multiple operations together
    exercise.set_value("test");
    EXPECT_EQ(exercise.get_value(), "test");
    
    std::string basic = exercise.basic_operation("input");
    EXPECT_EQ(basic, "input_processed");
    
    std::string combined = exercise.combine_strings("Hello", "World");
    EXPECT_EQ(combined, "Hello World");
    
    int count = exercise.count_character("hello", 'l');
    EXPECT_EQ(count, 2);
}

// ========== STATE PERSISTENCE TESTS ==========

TEST_F(ExerciseNameTest, StatePersistence) {
    ExerciseName exercise("initial");
    EXPECT_EQ(exercise.get_value(), "initial");
    
    // Perform operations that shouldn't change internal state
    exercise.basic_operation("test");
    exercise.combine_strings("a", "b");
    exercise.count_character("test", 't');
    
    // Internal state should remain unchanged
    EXPECT_EQ(exercise.get_value(), "initial");
}

// ========== STRESS TESTS ==========

TEST_F(ExerciseNameTest, StressTestLongStrings) {
    ExerciseName exercise;
    
    std::string long_string(1000, 'a');
    std::string result = exercise.combine_strings(long_string, "b");
    EXPECT_EQ(result.length(), 1002);
    
    std::string reversed = exercise.reverse_string(long_string);
    EXPECT_EQ(reversed.length(), 1000);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}