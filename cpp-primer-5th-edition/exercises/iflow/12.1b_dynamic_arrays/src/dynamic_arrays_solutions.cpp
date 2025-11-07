#include "dynamic_arrays_solutions.h"
#include "dynamic_arrays_exercises.h"
#include <new>
#include <cstring>
#include <algorithm>

// Exercise 1: Allocate and initialize an array of integers with a given size
int* DynamicArraysSolutions::createIntArray(size_t size) {
    if (size == 0) return nullptr;
    int* arr = new int[size];
    for (size_t i = 0; i < size; ++i) {
        arr[i] = 0;
    }
    return arr;
}

// Exercise 2: Allocate and initialize an array of SimpleClass objects with a given size
SimpleClass* DynamicArraysSolutions::createSimpleClassArray(size_t size) {
    if (size == 0) return nullptr;
    return new SimpleClass[size];
}

// Exercise 3: Deallocate an array of integers
void DynamicArraysSolutions::deleteIntArray(int* array) {
    delete[] array;
}

// Exercise 4: Deallocate an array of SimpleClass objects
void DynamicArraysSolutions::deleteSimpleClassArray(SimpleClass* array) {
    delete[] array;
}

// Exercise 5: Copy an array of integers from source to destination
void DynamicArraysSolutions::copyIntArray(const int* source, int* destination, size_t size) {
    if (source != nullptr && destination != nullptr) {
        for (size_t i = 0; i < size; ++i) {
            destination[i] = source[i];
        }
    }
}

// Exercise 6: Copy an array of SimpleClass objects from source to destination
void DynamicArraysSolutions::copySimpleClassArray(const SimpleClass* source, SimpleClass* destination, size_t size) {
    if (source != nullptr && destination != nullptr) {
        for (size_t i = 0; i < size; ++i) {
            destination[i] = source[i];  // Uses assignment operator
        }
    }
}

// Exercise 7: Resize an array of integers (allocate new array, copy elements, deallocate old)
int* DynamicArraysSolutions::resizeIntArray(int* oldArray, size_t oldSize, size_t newSize) {
    if (newSize == 0) {
        delete[] oldArray;
        return nullptr;
    }
    
    int* newArray = new int[newSize];
    
    // Copy elements from old array to new array
    size_t copySize = (oldSize < newSize) ? oldSize : newSize;
    for (size_t i = 0; i < copySize; ++i) {
        newArray[i] = oldArray[i];
    }
    
    // Initialize new elements to 0 if newSize > oldSize
    for (size_t i = copySize; i < newSize; ++i) {
        newArray[i] = 0;
    }
    
    // Deallocate old array
    delete[] oldArray;
    
    return newArray;
}

// Exercise 8: Find an element in an array of integers
int* DynamicArraysSolutions::findInIntArray(const int* array, size_t size, int value) {
    if (array == nullptr) return nullptr;
    
    for (size_t i = 0; i < size; ++i) {
        if (array[i] == value) {
            return const_cast<int*>(&array[i]);  // Cast away const to return non-const pointer
        }
    }
    
    return nullptr;  // Not found
}

// Exercise 9: Fill an array of integers with a specific value
void DynamicArraysSolutions::fillIntArray(int* array, size_t size, int value) {
    if (array != nullptr) {
        for (size_t i = 0; i < size; ++i) {
            array[i] = value;
        }
    }
}

// Exercise 10: Calculate the sum of elements in an array of integers
int DynamicArraysSolutions::sumIntArray(const int* array, size_t size) {
    if (array == nullptr) return 0;
    
    int sum = 0;
    for (size_t i = 0; i < size; ++i) {
        sum += array[i];
    }
    
    return sum;
}

// Exercise 11: Create a copy of an array of integers
int* DynamicArraysSolutions::createCopyOfIntArray(const int* source, size_t size) {
    if (source == nullptr) return nullptr;
    
    int* newArray = new int[size];
    for (size_t i = 0; i < size; ++i) {
        newArray[i] = source[i];
    }
    
    return newArray;
}

// Exercise 12: Create a copy of an array of SimpleClass objects
SimpleClass* DynamicArraysSolutions::createCopyOfSimpleClassArray(const SimpleClass* source, size_t size) {
    if (source == nullptr) return nullptr;
    
    SimpleClass* newArray = new SimpleClass[size];
    for (size_t i = 0; i < size; ++i) {
        newArray[i] = source[i];  // Uses assignment operator
    }
    
    return newArray;
}