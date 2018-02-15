#include <iostream>
#include "myFunction.hpp"
#include "namespace.h"


void myFunction(char []);

namespace myNamespace1
{
  void myGreeting();
}

namespace myNamespace2
{
  void myGreeting();
}

void theGreeting();

int main()
{
  char myArray[SIZE] = "123456789";

  // call your function using only the array - to demonstrate the SIZE is sharable (external)
  myFunction(myArray);
  // call your second namespace greeting function
  {
      using namespace myNamespace2;
      myGreeting();
  }
  // call your first namespace greeting function
  {
      using namespace myNamespace1;
      myGreeting();
  }
  // call your first namespace greeting function
  theGreeting();

  return 0;
}

void myNamespace1::myGreeting()
{
    std::cout << "Namespace 1 greets you\n";
}

void myNamespace2::myGreeting()
{
    std::cout << "Namespace 2 greets you\n";
}

void theGreeting()
{
    std::cout << "Welcome to our global empire\n";
}
