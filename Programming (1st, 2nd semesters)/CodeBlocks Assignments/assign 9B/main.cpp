/* Changes Copyright of Naomi Burhoe c. 2016
   (other coding used with permission :))
   Program: Element Shifter
   Author: Naomi Burhoe
           nrb74@zips.uakron.edu
   Purpose: this program accepts an integer array
   and the size of the array.  It creates a dynamic
   array one element longer and shifts the original
   array by one from the left and sets element 0 to 0.
   Returns a unique pointer to the new dynamic array.

   TECHNICAL NOTES:
   Returns a unique pointer to a heap array that this
   program takes ownership. Program acquires ownership
   of a uniquely-owned array with dynamic lifetime
   from the elementShift function
   The use of std::unique_ptr is mainly of intellectual
   interest.
*/
#include <iostream>
#include <memory>
#include "elementShifter.hpp"
#include "showArray.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::unique_ptr;

unique_ptr<int[]> elementShifter(int, int *);
void showArray(int *, int);

int main()
{
    const int SIZE = 5;
    int myNumbers[SIZE] = {18, 27, 3, 14, 95};

    // the unique pointer is used to dynamically
    // allocate an array of ints
    // it is used as a small, fast, move-only
    // smart pointer for managing resources with
    // exclusive-ownership semantics
    // (whatever that means...)
    unique_ptr<int[]> newCopy(new int[SIZE]);

    showArray(myNumbers, SIZE);

    newCopy = elementShifter(SIZE, myNumbers);

    // passing the unique smart pointer using
    // the get method creates a temporary
    // copy (raw pointer) that can be used
    // to access the memory alloted for the
    // unique pointer (b/c two instances
    // of a unique pointer cannot manage
    // the same memory)
    showArray(newCopy.get(), SIZE + 1);

    //allows for reuse of function to show array
    return 0;
}



