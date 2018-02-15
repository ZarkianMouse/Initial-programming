/* Part of Map Reading: As told from a movie-review perspective
   By Naomi Burhoe c. 2017
   Purpose: holds function definitions
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <map>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::map;
using std::string;

// openFile() is used to check for invalid file input
// precondition: receives a file by reference
// postcondition: returns false is file cannot be opened
//                returns true otherwise
bool openFile(ifstream &dataInput)
{
    if (!dataInput)
    {
        return false;
    }
    else
        return true;
}

// allocateMaps() is used to read lines from a file into
// two related maps
// precondition: receives a file by reference, map with string key
// and int data (for # of reviews), and map with string key and double
// data (for average rating)
// postcondition: returns nothing
void allocateMaps(ifstream &input, map<string, int> &map1, map<string, double> &map2)
{
    // variables for allocation
    string title; // for movie title
    double rating; // for individual ratings

    // reads until end of file is reached
    while(!input.eof())
    {
        // ends reading
        if (input.eof())
            break;

        // receives lines of type "# Movie Title"
        getline(input, title);
        if (isdigit(title[0]))
        {
            char* c = &title[0];
            rating = atoi(c);
            title = title.substr(2, title.size() - 1);
        }

        // defines iterators to look for data stored with key of title
        map<string, int>::iterator it1 = map1.find(title);
        map<string, double>::iterator it2 = map2.find(title);

        // if data is found, the values are updated accordingly
        if (it1 != map1.end() && it2 != map2.end())
        {
            it1->second = ++it1->second; // to add another review
            it2->second = (it2->second + rating) / 2; // to average in new rating

        }
        // if not, a new pair is added to the map
        else
        {
            map1.insert(std::pair<string, int>(title, 1)); // to indicate a review of a new movie
            map2.insert(std::pair<string, double>(title, rating)); // to indicate average rating
        }
    }
    return;
}

// printMaps() is used to print out data from two maps
// precondition: receives maps to be printed
// postcondition: returns nothing
void printMaps(map<string, int> &map1, map<string, double> &map2)
{
    for (const auto & p : map1)
    {
        // iterator to find element in second map that corresponds
        // to the key of the first map
        map<string, double>::iterator it2 = map2.find(p.first);

        // accounts for the bug where the first map pair points
        // to the line with the total number of reviews
        if (p.first != "")
        {
            cout << p.first << ": " << p.second << " reviews, "
             << it2->second << " / 5\n";
        }
    }
}
