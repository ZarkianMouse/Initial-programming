/* Rock, Paper, Scissors, Lizard, Spock
Program Copyright of Naomi Burhoe c. 2016
Purpose:
user faces computer in updated version of Rock, Paper, Scissors

Level 1:
a. getComputerChoice
b. getUserChoice
c. determineWinner
d. displayChoice
*/

#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;
using std::cin;
using std::string;

// constants for game
const int ROCK = 1;
const int PAPER = 2;
const int SCISSORS = 3;
const int LIZARD = 4;
const int SPOCK = 5;
const int QUIT = 6;

// functional prototypes for program
int getComputerChoice();
int getUserChoice();
bool validateInput(int, int, int, string);
int determineWinner(int, int);
int displayChoice(int, int);

int main()
{
    cout << "Welcome to Rocks, Paper, Scissors, Lizard, Spock\n\n";

    // gamePlay determines if while loop continues to run
    bool gamePlay = true;
    while (gamePlay)
    {
        // local variables for user and computer choices in game
        int choice1 = getUserChoice();
        int choice2 = getComputerChoice();

        // checks to see if user chose to quit out of game before game play commences
        if (choice1 == QUIT)
        {
            gamePlay = false;
        }

        cout << displayChoice(choice2, choice1);
    }
}

// function getComputerChoice is used to
// figure out what the computer's choice for RoPaSLiSp
// would be
int getComputerChoice()
{
    // variables to control computer choice, validation loop, and invalid message
    int choice;
    bool loopFlag = true;
    string msg("The computer is still deciding");
	do
	{
		choice = (rand() % 5) + 1;
		loopFlag = validateInput(choice, 1, 5, msg);
	} while (loopFlag);
	return choice;
}

// function that displays user choice for game
// displays a menu and user inputs a number from keyboard
int getUserChoice()
{
  int choice;		                                   // User's game choice
  bool loopFlag = true;                             // control for validation
  string msg("The valid choices are 1 through 6."); // invalid message
	cout << "To play Rock, Paper, Scissors, Lizard, Spock\n\n";
	cout << "1. Rock\n";
	cout << "2. Paper\n";
	cout << "3. Scissors\n";
	cout << "4. Lizard\n";
	cout << "5. Spock\n";
	cout << "6. Quit\n\n";

	// loop used to validate user input before game play commences
	// kind of like making sure someone doesn't use God mode to win the game :)
	do
	{
		cout << "Enter your choice (1-6): ";
		cin >> choice;
		loopFlag = validateInput(choice, 1, 6, msg);
	} while (loopFlag);
	return choice;
}

// this function is used to determine if values the user inputs
// match up to values required by the game (see getUserChoice() function for menu)
bool validateInput(int userChoice, int range1, int range2, string message)
{
  bool goodOrNot = false;
  if ((cin.fail()) || ((userChoice < range1) || (userChoice > range2)))
  {
 	cout << message << endl;
    goodOrNot = true;
  }
  cin.clear();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return goodOrNot;
}

// function uses switch method to display computer's choice
// and to determine the winner of the match
int displayChoice(int computerChoice, int userChoice)
{
    switch (computerChoice)
    {
       case ROCK :
           cout << "The Computer chose Rock\n\n";
           cout << determineWinner(computerChoice, userChoice);
           break;
       case PAPER :
           cout << "Computer chose Paper\n\n";
           cout << determineWinner(computerChoice, userChoice);
           break;
       case SCISSORS :
           cout << "Computer chose Scissors\n";
           cout << determineWinner(computerChoice, userChoice);
           break;
       case LIZARD :
           cout << "Computer chose Lizard\n\n";
           cout << determineWinner(computerChoice, userChoice);
           break;
       case SPOCK :
           cout << "Computer chose Spock\n\n";
           cout << determineWinner(computerChoice, userChoice);
           break;
    }
}

// determineWinner uses a series of if and switch statements
// to determine whether the computer or the user wins
// these statements also declare the winner to the user
int determineWinner(int computer, int user)
{
    // these variables used in the event of a tie to determine the winner
    // new inputs are given by the user and computer and the game is replayed
    // until a winner is declared
    int user2;
    int computer2;

    if (user == ROCK)
    {
        switch (computer)
        {
          case ROCK :
              cout << "tie\n";
              cout << "Neither rock can chip each other\n";
              user2 = getUserChoice();
              computer2 = getComputerChoice();
              cout << displayChoice(computer2, user2);
              break;

          case PAPER :
              cout << "Computer wins\n";
             cout << "Paper covers rock\n";
              break;

          case SCISSORS :
              cout << "User Wins\n";
              cout << "Rock smashes scissors\n";
              break;

          case LIZARD :
              cout << "User Wins\n";
              cout << "Rock stones lizard\n";
              break;

          case SPOCK :
              cout << "Computer Wins\n";
              cout << "Spock vaporizes rock\n";
              break;
        }
    }
    else if (user == PAPER)
    {
        switch (computer)
        {
          case ROCK :
              cout << "User Wins\n";
              cout << "Paper covers rock\n";
              break;

          case PAPER :
              cout << "tie\n";
              cout << "The papers collide, and float to the ground unharmed\n";
              user2 = getUserChoice();
              computer2 = getComputerChoice();
              cout << displayChoice(computer2, user2);
              break;

          case SCISSORS :
              cout << "Computer Wins\n";
              cout << "Scissors cut paper\n";
              break;

          case LIZARD :
              cout << "Computer Wins\n";
              cout << "Lizard eats paper\n";
              break;

          case SPOCK :
              cout << "User Wins\n";
              cout << "Paper disproves Spock\n";
              break;
        }
    }
    else if (user == SCISSORS)
    {
        switch (computer)
        {
          case ROCK :
              cout << "Computer Wins\n";
              cout << "Rock smashes scissors\n";
              break;

          case PAPER :
              cout << "User Wins\n";
              cout << "Scissors cut paper\n";
              break;

          case SCISSORS :
              cout << "tie\n";
              cout << "A scissor fight commences, it ends in a draw\n";
              user2 = getUserChoice();
              computer2 = getComputerChoice();
              cout << displayChoice(computer2, user2);
              break;

          case LIZARD :
              cout << "User Wins\n";
              cout << "Scissors decapitate lizard\n";
              break;

          case SPOCK :
              cout << "Computer Wins\n";
              cout << "Spock smashes scissors\n";
              break;
        }
    }
    else if (user == LIZARD)
    {
        switch (computer)
        {
          case ROCK :
              cout << "Computer Wins\n";
              cout << "Rock smashes lizard\n";
              break;

          case PAPER :
              cout << "User wins\n";
             cout << "Lizard eats paper\n";
              break;

          case SCISSORS :
              cout << "Computer Wins\n";
              cout << "Scissors decapitate lizard\n";
              break;

          case LIZARD :
              cout << "tie\n";
              cout << "The lizards get along fabulously\n";
              user2 = getUserChoice();
              computer2 = getComputerChoice();
              cout << displayChoice(computer2, user2);
              break;

          case SPOCK :
              cout << "User Wins\n";
              cout << "Lizard poisons Spock\n";
              break;
        }
    }
    else if (user == SPOCK)
    {
        switch (computer)
        {
          case ROCK :
              cout << "User wins\n";
              cout << "Spock smashes rock\n";
              break;

          case PAPER :
              cout << "Computer wins\n";
              cout << "Paper disproves Spock\n";
              break;

          case SCISSORS :
              cout << "User Wins\n";
              cout << "Spock smashes scissors\n";
              break;

          case LIZARD :
              cout << "Computer Wins\n";
              cout << "Lizard poisons Spock\n";
              break;

          case SPOCK :
              cout << "tie\n";
              cout << "The twin Spocks travel to the fourth dimension in search of";
              cout << " greater scientific knowledge\n";
              user2 = getUserChoice();
              computer2 = getComputerChoice();
              cout << displayChoice(computer2, user2);
              break;
        }
    }
    else if (user == QUIT)
    {
        cout << "Program ending, thanks for playing\n";
        return 0;
    }
}
