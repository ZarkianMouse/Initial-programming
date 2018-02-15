/* Farmer's Market Part Two
Program Copyright of Naomi Burhoe c. 2016
Purpose: to sort items obtained from a farmer's market
         report, to determine the total contributions
         made to the market, and to output these
         contributions to a separate report file

Note before reading code and running program:
this program will not work as intended
i realized after starting this that i did not allot
enough time to make it good, or even executable

therefore, the items that i do have are simply the
preliminary steps i would usually take

i wasn't certain if i was allowed to remove the title
from the market report file (it is really annoying,
                             and hard to work around)
so i did...to make the program easier to execute.

*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <limits>
#include <string>

using std::cout;
using std::cin;
using std::ios;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::numeric_limits;
using std::streamsize;
using std::ios;
using std::setfill;
using std::setw;

// constant for array size
const int SIZE = 40;

// functions i wanted to use for program
bool inputSuccess(ifstream&);
void fillArray(ifstream&, string [], int [], string [], int);
void sortArray(int [], string [], int);

int main()
{
    ifstream inputFile("marketReport.txt");
    ofstream outputFile("contributions.txt");

    // if file failed to open, program will end here
    // the only function that is actually finished :(
    bool inputFlag = inputSuccess(inputFile);
    if (inputFlag == false)
    {
        outputFile.close();
        return 0;
    }

    // setting up arrays
    string farmName[SIZE];
    int itemCount[SIZE];
    string itemType[SIZE];
    int runningTotal[SIZE] = {0};

    // try to input items into arrays
    fillArray(inputFile, farmName, itemCount, itemType, SIZE);

   // functional call to sort array
    sortArray(itemCount, itemType, SIZE);

    // i keep getting errors in here
    // this loop is supposed to update the running total
    for (int i = 0; i < SIZE; i++)
    {
        if (itemType[i] = itemType[i + 1])
        {
             runningTotal[i] += itemCount[i];
             runningTotal[i] += itemCount[i + 1];
        }
        else
        {
            runningTotal[i] += itemCount[i];
        }
    }

    outputFile     << setw(75) << setfill('=') << '\n'
                   << "=" << "                    Farmer's Market Inventory                   =" << endl
                   << setw(75) << setfill('=') << '\n'
                   << setw(75) << setfill(' ') << '\n';


}

// inputSuccess determines if the file was able to open
// precondition: is passed input file
// postcondition: returns true if file could open
//                returns false if not
bool inputSuccess(ifstream& input)
{
    if (!input)
    {
        cout << "File input error\n";
        return false;
    }
    else
    {
        cout << "Input success!\n";
        return true;
    }
}

// i had a hard time coming up with this functional item
// hence why it is left blank
// i would like some help on this though.
void fillArray(ifstream& input, string farm[], int itemCount[], string type[], int sizeArr)
{
    string title;
    for (int i = 0; i < sizeArr; i++)
    {
        std::getline(input, farm[i], ':');
        input >> itemCount[i];
        input >> type[i];
    }
}

// this function is supposed to sort the array based on program necessities
// but is currently in the state of construction and confusion due to
// time constraints and over-tiredness...
void sortArray(int itemCount, string type[], int sizeArr)
{
    bool swapFlag = true;
    int temp = 0;
    string item;
    do
    {
        swapFlag = false;
        for (int i = 0; i < (sizeArr - 1); i++)
        {
            if (type[i] != type[i + 1])
            {
                item = type[i];
                temp = itemCount[i];
                type[i] = type[i + 1];
                itemCount[i] = itemCount[i + 1];
                type[i + 1] = item;
                itemCount[i + 1] = temp;

                swapFlag = true;
            }

        }
    } while (swapFlag);
}
// but, and I'm sad to say this
// i did leave this to the last minute
// and i work a lot so i had little time to actually complete this
// to the specifications that i would normally
// and doing this after being up since 3:20am sucks
// i am currently giving excuses
// i will try to do better
// this will be my worst grade yet
// i'm sorry
