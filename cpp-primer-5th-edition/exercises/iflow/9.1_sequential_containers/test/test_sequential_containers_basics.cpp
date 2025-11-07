#include <gtest/gtest.h>
#include "sequential_containers_exercises.h"
#include <vector>
#include <list>
#include <deque>

using namespace cpp_primer;

class SequentialContainersTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code before each test
    }
    
    void TearDown() override {
        // Cleanup code after each test
    }
};

// ========== CONSTRUCTOR TESTS ==========

TEST_F(SequentialContainersTest, DefaultConstructor) {
    SequentialContainers exercise;
    // Constructor should not throw
    SUCCEED();
}

// ========== VECTOR OPERATION TESTS ==========

TEST_F(SequentialContainersTest, CreateVector) {
    SequentialContainers exercise;
    
    // Test creating vector with size and initial value
    std::vector<int> result = exercise.create_vector(5, 10);
    EXPECT_EQ(result.size(), 5) << "Expected vector size to be 5";
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(result[i], 10) << "Expected all elements to be 10";
    }
}

TEST_F(SequentialContainersTest, AddToVector) {
    SequentialContainers exercise;
    
    // Test adding elements to vector
    std::vector<int> vec = {1, 2, 3};
    std::vector<int> elements_to_add = {4, 5, 6};
    exercise.add_to_vector(vec, elements_to_add);
    
    EXPECT_EQ(vec.size(), 6) << "Expected vector size to be 6 after adding 3 elements";
    EXPECT_EQ(vec[0], 1) << "Expected first element to be 1";
    EXPECT_EQ(vec[3], 4) << "Expected fourth element to be 4";
    EXPECT_EQ(vec[5], 6) << "Expected sixth element to be 6";
}

TEST_F(SequentialContainersTest, RemoveFromVector) {
    SequentialContainers exercise;
    
    // Test removing elements from vector
    std::vector<int> vec = {1, 2, 3, 2, 4, 2, 5};
    int removed_count = exercise.remove_from_vector(vec, 2);
    
    EXPECT_EQ(removed_count, 3) << "Expected to remove 3 elements with value 2";
    EXPECT_EQ(vec.size(), 4) << "Expected vector size to be 4 after removing 3 elements";
    EXPECT_EQ(vec[0], 1) << "Expected first element to be 1";
    EXPECT_EQ(vec[1], 3) << "Expected second element to be 3";
    EXPECT_EQ(vec[2], 4) << "Expected third element to be 4";
    EXPECT_EQ(vec[3], 5) << "Expected fourth element to be 5";
}

// ========== LIST OPERATION TESTS ==========

TEST_F(SequentialContainersTest, CreateList) {
    SequentialContainers exercise;
    
    // Test creating list with size and initial value
    std::list<int> result = exercise.create_list(3, 7);
    EXPECT_EQ(result.size(), 3) << "Expected list size to be 3";
    for (int value : result) {
        EXPECT_EQ(value, 7) << "Expected all elements to be 7";
    }
}

TEST_F(SequentialContainersTest, InsertInList) {
    SequentialContainers exercise;
    
    // Test inserting element in list at specific position
    std::list<int> lst = {1, 2, 4, 5};
    exercise.insert_in_list(lst, 2, 3);
    
    auto it = lst.begin();
    std::advance(it, 2);
    EXPECT_EQ(*it, 3) << "Expected element at position 2 to be 3";
    EXPECT_EQ(lst.size(), 5) << "Expected list size to be 5 after insertion";
}

TEST_F(SequentialContainersTest, SortList) {
    SequentialContainers exercise;
    
    // Test sorting list
    std::list<int> lst = {5, 2, 8, 1, 9};
    exercise.sort_list(lst);
    
    std::vector<int> sorted_vec(lst.begin(), lst.end());
    EXPECT_TRUE(std::is_sorted(sorted_vec.begin(), sorted_vec.end())) 
        << "Expected list to be sorted in ascending order";
}

// ========== DEQUE OPERATION TESTS ==========

TEST_F(SequentialContainersTest, CreateDeque) {
    SequentialContainers exercise;
    
    // Test creating deque with size and initial value
    std::deque<int> result = exercise.create_deque(4, 6);
    EXPECT_EQ(result.size(), 4) << "Expected deque size to be 4";
    for (int value : result) {
        EXPECT_EQ(value, 6) << "Expected all elements to be 6";
    }
}

TEST_F(SequentialContainersTest, AddToDequeEnds) {
    SequentialContainers exercise;
    
    // Test adding elements to both ends of deque
    std::deque<int> deq = {2, 3, 4};
    exercise.add_to_deque_ends(deq, 1, 5);
    
    EXPECT_EQ(deq.front(), 1) << "Expected front element to be 1";
    EXPECT_EQ(deq.back(), 5) << "Expected back element to be 5";
    EXPECT_EQ(deq.size(), 5) << "Expected deque size to be 5";
}

TEST_F(SequentialContainersTest, RemoveFromDequeEnds) {
    SequentialContainers exercise;
    
    // Test removing elements from both ends of deque
    std::deque<int> deq = {10, 20, 30, 40};
    std::pair<int, int> removed = exercise.remove_from_deque_ends(deq);
    
    EXPECT_EQ(removed.first, 10) << "Expected front element removed to be 10";
    EXPECT_EQ(removed.second, 40) << "Expected back element removed to be 40";
    EXPECT_EQ(deq.size(), 2) << "Expected deque size to be 2 after removal";
    EXPECT_EQ(deq.front(), 20) << "Expected new front element to be 20";
    EXPECT_EQ(deq.back(), 30) << "Expected new back element to be 30";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}