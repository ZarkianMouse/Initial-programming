#ifndef MYCONSTANTS_H_INCLUDED
#define MYCONSTANTS_H_INCLUDED

namespace
{
    //Constants of Program
    //number of labs
    extern const int NUMLABS = 8;
    //number of computers in each lab
    extern const int LABSIZES[NUMLABS] = {19, 15, 24, 33, 61, 17, 55, 37};
    //names of university for each lab
    extern const std::string UNIVERSITYNAMES[NUMLABS] = {"The University of Michigan", "The University of Pittsburgh", "Stanford University",
    "Indiana State University", "North Texas State University", "The University of Alabama", "Princeton University", "Duquesne University"};
}

#endif // MYCONSTANTS_H_INCLUDED
