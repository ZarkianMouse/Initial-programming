/*
   COPYRIGHT (C) 2017 Student Name (UANET ID ) All rights reserved.
   CSII assignment
   Author.  Student Name
            zippy@zips.uakron.edu
   Version. 1.01 09.09.2017
   Purpose: This program ...
*/
// This program uses the Rectangle class, which is declared in
// the Rectangle.hpp file. The member Rectangle class's member
// functions are defined in the Rectangle.cpp file. This program
// should be compiled with those files in a project.
#include <iostream>
#include <string>
#include <limits> // validation

#include "RectClass.hpp"  // Needed for Rectangle class

// the dream of making a universal validation can be done with templates!
template <typename T> bool validateCin(T, std::string);

int main() {
  Rectangle box;  // define instances of the Rectangle class
  double rectWidth; // local variable for width
  double rectLength; // local variable for length
  bool loopFlag = true; // for validation

  // get the rectangle's width and length
  std::string msg("Invalid input...try again "); // invalid message
  std::cout << "This program will calculate the area of a rectangle." << std::endl;
  do
  {
    std::cout << " What is the width? " << std::endl;
    std::cin >> rectWidth;
    loopFlag = validateCin(rectWidth, msg);
  } while (loopFlag);
  loopFlag = true;
  do
  {
    std::cout << " What is the length? " << std::endl;
    std::cin >> rectLength;
    loopFlag = validateCin(rectLength, msg);  // this is why he doesn't get to type!
  } while (loopFlag);
  // let's create an instance of a rectangle called a box (we did)
  // but let's use the setters (put data into the object) and getters ....
  box.setWidth(rectWidth);
  box.setLength(rectLength);

  // now that we've put an object out there, let's use the
  // getters to print it (output it). Methods are in our implementation file

  std::cout << "Here is the rectangle's data: " << std::endl;
  std::cout << "Width : " << box.getWidth() << std::endl;
  std::cout << "Length: " << box.getLength() << std::endl;
  std::cout << "Area  : " << box.getArea() << std::endl;

  return 0;
}
//**********************************************************************************
// Validate Input takes integer data and ensures it is correct.
// Note: it is asking is the data invalid? so true/false is in that vein
// precondtion: pass the function the user choice
//              pass the message to display for any user error
// postcondition: returns false if valid and true if not
//**********************************************************************************
// we can make this even better when we learn how to throw an exception!
template <typename T>  // template function
bool validateCin(T userChoice, std::string message)
{
  bool goodOrNot = false;
  if (std::cin.fail())
  {
    std::cout << message << std::endl;
    goodOrNot = true;
  }
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return goodOrNot;
}
