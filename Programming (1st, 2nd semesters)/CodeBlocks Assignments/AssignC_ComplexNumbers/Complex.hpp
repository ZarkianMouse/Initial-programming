#ifndef COMPLEX_HPP_INCLUDED
#define COMPLEX_HPP_INCLUDED

// Part of Complex Numbers Assign C
// By Naomi Burhoe
// This file holds the Complex class
// definition including prototypes and
// necessary variables
#include <iostream>
#include <memory>
// class the holds complex numbers of the form 'a + bi'
class Complex
{
    friend std::ostream& operator<<(std::ostream&, Complex&);
    friend std::istream& operator>>(std::istream&, Complex&);
    private:
        double realPart; // references the first number in 'a + bi'
        double imaginaryPart; // references the second number in 'a + bi'
    public:
        Complex(); // sets default values of realPart and imaginaryPart
        Complex(double newRealPart, double newImaginaryPart); // sets values based on input
        const Complex operator+(Complex&); // adds complex numbers
        const Complex operator-(Complex&); // subtracts complex numbers
        const Complex operator*(Complex&); // multiplies complex numbers
        Complex& operator=(const Complex& comObj); // assigns complex number a value
        bool operator!=(const Complex&); // compares complex numbers for inequality
        bool operator==(Complex&); // compares complex numbers for equality
        double getRealPart() const {return realPart;}; // returns realPart value
        double getImaginaryPart() const {return imaginaryPart;}; // returns imaginaryPart value
        std::string toString(); // converts complex number to a string for output

};

#endif // COMPLEX_HPP_INCLUDED
