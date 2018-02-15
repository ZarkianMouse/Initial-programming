/* Assign E by Naomi Burhoe c. 2017
   Purpose: to experiment with namespace
   in different capacities as well as
   experiment with external linkage
   between file                        */

#include <iostream>
#include "myFunction.hpp"
#include "namespace.h"

// myFunction declaration
void myFunction(char []);

// declares myGreeting function
namespace myNamespace1
{
  void myGreeting();
}

// declares another greeting function
namespace myNamespace2
{
  void myGreeting();
}

// declares greeting function in the global namespace
void theGreeting();

int main()
{
  char myArray[SIZE] = "123456789";

  // to demonstrate the SIZE is sharable (external)
  myFunction(myArray);

  // calls second namespace greeting function
  {
      using namespace myNamespace2;
      myGreeting();
  }

  // calls first namespace greeting function
  {
      using namespace myNamespace1;
      myGreeting();
  }

  // calls global namespace greeting function
  theGreeting();

  return 0;
}

/* myNamespace1::myGreeting
   precondition: receives nothing
   postcondition: returns nothing
   purpose: outputs a greeting to standard
*/
void myNamespace1::myGreeting()
{
    std::cout << "Namespace 1 greets you\n";
}

/* myNamespace2::myGreeting
   precondition: receives nothing
   postcondition: returns nothing
   purpose: outputs a greeting to standard
*/
void myNamespace2::myGreeting()
{
    std::cout << "Namespace 2 greets you\n";
}

/* theGreeting
   precondition: receives nothing
   postcondition: returns nothing
   purpose: outputs a greeting to standard
*/
void theGreeting()
{
    std::cout << "Welcome to our global empire\n\n";
}
