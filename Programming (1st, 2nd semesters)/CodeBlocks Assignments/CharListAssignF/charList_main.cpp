// This program demonstrates simple operations
// on a linked list.
// Modified by Naomi Burhoe for clarity of operation
#include <iostream>
#include "charList.hpp"

int main()
{
   // Define a CharList object.
   CharList list;

   // Append some values to the list.
   list.appendNode('t');
   list.appendNode('s');
   list.appendNode('n');
   list.appendNode('m');
   list.appendNode('j');
   list.appendNode('f');
   list.appendNode('c');
   list.appendNode('a');
   list.displayList();
   std::cout << std::endl;

   // Insert values between other values
   list.insertNode('y');
   list.insertNode('0');
   list.insertNode('9');
   list.insertNode('o');
   list.insertNode('p');
   list.insertNode('@');
   list.insertNode('Q');
   list.displayList();
   std::cout << std::endl;

   // Deletes a value from list
   list.deleteNode('t');
   list.displayList();
   return 0;
}
