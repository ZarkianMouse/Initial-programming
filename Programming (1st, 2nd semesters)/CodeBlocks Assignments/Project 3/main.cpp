/* Project 3: Hopsital Bed Assignment
   Programming copyright of Naomi Burhoe c. 2016
   Purpose: to update daily room assignments in a hospital
   based on checkouts, transfers, and new arrivals
*/
#include <iostream>
#include <fstream>
#include "checkOpen.hpp"
#include "readGrid.hpp"

using namespace std;

const int FLOORS = 5;
const int ROOMS = 8;

bool checkOpen(ifstream&);
void readGrid(ifstream &, int [], const int, const int);

int main()
{
    ifstream inFile("beds.txt");
    bool isOpen = checkOpen(inFile);
    if (isOpen == false)
    {
        cout << "Program Ending\n";
        inFile.close();
        return 0;
    }

    char bedsArr[FLOORS][ROOMS];
    readGrid(inFile, bedsArr, FLOORS, ROOMS);


    return 0;
}
