/* Sportmania Dodgeball Duel
Copyright of Naomi Burhoe c. 2016
Purpose: to simulate a tournament
between three people in order to see
who is the last man standing
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;
using std::cin;
using std::string;

// constants for tournament
const float AARONACCURACY = 1/3.0;
const float BOBACCURRACY = 0.5;
const float CHARLIEACCURACY = 1.0;
const int NUMDUELS = 1000;

int startDuel();
void shoot(bool& targetAlive, float accuracy);

int main()
{
    srand((unsigned int)time(0));
   // for (int i = 0; i < 10; i++)
   // {
    //    bool targetAlive = true;
    //    shoot(targetAlive, 0.5);
    //    cout << targetAlive << endl;
    //}

    int aaronWins = 0, bobWins = 0, charlieWins = 0;
    for (int i = 1; i <= NUMDUELS; i++)
    {
        int winner = startDuel();
        switch (winner)
        {
            case 1 :
                aaronWins++;
                break;
            case 2 :
                bobWins++;
                break;
            case 3 :
                charlieWins++;
                break;
        }
    }

    cout << "Using the strategy of shooting at the best shooter alive: " << endl
         << "Aaron win %: " << (static_cast<double>(aaronWins) / NUMDUELS) << endl
         << "Bob win %: " << (static_cast<double>(bobWins) / NUMDUELS) << endl
         << "Charlie win %: " << (static_cast<double>(charlieWins) / NUMDUELS) << endl;
}

void shoot(bool& targetAlive, float accuracy)
{
    float numRan = (rand() % 1000) / 1000.0;
    if (numRan < accuracy)
    {
        targetAlive = false;
    }
}

// start duel sets in motion the tournament between Aaron, Bob, and Charlie
// postcondition: returns '1' if Aaron wins
//                returns '2' if Bob wins
//                returns '3' if Charlie wins
int startDuel()
{
    bool aaron = true, bob = true, charlie = true;

    while ((aaron && bob) || (aaron && charlie) || (bob && charlie))
    {
        // Aaron begins
        if (aaron)
        {
            if (charlie)
                shoot(charlie, AARONACCURACY);
            else if (bob)
                shoot (bob, AARONACCURACY);
        }

        // Then, Bob goes
        if (bob)
        {
            if (charlie)
                shoot(charlie, BOBACCURRACY);
            else if (aaron)
                shoot(aaron, BOBACCURRACY);
        }

        //Then Charlie goes
        if (charlie)
        {
            if (bob)
                shoot(bob, CHARLIEACCURACY);
            else if (aaron)
                shoot (aaron, CHARLIEACCURACY);
        }
    }
    if (aaron)
        return 1;
    else if (bob)
        return 2;
    else
        return 3;
}
