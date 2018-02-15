/* Part of Naomi Burhoe's String Stack program
   Purpose: holds the definition and functions
   for the DynStringStack class (a class
   representing a dynamic string stack) */

#include <iostream>
#include <string>

using std::string;
class DynStringStack
{
    private :
        struct StackNode
        {
            string value;
            StackNode *next;
        };
        StackNode *top;
    public :
        //constructor
        DynStringStack() {top = nullptr;};


        //operation functions
        void push(string);
        string pop();
        //constraint check
        bool isEmpty() const;
};

/* DynStringStack::push()
   precondition: receives string to be added to stack
   postcondition: returns nothing, inserts string at
   end of stack (like a linked list)
   */
void DynStringStack::push(string myStr)
{
   // for node to be inserted
   StackNode *newNode = new StackNode;
   newNode->value = myStr;

   // if an empty stack, sets init value to newNode
   if(isEmpty())
   {
       top = newNode;
       newNode->next = nullptr;
   }
   // if not empty, appends node to end of list
   else
   {
       newNode->next = top;
       top = newNode;
   }
}

/* DynStringStack::pop()
   precondition: receives nothing
   postcondition: returns string representing
   most recent string removed from stack
   */
string DynStringStack::pop()
{
   StackNode *temp = nullptr;
   string myStr;

   if(isEmpty())
   {
       myStr = "The stack is empty\n";
   }
   // if stack isn't empty, a node is deleted
   else
   {
       myStr = top->value;
       temp = top->next;
       delete top;
       top = temp;
   }

   return myStr;
}

/* DynStringStack::isEmpty()
   precondition: receives nothing
   postcondition: returns true if
   stack currently contains nothing,
   returns false otherwise
   */
bool DynStringStack::isEmpty() const
{
    bool status;
    if (!top)
        status = true;
    else
        status = false;

    return status;
}
