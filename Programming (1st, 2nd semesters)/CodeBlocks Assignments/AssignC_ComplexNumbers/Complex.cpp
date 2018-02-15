// Part of Complex Numbers Assign C
// By Naomi Burhoe
// This file holds the function declarations
// for the Complex class, including
// Constructors, operation/overload functions,
#include "Complex.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <sstream>
/* Constructor Functions */
// sets default values of the real and imaginary parts of a complex object
Complex::Complex() : realPart(1), imaginaryPart(0)
{
}

// sets values of the real and imaginary parts of a complex object based on input from driver program
Complex::Complex(double newRealPart, double newImaginaryPart) : realPart(newRealPart), imaginaryPart(newImaginaryPart)
{
}

/* Operation Functions */
// Complex::toString
// precondition: is accessed by a Complex type object
// postcondition: returns a string representing
//                the object
std::string Complex::toString()
{
    // converts realPart to a string
    std::ostringstream realStrs;
    realStrs << realPart;
    std::string realString = realStrs.str();

    // converts imaginaryPart to a string
    std::ostringstream imagStrs;
    imagStrs << imaginaryPart;
    std::string imaginaryString = imagStrs.str() + "i";
    if (imaginaryPart < 0)
        imaginaryString[0] = ' ';

    // combines realString and imaginaryString to form 'a + bi' structure
    std::string complexString;
    if (imaginaryPart >= 0)
        complexString = ("(" + realString + " + " + imaginaryString + ")");
    else
        complexString = ("(" + realString + " -" + imaginaryString + ")");

    // Note: I used the form 'a - bi' for the second version
    // under the assumption that a - bi = a + (-bi) or a + (-b)i simply
    // because I thought it looked cleaner that way
    // An alternate version could be used to output the above notation
    // and I have used it here, but what is shown is the way I prefer
    // the expression to look.

    return complexString;
}

// overloads the addition operator
// precondition: one Complex object accesses the function using
//               addition operator, is passed a second object
// postcondition: returns the object representing the sum of the
//                original objects
const Complex Complex::operator+(Complex& otherNum)
{
    Complex result(realPart + otherNum.getRealPart(), imaginaryPart + otherNum.getImaginaryPart());
    return result;
}

// overloads the subtraction operator
// precondition: one Complex object accesses the function using
//               subtraction operator, is passed a second object
// postcondition: returns the object representing the difference of the
//                original objects
const Complex Complex::operator-(Complex& otherNum)
{
    Complex result(realPart - otherNum.getRealPart(), imaginaryPart - otherNum.getImaginaryPart());
    return result;
}


// overloads the multiplication operator
// precondition: one Complex object accesses the function using
//               multiplication operator, is passed a second object
// postcondition: returns the object representing the product of the
//                original objects
const Complex Complex::operator*(Complex& otherNum)
{
    Complex result(realPart * otherNum.getRealPart(), imaginaryPart * otherNum.getImaginaryPart());
    return result;
}

// overloads the assignment operator
// precondition: one Complex object accesses the function using assignment
//               operator, one is passed
// postcondition: returns a reference object for the newly assigned object
Complex& Complex::operator=(const Complex& comObj)
{
  realPart = comObj.realPart;
  imaginaryPart = comObj.imaginaryPart;
  return *this;
  // no matter what, we return the current object
  // we can cascade (below), but we stop things like (a = b) = c
  // enables x = y = z, for example
}

// overloads the != operator
// precondition: is accessed by one Complex object, is passed a second
// postcondition: returns true if objects are not equal, returns false otherwise
bool Complex::operator!=(const Complex& otherNum)
{
    if (realPart != otherNum.getRealPart() && imaginaryPart != otherNum.getImaginaryPart())
        return true;
    else
        return false;
}


// overloads == comparison operator
// precondition: is accessed by one Complex object, is passed a second
// postcondition: returns true if strings are equivalent, returns false otherwise
// note: I could have used the same configuration as the != operation overload function
//       but I don't think of it at that time
bool Complex::operator==(Complex& otherNum)
{
    if(toString() == otherNum.toString())
        return true;
    else
        return false;
}

/* Friend Functions */
// overloads >> operator
// precondition: is accessed when a std::istream and a Complex object are compared
//               is passed references to both variables
// postcondition: reads in values to the Complex object, returns std::istream variable
std::istream& operator>>(std::istream& input, Complex& num)
{
    input >> num.realPart >> num.imaginaryPart;

    return input;
}

// overloads << operator
// precondition: is accessed when a std::ostream and a Complex object are compared
//               is passed references to both variables
// postcondition: outputs the Complex object as a string, returns std::ostream variable
std::ostream& operator<<(std::ostream& output, Complex& num)
{
    output << num.toString();

    return output;
}
