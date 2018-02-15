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

    // this begins the user-interactive portion of the program
    cout << "WELCOME TO THE COMPUTER LAB OVERSIGHT SERVER\n\n";
    bool loopFlag = true; // controls the loop of user interaction
    do {
        // calls function that initiates user interaction
        int menuChoice = labMenu();
        switch(menuChoice) { // determines where user is sent based on choice
            // choice #1: log a student into a computer
            case 1 : cout << "\nSTUDENT LOGIN SCREEN\n";
                     loginStudent(computerLabArray);
                break;
            // choice #2: directs user to log-off menu
            //            where they can choose who they
            //            want to log off
            case 2 : cout << "\nLOG-OFF SCREEN\n";
                     logoffChoice(computerLabArray);
                break;
            // choice #3: allows user to search for a particular student
            // possible addition: allow user to see who is logged into a
            //                    particular computer
            case 3 : cout << "\nCommencing Search\n";
                     searchLabMenu(computerLabArray);
                break;
            // choice #4: allows user to see everyone logged into
            //            a particular lab's computer system
            case 4 : cout << "\nInitializing Lab Display Screen\n";
                     displayLab(computerLabArray);
                break;
            // choice #5: allows user to leave the server
            // possible addition: allow user to log off everyone
            //                    on the server- End of Day function :)
            case 5 : cout << "\nExiting server\n";
                     loopFlag = false; // ends loop cycle
                break;
            // serves as a validation check in case the user accidentally/purposefully
            // entered a wrong number when choosing what they wanted to do
            default : cout << menuChoice << " is not a valid choice\n\n";
                break;
        }
    } while(loopFlag);

    // performs some last minute clean up (deleting pointers) before exiting program
    deletePtrs(computerLabArray);

    // ends the program on a happy note
    cout << "Have a great day!\n";
    return 0;
}
