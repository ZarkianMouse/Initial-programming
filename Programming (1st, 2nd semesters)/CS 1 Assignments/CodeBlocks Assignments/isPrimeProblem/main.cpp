/* Prime Number Program
Copyright of Naomi Burhoe c. 2016
Purpose: asks the user to input a number
and checks to see if the number inputted is
prime.
*/
#include <iostream>
#include <limits>

using std::cout;
using std::endl;
using std::cin;
using std::string;

// functions for validation and calculation
bool validateInput(int, int, int, string);
bool isPrime(int);
bool toContinue();

int main()
{
   // variable for continuation loop
    bool loop = true;
    do
    {
        // variables for validation loop
        bool loopFlag = true;
        int number;
        string msg ("Please enter an integer greater than 0");

        //validation loop
        cout << "Enter a number: ";
        do
        {
            cin >> number;
            loopFlag = validateInput(number, 0, 9999, msg);
        } while (loopFlag);

        // call isPrime to check if number is prime
        bool primeNum;
        primeNum = isPrime(number);
        if (primeNum == false)
        {
            cout << "The number you inputted is not prime" << endl;
        }
        else
        {
            cout << "Congratulations, you have inputted a prime number!" << endl;
        }

        //to continue the loop
        loop = toContinue();
    } while (loop);
    return 0;

}

// Validate Input takes integer data and ensures it is correct.
// Note: it is asking is the data invalid? so true/false is in that vein
// precondtion: pass the function the user choice
//              pass the function a range, range1 lowest acceptable
//              pass the function a range, range2 highest acceptable
//              pass the message to display for any user error
// postcondition: returns false if valid and true if not
bool validateInput(int userChoice, int range1, int range2, string message)
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

// isPrime takes integer data and checks if it is prime
// precondition: pass the function the user choice
// postcondition: returns true if prime and false if not
bool isPrime(int userChoice)
{
    for (int i = 2; i < userChoice; i++)
    {
        if (userChoice % i == 0)
        {
            return false;
        }
    }
    return true;
}

//toContinue asks if user wants to continue program
// postcondition: returns true if user does and false if not
bool toContinue()
{
    char YN;
    cout << "Do you wish to continue?\n"
             << "Enter Y for yes or N for no: ";
    cin >> YN;
    if (YN == 'N' || YN == 'n')
    {
        return false;
    }
    return true;
}
