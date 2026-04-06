#include "Complex.h"
#include "CustomVector.h"
#include <iostream>

using namespace std;

/**
 * Lecture 2 Demo - Operator Overloading and The Rule of Three
 *
 * Part 1: Operator overloading with Complex class
 * Part 2: The Rule of Three with CustomVector class
 */

// ============================================
// PART 1: Operator Overloading
// ============================================

void demoOperatorOverloading() {
    cout << "========================================" << endl;
    cout << "  PART 1: Operator Overloading" << endl;
    cout << "========================================" << endl;
    cout << endl;
     
    // Create complex numbers
    Complex c;  //  0 + 0j
    Complex c1(3, 4);   // 3 + 4j --> Implicitly Calling a function -- constructor
    Complex c2(1, 2);   // 1 + 2j
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << endl;
    
    // Test operator+
    Complex c3 = c1 + c2;  // (3+1) + (4+2) j

                           // Complex c3 = operator+(c1, c2);
                           //            = c1.operator+(c2);
                           // v[0] = 5;

    cout << "c1 + c2 = " << c3 << endl;
    cout << endl;

    // // Test chaining
    cout << "Chaining test: " << c1 << " + " << c2 << " = " << c3 << endl;
    cout << endl;

    cout << endl;
}

// ============================================
// PART 2: Scenario A — Copy Constructor Problem
// ============================================

void test_scenarioA() {
    cout << "========================================" << endl;
    cout << "  PART 2: Scenario A — Copy Constructor" << endl;
    cout << "========================================" << endl;
    cout << endl;

    CustomVector v1(4);
    v1.push_back(10);
    v1.push_back(20);

    cout << "v1 = "; v1.print(); cout << endl;

    cout << "Executing: CustomVector v2 = v1;" << endl;
    CustomVector v2 = v1;   // default copy constructor — shallow copy

    cout << "v2 = "; v2.print(); cout << endl;
    cout << endl;

    cout << "Executing: v2[0] = 99;" << endl;
    v2[0] = 99;

    cout << "v2 = "; v2.print(); cout << endl;
    cout << "v1 = "; v1.print();
    //cout << " <-- v1 was never touched, but v1[0] is now 99!" << endl;
    cout << endl;

    cout << "Exiting function ..." << endl;
    
}

// ============================================
// PART 3: Scenario B — Copy Assignment Problem
// ============================================

void test_scenarioB() {
    cout << "========================================" << endl;
    cout << "  PART 3: Scenario B — Copy Assignment" << endl;
    cout << "========================================" << endl;
    cout << endl;

    CustomVector v1, v2;
    v1.push_back(10);

    cout << "v1 = "; v1.print(); cout << endl;
    cout << "v2 = "; v2.print(); cout << endl;
    cout << endl;

    cout << "Executing: v2 = v1;" << endl;
    v2 = v1;   // default copy assignment — shallow copy, v2's old array leaked

    cout << "v2 = "; v2.print(); cout << endl;
    cout << endl;

    cout << "Executing: v2[0] = 99;" << endl;
    v2[0] = 99;

    cout << "v2 = "; v2.print(); cout << endl;
    cout << "v1 = "; v1.print();
  //  cout << " <-- v1 was never touched, but v1[0] is now 99!" << endl;
    cout << endl;

    cout << "Exiting function ..." << endl;
}

// ============================================
// Main Function
// ============================================

int main() {
    cout << endl;
    cout << "=======================================" << endl;
    cout << "  CS24 Lecture 2 Demo" << endl;
    cout << "  Operator Overloading & Rule of Three" << endl;
    cout << "=======================================" << endl;
    cout << endl;

    // Part 1: Operator Overloading
    demoOperatorOverloading();

    cout << "Press Enter to continue to Part 2...";
    cin.get();
    cout << endl;

    // Part 2: Scenario A — Copy Constructor Problem
    test_scenarioA();

    cout << "Press Enter to continue to Part 3...";
    cin.get();
    cout << endl;

    // Part 3: Scenario B — Copy Assignment Problem
    test_scenarioB();

    cout << "=======================================" << endl;
    cout << "  End of Demo" << endl;
    cout << "=======================================" << endl;
    cout << endl;

    return 0;
}
