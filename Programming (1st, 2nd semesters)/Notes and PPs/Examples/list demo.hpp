
#ifndef LIST_HPP
#define LIST_HPP
//   COPYRIGHT (C) Will Crissey, Jr. 2015  All rights reserved.
// List class-template definition.
#include <iostream>
#include "ListNode.hpp" // ListNode class definition
// let's look at listnode - this is encapsulated in each list obj


// now List class template
template<typename NODETYPE>
class List
{

// we declare private data members
// firstPtr (a pointer to the first ListNode in a List)
// and lastPtr (a pointer to the last ListNode in a List)
private:
   ListNode<NODETYPE> *firstPtr{nullptr}; // pointer to first node
   ListNode<NODETYPE> *lastPtr{nullptr}; // pointer to last node

   // utility function to allocate new node - used by insert methods
   // we return a dynamically allocated ListNode object
   ListNode<NODETYPE> *getNewNode(const NODETYPE& value)
   {
      return new ListNode<NODETYPE>{value};
   }

// now the public members
public:
   // default constructor - initializes both pointers to null
   List()
   {
      firstPtr = lastPtr = nullptr;
   }

   // copy constructor - initialize to null again
   List(const List<NODETYPE> &copy)
   {
      firstPtr = lastPtr = nullptr; // initialize pointers

      ListNode<NODETYPE> *currentPtr{copy.firstPtr};
      // the object's first pointer is the current pointer

      // insert into the list
      while (currentPtr != 0)
      {
         insertAtBack(currentPtr->data);
         currentPtr = currentPtr->nextPtr;
      }
   }

   // destructor - ensures that all ListNode objects in a
   // List object are destroyed when that List object is destroyed
   ~List()
   {
      if (!isEmpty())
      { // List is not empty
         std::cout << "Destroying nodes ...\n";

         ListNode<NODETYPE>* currentPtr{firstPtr};
         ListNode<NODETYPE>* tempPtr{nullptr};

         while (currentPtr != nullptr)
         { // delete remaining nodes
            tempPtr = currentPtr;
            std::cout << tempPtr->data << '\n';
            currentPtr = currentPtr->nextPtr;
            delete tempPtr;
         }
      }

      std::cout << "All nodes destroyed\n\n";
   }

   // insert node at front of list
   void insertAtFront(const NODETYPE &value)
   {
// Call function getNewNode - passing node value to be inserted
      ListNode<NODETYPE>* newPtr{getNewNode(value)}; // new node

      if (isEmpty())  // predicate function determines whether the
      {               // List is empty
         firstPtr = lastPtr = newPtr; // new list has only one node
      }
      else
      { // List is not empty
         newPtr->nextPtr = firstPtr; // point new node to old 1st node
// if the list is empty, firstPtr and lastPtr are set to newPtr
         firstPtr = newPtr; // aim firstPtr at new node
// if not, newPtr is threaded into the list by copying firstPtr to newPtr->nextPtr
// so new node points to what used to be the first node of the list
      }
   }
// after this call, newPtr has the address of the new piece of memory

   // insert node at back of list
   void insertAtBack(const NODETYPE &value)
   {
      ListNode<NODETYPE> *newPtr{getNewNode(value)}; // new node

      if (isEmpty())
      { // List is empty - just set first and last to newPtr
         firstPtr = lastPtr = newPtr; // new list has only one node
      }
      else
      { // List is not empty - thread newPtr to next (set next to new)
         lastPtr->nextPtr = newPtr; // update previous last node
         lastPtr = newPtr; // new last node - copy newPtr to last (now new is last)
      }
   }

   // delete node from front of list
   bool removeFromFront(NODETYPE& value)
   {
      if (isEmpty())
      { // List is empty - we cannot delete anything
         return false; // delete unsuccessful
      }
      else
      {
         ListNode<NODETYPE>* tempPtr{firstPtr}; // hold item to delete

         if (firstPtr == lastPtr) // list has only one element
         {
            firstPtr = lastPtr = nullptr; // no nodes remain after removal (dethread)
         }
         else
         {
            firstPtr = firstPtr->nextPtr; // point to what was the 2nd node prior to removal
         }

         value = tempPtr->data; // set value to data being removed
         delete tempPtr; // reclaim previous front node
         return true; // delete successful
      }
   }

   // delete node from back of list

   bool removeFromBack(NODETYPE& value)
   {
      if (isEmpty())
      { // List is empty - nothing to remove
         return false; // delete unsuccessful
      }
      else
      {
         ListNode<NODETYPE>* tempPtr{lastPtr}; // hold item to delete

         if (firstPtr == lastPtr) // last node so make the list empty
         { // List has one element
            firstPtr = lastPtr = nullptr; // no nodes remain after removal
         }
         else
         {
            ListNode<NODETYPE> *currentPtr{firstPtr}; // assign current pointer
                                                      // the address if firstPtr

            // locate second-to-last element by traversing until the last node
            while (currentPtr->nextPtr != lastPtr)
            {
               currentPtr = currentPtr->nextPtr; // move to next node
            }

            lastPtr = currentPtr; // remove last node (dethread it)
            currentPtr->nextPtr = nullptr; // this is now the last node, so null
         }

         value = tempPtr->data; // set value to old last node
         delete tempPtr; // reclaim former last node
         return true; // delete successful
      }
   }

   // is List empty?
   bool isEmpty() const
   {
      return firstPtr == nullptr;
   }

   // display contents of List
   void print() const
   {
      if (isEmpty())
      { // List is empty
         std::cout << "The list is empty\n\n";
         return;
      }

// initialize currentPtr as a copy of firstPtr
      ListNode<NODETYPE> *currentPtr{firstPtr};

      std::cout << "The list is: ";

      while (currentPtr != nullptr)
      { // get element data
         std::cout << currentPtr->data << ' '; // print the data
         currentPtr = currentPtr->nextPtr;
      }

      std::cout << "\n\n";
   }

};

#endif
