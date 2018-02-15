/* The Boss Computer Lab Monitor System
   Copyright of Naomi Burhoe c. 2017
   Purpose: to provide a design for a system that monitors
   the log-in/log-off actions of lab users, allows the administrator
   to update records accordingly, and provides users with information
   about available labs and/or computers within the system
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "LabClass.hpp"
#include "LabFunctions.hpp"
#include "myConstants.h"
using std::cout;
using std::cin;
using std::endl;



int main()
{
     // seeds rand for use in new instance getID function
     srand((unsigned)time(0));

    LabList compLabList;
    Lab defUser;
    for (int i = 0; i < NUMLABS; i++)
        compLabList.appendNode(defUser);
    // sets up multidimensional dynamic array for storing computer lab records
    /*Lab **computerLabArray = new Lab*[NUMLABS];
    for (int i = 0; i < NUMLABS; i++)
    {
        computerLabArray[i] = new Lab[LABSIZES[i]];
    } */



    // performs some last minute clean up (deleting pointers) before exiting program
    deletePtrs(computerLabArray);

    // ends the program on a happy note
    cout << "Have a great day!\n";
    return 0;
}
