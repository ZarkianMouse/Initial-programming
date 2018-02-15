#include "Voter_class.hpp"
#include <string>
#include <iostream>

using std::string;
/* Class Functions */
Voter::Voter() : voterID(0), votes("")
{
}

Voter::Voter(int newID, string newVotes) : voterID(newID), votes(newVotes)
{
}

int Voter::getID()
{
    return voterID;
}

char Voter::getMayorVote()
{
    return votes[0];
}

char Voter::getPropVote()
{
    return votes[1];
}

char Voter::getMeas1Vote()
{
    return votes[2];
}
char Voter::getMeas2Vote()
{
    return votes[3];
}
