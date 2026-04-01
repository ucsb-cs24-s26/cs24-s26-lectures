# Lecture 2: Operator Overloading and The Rule of Three

## Overview
This directory contains starter code for Lecture 2, which covers:
1. **Operator Overloading** - Natural syntax for custom classes
2. **The Rule of Three** - Essential for classes with dynamic memory

---

## Files in This Directory

### Complex Class (for operator overloading)
- **Complex.h** - Class declaration
- **Complex.cpp** - Implementation with TODOs for students

### CustomVector Class (for Rule of Three)
- **CustomVector.h** - Class declaration
- **CustomVector.cpp** - Basic methods complete, Big Three as TODOs

### Demo Program
- **demo.cpp** - Comprehensive demos showing problems and solutions
- **Makefile** - Build system

---

## What You'll Demonstrate (Instructor)

### Part 1: Operator Overloading (15 mins)

#### Activity 1A: Implement operator<< (You Demo Live - 8 mins)
**File:** `Complex.cpp`, function `operator<<`

**Key Teaching Points:**
```cpp
ostream& operator<<(ostream& out, const Complex& c) {
    out << c.real;
    if (c.imag >= 0)
        out << " + " << c.imag << "j";
    else
        out << " - " << (-c.imag) << "j";
    return out;
}
```

**Points to emphasize:**
- ✓ Free function (not member) - why? Can't modify ostream!
- ✓ Return `ostream&` - enables chaining (`cout << c1 << c2`)
- ✓ Takes Complex by `const &` - efficient, no copy
- ✓ Must return `out` at end

#### Activity 1B: Students Implement operator+ (5 mins)
**File:** `Complex.cpp`, function `operator+`

Students fill in:
```cpp
Complex operator+(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.real + rhs.real, lhs.imag + rhs.imag);
}
```

**Quick check question:** "Why return `Complex` not `Complex&`?"
- Answer: Creating NEW object, can't return reference to local!

---

### Part 2: The Rule of Three (10 min mini-lecture + live coding)

#### The Problem Demo (3 mins)
**Show the disaster:**
```cpp
CustomVector v1;
v1.push_back(42);
CustomVector v2 = v1;  // Shallow copy!
// Both v1.data and v2.data point to SAME array!
// When both destroyed... CRASH! (double deletion)
```

**Draw the memory diagram on board** - This is CRITICAL!

#### Live Code the Big Three (7 mins)

**1. Destructor (2 mins)**
```cpp
CustomVector::~CustomVector() {
    delete[] data;  // Must use delete[] for arrays!
}
```

**Key point:** Without this, memory leak. With shallow copy, double deletion!

**2. Copy Constructor (3 mins)**
```cpp
CustomVector::CustomVector(const CustomVector& other)
    : data(nullptr), size(0), capacity(0) {
    size = other.size;
    capacity = other.capacity;
    data = new int[capacity];  // Allocate NEW array!
    for (size_t i = 0; i < size; i++) {
        data[i] = other.data[i];  // Copy VALUES
    }
}
```

**Key point:** DEEP COPY - new array, copy values, not pointers!

**3. Copy Assignment Operator (2 mins)**
```cpp
CustomVector& CustomVector::operator=(const CustomVector& other) {
    if (this == &other) return *this;  // Self-assignment check!

    delete[] data;  // Clean up old (like destructor)

    // Copy from other (like copy constructor)
    size = other.size;
    capacity = other.capacity;
    data = new int[capacity];
    for (size_t i = 0; i < size; i++) {
        data[i] = other.data[i];
    }

    return *this;  // For chaining: v1 = v2 = v3;
}
```

**Key points:**
- Self-assignment check: `if (this == &other)`
- Clean up old data first (object already exists!)
- Return `*this` for chaining

---

## What Students Will Do

### Activity 1B: Implement operator+ for Complex (5 mins)
Students complete the TODO in `Complex.cpp`

### Activities 3A-3D: CustomList Planning (25 mins)
Students work through handout activities:
- Analyze CustomList structure
- Draw shallow copy problem
- Plan destructor (pseudocode)
- Plan copy constructor (pseudocode)

**Note:** Students DON'T implement CustomList Big Three in lecture - that's for lab!

---

## Compiling and Running

### Build and run
```bash
make
./demo
```

### Clean up
```bash
make clean
```

### Test for memory leaks (after implementing Big Three)
```bash
make valgrind
```

---

## Expected Output

### Before Implementing Big Three
You'll see WARNING messages:
```
WARNING: Destructor not implemented - memory leak!
WARNING: Copy constructor not implemented - shallow copy!
WARNING: Assignment operator not implemented - shallow copy!
```

### After Implementing Big Three
All warnings should disappear, and:
- No crashes from double deletion
- `valgrind` shows no memory leaks
- Vectors are independent (modifying one doesn't affect the other)

---

## Lecture Timeline (50 mins)

| Time | Activity | Who |
|------|----------|-----|
| 0-2 min | Hook + Review | Instructor |
| 2-7 min | Mini-lecture: Why operator overloading? | Instructor |
| 7-12 min | Activity 1A: Implement operator<< | Instructor demos |
| 12-15 min | Debrief Activity 1A | Class discussion |
| 15-17 min | Activity 1B: Students implement operator+ | Students |
| 17-27 min | Part 2: Shallow copy problem demo + diagram | Instructor |
| 27-34 min | Live code: Destructor (2 min) | Instructor |
| 34-37 min | Live code: Copy constructor (3 min) | Instructor |
| 37-39 min | Live code: Copy assignment (2 min) | Instructor |
| 39-50 min | Activities 3A-3D: CustomList planning | Students |

---

## Key Concepts Covered

### Operator Overloading
✓ Free functions vs. member functions
✓ Return types: value vs. reference
✓ Const correctness
✓ Friend functions
✓ Chaining operators

### The Rule of Three
✓ Why classes with dynamic memory need all three
✓ Shallow copy vs. deep copy
✓ Double deletion problem
✓ Memory leak without destructor
✓ Self-assignment check
✓ Returning `*this` for chaining

---

## Common Student Mistakes to Watch For

### Operator Overloading
- ❌ Forgetting to return `out` from operator<<
- ❌ Returning `Complex&` from operator+ (can't return reference to local!)
- ❌ Making operator<< a member function

### Rule of Three
- ❌ Using `delete` instead of `delete[]` for arrays
- ❌ Forgetting self-assignment check in operator=
- ❌ Not initializing members in copy constructor initializer list
- ❌ Forgetting to delete old data in assignment operator
- ❌ Returning void from operator= (should return `*this`)

---

## Testing Checklist

After implementing the Big Three, verify:

- [ ] **No crashes** - Program runs to completion
- [ ] **No memory leaks** - `make valgrind` shows "All heap blocks were freed"
- [ ] **Deep copy works** - Modifying v2 doesn't change v1
- [ ] **Self-assignment safe** - `v1 = v1` doesn't crash
- [ ] **Old data freed** - Assignment operator cleans up properly

---

## Debugging Tips

### If you get a crash:
```bash
# Use gdb to find where crash happens
g++ -g demo.cpp Complex.cpp CustomVector.cpp -o demo
gdb ./demo
(gdb) run
(gdb) backtrace  # See where crash occurred
```

### If you have memory leaks:
```bash
# Use valgrind to find leaks
make valgrind
# Look for "definitely lost" bytes
# The output shows line numbers where memory was allocated but not freed
```

### Common crashes:
- **Double deletion** - Forgot to implement copy constructor (shallow copy + destructor)
- **Deleting invalid pointer** - Forgot self-assignment check
- **Segfault on access** - Used `delete` instead of `delete[]`

---

## Connection to Next Lecture

**Preview for Lecture 3:**
```
"Now you know how to manage memory for vectors and lists.
Next time: We'll use these skills to build STACKS and QUEUES!
These are fundamental data structures used everywhere in CS."
```

**Lab this week:**
Students will implement the Big Three for CustomList, using the same pattern they saw with CustomVector!

---

## Notes for Students

### Before Lab:
- Review memory diagrams for shallow vs. deep copy
- Understand why we need all three (destructor, copy constructor, assignment)
- Practice drawing stack vs. heap

### During Lab:
- TAs will help debug with valgrind and gdb
- You'll implement Big Three for CustomList (same pattern as CustomVector!)
- Don't copy-paste - understand each line

### Good Programming Practices:
- Always implement Big Three together (not one at a time)
- Test with valgrind regularly
- Draw memory diagrams before coding
- Check for self-assignment in operator=
