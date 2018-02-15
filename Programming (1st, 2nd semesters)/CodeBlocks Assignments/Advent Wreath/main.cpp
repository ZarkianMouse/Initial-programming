/* The Advent Wreath Project
   Programming by Naomi Burhoe
   Copyright (C) 2016 of Naomi Burhoe

   Purpose: to simulate an advent wreath lighting
   tradition through the use of programming
*/

#include <iostream>
#include <fstream>
#include <string>
#include "checkOpen.hpp"
#include "fillArr.hpp"
#include "setColor_Permissive.hpp"

using namespace std;

//constants for candles in each wreath
const int SIZE_WEST = 5;     //Western
const int OTHER = 7;    //Orthodox

//function prototypes
/*
  checkOpen
     purpose: to see if the files in question opened correctly/exist
     precondition: receives two input files
     postcondition: returns false if at least one file failed to open
                    returns true if both opened correctly
*/
bool checkOpen(ifstream &, ifstream &);

/*
  fillArr
     purpose: to fill arrays with values from input files
     precondition: receives two input files
                   receives two string arrays and two integer arrays
     postcondition: returns nothing
*/
void fillArr(ifstream &, ifstream &, string [], string [], int [], int []);

/*
  chooseType
     purpose: to read from standard the choice a user makes for which
               Advent tradition the user wishes to follow
     precondition: receives nothing
     postcondition: returns integer equivalent for choice
*/
int chooseType();

/*
  adventWreath
     purpose: to light the candles which the user requires for
              a specific Advent date
     precondition: receives candle types, lighting dates, and size
                   of arrays
     postcondition: returns nothing
*/
void adventWreath(string [], string [], int [], int);

/*
  westMenu
     purpose: to display the dates on which
              Western Advent candles would be
              lit
    pre/postcondition: receives and returns nothing
*/
void westMenu();

/*
  eastMenu
     purpose: to display the dates on which
              Eastern Advent candles would be
              lit
    pre/postcondition: receives and returns nothing
*/
void eastMenu();

/*
  officialDate
     purpose: to convert numeric equivalents of dates
              to string type dates
     precondition: receives numeric date equivalent
     postcondition: returns string message based on integer
                    value
*/
string officialDate(int);

/*
  lightCandle
     purpose: to display an simple simulation of a candle
              to make candle lighting more real :)
     pre/postcondition: receives and returns nothing
*/
void lightCandle();

/*
  setColor
     purpose: to change the text color of various candles
     pre/postcondition: receives int for background and candle type
*/
void setColor(int, string [], int);

/*
  explanation
     purpose: to provide more explanation for the meaning of the candle
     precondition: receives the candle name
     postcondition: returns string explanation based on name
*/
void explanation(string [], string [], int);

int main()
{
    // files for advent candle dates and types
    ifstream inFile("advent_candle.txt");
    ifstream otherFile("orthoadvent.txt");

    //checks to see if files are opened correctly
    bool fileOpen = checkOpen(inFile, otherFile);
    if (fileOpen == false)
    {
        cout << "Cannot check Advent File\n";
        inFile.close();
        otherFile.close();
        return 0;
    }
    cout << "Advent Wreath Lighting Ceremonies:\n\n";

    // arrays to store dates and candle types
    string adventCandle[SIZE_WEST];
    string orthoCandle[OTHER];
    int westDates[SIZE_WEST];
    int eastDates[OTHER];

    // calls function to input data into arrays from files
    fillArr(inFile, otherFile, adventCandle, orthoCandle, westDates, eastDates);

    // calls function that determines which advent tradition
    // the user wishes to partake in
    int choice = chooseType();
    //if user chooses Western tradition
    if (choice == 1)
    {
        string message[SIZE_WEST];
        explanation(adventCandle, message, SIZE_WEST);
        //Western date menu is called
        westMenu();
        //candles are lit according to Western types
        adventWreath(adventCandle, message, westDates, SIZE_WEST);
    }

    //if user chooses Eastern tradition
    else
    {
        string message[OTHER];
        explanation(orthoCandle, message, OTHER);
        //Eastern date menu is called
        eastMenu();
        //candles are lit according to Eastern types
        adventWreath(orthoCandle, message, eastDates, OTHER);
    }

    inFile.close();
    otherFile.close();
    return 0;
}





int chooseType()
{
    int choice = 0;
    bool loopFlag = true;
    cout << "Which Advent tradition do you subscribe to?\n"
         << "1. Western Tradition\n"
         << "2. Eastern Tradition\n";

    // makes sure that input data is valid
    while (loopFlag)
    {
        cout << "Enter 1 for Western\n"
             << "      2 for Eastern\n";
        cin >> choice;
        if (choice >= 1 && choice <= 2)
            loopFlag = false;
    }

    return choice;
}

void westMenu()
{
    cout << "Which date would you like the candle lit for?\n"
         << "November 27 = 1\n"
         << "December 4 = 2\n"
         << "December 11 = 3\n"
         << "December 18 = 4\n"
         << "December 25 = 5\n\n";
}

void eastMenu()
{
    cout << "Which date would you like the candle lit for?\n"
         << "November 13: = 1\n"
         << "November 20: = 2\n"
         << "November 27 = 3\n"
         << "December 4 = 4\n"
         << "December 11 = 5\n"
         << "December 18 = 6\n"
         << "December 25 = 7\n\n";
}

void adventWreath(string advent[], string message[], int date[], int sizeArr)
{
    int choice = 0;
    bool loopFlag = true;

    //makes sure that input data is valid
    while (loopFlag)
    {
        cout << "Date Choice: ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > sizeArr)
            cout << "Choice must be between 1 and " << sizeArr << endl;
        else
            loopFlag = false;
    }
    choice--;

    //converts int date values to string ones
    int dayChoice = date[choice];
    string day = officialDate(dayChoice);
    cout << day << ": \n" << endl;

    //determines candles to be lit
    switch (choice)
    {
    case 6 :
        setColor(30, advent, choice);
        lightCandle();
        cout << advent[choice]
             << " Candle lit\n"
             << message[choice] << endl;
        choice--;
    case 5 :
        setColor(30, advent, choice);
        lightCandle();
        cout << advent[choice]
             << " Candle lit\n"
             << message[choice] << endl;
        choice--;
    case 4 :
        setColor(30, advent, choice);
        lightCandle();
        cout << advent[choice]
             << " Candle lit\n"
             << message[choice] << endl;
        choice--;
    case 3 :
        setColor(30, advent, choice);
        lightCandle();
        cout << advent[choice]
             << " Candle lit\n"
             << message[choice] << endl;
        choice--;
    case 2 :
        setColor(30, advent, choice);
        lightCandle();
        cout << advent[choice]
             << " Candle lit\n"
             << message[choice] << endl;
        choice--;
    case 1 :
        setColor(30, advent, choice);
        lightCandle();
        cout << advent[choice]
             << " Candle lit\n"
             << message[choice] << endl;
        choice--;
    case 0 :
        setColor(30, advent, choice);
        lightCandle();
        cout << advent[choice]
             << " Candle lit\n"
             << message[choice] << endl;
        choice--;
        break;

    }

}

string officialDate(int dayChoice)
{
    string offlDay;
    switch (dayChoice)
    {
    case 1113 :
        offlDay = ("11/13");
        break;
    case 1120 :
        offlDay = ("11/20");
        break;
    case 1127 :
        offlDay = ("11/27");
        break;
    case 1204 :
        offlDay = ("12/04");
        break;
    case 1211 :
        offlDay = ("12/11");
        break;
    case 1218 :
        offlDay = ("12/18");
        break;
    case 1225 :
        offlDay = ("12/25");
        break;
    }
    return offlDay;
}

void lightCandle()
{
    cout << "    *    \n"
         << "   * *   \n"
         << "    *    \n"
         << "   | |   \n"
         << "   | |   \n"
         << "   | |   \n"
         << "   | |   \n"
         << " <-----> \n";
   return;
}

void explanation(string candleType[], string message[], int sizeArr)
{
    string type;
    if (sizeArr == 5)
    {
        for (int i = 0; i < sizeArr; i++)
        {
            type = candleType[i];
            if (type == "Prophesy")
                message[i] = ("We have hope that God will keep his promises to us\nAlso called the Candle of Hope\n");
            else if (type == "Peace")
                message[i] = ("Peace be with you as you prepare for this new season\nAlso called the Bethlehem Candle\n");
            else if (type == "Love")
                message[i] = ("It was out of love that God sent his Son\nmay be called Angel Candle\n sometimes switched with Joy\n");
            else if (type == "Joy")
                message[i] = ("The news that a savior was coming was one of great joy\nAlso called the Shepherd Candle\n");
            else
                message[i] = ("Jesus Christ is born.  Let us all rejoice!\nThere need be no other name\n");
        }
    }
    else
    {
        for (int i = 0; i < sizeArr; i++)
        {
            type = candleType[i];
            if (type == "Faith")
                message[i] = ("We have faith that God will keep his promises\n");
            else if (type == "Hope")
                message[i] = ("We have this hope, that Christ is coming again\n");
            else if (type == "Love")
                message[i] = ("God so loved the world that he gave his only son\n");
            else if (type == "Peace")
                message[i] = ("Peace be with you. We come bearing good tidings which shall be for all people.\n");
            else if (type == "Repentance")
                message[i] = ("Repent for the kingdom of the Lord is at hand\n");
            else if (type == "Holy Communion")
                message[i] = ("Christ came that we might eventually partake\nof Holy Communion with him in a new age\n");
            else
                message[i] = ("For unto us a child is born, unto us a Son is given\nand His name shall be called Emmanuel\n");
        }
    }
}
