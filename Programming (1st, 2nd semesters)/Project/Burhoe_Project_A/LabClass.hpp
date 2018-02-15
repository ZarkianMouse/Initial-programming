/* A part of Naomi Burhoe's Computer Server Program
   Purpose: holds Lab class declaration             */
#ifndef LABCLASS_HPP_INCLUDED
#define LABCLASS_HPP_INCLUDED

#include <string>
class Lab
{
    private :
        int id;
        std::string name;
        int useTime;
    public :
        // constructors
        Lab() : id(-1), name(" "), useTime(0) {}; // default
        Lab(int i, std::string n, int t) : id(i), name(n), useTime(t) {};
        void setValues(); // resets values to default

        // retrieve and display
        int getID() const; // retrieves user id
        std::string getName() const; // retrieves user name
        int getTime() const; // retrieves use time
        void displayID() const; // displays id as 5-digits

        // operator to assign values of one object to another
        void operator=(const Lab); //
};

// operator to compare two objects of the same type
bool operator==(Lab a, Lab b);

#endif // LABCLASS_HPP_INCLUDED
