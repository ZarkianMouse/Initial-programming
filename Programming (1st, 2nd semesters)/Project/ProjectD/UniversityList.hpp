/* A part of Naomi Burhoe's Computer Server Program
   Purpose: holds LabList class definition (linked list)
   Note: This design only covers the list for a single lab
   An array of linked lists is used to hold multiple labs */

#ifndef UNIVERSITYLIST_HPP_INCLUDED
#define UNIVERSITYLIST_HPP_INCLUDED

#include "LabClass.hpp"
class LabList
{
    private :
        struct ListNode
        {
            Console user;
            ListNode *next;
        };
        ListNode *head;
    public :
        // constructor
        LabList () {head = nullptr;};
        // destructor
        ~LabList();

        // operation functions
        bool isEmpty(); //checks if lab is empty
        bool isFull(int); // checks if lab is full
        void appendNode(Console, int); // appends node to end of list
        void insertNode(Console, int); // inserts node based on compNum value
        int deleteNode(int, std::string, int); // deletes node, if possible

        // search
        std::string findName(std::string); // searches based on name
        std::string findID(int); // searches based on ID #
        bool doesIDExist(int); // checks if ID exists
        bool searchList(Console); // searches list for user

        // display
        void displayList() const;
        void fileAppend(Console, int, char);
};



#endif // UNIVERSITYLIST_HPP_INCLUDED
