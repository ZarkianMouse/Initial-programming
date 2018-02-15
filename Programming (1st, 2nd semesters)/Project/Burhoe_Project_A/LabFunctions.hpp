/* A part of Naomi Burhoe's Computer Server Program
   Purpose: holds constants and function declarations*/

#ifndef LABFUNCTIONS_HPP_INCLUDED
#define LABFUNCTIONS_HPP_INCLUDED

//Function Declarations
//functions for program maintenance
void deletePtrs(Lab **); // deletes ptrs
char checkValidity(std::string, const int); //checks for non-numeric characters

//functions for general user input
int labMenu(); // presents user choice
std::string getName(); // receives name from standard
int getTime(); // receives use time from standard

bool checkValidity(int, int, std::string); // checks validity of int input
int enterLabNum();  // receives lab # from standard
int enterCompNum(int);  // receives computer # from standard
//input for searching
int getID();  // receives ID from standard for searching

// functions for process choice
//log-in process
void loginStudent(Lab **);  // logs student into system
bool isLabFull(Lab **, int); // checks to see if designated lab is full
int getID(Lab **); // generates random ID for new log-ins

//log-off process
void logoffChoice (Lab **);  // gives user choice of how many students to be logged out
void logoffStudent(Lab **);  // logs student out of system

void setInitValues(Lab **); // resets labs to default status

//search process
void searchLabMenu(Lab **);  // gives user choice of what info to search for
void searchID(Lab **); // searches for student by ID number
void searchName(Lab **); // searches for student by name

//display
void displayID(int);
void displayLab(Lab **);  // displays lab in standard

#endif // LABFUNCTIONS_HPP_INCLUDED
