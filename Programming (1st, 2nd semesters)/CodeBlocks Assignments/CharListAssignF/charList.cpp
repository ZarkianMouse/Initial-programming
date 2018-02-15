/*
   COPYRIGHT (C) 2017 Naomi Burhoe All rights reserved.
   CSII assignment F
   Author.  Naomi Burhoe
            nrb74@zips.uakron.edu
   Version. 1.01 10.17.2017

*/
#include <iostream>
#include "charList.hpp"

//**************************************************
// appendNode adds nodes to the end of the linked  *
// list                                            *
// pre: receives character to be appended          *
// post: returns nothing, a node is added          *
//**************************************************
void CharList::appendNode(char nChar)
{
   ListNode *newNode; // node to be added
   ListNode *nodePtr; // current node

   // defines newNode using nChar
   newNode = new ListNode;
   newNode->myChar = nChar;
   newNode->next = nullptr;

    // if empty, newNode becomes head node
   if(!head)
        head = newNode;

   // if not, moves through list until end is reached
   // adds newNode to the end
   else
   {
       nodePtr = head;
       while(nodePtr->next)
          nodePtr = nodePtr->next;
       nodePtr->next = newNode;
   }
}

//**************************************************
// insertNode adds nodes to linked list between    *
// other nodes based on value                      *
// pre: receives character to be inserted          *
// post: returns nothing, a node is added          *
//**************************************************
void CharList::insertNode(char nChar)
{
    // used to move through list
    ListNode *newNode; // node to be added
    ListNode *nodePtr; // ptr to current node in list
    ListNode *previousNode = nullptr; // ptr to previous node

    // defines new node
    newNode = new ListNode;
    newNode->myChar = nChar;

    // if head is empty, sets newNode to head
    if (!head)
    {
        head = newNode;
        newNode->next = nullptr;
    }

    // if not empty, checks if value of newNode is greater than current node
    else
    {
        nodePtr = head;
        while (nodePtr != nullptr && newNode->myChar < nodePtr->myChar)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // if the last node was null (indicating current node is head)
        // sets newNode to head
        if (previousNode == nullptr)
        {
            head = newNode;
            newNode->next = nodePtr;
        }

        // if not, inserts newNode between current and previous nodes
        else
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

//**************************************************
// deleteNode removes nodes from the linked list   *
// pre: receives character to be removed           *
// post: returns nothing, a node is removed,       *
//      unless the value passed is not in the list *
//**************************************************
void CharList::deleteNode(char oChar)
{
    // variables to change node position
    ListNode *nodePtr;
    ListNode *previousNode;

    // does not continue operation if list is empty
    if(!head)
        return;

    // checks to see if char is head
    else if (head->myChar == oChar)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }

    // otherwise sets node to head and moves through list
    else
    {
        nodePtr = head;
        while (nodePtr != nullptr && nodePtr->myChar != oChar)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // deletes node if it isn't nullptr
        if (nodePtr)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
// pre: an empty parameter list                    *
// post: standard output of the linked list        *
//**************************************************

void CharList::displayList() const
{
   ListNode *nodePtr;  // To move through the list

   // Position nodePtr at the head of the list.
   nodePtr = head;
   short count = 0;

   // While nodePtr points to a node, traverse
   // the list.
   while (nodePtr)
   {
      // Display the value in this node.
      std::cout << "[" << nodePtr->myChar << "] -> ";
      ++count;
      // Move to the next node.
      nodePtr = nodePtr->next;
      if (count % 10 == 0) {
        std::cout << std::endl;
        count = 0;
      }
   }
   std::cout << std::endl;
}


// More of your coding required here


//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
// pre: n/a                                        *
// post: destroyed object                          *
//**************************************************

CharList::~CharList()
{
   ListNode *nodePtr;   // To traverse the list
   ListNode *nextNode;  // To point to the next node

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr is not at the end of the list...
   while (nodePtr != nullptr)
   {
      // Save a pointer to the next node.
      nextNode = nodePtr->next;

      // Delete the current node.
      delete nodePtr;

      // Position nodePtr at the next node.
      nodePtr = nextNode;
   }
}
