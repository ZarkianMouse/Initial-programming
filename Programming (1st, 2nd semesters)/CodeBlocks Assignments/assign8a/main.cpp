/* Pig Latin Program
   Copyright of Naomi Burhoe c. 2016
   Purpose: to read text from a file and convert it to
   a form of Pig Latin */

#include <iostream>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <fstream>
#include "checkOpen.hpp"
#include "readPhrase.hpp"
#include "translatePhrase.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;


bool checkOpen(ifstream&);
// checkOpen is used to determine if input file
// could be successfully opened in program


void readPhrase(ifstream&, string&);
// readPhrase function reads lines of text from
// input file to phrase string


void translatePhrase(string, string&);
// translatePhrase is used to update new phrase to its
// Pig Latin counterpart

int main()
{
    ifstream inputFile("ASSGN8-A.txt");

    // used to see if file opens
    bool checkFile = checkOpen(inputFile);
    if (checkFile == false) // if failure, program ends
    {
        inputFile.close();
        return 0;
    }

    // used for phrase translation
    string origPhrase;
    string pigPhrase;

    // loop runs while file still contains values to be read
    while(!inputFile.eof())
    {
        // if end of file reached, loop is exited and program ends
        if (inputFile.eof())
        {
            cout << "End of File reached\n";
            break;
        }

        // function call for reading input from file
        readPhrase(inputFile, origPhrase);

        // calls function that translates phrase to Pig latin
        translatePhrase(origPhrase, pigPhrase);
        cout << "Pig Latin: " << pigPhrase << endl << endl;

        // mainly use this to prevent overlapping phrases
        pigPhrase.clear();
    }
    inputFile.close();
    return 0;
}



