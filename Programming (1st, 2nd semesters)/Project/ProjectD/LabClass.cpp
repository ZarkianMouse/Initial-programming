/* A part of Naomi Burhoe's Computer Server Program
   Purpose: holds Lab class functions               */

#include <iostream>
#include <iomanip>
#include <string>
#include "LabClass.hpp"

/* Default Constructor
   precondition: receives nothing
   postcondition: creates a new Console object
   with default values
   */
Console::Console()
{
    myUser.id = -1;
    myUser.name = "";
    useTime = 0;
    compNum = -1;
}

/* Normal Constructor
   precondition: receives ints for ID, use time and comp num
                 receives string for user name
   postcondition: creates a new Console object
   based on passed data
   */
Console::Console(int nID, std::string nNme, int nTime, int cNum)
{
    myUser.id = nID;
    myUser.name = nNme;
    useTime = nTime;
    compNum = cNum;
}

/* Copy Constructor
   precondition: receives Console object
   postcondition: creates a new Console object
   based on values of original
   */
Console::Console(const Console &orig)
{
    myUser.id = orig.getID();
    myUser.name = orig.getName();
    useTime = orig.getTime();
    compNum = orig.getCompNum();
}

/* Console::setValues
   precondition: receives nothing
   postcondition: returns nothing
                  resets object to default values
   */
void Console::setValues()
{
    myUser.id = -1;
    myUser.name = "Available";
    useTime = 0;
    compNum = -1;
}

/* Console::getID
   precondition: receives nothing
   postcondition: returns value of object.myUser.id
   */
int Console::getID() const
{
    return myUser.id;
}

/* Console::getName
   precondition: receives nothing
   postcondition: returns value of object.myUser.name
   */
std::string Console::getName() const
{
    return myUser.name;
}

/* Console::getTime
   precondition: receives nothing
   postcondition: returns value of object.useTime
   */
int Console::getTime() const
{
    return useTime;
}

/* Console::getTime
   precondition: receives nothing
   postcondition: returns value of object.compNum
   */
int Console::getCompNum() const
{
    return compNum;
}

/* Console::displayID
   precondition: receives student ID variable
   postcondition: returns nothing
                  outputs 5-digit ID to standard
   */
void Console::displayID() const
{
    if (myUser.id == -1)
        std::cout << "Available";
    else
    {
        if(myUser.id < 10000)
        {
            std::cout << std::setw(5) << std::setfill('0') << myUser.id;
        }
        else
            std::cout << myUser.id;
    }

}

/* Console::operator=
   precondition: receives second object in assignment operation
   postcondition: returns nothing
                  sets first object's members to that of the second's
   */
void Console::operator=(const Console b)
{
    myUser.id = b.getID();
    myUser.name = b.getName();
    useTime = b.getTime();
    compNum = b.getCompNum();
}

/* operator!=
   precondition: two objects of type Console for comparison
   postcondition: returns a bool variable comparing
                  the individual components of each object
   */
bool operator==(Console a, Console b)
{
    return (a.getID() == b.getID()) && (a.getName() == b.getName())&&
           (a.getTime() == b.getTime()) && (a.getCompNum() == b.getCompNum());
}

/* operator!=
   precondition: two objects of type Console for comparison
   postcondition: returns a bool variable comparing
                  the individual components of each object
   */
bool operator!=(Console a, Console b)
{
    return !(a == b);
}
