/* Part of Assign E by Naomi Burhoe c. 2017
   Purpose: holds myFunction definition    */

#ifndef MYFUNCTION
#define MYFUNCTION

#include "namespace.h"

/* myFunction
   precondition: receives array of chars
   postcondition: returns nothing, outputs
                  contents of array to standard
 */
void myFunction(char myArray[])
{
    for (int i = 0; i < SIZE; i++)
        std::cout << myArray[i] << " ";

    std::cout << std::endl;
}

#endif // MYFUNCTION
