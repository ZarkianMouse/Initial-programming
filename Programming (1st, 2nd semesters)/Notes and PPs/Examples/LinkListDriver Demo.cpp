/*
   COPYRIGHT (C) Will Crissey, Jr. 2015  All rights reserved.
This program implements a linked list. We're going to use template classes.
The list can hold chars, ints, floats, etc...

One class template will be the nodes, one the list (nodes within the list)

*/

#include <iostream>
#include "List.hpp"

template<typename T>
void concatenate(List<T> &first, List<T> &second)
{
   List<T> temp{second}; // create a copy of second
   T value; // variable to store removed item from temp

   while (!temp.isEmpty())
   {
      temp.removeFromFront(value); // remove value from temp list
      first.insertAtBack(value); // insert at end of first list
   }
}

int main()
{
   // create two list objects, both chars
   List<char> list1; // storage for first list
   List<char> list2; // storage for second list

   // assign alphabets into first list, from a to e
   for (char c{'a'}; c <= 'e'; ++c) {
      list1.insertAtBack(c);
   }

   // call function print to print the list
   list1.print();

   // assign from f to j into second list
   for (char c{'f'}; c <= 'j'; ++c) {
      list2.insertAtBack(c);
   }

   list2.print();

   // function concatenate will append list2 with list1
   concatenate(list1, list2);
/*   cout << "The new list1 after concatenation is:\n";
   list1.print();*/
}
