/* A part of Naomi Burhoe's Computer Server Program
   Purpose: holds function declarations*/

#ifndef LABFUNCTIONS_HPP_INCLUDED
#define LABFUNCTIONS_HPP_INCLUDED
#include <queue>
#include <map>
#include "UniversityList.hpp"

struct FreedConsole
{
    int labNum;
    int compNum;
};

/* Validation */
// checks numeric entries for validity
bool checkValidity(int, int, std::string);
// checks string for non-numeric entries
char checkValidity(std::string, const int);

/* User Input */
// administrator choice of action
int labMenu();
// input for user name
std::string getName();
// input for time used (min)
int getTime();
// input for user ID (for search)
int getID();
// input of lab number
int enterLabNum();
// input of computer number (based on lab number)
int enterCompNum(int);
// generates ID randomly when a new user is added
int getID(LabList []);

/* Process Choices */ // excludes display options
// adds new user/student to computer lab list
FreedConsole loginStudent(LabList [], std::queue<Console> &, FreedConsole);
// removes user/student from list
FreedConsole logoffStudent(LabList []);
// searches for user by name
void searchName(LabList []);
// searches for user by ID #
void searchID(LabList []);
// presents choice of search
void searchLabMenu(LabList []);

/* Display */
// displays ID based on 5-digit standard
void displayID(int);
// displays all users in a lab
// Note: does not list all available computers
void displayLab(LabList []);
// displays file containing login/log-off attempts
void displayFile();

#endif // LABFUNCTIONS_HPP_INCLUDED
