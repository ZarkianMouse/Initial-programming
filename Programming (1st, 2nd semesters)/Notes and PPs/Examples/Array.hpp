#ifndef ARRAY_HPP
#define ARRAY_HPP
// Array class definition with overloaded operators.
// Notes: dynamic memory is theme so
// look for the big 3 - A copy constructor, a destructor,
// and an overloaded assignment operator

// Not providing an overloaded assignment operator and
// a copy constructor for a class when objects contain pointers
// to dynamically memory is a logic error.
#include <iostream>
#include <memory> // for unique_ptr and make_unique
class Array
{
   // friend functions are used for overloading stream operations
   // why? insertion and stream extraction operator functions cannot
   // be members of class, b/c the Array object is always mentioned on the right side
   // of the insertion/extraction operators. If these operator functions
   // were to be members of class Array, we would have to write this to
   // output and input an Array: object << cout  AND  object >> cin

   // when compiler sees cout << object -
   //                                    it invokes operator<<( cout, object )
   friend std::ostream& operator<<(std::ostream&, const Array&);

   // when compiler sees cout >> object -
   //                                    it invokes operator>>( cout, object )
   friend std::istream& operator>>(std::istream&, Array&);

public:
   // without input, default constructor makes all arrays size 10 elements
   Array(int = 10); // default constructor

   // The argument to a copy constructor should be a const reference to allow
   // a const object to be copied
   Array(const Array&); // copy constructor

   size_t getSize() const; // return size

   const Array& operator=(const Array&); // assignment operator

   // when compiler sees cout >> object -
   //                                   it invokes integers1.operator=( integers2 )
   bool operator==(const Array&) const; // equality operator

   // inequality operator; returns opposite of == operator
   bool operator!=(const Array& right) const {
      return !(*this == right); // compiler invokes Array::operator==
   }

   // subscript operator for non-const objects returns modifiable lvalue
   int& operator[](int);

   // subscript operator for const objects returns rvalue
   int operator[](int) const;

private:

   // size is going to be this pointer based array's size
   // recall size_t is the unsigned integer type of the
   // result of the sizeof operator, and returns the maximum size
   size_t size; // pointer-based array size

   // the smart pointer - no destructor needed!
   std::unique_ptr<int[]> ptr; // smart pointer

};

#endif // ARRAY_HPP
