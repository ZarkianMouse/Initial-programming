/*
   COPYRIGHT (C) 2017 Naomi Burhoe All rights reserved.
   CSII assignment C
   Author.  Naomi Burhoe
            nrb74@zips.uakron.edu
   Version. 2.01 09.09.2017
   Purpose: This program is the test cases for the assignment
*/

#include <iostream>
#include <string>
#include <memory>
#include <sstream> // for ostringstream class
#include "Complex.hpp"

int main()
{
   for (double i = 1; i < 10; ++ i)
   {
     Complex y{i * 2.7, i + 3.2};
     Complex z{i * 6, i + 8.3};

     Complex x;
     Complex k;

     std::cout << "Enter a complex number in the form: (a, b)\n? ";
     std::cin >> k; // demonstrating overloaded >>
     std::cout << "x: " << x << "\ny: " << y << "\nz: " << z << "\nk: "
               << k << '\n'; // demonstrating overloaded <<
     x = (y + z); // demonstrating overloaded + and =
     std::cout << "\nx = y + z:\n" << x << " = " << y << " + " << z << '\n';
     x = (y - z); // demonstrating overloaded - and =
     std::cout << "\nx = y - z:\n" << x << " = " << y << " - " << z << '\n';
     x = (y * z); // demonstrating overloaded * and =
     std::cout << "\nx = y * z:\n" << x << " = " << y << " * " << z << "\n\n";

     if (x != k) { // demonstrating overloaded !=
        std::cout << x << " != " << k << '\n';
     }

     std::cout << '\n';
     x = k;

     if (x == k) { // demonstrating overloaded ==
        std::cout << x << " == " << k << '\n';
     }
       std::cout << std::endl;
     }

}





