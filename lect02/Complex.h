#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

using namespace std;

/**
 * Complex - A simple complex number class for operator overloading demo
 *
 * This class demonstrates:
 * - Operator overloading (<<, +, ==)
 * - Friend functions
 * - Why we return references vs. values
 */
class Complex {
public:
    // Constructor with default parameters
    Complex(double r = 0.0, double i = 0.0);
    Complex operator+(Complex rhs){
         return Complex(real+ rhs.real, 
                   imag + rhs.imag);
        
    }

    // Accessors
    double getReal() const;
    double getImag() const;

private:
    double real;
    double imag;
};

// TODO: Implement operator<< (demo this live!)
// This allows: cout << complex_obj;
ostream& operator<<(ostream& out, const Complex& c);  // cout << c1 << c2;
                                                      // operator<<(cout, c1)     << c2;
                                                      // cout << c2 <--- note operator<<(cout, c1)
                                                      //                 must return ostream type 
// If you implement with void return type
// chaining will not be possible.
// void operator<<(ostream& out, const Complex& c);
// TODO: Implement operator+ (students do this in Activity 1B!)
// This allows: Complex c3 = c1 + c2;
Complex operator+(const Complex& lhs, const Complex& rhs);

// Optional: operator== for comparison
// This allows: if (c1 == c2) { ... }
//bool operator==(const Complex& lhs, const Complex& rhs);

#endif
// Complex c1 = c2; // Copy constructor!  Initialize a newly created object using the values of an existing object
// Complex c1(c2); //Another notation that calls copy constructor

// Big four: C++ will provide default implementations. 
/*
1. Constructor: initialize a new object from parameters
2. Destructor : clean up routine if needed
3. Copy constructor: initializae a new object based on attributes of an existing object
4. Copy assignment operator: assign the member variables of one existing object to another
// e.g. a = b;  

*/

