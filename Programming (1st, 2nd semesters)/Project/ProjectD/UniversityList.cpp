/* A part of Naomi Burhoe's Computer Server Program
   Purpose: holds LabList function definitions     */

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <ctype.h>
#include <fstream>
#include <memory>
#include <iomanip>
#include "UniversityList.hpp"
#include "LabClass.hpp"
#include "LabFunctions.hpp"
#include "myConstants.h"

/* Destructor
   precondition: receives nothing
   postcondition: deletes list
   */
LabList::~LabList()
{
    ListNode *nodePtr, *nextNode;

    nodePtr = head;

    while (nodePtr != nullptr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

// Optimization #3: moved function declarations to above where they are used in other functions
/* isEmpty() checks to see if the lab is currently empty
   precondition: receives nothing
   postcondition: returns true if the lab is empty
   and false otherwise
   */
bool LabList::isEmpty()
{
    if(!head)
        return true;
    else
        return false;
}

/* isFull checks to see if the lab is currently full
   precondition: receives capacity of lab (listSize)
   postcondition: returns true if the lab is full
   and false otherwise
   */
bool LabList::isFull(int listSize)
{

    int compsChecked = 0;
    bool status = false;
    ListNode *nodePtr;

    if(!head)
    {
        status = false;
    }
    else
    {
        nodePtr = head;
        while (nodePtr != nullptr)
        {
            if (nodePtr == nullptr)
                break;
            nodePtr = nodePtr->next;
            compsChecked++;
        }

        if(compsChecked == listSize)
            status = true;
        else
            status = false;

    }

    return status;
}

/* appendNode adds nodes to the end of the linked list                                            *
   precondition: receives user to be appended
   postcondition: returns nothing, a node is added
   */
void LabList::appendNode(Console nUser, int labNum)
{
   ListNode *newNode, *nodePtr;
   newNode = new ListNode;
   newNode->user = nUser;
   newNode->next = nullptr;

   if(!head)
   {
       head = newNode;

       char IO = 'I';
       fileAppend(nUser, labNum, IO);
   }

   else
   {
       nodePtr = head;
       while(nodePtr->next)
          nodePtr = nodePtr->next;
       nodePtr->next = newNode;

       char IO = 'I';
       fileAppend(nUser, labNum, IO);
   }
}

/* insertNode adds nodes to linked list between
   other nodes based on value
   precondition: receives Console object to be inserted
   postcondition: returns nothing, a node is added
   */
void LabList::insertNode(Console nUser, int labNum)
{
    ListNode *newNode, *nodePtr;
    ListNode *previousNode = nullptr;
    newNode = new ListNode;
    newNode->user = nUser;

    if (!head)
    {
        head = newNode;
        newNode->next = nullptr;

        char IO = 'I';
        fileAppend(nUser, labNum, IO);
    }
    else
    {
        nodePtr = head;
        while (nodePtr != nullptr && nUser.getCompNum() > nodePtr->user.getCompNum())
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (previousNode == nullptr)
        {
            head = newNode;
            newNode->next = nodePtr;

            char IO = 'I';
            fileAppend(nodePtr->user, labNum, IO);
        }
        else
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;

            char IO = 'I';
            fileAppend(nUser, labNum, IO);
        }
    }
}

/* deleteNode removes nodes from the linked list
   precondition: receives user ID and name to be removed
   postcondition: returns nothing, a node is removed, if possible
   */
int LabList::deleteNode(int ID, std::string name, int labNum)
{
    ListNode *nodePtr, *previousNode;

    int compNum;
    // checks if lab is empty
    if(!head)
    {
        std::cout << "Lab is empty\n";
        return -1;
    }

    // if not, checks if user exists in first node
    else if (head->user.getID() == ID && head->user.getName() == name)
    {

        std::cout << "User " << head->user.getName() << " has been logged out of"
                  << " computer #" << head->user.getCompNum() << "\nID #";
        head->user.displayID();
        std::cout << "\nUse Time: " << head->user.getTime() << " minutes\n";

        char IO = 'O';
        fileAppend(head->user, labNum, IO);

        compNum = head->user.getCompNum();
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }

    // if not, checks if user exists anywhere
    else
    {
        nodePtr = head;
        while (nodePtr != nullptr && nodePtr->user.getID() != ID && nodePtr->user.getName() != name)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // if so, user is removed from list
        if (nodePtr)
        {
            std::cout << "User " << nodePtr->user.getName() << " has been logged out of"
                      << " computer #" << nodePtr->user.getCompNum() << "\nID#";
            nodePtr->user.displayID();
            std::cout << "\nUse Time: " << nodePtr->user.getTime() << " minutes\n";

            char IO = 'O';
            fileAppend(nodePtr->user, labNum, IO);

            compNum = nodePtr->user.getCompNum();
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }

        // outputs message if user was not in lab originally
        else if (nodePtr == nullptr)
        {
            std::cout << "User " << name << " is not logged into this lab\n";
        }
    }
    return compNum;
}

/* findName searches for user based on name
   precondition: receives name to be searched for
   postcondition: returns a message based on status
   of name in list
   */
std::string LabList::findName(std::string fName)
{
    ListNode *nodePtr;
    std::string msg;

    // checks to see if lab is empty
    if(!head)
    {
        msg = "Lab is empty\n";
        return msg;
    }

    // if not empty, checks to see if first node contains name
    else if (head->user.getName() == fName)
    {
        std::cout <<"User " << fName << " is located at computer #"
                  << head->user.getCompNum() << "\nID: ";
        head->user.displayID();
        msg = "";
        return msg;
    }

    // if not, checks all other nodes in lab list
    else
    {
        nodePtr = head;
        while (nodePtr != nullptr && nodePtr->user.getName() != fName)
        {
            nodePtr = nodePtr->next;
        }

        // if user is found, outputs name, location in lab, and ID #
        if(nodePtr->user.getName() == fName)
        {
            std::cout << "User " << fName << " is located at computer #"
                      << nodePtr->user.getCompNum() << "\nID: ";
            nodePtr->user.displayID();
            msg = "";
        }

        // if not, updates message to be returned
        else if (nodePtr == nullptr)
            msg = "User could not be found in this lab\n";

    }
    return msg;
}

/* findID searches for user based on ID #
   precondition: receives ID # to be searched for
   postcondition: returns a message based on status
   of ID # in list
   */
std::string LabList::findID(int fID)
{
    ListNode *nodePtr;
    std::string msg;

    // checks to see if lab is empty
    if(!head)
    {
        msg = "Lab is empty\n";
        return msg;
    }

    // if not empty, checks to see if first node contains ID #
    else if (head->user.getID() == fID)
    {
        std::cout <<"User ";
        displayID(fID);
        std::cout << " is located at computer #"
                  << head->user.getCompNum() << "\n"
                  << "Name: " << head->user.getName() << "\n";
        msg = "";
        return msg;
    }

    // if not, checks all other nodes in lab list
    else
    {
        nodePtr = head;
        while (nodePtr != nullptr && nodePtr->user.getID() != fID)
        {
            nodePtr = nodePtr->next;
        }

        // if user is found, outputs name, location in lab, and ID #
        if(nodePtr->user.getID() == fID)
        {
            std::cout <<"User ";
            displayID(fID);
            std::cout << " is located at computer #"
                      << head->user.getCompNum() << "\n"
                      << head->user.getName() << "\n";
            msg = "";
            return msg;
        }

        // if not, updates message to be returned
        else if (nodePtr == nullptr)
        {
            msg = "User could not be found in this lab\n";
        }
    }
    return msg;
}

/* doesIDExist searches for user based on ID #
   precondition: receives ID # to be searched for
   postcondition: returns true if ID found, and
   false otherwise
   */
bool LabList::doesIDExist(int nID)
{
    ListNode *nodePtr;
    bool idExists = false;

    // checks to see if lab is empty
    if(!head)
    {
        return idExists;
    }

    // if not empty, checks to see if first node contains ID #
    else if (head->user.getID() == nID)
    {
        idExists = true;
        return idExists;
    }

    // if not, checks all other nodes in lab list
    else
    {
        nodePtr = head;
        while (nodePtr != nullptr ||  nID != nodePtr->user.getID())
        {
            if (nodePtr->next == nullptr || nID != nodePtr->user.getID())
                break;
            nodePtr = nodePtr->next;
        }

        if (nodePtr == nullptr)
            return idExists;

        // if user is found, updates value of idExists accordingly
        else if(nodePtr->user.getID() == nID)
        {
            idExists = true;
            return idExists;
        }

    }

    return idExists;
}

/* searchList searches for user
   precondition: receives user object to be found
   postcondition: returns true if the user is exists
   returns false otherwise
   */
bool LabList::searchList(Console fUser)
{
    ListNode *nodePtr;
    bool isUserThere;

    // checks to see if lab is empty
    if(isEmpty())
    {
        isUserThere = false;
    }

    // if not, checks if first node matches computer to be filled
    else if (head->user.getCompNum() == fUser.getCompNum())
    {
        std::cout << "User " << fUser.getName() << " could not be logged in\n"
                  << "Please log out user " << head->user.getName();
        isUserThere = true;
    }

    // if not, checks if computer number is represented anywhere else in list
    else
    {
        nodePtr = head;
        while (nodePtr != nullptr && nodePtr->user.getCompNum() != fUser.getCompNum())
        {

            if(nodePtr->next == nullptr || (nodePtr != nullptr && nodePtr->user.getCompNum() != fUser.getCompNum()))
                break;
            nodePtr = nodePtr->next;
        }

        // if currently in use, sets value accordingly
        if(nodePtr->user.getCompNum() == fUser.getCompNum())
        {
            std::cout << "User ";
            fUser.displayID();
            std::cout << " could not be logged in\n"
                      << "Please log out user ";
            head->user.displayID();
            isUserThere = true;
        }

        // if computer is represented nowhere in list, such is indicated
        else
        {
            isUserThere = false;
        }
    }

    return isUserThere;
}

/* displayList shows the value stored in each node
   of the linked list pointed to by head.
   precondition: an empty parameter list
   postcondition: standard output of the linked list
   */
void LabList::displayList() const
{
    ListNode *nodePtr = head;
    if (!head)
    {
        std::cout << "This lab is currently empty\n";
    }
    while(nodePtr != nullptr)
    {
       std::cout << "Console #" << nodePtr->user.getCompNum() << "\n";
       std::cout << "User ID: ";
       nodePtr->user.displayID();
       std::cout << "\nName: " << nodePtr->user.getName() << '\n';
       std::cout << "Use time: " << nodePtr->user.getTime() << " minutes\n\n";
       nodePtr = nodePtr->next;
    }
    return;
}

/* fileAppend() appends login/logoff attempts to output file
   precondition: receives user, lab number, and char for input/output
   postcondition: returns nothing
   */
void LabList::fileAppend(Console user, int labNum, char IO)
{
    // opens file
    std::ofstream outFile;
    outFile.open("LabLoginFile.txt", std::ios_base::app);

    // used from CPPreference
    auto time = std::chrono::system_clock::now();   // get time now
    std::time_t now = std::chrono::system_clock::to_time_t(time); // converts time

    // appends attempt to file
    outFile << std::ctime(&now) // changes time to c-string type for easier readability
            << "Lab: " << UNIVERSITYNAMES[labNum - 1] << std::endl
            << "IO type: " << IO << std::endl
            << "User ID: " << std::setw(5) << std::setfill('0') << user.getID() << std::endl
            << "Time Use: " << user.getTime() << " minutes\n"
            << "User Name: " << user.getName() << std::endl << std::endl;
    return;
}
