/* A part of Naomi Burhoe's Computer Server Program
   Purpose: holds non-member functions for program  */

#include <iostream>
#include <memory>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <ctype.h>
#include "LabClass.hpp"
#include "LabFunctions.hpp"
#include "myConstants.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

/*                      Program Maintenance                         */
/* deletePtrs
   precondition: receives array of computer lab records
   postcondition: returns nothing, deletes all pointers
   */
void deletePtrs(Lab **computerLabArray)
{
    for (int i = 0; i < NUMLABS; i++)
    {
        delete [] computerLabArray[i];
    }
    delete [] computerLabArray;
}


/* checkValidity (numeric input)
   precondition: receives int value to be checked, limit for value,
                 and a message should an integer input error occur
   postcondition: returns false if conditions are not met and true otherwise
   conditions: checks for input fail
               checks for negative/0 entry
               checks for a number larger than the limit
*/
bool checkValidity(int num, int limit, string msg)
{
    if (cin.fail() || num <= 0 || num > limit)
    {
        cout << msg;
        return false;
    }

    return true;
}

/* checkValidity (string input)
   precondition: receives string for a numeric value
                 and the required length
   postcondition: returns a char value for if the length
                  is correct and/or if the string contains
                  non-numeric values
*/
char checkValidity(string stringID, const int length)
{
    // necessary variables
    int i = 0; // to check individual characters
    char invalidYN = 'N'; // monitors validity of numeric string

    // checks to see if the string length meets the requirements
    int stringLength = stringID.length();
    if (stringLength > length)
    {
        char invalidYN = 'Y';
        return invalidYN;
    }

    // loops through length of string
    while (stringID[i])
    {
        // checks for non-numeric characters
        if (!isdigit(stringID[i]))
        {
            invalidYN = 'Y';
            return invalidYN;
        }
        else
            invalidYN = 'N';
        i++;
    }

    return invalidYN;
}

/*                      Menu Choice Functions                         */
/* loginStudent
   precondition: receives 2D dynamic array of computer lab records
   postcondition: returns nothing
                  updates records to show a new log in attempt
   */
void loginStudent(Lab **compLabArr)
{
    // variables for user choice of lab, computer, and ID numbers
    int labNumber = enterLabNum();
    bool isFull = isLabFull(compLabArr, labNumber);
    if (isFull == true)
    {
        cout << "Sorry for the inconvenience but the lab for\n"
             << UNIVERSITYNAMES[labNumber - 1] << " is currently at capacity\n"
             << "Please try again later.\n";
        return;
    }

    int computerNumber = enterCompNum(labNumber);
    string name = getName();
    int timeUse = getTime();
    int studentID = getID(compLabArr);


    Lab defUser, user(studentID, name, timeUse);
    // checks to see if the selected computer is available for use
    if (compLabArr[labNumber - 1][computerNumber - 1] == defUser) // if "available"
    {
        // updates computer login status to in use by *insert student ID*
        compLabArr[labNumber - 1][computerNumber - 1] = user;
        // outputs login status of student
        cout << name << " has successfully been logged in with ID #";
        user.displayID();
        cout << "\n\n";
    }
    else // if the computer is in use already
    {
        // tells user of inaccessibility
        cout << name << " could not be logged in\n";
        // displays who is currently logged into the computer
        cout << "Please log out student " << compLabArr[labNumber - 1][computerNumber - 1].getName()
             << endl << "ID: " << compLabArr[labNumber - 1][computerNumber - 1].getID()
             << endl << endl;
    }
}

/* isLabFull
   precondition: receives array for labs and number of designated lab
   postcondition: returns true if the lab still has stations open
                  returns false otherwise
   */
bool isLabFull(Lab **compLabArr, int labNum)
{
    Lab defUser;
    int compsChecked = 0;
    for (int i = 0; i < LABSIZES[labNum - 1]; i++)
    {
        if (compLabArr[labNum - 1][i] == defUser)
            return false;
    }

    if (compsChecked == 261)
    {
        // outputs message if the student isn't logged in anywhere
        cout << "I'm sorry but we could not process your choice right now.\nThe lab is currently full\n";
    }
    return true;
}

/* getID(new instance)
   precondition: receives array for labs
   postcondition: returns a uniquely and randomly
                  generated student ID
   */
int getID(Lab **compLabArr)
{
    // necessary variables for getting a correct ID
    int studentID; // is updated once stipulations are met

    bool isValid = false; // updates once ID is valid

    // loops until a valid student ID is inputted
    do {
        studentID = rand();

        if (studentID < 99999)
        {
            int compsChecked = 0;

            for (int i = 0; i < NUMLABS; i++)
            {
                for (int j = 0; j < LABSIZES[i]; j++)
                {
                    // if id is not unique
                    if (compLabArr[i][j].getID() == studentID)
                    {
                        isValid = false;
                        break;
                    }

                    else
                    {
                        compsChecked++; // updates number of computers checked
                    }
                }
            }

            // if id is unique
            if (compsChecked == 261)
            {
                isValid = true;
            }
        }
    } while(!isValid);
    return studentID;
}

/* logoffChoice
   precondition: receives 2D dynamic array of computer lab records
   postcondition: returns nothing
                  gives user choice of logging off one or more students
                  or logging out all students
   */
void logoffChoice(Lab **compLabArr)
{
    int choice = 1; // sets default choice
    cout << "Who would you like to log off?\n"
         << "1. A student\n"
         << "2. All students\n";

    bool logOffdone = false; // monitors if user is done logging out students
    do {
        cout << "Enter choice: ";
        cin >> choice; // receives user choice

        switch(choice)
        {
            case 1 : cout << "Student Log-Off Screen\n";
                    while (!logOffdone)
                    {
                        logoffStudent(compLabArr); // performs initial log-off student

                        cout << "Are you finished?\n"
                             << "1 for yes\n"
                             << "Any other number for no\n"
                             << "Enter choice: ";
                        cin >> choice; // gives user choice of logging out more students
                        if (choice == 1)
                            logOffdone = true; // finishes log-off routine
                    }
                    break;
            case 2 : cout << "Logging out all students\n\n";
                    setInitValues(compLabArr); // resets computer lab for a new day
                    logOffdone = true;
                    break;
            default : cout << choice << " is not a valid choice\n"; // forces user to choose
                    break;
        }
    } while (!logOffdone);

    cout << endl;
}

/* logoffStudent
   precondition: receives 2D dynamic array of computer lab records
   postcondition: returns nothing
                  updates records to show a new log off attempt
   */
void logoffStudent(Lab **compLabArr)
{

    // variables for user search
    int studentID = getID(); // calls search getID
    string name = getName(); // calls name input function
    Lab defUser;


    // checks which computer student is logged into so it can perform log-off procedure
    int compsChecked = 0;
    for (int i = 0; i < NUMLABS; i++)
    {
        for (int j = 0; j < LABSIZES[i]; j++)
        {
            // if the student is logged in somewhere
            if (compLabArr[i][j].getName() == name && compLabArr[i][j].getID() == studentID)
            {

                // displays log-off success message to standard
                cout << UNIVERSITYNAMES[i] << endl
                     << compLabArr[i][j].getName() << " has been logged off of"
                     << " computer #" << j + 1 << endl
                     << "Use time: " << compLabArr[i][j].getTime() << endl << endl;

                compLabArr[i][j] = defUser; // updates availability of computer station


            }
            // note: this can/will happen multiple times is the student is logged into
            // multiple computer stations

            else // if student is not logged into that particular station
            {
                compsChecked++; // updates number of computers checked during cleanup
            }
        }
    }

    // checks if student never logged in (you can't log-off someone who never logged in)
    if (compsChecked == 261)
    {
        // outputs message if the student isn't logged in anywhere
        cout << name << " with ID #";
        displayID(studentID);
        cout << " is not logged in on any computer\n\n";
    }
}

/* setInitValues
   precondition: receives array of computer lab records
   postcondition: returns nothing, resets comp array to default
   */
void setInitValues(Lab **compLabArr)
{
    for (int i = 0; i < NUMLABS; i++)
    {
        for (int j = 0; j < LABSIZES[NUMLABS - 1]; i++)
        {
            compLabArr[i][j].setValues();
        }
    }
}

/* searchLabMenu
   precondition: receives 2D dynamic array of computer lab records
   postcondition: returns nothing, calls function that searches for
                  student based on information given
   */
void searchLabMenu(Lab **compLabArr)
{
    // type of info the user has
    int info;
    cout << "What information do you have for the student?\n"
         << "1. Student Name\n"
         << "2. Student ID\n\n";

    // validates whether info fits previous specifications
    bool loopFlag = false;
    do {
        cout << "Enter type of info: ";
        cin >> info;
        switch(info)
        {
            // if the user has the student's name
            case 1 : searchName(compLabArr); // searches for name
                    break;
            // if the user has the student's id
            case 2 : searchID(compLabArr); // searches for id
                    break;
            // if the user input an invalid numeric choice
            default : cout << info << "is invalid\n";
                    loopFlag = true; // forces reiteration of loop
                    break;
        }
    } while(loopFlag);

    return;
}

/* searchName
   precondition: receives 2D dynamic array of computer lab records
   postcondition: returns nothing, searches for an outputs all names
                  with corresponding IDs and use times that match
                  a given name
   */
void searchName(Lab **compLabArr)
{
    string studentName = getName();
    int compsChecked = 0;
    for (int i = 0; i < NUMLABS; i++)
    {
        for (int j = 0; j < LABSIZES[i]; j++)
        {
            // if student is found at a particular station
            if (compLabArr[i][j].getName() == studentName)
            {
                // outputs location of student
                cout << "\nStudent " << compLabArr[i][j].getName() << " is logged into "
                     << "computer " << j + 1 << endl
                     << "in the lab for " << UNIVERSITYNAMES[i] << endl
                     << "ID: " << compLabArr[i][j].getID() << endl
                     << "Use time: " << compLabArr[i][j].getTime() << " min\n\n";
            }

            else // if not at that station
            {
                compsChecked++; // updates number of computers checked
            }
        }
    }

    // outputs a message if student isn't logged in anywhere
    if (compsChecked == 261)
    {
        cout << studentName << " is not logged in on any computer\n\n";
    }
}

/* searchID
   precondition: receives 2D dynamic array of computer lab records
   postcondition: returns nothing, searches for an outputs ID with
                  corresponding name and time use
   */
void searchID(Lab **compLabArr)
{
    int studentID = getID();
    int compsChecked = 0;
    for (int i = 0; i < NUMLABS; i++)
    {
        for (int j = 0; j < LABSIZES[i]; j++)
        {
            // if student is found at a particular station
            if (compLabArr[i][j].getID() == studentID)
            {
                // outputs location of student
                cout << "\nStudent " << compLabArr[i][j].getID() << " is logged into "
                     << "computer " << j + 1 << endl
                     << "in the lab for " << UNIVERSITYNAMES[i] << endl
                     << "Name: " << compLabArr[i][j].getName() << endl
                     << "Use time: " << compLabArr[i][j].getTime() << " min\n\n";
            }

            else // if not at that station
            {
                compsChecked++; // updates number of computers checked
            }
        }
    }

    // outputs a message if student isn't logged in anywhere
    if (compsChecked == 261)
    {
        cout << "Student " << studentID << " is not logged in on any computer\n\n";
    }
}
