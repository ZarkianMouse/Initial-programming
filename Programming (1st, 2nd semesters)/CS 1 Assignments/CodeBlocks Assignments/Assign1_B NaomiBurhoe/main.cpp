/* Program: Quarters, Dimes, and Nickels Calculation
Author: Naomi Burhoe
Purpose: to calculate the monetary value of a certain number
of quarters, dimes, and nickels in a stack of change
*/
#include <iostream>

using namespace std;

int main()
{
    //variables to represent number of quarters, dimes and nickels
    int quarter;
    int dime;
    int nickel;

    cout << "Enter number of quarters: ";
    cin >> quarter;
    cout << "Enter number of dimes: ";
    cin >> dime;
    cout << "Enter number of nickels: ";
    cin >> nickel;

    // variable/function to represent monetary value of coins inputted previously
    int monetaryValue = (25 * quarter) + (10 * dime) + (5 * nickel);
    cout << "The monetary value of your coins is " << monetaryValue << " cents.";


}
