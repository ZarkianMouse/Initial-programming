/* Voter Fraud Detection System
   Copyright of Naomi Burhoe c. 2017
   Purpose: to analyze voting poll records
   to determine election outcomes
   and to prevent voter fraud by forcing
   voters to search the directory for
   their unique ID code
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <string>
#include <vector>
#include "Voter_class.hpp"

using std::cout;
using std::cin;
using std::ifstream;
using std::endl;
using std::string;
using std::vector;
using std::ios;


// necessary function declarations
bool openFile(ifstream &); // checks for file open failure
vector<Voter> fillVector(ifstream &); // fills vector slots from file
void countVotes(int [], int, vector<Voter>); // counts votes from election
void printResults(int [], int); // prints results of election
void printPercent(int, int); // prints percent of votes each component won
void printChoice(char); // prints necessary names/words

int main()
{
    cout << "Welcome to the Voter Fraud Detection Center\n";

    // checks for file open failure
    ifstream inputFile;
    inputFile.open("list.txt");
    bool isOpen = openFile(inputFile);
    if (isOpen == false)
    {
        cout << "File failed to open\n";
        return 0;
    }

    // necessary variables
    vector<Voter> votesVector;
    int totalVoters, myVoteID;
    int countArr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    votesVector = fillVector(inputFile);
    inputFile.close();

    // calculates and outputs total number of voters
    totalVoters = (votesVector.size() - 1);
    cout << "Total Voters = " << totalVoters << endl;

    // calls function that counts and outputs results of election
    countVotes(countArr, totalVoters, votesVector);



    // separate function may be helpful
    // search for user
    cout << "\n\nEnter voter ID to search for: ";
    cin >> myVoteID;
    int countVotes = 0;
    for (int i = 0; i < totalVoters; i++)
    {
        if (myVoteID == votesVector[i].getID())
        {
            cout << "ID found! \n"
                 << "Our records indicate that Voter " << myVoteID
                 << " voted: \n";
            printChoice(votesVector[i].getMayorVote());
            cout << "for Mayor\n";

            printChoice(votesVector[i].getPropVote());
            cout << "on Proposition 17\n";

            printChoice(votesVector[i].getMeas1Vote());
            cout << "on Measure 1\n";

            printChoice(votesVector[i].getMeas2Vote());
            cout << "on Measure 2\n";
        }
        else
            ++countVotes;
    }

    if (countVotes == totalVoters)
        cout << "Sorry, voter " << myVoteID << " could not be found in our records\n";




    return 0;
}

/*    Class Functions    */
/* Constructors */
// sets default values for voterID and votes
Voter::Voter() : voterID(0), votes("")
{
}

// sets values for voterID and votes based on input from driver program
Voter::Voter(int newID, string newVotes) : voterID(newID), votes(newVotes)
{
}

// Voter::getID()
// precondition: receives nothing
// postcondition: returns voterID variable
int Voter::getID()
{
    return voterID;
}

// Voter::getMayorVote()
// precondition: receives nothing
// postcondition: returns char representing mayor vote
char Voter::getMayorVote()
{
    return votes[0];
}

// Voter::getPropVote()
// precondition: receives nothing
// postcondition: returns char representing proposition 17 vote
char Voter::getPropVote()
{
    return votes[1];
}

// Voter::getMeas1Vote()
// precondition: receives nothing
// postcondition: returns char representing measure 1 vote
char Voter::getMeas1Vote()
{
    return votes[2];
}

// Voter::getMeas2Vote()
// precondition: receives nothing
// postcondition: returns char representing measure 2 vote
char Voter::getMeas2Vote()
{
    return votes[3];
}


/* Program Functions */
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

// fillVector() is used to fill up a vector with input
// from a file that holds IDs and ballot choices from
// a recent election
// precondition: receives a file by reference
// postcondition: returns a vector of the Voter class
vector<Voter> fillVector(ifstream &inputFile)
{
    vector<Voter> voterVector;
    int voteID;
    string voteStr;
    while (!inputFile.eof())
    {
        if (inputFile.eof())
            break;
        else
        {
            inputFile >> voteID >> voteStr;
            Voter myVoter(voteID, voteStr);
            voterVector.push_back(myVoter);
        }
    }
    return voterVector;
}

// countVotes() is used to count up the votes from the election
// precondition: receives an array for storing vote totals
//               receives the total number of voters
//               receives the vector storing voter information
// postcondition: returns nothing
void countVotes(int countArr[], int totalVoters, vector<Voter> votesVector)
{
    for (int i = 0; i < totalVoters; i++)
    {
        Voter myVoter = votesVector[i];
        char mayor = myVoter.getMayorVote();
        switch(mayor)
        {
            case 'A' : ++countArr[0];
                       break;
            case 'B' : ++countArr[1];
                       break;
            case 'C' : ++countArr[2];
                       break;
            default : cout << "Count Error\n";
        }

        char prop17 = myVoter.getPropVote();
        switch(prop17)
        {
            case 'D' : ++countArr[3];
                       break;
            case 'E' : ++countArr[4];
                       break;
            default : cout << "Count Error\n";
        }

        char meas1 = myVoter.getMeas1Vote();
        switch(meas1)
        {
            case 'F' : ++countArr[5];
                       break;
            case 'G' : ++countArr[6];
                       break;
            default : cout << "Count Error\n";
        }

        char meas2 = myVoter.getMeas2Vote();
        switch(meas2)
        {
            case 'H' : ++countArr[7];
                       break;
            case 'I' : ++countArr[8];
                       break;
            default : cout << "Count Error\n";
        }
    }

    // outputs results of the election to standard
    printResults(countArr, totalVoters);

    return;
}

// printResults() is used to output data from the
// election to standard
// precondition: receives an array which holds
//               vote counts
//               also receives an integer
//               representing the total number
//               of voters in the election
// postcondition: returns nothing
void printResults(int countArr[], int totalVoters)
{
    cout << "Poll Results\n"
    // prints percentages for mayor votes
         << "1. Mayor"
         << "\n   A. Pincher, Penny ";
    printPercent(countArr[0], totalVoters);
    cout << "\n   B. Dover, Skip ";
    printPercent(countArr[1], totalVoters);
    cout << "\n   C. Perman, Sue ";
    printPercent(countArr[2], totalVoters);

    // prints percentages for proposition 17 votes
    cout << "\n2. Proposition 17"
         << "\n   D. Yes ";
    printPercent(countArr[3], totalVoters);
    cout << "\n   E. No ";
    printPercent(countArr[4], totalVoters);

    // prints percentages for measure 1 votes
    cout << "\n3. Measure 1"
         << "\n   F. Yes ";
    printPercent(countArr[5], totalVoters);
    cout << "\n   G. No ";
    printPercent(countArr[6], totalVoters);

    // prints percentages for measure 2 votes
    cout << "\n4. Measure 2"
         << "\n   H. Yes ";
    printPercent(countArr[7], totalVoters);

    cout << "\n   I. No ";
    printPercent(countArr[8], totalVoters);
}

// printPercent() is used to calculate and output
// vote percentages to standard
// precondition: receives the count number for a ballot
//               choice
//               also receives the total number of voters
// postcondition: returns nothing
void printPercent(int num, int total)
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << (static_cast<double>(num * 100)/total) << "%";
}

// printChoice() is used to convert and output ballot
// choices to standard
// precondition: receives a character for the specific
//               ballot choice
// postcondition: returns nothing
void printChoice(char choice)
{
    switch(choice)
    {
        case 'A' : cout << "Penny Pincher ";
                   break;
        case 'B' : cout << "Skip Dover ";
                   break;
        case 'C' : cout << "Sue Perman ";
                   break;
        case 'D' : cout << "Yes ";
                   break;
        case 'E' : cout << "No ";
                   break;
        case 'F' : cout << "Yes ";
                   break;
        case 'G' : cout << "No ";
                   break;
        case 'H' : cout << "Yes ";
                   break;
        case 'I' : cout << "No ";
                   break;
    }
}

