#ifndef VOTER_CLASS_HPP_INCLUDED
#define VOTER_CLASS_HPP_INCLUDED
#include <string>

using std::string;
class Voter
{
    private:
        int voterID;
        string votes;
    public:
        Voter();
        Voter(int newID, string newVotes);
        /*void newVotes(); */
        int getID();
        char getMayorVote();
        char getPropVote();
        char getMeas1Vote();
        char getMeas2Vote();

};


#endif // VOTER_CLASS_HPP_INCLUDED
