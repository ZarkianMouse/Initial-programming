/* MadLibs Among Us Copyright of Naomi Burhoe c. 2016
Author: Naomi Burhoe
Purpose: to create a program that replicates the form of
the Mad Libs game
*/

#include <iostream>

using namespace std;

int main()
{
    // variables for story game
    string name;
    string noun;
    int number;
    string bodyPart;
    string verb;

    //variable for loop
    char YN = 'Y';
    cout << "Welcome to Mad Libs\n";

    do {
        // entering the words
        cout << "To begin, please enter a(n):  \n";
        cout << "Proper First Name: ";
        cin >> name;
        cout << "Plural Noun: ";
        cin >> noun;
        cout << "Arbitrary Number: ";
        cin >> number;
        cout << "Body Part: ";
        cin >> bodyPart;
        cout << "Verb: ";
        cin >> verb;


        //creating a menu for stories, cause I was bored :)
        char story;
        cout << "\nNow choose a story to play: \n";
        cout << "explorer = e\n";
        cout << "puppy = p\n";
        cout << "sandwich = s\n";
        cin >> story;

        // story choices
        switch(story)
        {
            case 'e' :
                cout << "The famous explorer " << name << " had nearly given up ";
                cout << "a life-long quest to find the Lost City of \n" << noun << " ";
                cout << "when one day the " << noun << " found the explorer.\n\n";
                cout << "Surrounded by the " << number << " " << noun;
                cout << ", a tear came to " << name << "'s " << bodyPart;
                cout << ". \n After all this time, the quest was finally over.\n";
                cout << "And then, the " << noun << " promptly devoured " << name;
                cout << ". \n The moral of the story?  Be careful what you " << verb;
                cout << " for.\n" << "Thanks for playing\n";
                break;
            case 'p' :
                cout << "There once was a child, " << name << ", who really wanted a puppy.";
                cout << "\n Her parents finally agreed to get her one, as long as she agreed to ";
                cout << "help out with the " << noun << ".  ";
                cout << name << " went above and beyond, finishing her tasks in a whopping ";
                cout << number << " hours.  As a result, her parents got her that puppy.\n";
                cout << "Now one can see " << name << " as she " << verb << " a movie with the puppy";
                cout << " cradled in her " << bodyPart << ".\n";
                cout << "Thanks for playing.\n";
                break;
            case 's' :
                cout << name << " owns a deli downtown, and is trying to create a new sandwich.\n";
                cout << "He has requested you specifically to help him arrange " << noun;
                cout << " in such a way that he will be able to create a masterpiece.\n";
                cout << "Firstly, " << name << " needs you to use your " << bodyPart;
                cout << " to toss " << noun << " around that will be used to for the sandwich.\n";
                cout << "Then, he needs you to come up with " << number << " names for the creation.\n";
                cout << "Finally, he wants you to be the first one that " << verb << " the sandwich.\n";
                cout << "Are you up for it?\n";
                cout << "Thanks for playing.\n";
                break;
            default :
                cout << "What you entered was an invalid input.\n";
                break;
        }
        cout << "Would you like to play again? ";
        cin >> YN;
    } while (YN == 'Y' || YN == 'y');
}
