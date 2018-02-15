/* Part of Map Reading: As told from a movie-review perspective
   By Naomi Burhoe c. 2017
   Purpose: holds function declarations
*/

#ifndef MAPFUNCTIONS_HPP_INCLUDED
#define MAPFUNCTIONS_HPP_INCLUDED

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <map>
#include <string>

using std::ifstream;
using std::map;
using std::string;

bool openFile(ifstream &);
void allocateMaps(ifstream &, map<string, int> &, map<string, double> &);
void printMaps(map<string, int> &, map<string, double> &);


#endif // MAPFUNCTIONS_HPP_INCLUDED
