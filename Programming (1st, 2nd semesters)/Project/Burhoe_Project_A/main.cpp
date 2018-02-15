/* The Boss Computer Lab Monitor System
   Copyright of Naomi Burhoe c. 2017
   Purpose: to provide a design for a system that monitors
   the log-in/log-off actions of lab users, allows the administrator
   to update records accordingly, and provides users with information
   about available labs and/or computers within the system
*/
#include <iostream>
#include <memory>
#include <iomanip>
#include <string>
#include <sstream>
#include <istream>
#include <stdio.h>
#include <ctype.h>

using intArrayPtr = int*;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::istringstream;

//Constants of Program
//number of labs
const int NUMLABS = 8;
//number of computers in each lab
const int LABSIZES[NUMLABS] = {19, 15, 24, 33, 61, 17, 55, 37};

//Function Declarations
//functions for program maintenance
void setInitValues(intArrayPtr *); //initializes array values
void deletePtrs(intArrayPtr *);  // deletes ptrs

//functions for user input
int labMenu(); // presents user choice
int getID();  // receives ID from standard
char checkValidity(string, const int); //checks for non-numeric characters
int getLabNum();  // receives lab # from standard
int getCompNum(int);  // receives computer # from standard
void displayID(int);  // sets user ID to a 5-digit output #

// functions for process choice
void loginStudent(intArrayPtr *);  // logs student into system
void logoffStudent(intArrayPtr *);  // logs student out of system
void logoffChoice (intArrayPtr *);
void searchLab(intArrayPtr *);  // searches labs for a student
void displayLab(intArrayPtr *);  // displays lab in standard


int main()
{
   // sets up multidimensional dynamic array for storing computer lab records
    intArrayPtr *computerLabArray = new intArrayPtr[NUMLABS];
    for (int i = 0; i < NUMLABS; i++)
    {
        computerLabArray[i] = new int[LABSIZES[i]];
    }
    setInitValues(computerLabArray); // calls function that sets initial values to -1
                                     // where -1 designates an empty/available computer

    // this begins the user-interactive portion of the program
    cout << "WELCOME TO THE COMPUTER LAB OVERSIGHT SERVER\n\n";
    bool loopFlag = true; // controls the loop of user interaction
    do {
        // calls function that initiates user interaction
        int menuChoice = labMenu();
        switch(menuChoice) { // determines where user is sent based on choice
            // choice #1: log a student into a computer
            case 1 : cout << "\nStudent Login Screen\n";
                     loginStudent(computerLabArray);
                break;
            // choice #2: directs user to log-off menu
            //            where they can choose who they
            //            want to log off
            case 2 : cout << "\nLog-off Screen\n";
                     logoffChoice(computerLabArray);
                break;
            // choice #3: allows user to search for a particular student
            // possible addition: allow user to see who is logged into a
            //                    particular computer
            case 3 : cout << "\nCommencing Search\n";
                     searchLab(computerLabArray);
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


/*                      Program Maintenance                         */
/* setInitValues
   precondition: receives array of computer lab records
   postcondition: returns nothing
                  sets all initial entries to -1 (empty value)
   */
void setInitValues(intArrayPtr *computerLabArray)
{
    for (int i = 0; i < NUMLABS; i++)
    {
        for (int j = 0; j < LABSIZES[i]; j++)
        {
            computerLabArray[i][j] = -1;
        }
    }
}

/* deletePtrs
   precondition: receives array of computer lab records
   postcondition: receives nothing
                  deletes all pointers
   */
void deletePtrs(intArrayPtr *computerLabArray)
{
    for (int i = 0; i < NUMLABS; i++)
    {
        delete [] computerLabArray[i];
    }
    delete [] computerLabArray;
}


/*                      User Input Functions                        */
/* labMenu
   precondition: receives nothing
   postcondition: returns integer variable
   for user choice of process
   */
int labMenu()
{
    int choice = 0;
    cout << "MAIN MENU" << endl
         << "1. Simulate Login\n"
         << "2. Simulate Log-off\n"
         << "3. Search\n"
         << "4. Display a Lab\n"
         << "5. Quit\n\n"
         << "What would you like to do? ";
    cin >> choice;

    return choice;
}

/* getID
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

/* checkValidity
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
    if (stringLength != length)
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

/* getLabNum
   precondition: receives nothing
   postcondition: returns integer variable
   for a specific lab number
   */
int getLabNum()
{
    int labNum = 0; // for getting choice of lab

    // loops until a valid int is entered
    bool checkValidity = false;
    do {
        cout << "Enter Lab Number (1-8): ";
        cin >> labNum;

        // checks to makes sure all constraints are met
        // 1. checks for input fail
        // 2. checks for a negative/0 entry
        // 3. checks for a number larger that the number of labs
        if (cin.fail() || (labNum <= 0) || (labNum > NUMLABS))
        {
            cout << labNum << " is not a valid entry\n";
        }
        else { // updates validity of lab number after constraints are met
            checkValidity = true;
        }
    } while(!checkValidity);
    return labNum;
}

/* getCompNum
   precondition: receives nothing
   postcondition: returns integer variable
   for a specific computer number
   */
int getCompNum(int labNum)
{
    int compNum = 0; // holds computer number value
    int labSize = LABSIZES[labNum - 1];

    // loops until constraints are met
    bool checkValidity = false;
    do
    {
        cout << "Enter Computer Number (1-" << labSize << "): ";
        cin >> compNum;

         // checks to makes sure all constraints are met
        // 1. checks for input fail
        // 2. checks for a negative/0 entry
        // 3. checks for a number larger that the number of computers
        if (cin.fail() || (compNum <= 0) || (compNum > labSize))
            cout << compNum << " is not a valid entry\n";
        else // updates once constraints are met
            checkValidity = true;
    } while(!checkValidity);

    return compNum;
}


/*                      Menu Choice Functions                         */
/* loginStudent
   precondition: receives 2D dynamic array of computer lab records
   postcondition: returns nothing
                  updates records to show a new log in attempt
   */
void loginStudent(intArrayPtr* compLabArr)
{
    // variables for user choice of lab, computer, and ID numbers
    int labNumber, computerNumber, studentID;

    // function calls for input of ^necessary variables^
    labNumber = getLabNum();
    computerNumber = getCompNum(labNumber);
    studentID = getID();

    // checks to see if the selected computer is available for use
    if (compLabArr[labNumber - 1][computerNumber - 1] == -1) // if "available"
    {
        // updates computer login status to in use by *insert student ID*
        compLabArr[labNumber - 1][computerNumber - 1] = studentID;
        // outputs login status of student
        cout << "Student ";
        displayID(studentID);
        cout << " has successfully been logged in\n\n";
    }
    else // if the computer is in use already
    {
        // tells user of inaccessibility
        cout << "Student ";
        displayID(studentID);
        cout << " could not be logged in\n";
        // displays who is currently logged into the computer
        cout << "Please log out student ";
        displayID(compLabArr[labNumber - 1][computerNumber - 1]);
        cout << endl << endl;
    }
}

/* logoffChoice
   precondition: receives 2D dynamic array of computer lab records
   postcondition: returns nothing
                  gives user choice of logging off one or more students
                  or logging out all students
   */
void logoffChoice(intArrayPtr* compLabArr)
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
}

/* logoffStudent
   precondition: receives 2D dynamic array of computer lab records
   postcondition: returns nothing
                  updates records to show a new log off attempt
   possible edit: make it possible to log out a student from only one computer
                  while leaving them logged into any other station they might be
                  using
   */
void logoffStudent(intArrayPtr* compLabArr)
{
    int studentID = getID(); // receives data necessary for logging off student

    // checks which computer student is logged into so it can perform log-off procedure
    int compsChecked = 0;
    for (int i = 0; i < NUMLABS; i++)
    {
        for (int j = 0; j < LABSIZES[i]; j++)
        {
            if (compLabArr[i][j] == studentID) // if the student is logged in somewhere
            {
                compLabArr[i][j] = -1; // updates availability of computer station

                // displays log-off success message to standard
                cout << "Student ";
                displayID(studentID);
                cout << " has been logged off of\n"
                     << " computer #" << j + 1
                     << " in lab #" << i + 1 << endl << endl;

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
        cout << "Student ";
        displayID(studentID);
        cout << " is not logged in on any computer\n\n";
    }
}

/* searchLab
   precondition: receives 2D dynamic array of computer lab records
   postcondition: returns nothing
                  searches records for specified student
   */
void searchLab (intArrayPtr *compLabArr)
{
    int studentID = getID(); // receives necessary student info

    // looks for student
    int compsChecked = 0;
    for (int i = 0; i < NUMLABS; i++)
    {
        for (int j = 0; j < LABSIZES[i]; j++)
        {
            // if student is found at a particular station
            if (compLabArr[i][j] == studentID)
            {
                // outputs location of student
                cout << "Student ";
                displayID(studentID);
                cout << " is logged into "
                     << "computer " << j + 1 << " in "
                     << "lab " << i + 1 << endl << endl;
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
        cout << "Student ";
        displayID(studentID);
        cout << " is not logged in on any computer\n\n";
    }
}

/* displayLab
   precondition: receives array for computer lab records
   postcondition: returns nothing
                  outputs specified lab to standard
   */
void displayLab(intArrayPtr *compLabArr)
{
    int labNumber = getLabNum(); // receives lab number

    // outputs all computer stations in the lab to standard
    cout << "Lab " << labNumber << endl;
    for (int i = 0; i < LABSIZES[labNumber - 1]; i++)
    {
        cout << i + 1 << ": ";
        displayID(compLabArr[labNumber - 1][i]);
        cout << "  ";
    }
    cout << "\n\n";
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
