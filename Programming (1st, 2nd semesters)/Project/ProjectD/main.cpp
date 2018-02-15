/* The Boss Computer Lab Monitoring System
   By: Naomi Burhoe COPYRIGHT 2017
   Version: 4
   Purpose: provides options for overseeing contracted
   lab networks for universities
   Latest Updates: added a queue, added option to display
   log file in console, some error handling
   Optimizations:
      1. Changed post-fix to prefix in destructor call loop
      2. Moved rand seed to after variable declarations and moved
         declarations around a bit
      3. Moved function declarations to before where they are used
         (isEmpty()/isFull() in UniversityList)
      4. Moved variable declarations to before function processes
         (LabFunctions.cpp: searchLabMenu())
   Exception Handling:
      1. In "Display File" option: an exception is thrown if file does
         not open, for whatever reason.
      2. In enterCompNum: test for cin.fail........program stills fails
         if input is non-numeric
   Other Notes:
      strategy for linked list
         deletes and allocates nodes as necessary
      queue functioning: works on FIFO basis,
         possible inclusion: add a structure to
         maintain list of available computers in individual
         labs for easier handling when objects in queue are
         deleted (see attachment)
       data entry malfunction/shortcut: by entry for menuChoice/labNum
         sometimes occurs with compNum too if valid entries for
         menuChoice and labNum                                         */

#include <iostream>
#include <memory>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <ctype.h>
#include <queue>
#include <exception>
#include "UniversityList.hpp"
#include "LabFunctions.hpp"
#include "myConstants.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::queue;

int main()
{
    //Optimization #2:
    //Originally seeded rand before declaring necessary variables
    //Moved seeding to below variable declarations, also moved
    //moved most called variables to being declared last
    FreedConsole nconsole;
    nconsole.compNum = -1;
    nconsole.labNum = -1;
    int menuChoice;

    // instantiates array of linked lists for lab
    LabList compLabList[NUMLABS];
    // instantiates queue
    queue<Console> labQueue;

    // seeds rand for use in new instance getID function
    srand((unsigned)time(0));

    // this begins the user-interactive portion of the program
    cout << "WELCOME TO THE COMPUTER LAB OVERSIGHT SERVER\n\n";
    bool loopFlag = true; // controls the loop of user interaction
    do {

        // checks if a console has been freed and someone is waiting in queue
        if (nconsole.compNum > -1 && labQueue.size() > 0)
        {
            menuChoice = 1;
            cout << "Checking for student to log in from queue\n";
        }

        // if either req is unmet, a choice is simply given to user for interaction
        else
        {
            menuChoice = labMenu();
        }

        switch(menuChoice) { // determines where user is sent based on choice
            // choice #1: log a student into a computer
            case 1 : cout << "\nSTUDENT LOGIN SCREEN\n";
                     nconsole = loginStudent(compLabList, labQueue, nconsole);
                break;
            // choice #2: directs user to log-off menu
            //            where they can choose who they
            //            want to log off
            case 2 : cout << "\nLOG-OFF SCREEN\n";
                     nconsole = logoffStudent(compLabList);
                break;
            // choice #3: allows user to search for a particular student
            // possible addition: allow user to see who is logged into a
            //                    particular computer
            case 3 : cout << "\nCommencing Search\n";
                     searchLabMenu(compLabList);
                break;
            // choice #4: allows user to see everyone logged into
            //            a particular lab's computer system
            case 4 : cout << "\nInitializing Lab Display Screen\n";
                     displayLab(compLabList);
                break;
            // choice #5: allows user to see all login/logoff attempts
            //            in log file
            case 5 : cout << "\nLoading Log File\n";

                // Exception Handling: if file doesn't open, then an exception is thrown
                try {
                    displayFile();
                }
                catch (std::exception &e)
                {
                    cout << "Standard Exception: " << e.what() << '\n';
                }
                break;
            // choice #6: allows user to leave the server
            // possible addition: allow user to log off everyone
            //                    on the server- End of Day function :)
            case 6 : cout << "\nExiting server\n";
                     loopFlag = false; // ends loop cycle
                break;

            // serves as a validation check in case the user accidentally/purposefully
            // entered a wrong number when choosing what they wanted to do
            default : cout << menuChoice << " is not a valid choice\n\n";
                break;
        }
    } while(loopFlag);

    // calls destructor
    // Optimization #1: changed post-fix (i++) to prefix (++i)
    for (int i = 0; i < NUMLABS; ++i)
        compLabList[i].~LabList();

    cout << "Thanks for choosing THE BOSS COMPUTER MONITORING SYSTEMS, LLC\n"
         << "Have a great rest of your day\n";

    return 0;
}
