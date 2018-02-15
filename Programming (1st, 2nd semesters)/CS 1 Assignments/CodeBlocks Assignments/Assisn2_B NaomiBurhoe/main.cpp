/* Program: Treadmill Copyright of Naomi Burhoe c. 2016
Author: Naomi Burhoe
Purpose: to emulate the output of a treadmill in minutes/seconds per mile rather than mph
*/
#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::setprecision;

int main()
{
    //the loopHole integer merely is there so I can create the do-while loop for user benefit
    int loopHole = 0;
    do {
    //creating the variables for treadmill project
    double milesInHour;
    double hourPerMile;
    double minutePerMile;
    double secondPerMile;

    //miles per hour based on user input
    std::cout << "Enter mph achieved: ";
    std::cin >> milesInHour;

    // conversion of mph to hrs/mile
    hourPerMile = 1 / milesInHour;

    // conversion to minutes/mile
    minutePerMile = static_cast<int> (hourPerMile * 60);

    // calculating seconds in pace
    secondPerMile = hourPerMile * 60 - minutePerMile;

    //outputting the data
    std::cout << "Your pace is " << minutePerMile << " minutes and ";
    std::cout << setprecision(1) << secondPerMile << " seconds per mile.\n";

    //initializing the user loop preference for user benefit
    std::cout << "Would you like to see what another pace would look like?\n";
    std::cout << "Enter 0 for yes, or 1 for no: ";
    std::cin >> loopHole;

    //simply stating a fact, the user will have to fully restart program if they hit another nonzero number
    std::cout << "\nIf you hit another nonzero number, it still counts as no.\n";
    } while (loopHole == 0);

    return 0;
}
