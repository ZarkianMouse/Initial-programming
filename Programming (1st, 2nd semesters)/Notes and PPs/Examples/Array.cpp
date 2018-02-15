/*
   COPYRIGHT (C) 2017 Student Name (UANET ID ) All rights reserved.
   CS assignment
   Author.  Student Name
            zippy@zips.uakron.edu
   Version. 1.01 09.09.2017
   Purpose: This program ...
*/

// Array class member- and friend-function definitions.
#include <iostream>
#include <iomanip>
#include <stdexcept>  // exceptions - explained later :)
#include "Array.hpp" // Array class definition

// default constructor for class Array (1 argument, int, defaults to 10)
// validates size is > 0 and assigns the argument to the data member size
// we have a unique pointer assigned to the memory (new) as data member ptr.
Array::Array(int arraySize)
  : size{(arraySize > 0 ? static_cast<size_t>(arraySize) :
     throw std::invalid_argument{"Array size must be greater than 0"})},
   ptr{std::unique_ptr<int[]>(new int(size))} { /* empty body */ }

// copy constructor for class Array; initializes an Array by making a copy
// of an existing Array object, arrayToCopy. This must be received by &reference&.
// if not - infinite recursion!
// if we didn't have the copy constructor, what would happen?
// (Hint:default copy constructor)
Array::Array(const Array& arrayToCopy)
  : size{arrayToCopy.size}, ptr{std::unique_ptr<int[]>(new int(size))} {
  for (size_t i{0}; i < size; ++i) {
   ptr[i] = arrayToCopy.ptr[i]; // copy into object
  }
}

// return number of elements of Array
size_t Array::getSize() const {
   return size; // number of elements in Array
}

// overloaded assignment operator;
// const return avoids: (a1 = a2) = a3
const Array& Array::operator=(const Array& right)
{
  if (&right != this) { // avoid self-assignment (same place?)
     // for Arrays of different sizes, deallocate original
     // left-side Array, then allocate new left-side Array
     if (size != right.size)
     {
       size = right.size; // resize this object
       ptr = std::unique_ptr<int[]>(new int(size)); // create space for copy
     }

     for (size_t i{0}; i < size; ++i) {
       ptr[i] = right.ptr[i]; // copy array elements into object
    }
  }
  // no matter what, we return the current object
  // we can cascade (below), but we stop things like (a = b) = c
  return *this; // enables x = y = z, for example
}

// determine if two Arrays are equal and
// return true, otherwise return false
bool Array::operator==(const Array& right) const {
  if (size != right.size) {
    return false; // returning false right away if sizes differ
  }

  for (size_t i{0}; i < size; ++i) {
    if (ptr[i] != right.ptr[i]) {
       return false; // Array contents are not equal
    }
  }

  return true; // Arrays are equal
}

// overloaded subscript operator for non-const Arrays;
// reference return creates a modifiable lvalue
int& Array::operator[](int subscript) {
  // check for subscript out-of-range error
  if (subscript < 0 || subscript >= size) {
    std::cout << "Subscript out of range";
  }

  return ptr[subscript]; // reference return
}

// overloaded subscript operator for const Arrays
// const reference return creates an rvalue
int Array::operator[](int subscript) const {
  // check for subscript out-of-range error
  if (subscript < 0 || subscript >= size) {
    std::cout << "Subscript out of range";
  }

  return ptr[subscript]; // returns copy of this element
}

// overloaded input operator for class Array;
// inputs values for entire Array
std::istream& operator>>(std::istream& input, Array& a) {
  for (size_t i{0}; i < a.size; ++i) {
    input >> a.ptr[i];
  }

  return input; // enables cin >> x >> y;
}

// overloaded output operator for class Array
std::ostream& operator<<(std::ostream& output, const Array& a) {
  // output private ptr-based array
  for (size_t i{0}; i < a.size; ++i) {
    output << a.ptr[i] << "  ";
  }

  output << std::endl;
  return output; // enables cout << x << y;
}

