/* A part of Naomi Burhoe's Computer Server Program
   Purpose: holds Lab class functions               */

#include <iostream>
#include <string>
#include "LabClass.hpp"


/* Lab::setValues
   precondition: receives nothing
   postcondition: returns nothing
                  resets object to default values
   */
void Lab::setValues()
{
    id = -1;
    name = "Available";
    useTime = 0;
}

/* Lab::getID
   precondition: receives nothing
   postcondition: returns value of object.id
   */
int Lab::getID() const
{
    return id;
}

/* Lab::getName
   precondition: receives nothing
   postcondition: returns value of object.name
   */
std::string Lab::getName() const
{
    return name;
}

/* Lab::getTime
   precondition: receives nothing
   postcondition: returns value of object.useTime
   */
int Lab::getTime() const
{
    return useTime;
}

/* Lab::displayID
   precondition: receives student ID variable
   postcondition: returns nothing
                  outputs 5-digit ID to standard
   */
void Lab::displayID() const
{
    if (id == -1)
        std::cout << "Available";
    else if (id < 10)
        std::cout << "0000" << id;
    else if (id < 100)
        std::cout << "000" << id;
    else if (id < 1000)
        std::cout << "00" << id;
    else if (id < 10000)
        std::cout << "0" << id;
    else
        std::cout << id;
}

/* Lab::operator=
   precondition: receives second object in assignment operation
   postcondition: returns nothing
                  sets first object's members to that of the second's
   */
void Lab::operator=(const Lab b)
{
    id = b.getID();
    name = b.getName();
    useTime = b.getTime();
}

/* operator==
   precondition: two objects of type Lab for comparison
   postcondition: returns a bool variable comparing
                  the individual components of each object
   */
bool operator==(Lab a, Lab b)
{
    return (a.getID() == b.getID()) && (a.getName() == b.getName()) && (a.getTime() == b.getTime());
}
