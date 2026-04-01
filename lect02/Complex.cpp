#include "Complex.h"

// Constructor - uses initializer list
Complex::Complex(double r, double i) : real(r), imag(i) {
    // Body empty - all initialization in initializer list!
}

// Getter for real part
double Complex::getReal() const {
    return real;
}

// Getter for imaginary part
double Complex::getImag() const {
    return imag;
}

// TODO: Implement operator<< (


// TO DO: Implement operator+ 
// Addition of complex numbers: (a + bi) + (c + di) = (a+c) + (b+d)i
Complex operator+(const Complex& lhs, const Complex& rhs){
    //TO DO
    return Complex();
}

