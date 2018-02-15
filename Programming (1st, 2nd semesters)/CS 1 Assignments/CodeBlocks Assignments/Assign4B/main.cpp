#include <iostream>
#include <limits>

using std::cout;
using std::endl;
using std::cin;
using std::string;

float mySquareRoot(float);
bool validateInput(float, float, float, string);
const float EPSILON = .0001;
int main()
{
    float number;
    bool loopFlag = true;
    string msg ("Please enter a real number 1 to 100");

    cout << "To begin square root approximation, enter a real number (1-100): ";
    do
    {
        cin >> number;
        loopFlag = validateInput(number, 1, 100, msg);
    } while (loopFlag);

    float squareRoot = mySquareRoot(number);

    cout << "The square root approximation for " << number << " is " << squareRoot << endl;

    cout << "\nTest calculation for the square roots of first 10 positive integers:\n";

    for (int i = 1; i <= 10; i++)
    {
        cout << "The square root approximation for " << i << " is: " << mySquareRoot(i) << endl;
    }
}

float mySquareRoot(float square)
{
    float lower = .1;
    float upper = 10.1;
    float root = (lower + upper) / 2;

    while (upper - lower > EPSILON)
    {
        if (root * root == square)
        {
            return root;
        }
        else if (root * root > square)
        {
            upper = root;
        }
        else
        {
            lower = root;
        }
        root = (lower + upper) / 2;
    }
    return root;
}

// Validate Input takes integer data and ensures it is correct.
// Note: it is asking is the data invalid? so true/false is in that vein
// precondtion: pass the function the user choice
//              pass the function a range, range1 lowest acceptable
//              pass the function a range, range2 highest acceptable
//              pass the message to display for any user error
// postcondition: returns false if valid and true if not
bool validateInput(float userChoice, float range1, float range2, string message)
{
  bool goodOrNot = false;
  if ((cin.fail()) || ((userChoice < range1) || (userChoice > range2)))
  {
 	cout << message << endl;
    goodOrNot = true;
  }
  cin.clear();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return goodOrNot;
}
