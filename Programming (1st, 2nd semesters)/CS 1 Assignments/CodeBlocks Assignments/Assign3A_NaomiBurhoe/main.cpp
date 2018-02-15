/* Rectangle Display Copyright Naomi Burhoe c. 2016
Author: Naomi Burhoe
Purpose: to create a rectangle with dimensions length x width
*/
#include <iostream>
#include <iomanip>
#include <limits>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    int length = 0;
    int width = 0;

    //validation loop set up
    bool loopHole = true;
    do {

        //inputting initial test values
        cout << "Enter the length and width of the rectangle to be created:\n";
        cout << "length: ";
        cin >> length;
        cout << "width: ";
        cin >> width;

        // testing to see if values concur with valid number requirements
        if ((cin.fail()) || length <= 0 || length >= 75)
        {
            cout << "\nThe length must be a valid number greater than zero.\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if ((cin.fail()) || width <= 0 || width >= 75)
        {
            cout << "\nThe width must be a valid number greater than zero.\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            loopHole = false;
        }
    } while (loopHole);

    //creating the loop that'll design rectangle
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << "X";
        }
        cout << endl;
    }
}
