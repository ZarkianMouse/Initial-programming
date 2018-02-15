#ifndef CHECKOPEN_HPP_INCLUDED
#define CHECKOPEN_HPP_INCLUDED

// checkOpen is used to determine if input file
// could be successfully opened in program
// precondition: is passed input file by reference
// postcondition: returns false if input file failure
//                returns true otherwise
bool checkOpen(std::ifstream& inputFile)
{
    if(!inputFile)
    {
        std::cerr << "File Open Failure\n";
        return false;
    }
    else
    {
        std::cout << "Successful Open!\n";
        return true;
    }
}

#endif // CHECKOPEN_HPP_INCLUDED
