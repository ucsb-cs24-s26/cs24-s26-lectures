#include "CustomVector.h"

// Constructor - allocates initial capacity
CustomVector::CustomVector(size_t initialCapacity) : data(nullptr), size(0), capacity(initialCapacity) {
    data = new int[capacity];
}

// Add element to end
void CustomVector::push_back(int val) {
    // Check if we need more space
    if (size >= capacity) {
        resize();
    }
    // Add the element
    data[size] = val;
    size++;
}

// Get element at index with bounds checking
int CustomVector::get(size_t index) const {
    if (index >= size) {
        throw out_of_range("Index out of bounds");
    }
    return data[index];
}

// Set element at index with bounds checking
void CustomVector::set(size_t index, int val) {
    if (index >= size) {
        throw out_of_range("Index out of bounds");
    }
    data[index] = val;
}

// Index operator — returns reference so v[i] = val works
int& CustomVector::operator[](size_t index) {
    if (index >= size) {
        throw out_of_range("Index out of bounds");
    }
    return data[index];
}

// Print all elements
void CustomVector::print() const {
    cout << "[";
    for (size_t i = 0; i < size; i++) {
        cout << data[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}

// Helper: Double the capacity when full
void CustomVector::resize() {
    capacity *= 2;

    // Allocate new larger array
    int* newData = new int[capacity];

    // Copy existing elements
    for (size_t i = 0; i < size; i++) {
        newData[i] = data[i];
    }

    // Delete old array
    delete[] data;

    // Update pointer
    data = newData;
}

// ============================================
// THE BIG THREE - INSTRUCTOR WILL LIVE-CODE!
// ============================================

// Destructor - Clean up dynamic memory
// TODO: Instructor will implement this LIVE!
//
// Key teaching points:
// 1. We MUST delete[] the array we allocated in constructor
// 2. If we don't, we get a MEMORY LEAK
// 3. Use delete[] (not delete) for arrays
// Destructor — frees the heap array
CustomVector::~CustomVector() {
    delete[] data;
}

// SHALLOW copy constructor — TODO: live-code deep copy
CustomVector::CustomVector(const CustomVector& other)
    : data(other.data), size(other.size), capacity(other.capacity) {
}

// SHALLOW copy assignment — TODO: live-code deep copy
CustomVector& CustomVector::operator=(const CustomVector& other) {
    data = other.data;
    size = other.size;
    capacity = other.capacity;
    return *this;
}
