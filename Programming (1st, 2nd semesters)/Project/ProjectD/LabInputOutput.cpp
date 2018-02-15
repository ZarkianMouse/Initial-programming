/* A part of Naomi Burhoe's Computer Server Program
   Purpose: holds non-member functions for program  */

#include <iostream>
#include <memory>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <sstream>
#include <istream>
#include "LabClass.hpp"
#include "LabFunctions.hpp"
#include "myConstants.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::istringstream;

/*                      User Input Functions                        */
/* labMenu
   precondition: receives nothing
   postcondition: returns integer variable
   for user choice of process
   */
int labMenu()
{
    int choice = 0;
    char cchoice = '0';
    char *c = &cchoice;
    bool isDigit = false;
    cout << "MAIN MENU" << endl
         << "1. Simulate Login\n"
         << "2. Simulate Log-off\n"
         << "3. Search for a Student\n"
         << "4. Display a Lab\n"
         << "5. Quit\n\n";

    do {
        cout << "What would you like to do? ";
        cin >> cchoice;
        if (isdigit(cchoice))
            isDigit = true;

        else
            cout << "Choice input must be numeric\n";
    } while(!isDigit);

    choice = atoi(c);

    return choice;
}

/* getName
   precondition: receives nothing
   postcondition: returns string variable
   for student name
   */
string getName()
{
    string name;
    cout << "Enter student name: ";
    while(name.empty() || name.size() > 35)
    {
        getline(cin, name);
        if (name.size() > 35)
            cout << name << " is too long\n";
    }

    return name;
}

/* getTime
   precondition: receives nothing
   postcondition: returns integer variable
   for the time used
   */
int getTime()
{
    int time = 0;
    bool loopFlag = false;

    do {
        cout << "Enter use time(in min): ";
        cin >> time;

        if (time == 15 || time == 30 || time == 45 || time == 60)
            loopFlag = true;
        else
            cout << time << " min is not a valid time input\n";
    } while(!loopFlag);

    return time;
}

/* enterLabNum
   precondition: receives nothing
   postcondition: returns integer variable
   for a specific lab number
   */
int enterLabNum()
{
    int labNum = 0; // for getting choice of lab
    string msg = "Lab input is invalid\n";

    cout << "University Labs Menu:\n";

    for (int i = 0; i < NUMLABS; i++)
    {
        cout << i + 1 << ". " << UNIVERSITYNAMES[i] << endl;
    }

    // loops until a valid int is entered
    bool isValid = false;
    do {
        cout << "Enter Lab Number: ";
        cin >> labNum;

        isValid = checkValidity(labNum, NUMLABS, msg);

    } while(!isValid);
    return labNum;
}

/* enterCompNum
   precondition: receives nothing
   postcondition: returns integer variable
   for a specific computer number
   */
int enterCompNum(int labNum)
{

    int compNum = 0; // holds computer number value
    int labSize = LABSIZES[labNum - 1];
    string msg = "Computer input is invalid\n";

    cout << "Lab #" << labNum << ": " << UNIVERSITYNAMES[labNum - 1] << endl;
    // loops until constraints are met
    bool isValid = false;
    do
    {
        cout << "Enter Computer Number (1-" << labSize << "): ";
        cin >> compNum;

        isValid = checkValidity(compNum, labSize, msg);
    } while(!isValid);

    return compNum;
}

/* getID(for search)
   precondition: receives nothing
   postcondition: returns integer variable
   for a specific student ID number
   */
int getID()
{
    // necessary variables for getting a correct ID
    string stringID; // controls for correct length and digit types
    int studentID = 0; // is updated once stipulations are met
    const int length = 5; // sets necessary length for ID
    char invalidYN = 'N'; // outputs a 'Y' value when incorrect
                          // values are detected in ID
    bool isValid = false; // updates once ID is valid

    // loops until a valid student ID is inputted
    do {
        cout << "Enter 5-digit Student ID Number: ";
        cin >> stringID; // reads in ID value

        // next few steps check for validity in ID
        // check for validity of string
        invalidYN = checkValidity(stringID, length);
        if (invalidYN == 'Y') //if invalid
        {
            cout << stringID << " is not a valid entry.\n";
        }
        else // if string is valid
        {
            // converts string version of ID to an int for return value transfer
            istringstream(stringID) >> studentID;

            // checks for validity of integer value, an additional backup
            // though checkValidity covers most issues, including negative numbers
            if (studentID < 0) // if negative
                cout << studentID << " is not a valid entry\n";
            else // if a valid ID is entered, ends the loop
                isValid = true;
        }
    } while(!isValid);
    return studentID;
}

/* displayID
   precondition: receives student ID variable
   postcondition: returns nothing
                  outputs 5-digit ID to standard
   */
void displayID(int studentID)
{
    // since the ID should be correct now
    // simply changes the display so it
    // looks the same as initial/inputted values
    if (studentID == -1) // for use in unused computers
        cout << "Available";
    else if (studentID < 10) // for single-digit ints
        cout << "0000" << studentID;
    else if (studentID < 100) // for two-digit ints
        cout << "000" << studentID;
    else if (studentID < 1000) // for three-digit ints
        cout << "00" << studentID;
    else if (studentID < 10000) // for four-digit ints
        cout << "0" << studentID;
    else // if five-digit int, no change is needed
        cout << studentID;
}

/* displayLab
   precondition: receives array for computer lab records
   postcondition: returns nothing
                  outputs specified lab to standard
   */
void displayLab(Lab **compLabArr)
{

    int labNumber = enterLabNum(); // receives lab number

    // outputs all computer stations in the lab to standard
    cout << "Lab " << labNumber << ": "
         << UNIVERSITYNAMES[labNumber - 1] << endl;
    for (int i = 0; i < LABSIZES[labNumber - 1]; i++)
    {
        cout << i + 1 << ": ";
        if (i + 1 < 10)
            cout << " ";
        compLabArr[labNumber - 1][i].displayID();
        cout << endl;
    }
    cout << "\n\n";
}
