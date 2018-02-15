#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>


using std::cout;
using std::cin;
using std::endl;
using std::string;

/* *******************************************
         Constant Variables for Board
   ******************************************* */
// denotes size of multi-dimensional board array
const int ROWS = 8;
const int COLUMNS = 7;

// denotes type variables for cards
const string HEARTS(" of Hearts  ");
const string DIAMONDS(" of Diamonds ");
const string SPADES(" of Spades  ");
const string CLUBS(" of Clubs  ");

// denotes card types
const string ACE("A");
const string KING("K");
const string QUEEN("Q");
const string JACK("J");
const string JOKER(" Joker  ");
const string TWO("2");
const string THREE("3");
const string FOUR("4");
const string FIVE("5");
const string SIX("6");
const string SEVEN("7");
const string EIGHT("8");
const string NINE("9");
const string TEN("10");

void fillArray(string [][COLUMNS]);
string chooseSuite(int, int &, int &, int &, int &);
string chooseCard(int);
bool isNewCard(string [][COLUMNS], string);
void displayArray(string [][COLUMNS]);

int main()
{
    srand(time(0));
    string board[ROWS][COLUMNS];

    // the problem array
    fillArray(board);


    displayArray(board);
    return 0;
}

void fillArray(string arr[][COLUMNS])
{
    // designed to fix problems with rand (changes it every time)
    int fixRand = 1;
    int fixRand2 = 1;

    // designed to fix problems with one suite filling up and preventing
    // continuance of program
    int clubCount = 0;
    int heartCount = 0;
    int spadeCount = 0;
    int diamondCount = 0;

    // determines suite and card number for cards
    int suite = 0;
    int card = 0;
    string newCard;
    bool isANewCard = false;

    for (unsigned int i = 0; i < ROWS; i++)
    {
        for (unsigned int j = 0; j < COLUMNS; j++)
        {
            while (isANewCard == false)
            {

                card = (rand() * fixRand) % 13 + (j + 1);
                suite = (rand() * fixRand * fixRand) % 4 + (j + 1);

                if (chooseCard(card) == JOKER)
                    newCard = JOKER;
                else
                    newCard = chooseCard(card) + chooseSuite(suite, heartCount, spadeCount, clubCount, diamondCount);

                isANewCard = isNewCard(arr, newCard);

                if (isANewCard == true)
                    arr[i][j] = newCard;
                else if (spadeCount == 13 || clubCount == 13)
                {
                    fixRand = 2 * fixRand2 * fixRand - 3 * fixRand + 2;
                    fixRand2 = 3 * fixRand2 * fixRand * fixRand2 * fixRand;
                }
                else if (heartCount == 13 || diamondCount == 13)
                {
                    fixRand = 19 * fixRand2 * fixRand - 13 * fixRand + 3;
                    fixRand2 = 23 * fixRand * fixRand * fixRand2 * fixRand;
                }
                else
                {
                    fixRand = 13 * fixRand2 * fixRand2 * fixRand - 15 * fixRand;
                    fixRand2 = 17 * fixRand;
                }

            }
            isANewCard = false;
            cout << " arr[i][j] = " << arr[i][j] << endl
                 << "i = "  << i << endl
                 << "j = " << j << endl;
        }
        cout << endl;
    }
    return;
}

string chooseSuite(int suite, int &heartC, int &spadeC, int &clubC, int &diamondC)
{
    if (suite == 1)
    {
        heartC++;
        return HEARTS;
    }

    else if (suite == 2)
    {
        diamondC++;
        return DIAMONDS;
    }

    else if (suite == 3)
    {
        spadeC++;
        return SPADES;
    }

    else if (suite == 4)
    {
        clubC++;
        return CLUBS;
    }

}

string chooseCard(int card)
{
    switch(card)
    {
    case 1 :
        return ACE;
    case 2 :
        return TWO;
    case 3 :
        return THREE;
    case 4 :
        return FOUR;
    case 5 :
        return FIVE;
    case 6 :
        return SIX;
    case 7 :
        return SEVEN;
    case 8 :
        return EIGHT;
    case 9 :
        return NINE;
    case 10 :
        return TEN;
    case 11 :
        return JACK;
    case 12 :
        return QUEEN;
    case 13 :
        return KING;
    default :
        return JOKER;
    }
}

bool isNewCard (string arr[][COLUMNS], string newCard)
{
    for (unsigned int i = 0; i < ROWS; i++)
    {
        for (unsigned int j = 0; j < COLUMNS; j++)
        {
            if (newCard == arr[i][j])
                return false;
        }
    }
    return true;
}

void displayArray (string arr[][COLUMNS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << "\n";
    }
    return;
}
