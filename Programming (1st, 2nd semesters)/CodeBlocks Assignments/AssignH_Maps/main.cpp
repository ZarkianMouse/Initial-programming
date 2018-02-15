/* Map Reading: As told from a movie-review perspective
   Copyright of Naomi Burhoe c. 2017
   Purpose: to organize and output data gleaned from a
   file in order to analyze movie review records
   Note: Driver Program
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <map>
#include <string>
#include "MapFunctions.hpp"

using std::cout;
using std::endl;
using std::ifstream;
using std::map;
using std::string;

int main()
{
    // instantiates new file input variable
    ifstream input;
    // opens files
    input.open("file.txt");
    // checks if file truly opened
    bool isFileOpen = openFile(input);
    // if not, ends program
    if (isFileOpen == false)
    {
        cout << "File failed to open\n";
        return 0;
    }

    // reads in total number of reviews in file
    int totalReviews;
    input >> totalReviews;

    // instantiates maps to hold necessary data
    map<string, int> map1; // for number of reviews
    map<string, double> map2; // for average rating
    allocateMaps(input, map1, map2);

    // prints out data to standard
    cout << "Total Reviews: " << totalReviews << endl;
    printMaps(map1, map2);

    return 0;
}


