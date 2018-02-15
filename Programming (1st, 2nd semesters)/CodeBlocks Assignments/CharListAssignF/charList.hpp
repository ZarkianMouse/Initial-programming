/*
   A Part of Assignment F
   by: Naomi Burhoe
   Purpose: defines CharList class
*/

#ifndef CHARLIST_HPP_INCLUDED
#define CHARLIST_HPP_INCLUDED

// CharList defines a class for a linked list of chars
class CharList
{
    private :
        struct ListNode // a position for the list
        {
            char myChar; // holds char
            ListNode *next; // moves node
        };
        ListNode *head; // designates top of list
    public :
        CharList () {head = nullptr;}; // default constructor
        ~CharList(); // destructor

        void appendNode(char); // adds node to end of list
        void insertNode(char); // inserts node based on value
        void deleteNode(char); // deletes designated nodes
        void displayList() const; // displays contents of list
};

#endif // CHARLIST_HPP_INCLUDED
