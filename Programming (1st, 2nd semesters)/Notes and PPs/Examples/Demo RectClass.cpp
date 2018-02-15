/*
   COPYRIGHT (C) 2017 Student Name (UANET ID ) All rights reserved.
   CSII assignment
   Author.  Student Name
            zippy@zips.uakron.edu
   Version. 1.01 09.09.2017
   Purpose: This program ...
*/
// Implementation file for the Rectangle class.
// this program may need pre and post conditions?

#include "RectClass.hpp"   // Needed for the Rectangle class
#include <iostream>      // Needed for cout
#include <cstdlib>       // Needed for the exit function

// setWidth sets the value of the member variable width
// precondtion: pass the function the valid user choice
// postcondition: sets the object value if valid
void Rectangle::setWidth(double widthIn)
{
   if (widthIn >= 0)
      width = widthIn;
   else
   {
      std::cout << "Invalid width\n";
      exit(EXIT_FAILURE);
   }
}
// setLength sets the value of the member variable length
// precondtion: pass the function the valid user choice
// postcondition: sets the object value if valid
void Rectangle::setLength(double lenIn)
{
  if (lenIn >= 0)
    length = lenIn;
  else {
    std::cout << "Invalid length\n";
    exit(EXIT_FAILURE);
  }
}
// getWidth returns the value in the member variable width
// precondtion: no parameters
// postcondition: return the object width
double Rectangle::getWidth() const
{
  return width;
}
// getLength returns the value in the member variable length
// precondtion: no parameters
// postcondition: return the object length
double Rectangle::getLength() const
{
   return length;
}
// getArea returns the product of width times length.
// precondtion: no parameters
// postcondition: return the result of the object's width * length
double Rectangle::getArea() const
{
  return width * length;
}










