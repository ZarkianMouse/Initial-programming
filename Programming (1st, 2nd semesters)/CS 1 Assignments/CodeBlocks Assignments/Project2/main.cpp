/* The Hospital Election
  Copyright of Naomi Burhoe c. 2016
  Purpose: to analyze ballots from a hospital election for:
           a. cheat votes
           b. the winner of the presidential race
           c. if amendments to the hospital charter passed
Presidential Candidates:
1. The Original President
2. The New Guy (a very creative title)

Amendments:
1.	What does the fox say? Whatever WE tell it to.
2.	From now on the annual Cinco de Mayo party will be held on March 8.
3.	Beginning this year, patients shall have a week dedicated to us.
4.	Doctors are now allowed to talk about fight club.
5.	When in our hospital, patients must clean up after themselves.
6.	Our paychecks will immediately include royalties from the parking funds.
7.	From now on the President will take our birthdays off.
8.	If we say something costs an arm and a leg, it does.
9.	New staff members are ordered to learn OUR secret handshake.
10.	If a patient needs help and no one is around, the new President will handle them.

(Be sure to check out end for commentary on amendments)
*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <limits>
#include <string>

using std::cout;
using std::cin;
using std::ios;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::numeric_limits;
using std::streamsize;

// controls size of arrays used in program
const int ROWS = 100;
const int COLUMNS = 10;

/* functions that govern various processes in program */
bool fileOpen(ifstream&);
void origFill(int [], char [][COLUMNS], string [], string []);
void fillArrays(ifstream&, ofstream&, int [], char [][COLUMNS], string []);
void outputBallots(ofstream&, int [], char [][COLUMNS], string []);
string newPresident (string [], int&, int&);
void presOutput(ofstream&,string&, int&, int&);
void yesNoAmend(char [][COLUMNS], int [], int [], string []);
void amendOutput(ofstream&, int [], int [], string [], string []);

int main()
{
    // stream variables for election
    ifstream origBallots("BallotsHospital.txt");
    ofstream goodBallots("counted.txt");
    ofstream electResult("election_results.txt");

    // parallel arrays to store ballots
    int voteID[ROWS];
    char amendments[ROWS][COLUMNS];
    string voteName[ROWS];
    string amendCall[COLUMNS];

    // calls function that initializes arrays to default/blank values
    origFill(voteID, amendments, voteName, amendCall);

    // calls function that determines if a file open failure occurred
    bool doesFileExist = fileOpen(origBallots);
    if (doesFileExist)
    {
        /* section for inputting ballots from file and outputting
                       good ballots to counted file               */
        fillArrays(origBallots, electResult, voteID, amendments, voteName);
        origBallots.close();

        outputBallots(goodBallots, voteID, amendments, voteName);
        goodBallots.close();
    }
    // if file fails to open, program ends
    else
    {
        return 0;
    }

    /* section for analysis of presidential candidate votes */
    // variables to log votes each candidate received
    int presVote = 0, newGuy = 0;

    // function call to determine new president
    string president = newPresident(voteName, presVote, newGuy);
    presOutput(electResult, president, presVote, newGuy);


    /* section for analysis of amendment votes */
    // arrays used to determine if amendments pass/fail
    int yesVote[COLUMNS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int noVote[COLUMNS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    string decision[COLUMNS];

    // function calls for analysis/output of amendments array
    yesNoAmend(amendments, yesVote, noVote, decision);
    amendOutput(electResult, yesVote, noVote, decision, amendCall);


    electResult.close();
    return 0;
}


/* ***********************************************************************************
                            Function to Test for File Open Failure
   *********************************************************************************** */
// fileOpen is used to determine if the input file opens
// precondition: is passed input file
// postcondition: returns true if file opened
//                returns false if not
bool fileOpen(ifstream& inputFile)
{
    if (!inputFile)
    {
        cout << "File open failure.\n";
        return false;
    }
    else
        return true;
}


/* ***********************************************************************************
                            Function to Set Default Array Values
   *********************************************************************************** */
// origFill is used to initialize the arrays before ballot analysis
// is completed
// precondition: is passed arrays for vote ID, amendment vote and name,
//               and candidate vote
// postcondition: updates default array values to ones that won't affect
//                outcome of ballot analysis
void origFill(int initID[], char initVote[][COLUMNS], string blankVote[], string amendCall[])
{
    for (int i = 0; i < ROWS; i++)
    {
        initID[i] = -1;
        for (int j = 0; j < COLUMNS; j++)
        {
            initVote[i][j] = 'B'; // 'B' stands for blank
        }
        blankVote[i] = ("No candidate name entered");
    }

    // fills in the amendments which are up for vote on the ballot
    amendCall[0] = ("What does the fox say? Whatever WE tell it to.");
    amendCall[1] = ("From now on the annual Cinco de Mayo party will be held on March 8.");
    amendCall[2] = ("Beginning this year, patients shall have a week dedicated to us.");
    amendCall[3] = ("Doctors are now allowed to talk about fight club.");
    amendCall[4] = ("When in our hospital, patients must clean up after themselves.");
    amendCall[5] = ("Our paychecks will immediately include royalties from the parking funds.");
    amendCall[6] = ("From now on the President will take our birthdays off.");
    amendCall[7] = ("If we say something costs an arm and a leg, it does.");
    amendCall[8] = ("New staff members are ordered to learn OUR secret handshake.");
    amendCall[9] = ("If a patient needs help and no one is around, the new President will handle them.");
}


/* ****************************************************************************************
                        Functions to Analyze Input Data for Cheat Votes
   **************************************************************************************** */
// fillArrays is used to update the information in the ballot arrays
// precondition: is passed input file and election results file
//               is passed voter ID, amendment, and pres name arrays
// postcondition: fills the arrays used for election ballot storage
//                updates number of good ballots read
//                outputs results of first test to std and file

void fillArrays(ifstream& input, ofstream& results, int voteID[], char amend[][COLUMNS], string presVote[])
{
    // variables for cheat vote test
    int goodVote = 0, badVote = 0;
    int holdID = 0;

    // loop is used to input file into parallel arrays
    int i = 0;
    while(!(input >> voteID[i]).eof())
    {
        if (holdID != voteID[i])
        {
            holdID = voteID[i];

            // loop to govern input into columns of
            // multidimensional array for amendment vote
            for (int j = 0; j < COLUMNS; j++)
            {
                input >> amend[i][j];
            }
            getline(input, presVote[i]);
            goodVote++;
            i++;
        }
        else
        {
            badVote++;
            input.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    }

    // output results of test for cheat votes
    int totalBallots = goodVote + badVote;
    cout << "Election Result Data" << endl
         << "Total ballots: " << totalBallots << endl
         << "Staff members that voted: " << goodVote << endl;
    results << "Election Result Data" << endl
            << "Total ballots: " << totalBallots << endl
            << "Staff members that voted: " << goodVote << endl;
}

// outputBallots is used to output the non-cheat ballots to the
// 'counted.txt' file
// precondition: is passed output file variable
//               is passed variables for vote ID, amendments
//               and candidate vote
// postcondition: outputs non-cheat ballots to file
void outputBallots(ofstream& ballots, int voteID[], char amend[][COLUMNS], string presVote[])
{
    for (int i = 0; i < ROWS; i++)
    {
        // checks to see if voteID[i] is a default value for array (-1)
        if (voteID[i] == -1)
        {
            return;
        }

        // if not, outputs value of voteID[i], amend[i], and presVote[i] to ballots file
        ballots << voteID[i];
        for (int j = 0; j < COLUMNS; j++)
        {
            ballots << amend[i][j];
        }
        ballots << presVote[i] << endl;
    }
}


/* ***********************************************************************************
                        Functions to Determine New President
   ********************************************************************************** */
// newPresident is used to determine who wins the hospital presidential election
// precondition: function is passed array for ballot choices for president
//                        is passed by reference number of votes for each candidate
// postcondition: function updates number of votes each candidate received
//                         returns who won the election (the New Guy or the President)
string newPresident(string candidateName[], int& presVote, int& newGuy)
{
    // adds up number of votes each candidate received
    string name;
    for (int i = 0; i < ROWS; i++)
    {
        name = candidateName[i];
        if (name == "The President")
            presVote++;
        else if (name == "The New Guy")
            newGuy++;
    }

    // determines winner of election
    if (presVote > newGuy)
        return ("The new president remains the same as the old");
    else if (newGuy > presVote)
        return ("The new president is 'The New Guy'");
    else
        return ("A follow-up election is necessary to break the stalemate");
}

void presOutput(ofstream& results, string& decision, int& presVote, int& newGuy)
{
    cout << decision << endl
         << "The President (" << presVote << " votes), "
         << "The New Guy (" << newGuy << " votes)" << endl;
    results << decision << endl
         << "The President (" << presVote << " votes), "
         << "The New Guy (" << newGuy << " votes)" << endl;
    return;
}


/* ***********************************************************************************
                    Functions to Determine if Amendments Pass or Fail
   *********************************************************************************** */
// yesNoAmend is used to determine whether an amendment will pass or fail
// precondition: is passed the amendment array in question
//               is passed the initial number of yes votes by reference
//               is passed the initial number of no votes by reference
// postcondition: will return string "passes" if yes votes reaches a majority
//                of 2/3 over no votes, or will return string "fails" if not
void yesNoAmend(char amend[][COLUMNS], int yesVotes[], int noVotes[], string decision[])
{
    // calculating number of yes and no votes
    for(int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            char YN = amend[i][j];
            if (YN == 'Y')
                ++yesVotes[j];
            else if (YN == 'N')
                ++noVotes[j];
        }
    }

    // determines if amendments passed or not
    for (int i = 0; i < COLUMNS; i++)
    {
        int yes = yesVotes[i];
        int no = noVotes[i];
        if (yes > no)
        {
            float majority = 2 * no;
            if (yes > majority)
                decision[i] = "passes";
            else
                decision[i] = "fails";
        }
        else
            decision[i] = "fails";
   }

   return;
}

// amendOutput is mainly used to output results of analysis of ballots for
// amendment passage
// precondition: is passed output file
//               is passed arrays for yes/no votes, overall decision
//               and what the amendments up for debate are
// postcondition: outputs the results to std and to output file
//                includes what the updates to hospital charter are
void amendOutput(ofstream& results, int yesVote[], int noVote[], string decision[], string call[])
{
    for(int i = 0; i < COLUMNS; i++)
    {
        cout << "Amendment " << (i + 1) << " " << decision[i]
             << " with " << yesVote[i] << " yes votes, and "
             << noVote[i] << " no votes" << endl;
        results << "Amendment " << (i + 1) << " " << decision[i]
             << " with " << yesVote[i] << " yes votes, and "
             << noVote[i] << " no votes" << endl;
    }

    // because i wanted to make sure that the program included
    // what the updates to the hospital charter were
    cout << "\nNew hospital rules include: \n";
    results << "Now hospital rules include: \n";
    for (int i = 0; i < COLUMNS; i++)
    {
        if (decision[i] == "passes")
        {
            cout << call[i] << endl;
            results << call[i] << endl;
        }
    }
    return;
}



/* ***********************************************************************************
                            Bonus Section (Because I was bored)
   *********************************************************************************** */
/* Amendments:
1.	What does the fox say? Whatever WE tell it to.
    This one is pretty good actually (or at least funny)

2.	From now on the annual Cinco de Mayo party will be held on March 8.
    Of course, Cinco de Mayo means "5th of May," but hey, that's fine

3.	Beginning this year, patients shall have a week dedicated to us.
    But what would you call it, "Health Care Worker Appreciation Week"?
    Don't they have one of those already?

4.	Doctors are now allowed to talk about fight club.
    Wat kind of fights do they get into that they were outlawed from talking
    about fight club?

5.	When in our hospital, patients must clean up after themselves.
    Looks like the most incapacitated patients will be lying in their
    own filth for days on end now.

6.	Our paychecks will immediately include royalties from the parking funds.
    That actually would be an interesting way to do things for a hospital.

7.	From now on the President will take our birthdays off.
    Like, he gets off for every single birthday?
    Or do the hospital workers get to request off for their
    birthdays (not have to come into work)?

8.	If we say something costs an arm and a leg, it does.
    I guess that means that you better start collecting on that
    bill.

9.	New staff members are ordered to learn OUR secret handshake.
    That would be awesome.

10.	If a patient needs help and no one is around, the new President will handle them.
    What if he's not around?  Does that mean that no one does that?

This hospital won't be around much longer.
*/
