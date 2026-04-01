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

ostream& operator<<(ostream& out, const Complex& c){
    out<< c.getReal() << " ";
    if(c.getImag() < 0){
        out << "- " << -1 * c.getImag() <<"j";
    }else{
        out << "+ " << c.getImag() << "j";
    }
    return out;
}


// TO DO: Implement operator+ 
// Addition of complex numbers: (a + bi) + (c + di) = (a+c) + (b+d)i
Complex operator+(const Complex& lhs, const Complex& rhs){
    //TO DO
    return Complex(lhs.getReal() + rhs.getReal(),  lhs.getImag() + rhs.getImag());
}

