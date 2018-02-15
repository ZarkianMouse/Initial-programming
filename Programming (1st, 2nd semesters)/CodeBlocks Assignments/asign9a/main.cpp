#include <iostream>
#include <cstdlib>
#include <cstring>
#include "reverse.hpp"

using std::cout;
using std::endl;

void reverse(char []);
int main()
{
  // these are the test cases
  char str1[] = "time";
  char str2[] = "straw";
  char str3[] = "deliver";
  char str4[] = "star";
  char str5[] = "knits";


  cout << "The strings before reversing: " << endl;
  cout << str1 << " " << str2 << " " << str3 << " " << str4 << " " << str5 << " " << endl;

  reverse(str1);
  reverse(str2);
  reverse(str3);
  reverse(str4);
  reverse(str5);

  cout << "The strings after reversing: " << endl;
  cout << str1 << " " << str2 << " " << str3 << " " << str4 << " " << str5 << " " << endl;

  return 0;
}

