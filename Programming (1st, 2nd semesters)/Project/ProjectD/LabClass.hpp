/* A part of Naomi Burhoe's Computer Server Program
   Purpose: holds Lab class declaration
   Class renamed to Console for purposes of linked list */
#ifndef LABCLASS_HPP_INCLUDED
#define LABCLASS_HPP_INCLUDED

#include <string>

class Console
{
    private :
        struct User
        {
            int id;
            std::string name;
        };
        User myUser;
        int useTime;
        int compNum;
        //Note: compNum = labNum for queue

    public :
        // constructors
        Console(); // default
        Console(int, std::string, int, int); // inserted Console

        Console(const Console &);

        void setValues(); // resets values to default
        void setCompNum(int num) {compNum = num;}
        // retrieve and display
        int getID() const; // retrieves user id
        std::string getName() const; // retrieves user name
        int getTime() const; // retrieves use time
        int getCompNum() const; // retrieves computer number
        void displayID() const; // displays id as 5-digits

        // operator to assign values of one object to another
        void operator=(const Console); //
};

// operator to compare two objects of the same type
bool operator==(Console, Console);
bool operator!=(Console, Console);
#endif // LABCLASS_HPP_INCLUDED
