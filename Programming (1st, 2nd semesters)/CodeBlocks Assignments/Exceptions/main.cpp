#include <iostream>
#include <fstream>
#include <exception>


void displayFile();
int main()
{
    try
    {
        displayFile();
    }
    catch(char* msg)
    {
        std::cout << msg;
    }
    return 0;
}

/* displayLab
   precondition: receives nothing
   postcondition: returns nothing
                  reads in and outputs log file to console
   */
void displayFile()
{
    // for reading file
    std::ifstream inFile("myFile.txt");

    // simply returns to main menu if file unavailable
    if(!inFile.is_open())
    {
        throw "file could not be opened\n";
    }

    // if the file exists, is outputted to console
    std::cout << "LOG FILE\n";
    std::string line;
    while(!inFile.eof())
    {
        if(inFile.eof())
            return;
        std::getline(inFile, line);
        std::cout << line << '\n';
    }
    std::cout << '\n';
    return;
}
