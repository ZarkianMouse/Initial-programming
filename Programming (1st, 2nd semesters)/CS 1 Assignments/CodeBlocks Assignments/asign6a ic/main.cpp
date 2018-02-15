/* Farmer's Market Report
Copyright of Naomi Burhoe c. 2016
Purpose: this program should input data
from a file
calculate total items and costs incurred
and output them to a new file
 */

// all the preprocessor directives possibly necessary for program
#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>
#include <cstdlib>

// I don't know if this is bad but this is how i prefer
// to organize the operators and such i plan to use
// for the program
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::ios;
using std::setfill;
using std::setw;
bool openFile(ifstream &);
void commenceOutput(ifstream &, ofstream &);

int main()
{
    // file objects for program
    ifstream dataInput("ASSGN6-A.txt");
    ofstream dataOutput ("marketReport");

    // to operate openFile function and check for invalid files
    bool openSuccess = openFile(dataInput);
    switch (openSuccess)
    {
        case true :
            commenceOutput(dataInput, dataOutput);

            break;
        case false :
            cout << "Program failed to open designated file";
            return 0;
    }
}

// openFile() is used to check for invalid file input
// a reference variable for file input is passed to function
// the function returns false if file cannot be opened and true otherwise
bool openFile(ifstream& dataInput)
{
    if (!dataInput)
    {
        return false;
    }
    else
        return true;
}

// commenceOutput does a number of things (probably lose points : ( )
// precondition: is passed reference input file stream
//               is passed reference output file stream
// postcondition: outputs various necessities for farmer's market report
void commenceOutput(ifstream& dataInput, ofstream& dataOutput)
{
     // variables for market input and report
        string farmName, itemType;
        int itemCount = 0;
        float itemPrice = 0.00;
        float totalPrice = 0.00;
        int grandItemCount = 0;
        float grandTotal = 0.00;


        dataOutput << setw(75) << setfill('=') << '\n'
                   << "=" << "                    Farmer's Market Inventory                   =" << endl
                   << setw(75) << setfill('=') << '\n'
                   << setw(75) << setfill(' ') << '\n';
         while (getline(dataInput, farmName, ','))
        {
            if (is.eof())
            {
                break;
            }
            else
            {
                // streams inputs to designated variables
                dataInput >> itemCount >> itemType >> itemPrice;

                // calculates total price per farm
                totalPrice = itemCount * itemPrice;
                // calculates total item count
                grandItemCount = grandItemCount + itemCount;
                // calculates grand total
                grandTotal = totalPrice + grandTotal;

                dataOutput.setf(ios::fixed);
                dataOutput.setf(ios::showpoint);
                dataOutput.setf(ios::left);
                dataOutput.precision(2);
                dataOutput << setw(25) << farmName << ":" << itemCount << " "
                       << itemType << " @ " << itemPrice << " each, totaling $" << totalPrice << '\n';

                dataInput.ignore();
            }

        }
        dataInput.close();
        dataOutput << setw(25) << "Total Item Count: " << grandItemCount
                   << "  Grand Total: $" << grandTotal;
       dataOutput.close();
}
