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
#include <sstream>
#include <fstream>
#include <queue>
#include <stdexcept>
#include <limits>
#include "LabFunctions.hpp"
#include "myConstants.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::istringstream;

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
         << "5. Display Log File\n"
         << "6. Quit\n\n";

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
        {
            cout << name << " is too long\n";
        }
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

/* enterLabNum
   precondition: receives nothing
   postcondition: returns integer variable
   for a specific lab number
   */
int enterLabNum()
{
    char labNum1 = '0'; // for getting choice of lab
    char *l = &labNum1;
    int labNum = 0;

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
        cin >> labNum1;

        if (isdigit(labNum1))
        {
            labNum = atoi(l);
            isValid = checkValidity(labNum, NUMLABS, msg);
        }

        if (isValid == false)
            cout << "Lab input is invalid\n";

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


    // exception handling
    do
    {
        try {
            cout << "Enter Computer Number (1-" << labSize << "): ";
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> compNum;
            if (cin.fail())
                throw std::runtime_error("compNum must be a numeric value\n");
            else if(compNum < 1  || compNum > labSize)
                cout << "Input is not within limits\n";
            else
                isValid = true;
        }
        catch (std::exception &e)
        {
            cout << "Standard Error: " << e.what();
        }

    } while(!isValid);

    return compNum;
}

/* getID(new instance)
   precondition: receives array/list of computer lab records
   postcondition: returns a uniquely and randomly
                  generated student ID
   */
int getID(LabList compLabList[])
{
    // necessary variables for getting a correct ID
    int studentID; // is updated once stipulations are met

    bool isValid = false; // updates once ID is valid
    // loops until a valid student ID is generated
    do {
        studentID = rand();

        if (studentID < 100000)
        {
            // searches for ID # in lab list array
            for (int i = 0; i < NUMLABS; i++)
            {
                isValid = !(compLabList[i].doesIDExist(studentID));
                if (isValid == false)
                {
                    break;
                }

            }
        }
    } while(!isValid);
    return studentID;
}


/* Process Choices */
/* logoffStudent
   precondition: receives array/list of computer lab records
   postcondition: returns nothing, adds new user to list, if possible
   */
FreedConsole loginStudent(LabList compLabList[], std::queue<Console> &labQueue, FreedConsole nconsole)
{

    int labNumber;
    Console newUser;
    if (labQueue.empty() || nconsole.compNum == -1)
    {
        // variables for user choice of lab
        labNumber = enterLabNum();

        // checks if lab is currently full
        bool isFull = compLabList[labNumber - 1].isFull(LABSIZES[labNumber - 1]);
        if (isFull == true)
        {
            cout << "Sorry for the inconvenience but the lab for\n"
                 << UNIVERSITYNAMES[labNumber - 1] << " is currently at capacity\n"
                 << "Adding info to queue.\n\n";

            // receives data to be added to queue
            string name = getName();
            int timeUse = getTime();
            // a placeholder ID until the user is added to lab
            int studentID = -1;
            Console newUser(studentID, name, timeUse, labNumber);

            // for adding user to queue
            if (labQueue.empty() == true)
            {
                labQueue.emplace(newUser);
            }
            else
            {
                labQueue.push(newUser);
            }

            nconsole.compNum = -1;
            return nconsole;
        }
        cout << "\n";

        // if not, moves onto next step
        // variables for console object creation
        int computerNumber = enterCompNum(labNumber);
        string name = getName();
        int timeUse = getTime();

        cout << "Getting new ID\n";
        int studentID = getID(compLabList);

        newUser = Console(studentID, name, timeUse, computerNumber);
    }
    else
    {
        labNumber = nconsole.labNum;
        int computerNumber = nconsole.compNum;
        string name = labQueue.front().getName();
        int timeUse = labQueue.front().getTime();
        int studentID = getID(compLabList);
        newUser = Console(studentID, name, timeUse, computerNumber);
    }

    cout << "Checking if user exists in designated console\n";
    // checks if a user exists in currently indicated lab/computer station
    bool isUserThere = compLabList[labNumber - 1].searchList(newUser);
    if(isUserThere == false)
    {
        cout << "No such user exists\n";

        bool isEmpty = compLabList[labNumber - 1].isEmpty();

        if(isEmpty == false)
            compLabList[labNumber - 1].insertNode(newUser, labNumber);
        else
            compLabList[labNumber - 1].appendNode(newUser, labNumber);

        cout << "User " << newUser.getName() << " was logged into"
             << "\ncomputer #" << newUser.getCompNum() << " with ID #";
        newUser.displayID();
        cout << "\n\n";

        if (newUser.getCompNum() == nconsole.compNum)
        {
            labQueue.pop();
            cout << "queue size = " << labQueue.size() << '\n';
        }

    }

    nconsole.compNum = -1;
    return nconsole;
}

/* logoffStudent
   precondition: receives array/list of computer lab records
   postcondition: returns nothing
                  updates records to show a new log off attempt
   */
FreedConsole logoffStudent(LabList compLabList[])
{
    // looks in specific lab
    int labNum = enterLabNum(); // calls for lab to search
    cout << "\nLab #" << labNum << ": " << UNIVERSITYNAMES[labNum - 1] << '\n';

    // variables for search
    int studentID = getID(); // calls search getID
    string name = getName(); // calls name input function

    // if applicable, deletes user node
    FreedConsole nconsole;
    nconsole.compNum = compLabList[labNum - 1].deleteNode(studentID, name, labNum);
    nconsole.labNum = labNum;

    return nconsole;
}

/* searchName
   precondition: receives array/list of computer lab records
   postcondition: returns nothing, searches for an outputs all names
                  with corresponding IDs and use times that match
                  a given name
   */
void searchName(LabList compLabList[])
{
    // prompts student name
    string studentName = getName();
    string msg;

    // looks for student in each lab
    for (int i = 0; i < NUMLABS; i++)
    {
        cout << UNIVERSITYNAMES[i] << " Lab:\n";
        cout << compLabList[i].findName(studentName);
    }
    cout << "\n\n";
    return;
}

/* searchID
   precondition: receives array/list of computer lab records
   postcondition: returns nothing, searches for an outputs ID with
                  corresponding name and time use
   */
void searchID(LabList compLabList[])
{
    //prompts student ID
    int studentID = getID();
    std::string msg;
    // looks for student in each lab
    // there should only be one location with that ID listed
    // the rest should say, "user could not be found in this lab"
    for (int i = 0; i < NUMLABS; i++)
    {
        std::cout << UNIVERSITYNAMES[i] << " Lab:\n";
        msg = compLabList[i].findID(studentID);
        std:: cout << msg;
    }
    return;
}

/* searchLabMenu
   precondition: receives array/list of computer lab records
   postcondition: returns nothing, calls function that searches for
                  student based on information given
   */
void searchLabMenu(LabList compLabList[])
{
    // Optimization #4: declaring variables to be used before
    // beginning function processes

    // necessary variables
    int info; // what user wants to search for
    int limit = 2; // user has only two choices
    string msg = "Input is invalid\n";
    bool loopFlag = false; // controls loop

    cout << "What information do you have for the student?\n"
         << "1. Student Name\n"
         << "2. Student ID\n\n";

    // begins validation loop
    do {
        cout << "Enter type of info: ";
        cin >> info;

        loopFlag = checkValidity(info, limit, msg);
        switch(info)
        {
            // if the user has the student's name
            case 1 : searchName(compLabList); // searches for name
                    loopFlag = false;
                    break;
            // if the user has the student's id
            case 2 : searchID(compLabList); // searches for id
                    loopFlag = false;
                    break;
            // if the user input an invalid numeric choice
            default : cout << info << "is invalid\n";
                    loopFlag = true; // forces reiteration of loop
                    break;
        }
    } while(loopFlag);

    return;
}


/* Display */
/* displayID
   precondition: receives student ID variable
   postcondition: returns nothing
                  outputs 5-digit ID to standard
   */
void displayID(int studentID)
{
    // may not be necessary, but is still included
    if (studentID == -1)
        std::cout << "Available";

    // outputs ID with 5-digits
    else
    {
        if(studentID < 10000)
        {
            std::cout << std::setw(5) << std::setfill('0') << studentID;
        }
        else
            std::cout << studentID;
    }
}

/* displayLab
   precondition: receives array/list of computer lab records
   postcondition: returns nothing
                  outputs specified lab to standard
   */
void displayLab(LabList compLabList[])
{
    int labNumber = enterLabNum(); // receives lab number

    // outputs all computer stations in the lab to standard
    cout << "\nLab " << labNumber << ": "
         << UNIVERSITYNAMES[labNumber - 1] << endl;
    compLabList[labNumber - 1].displayList();
}


/* displayLab
   precondition: receives nothing
   postcondition: returns nothing
                  reads in and outputs log file to console
   */
void displayFile()
{
    // for reading file
    std::ifstream inFile("LabLoginFile.txt");

    // simply returns to main menu if file unavailable
    if(!inFile.is_open())
    {
        throw std::runtime_error("file open failure\n");
    }

    // if the file exists, is outputted to console
    std::cout << "LOG FILE\n";
    std::string line;
    while(!inFile.eof())
    {
        if(inFile.eof())
            return;
        std::getline(inFile, line);
        std::cout << line << '\n';
    }
    std::cout << '\n';
    return;
}
