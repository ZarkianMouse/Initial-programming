/* The Dynamic String Stack Challenge
   Copyright of Naomi Burhoe c. 2017
   Purpose:  to perform basic stack functions, namely pushing
   and popping, using a dynamic stack of strings
*/

#include <iostream>
#include "DynStringStack.hpp"

int main()
{
	// Create a DynamicStringStack object.
	DynStringStack myStack;

	// Push the strings "one", "two", and
	// "three" onto the stack.
	std::cout << "Pushing one\n";
	myStack.push("one");
	std::cout << "Pushing two\n";
	myStack.push("two");
	std::cout << "Pushing three\n";
	myStack.push("three");

	// Pop the first string from the stack
	// and display it.
	std::cout << "Popping...\n";
	std::cout << myStack.pop();

	// Pop the second string from the stack
	// and display it.
	std::cout << "\nAttempting to pop again... ";
	std::cout << std::endl;
	std::cout << myStack.pop();

	// Pop the third string from the stack
	// and display it.
	std::cout << "\nAttempting to pop again... ";
	std::cout << std::endl;
	std::cout << myStack.pop();

	// The stack is empty, but try to pop again.
	std::cout << "\nAttempting to pop again... ";
	std::cout << std::endl;
	std::cout << myStack.pop();

	return 0;
}
