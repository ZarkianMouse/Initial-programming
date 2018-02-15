/*
   Hospital Room Assignment Project
   Copyright of Naomi Burhoe c. 2016
   purpose: to update room assignments in a hospital
   based on requests entered through the Nurse's Station
*/

#include <iostream>
#include <iomanip>
#include <fstream>


using std::cout;
using std::endl;
using std::cin;
using std::ifstream;

const int FLOOR_ARRAY_SIZE = 5;
const int ROOM_ARRAY_SIZE = 8;

//	Transfers are represented by a 'T'.
//	The Check outs are represented by a 'C'.
//	Nurse work stations are represented by a 'W'.
//	Occupied rooms are represented by an asterisk 'O'.
//	A vacant room is represented by a blank 'V'.
//	The utility rooms are represented by an 'X'.

const char VACANT = 'V';
const char CHECKOUT = 'C';
const char OCCUPIED = 'O';
const char NURSE_STATION = 'W';
const char TRANSFER = 'T';
const char UTILITY = 'X';
const char INVALID = '@';


/* printGrid
    purpose: prints array for hospital room assignment to standard
    precondition: is passed array for hospital room assignment
    postcondition: returns nothing
*/
void printGrid(const char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE]);


/* readGrid
    purpose: reads initial hospital arrangement file into array
    precondition: is passed array for hospital room assignment
    postcondition: returns nothing
*/
void readGrid(char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE]);


/* checkOuts
    purpose: updates assignments marked as CHECKOUTS to VACANT
    precondition: is passed array for hospital room assignment
    postcondition: returns nothing
*/
void checkOuts(char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE]);


/* transfers
    purpose: performs transfers, builds dynamic array of pointers
             and computes number of available rooms
    precondition: is passed array for hospital room assignment
                  is passed variable for number of vacant rooms
    postcondition: returns dynamic array of pointers
*/
char** tranfers(char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE], int &);


/* newPatient
    purpose: performs new patients adds and updates number of vacancies
    precondition: is passed number of new patients and number of vacant rooms
                  is passed dynamic array of pointers
    postcondition: returns nothing
*/
void newPatient(int, int &, char **);


/* newPatientInput
    purpose: receives input from nurse workstations
    precondition: is passed number of vacancies
    postcondition: returns number of new patients
*/
int newPatientInput(int);


int main()
{
    // variables to be used in program
    char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE]; //stores floor layout
    int vacRooms = 0; // stores number of vacant rooms
    char **arrOfPtrs; // stores array to point to vacant rooms

    readGrid(hospitalFloors);
    printGrid(hospitalFloors);
    cout << "Grid loaded\n\n";

    checkOuts(hospitalFloors);
    arrOfPtrs = tranfers(hospitalFloors, vacRooms);
    printGrid(hospitalFloors);
    cout << "Checkouts and Transfers completed\n\n";

    int numNewPatients = 0; // stores number of new patients

    // used to determine where new patients are placed
    while (vacRooms != 0)
    {
        if (vacRooms == 0)
            break;
        numNewPatients = newPatientInput(vacRooms);
        newPatient(numNewPatients, vacRooms, arrOfPtrs);
        printGrid(hospitalFloors);
        cout << " New patient updates completed\n\n";
    }

    // a little cleanup to remove dynamic memory allotments
    // from program before it ends
    delete [] arrOfPtrs;
    arrOfPtrs = nullptr;
    cout << "***No more rooms are available today***\n";

    return 4;
}

//******************************************************
//                     printGrid
//******************************************************
void printGrid(const char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE])
{
    cout << std::setfill('-') << std::setw(17) << "\n";
    for (unsigned int i = 0; i < FLOOR_ARRAY_SIZE; ++i)
    {
        for (unsigned int j = 0; j < ROOM_ARRAY_SIZE; ++j)
        {
            cout << hospitalFloors[i][j] << " ";
        }
        cout << endl;
    }
    cout << std::setfill('-') << std::setw(17) << "\n";
    return;
}

//******************************************************
//                      readGrid
//******************************************************
void readGrid(char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE])
{
    ifstream inFile("Beds.txt");
    int itm = 0;
    char stat;
    for (unsigned int i = 0; i < FLOOR_ARRAY_SIZE; ++i)
    {
        for (unsigned int j = 0; j < ROOM_ARRAY_SIZE; ++j)
        {
            inFile >> itm;
            switch (itm)
            {
            case 0 :
                stat = VACANT;
                break;
            case 1 :
                stat = CHECKOUT;
                break;
            case 2 :
                stat = OCCUPIED;
                break;
            case 3 :
                stat = NURSE_STATION;
                break;
            case 4 :
                stat = TRANSFER;
                break;
            case 5 :
                stat = UTILITY;
                break;
            }

            hospitalFloors[i][j] = stat;
        }
    }
    inFile.close();
    return;

}

//******************************************************
//                     checkOuts
//******************************************************
void checkOuts(char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE])
{
    for (unsigned int i = 0; i < FLOOR_ARRAY_SIZE; ++i)
    {
        for (unsigned int j = 0; j < ROOM_ARRAY_SIZE; ++j)
        {
            if (hospitalFloors[i][j] == CHECKOUT)
                hospitalFloors[i][j] = VACANT;
        }
    }
}

//******************************************************
//                     transfers
//******************************************************
char** tranfers(char hospitalFloors[FLOOR_ARRAY_SIZE][ROOM_ARRAY_SIZE], int &numRooms)
{
    // counts up number of vacancies
    for (unsigned int i = 0; i < FLOOR_ARRAY_SIZE; ++i)
    {
        for (unsigned int j = 0; j < ROOM_ARRAY_SIZE; ++j)
        {
            if (hospitalFloors[i][j] == VACANT)
                numRooms++;
        }
    }

    // variables for finding vacant rooms
    int numOfArr = 0;
    char **arrVacPtr;
    arrVacPtr = new char*[numRooms];
    // assigns vacancies to positions in ptr array
    for (unsigned int i = 0; i < FLOOR_ARRAY_SIZE; ++i)
    {
        for (unsigned int j = 0; j < ROOM_ARRAY_SIZE; ++j)
        {
            if (hospitalFloors[i][j] == VACANT)
            {
                if (numOfArr == numRooms)
                    break;

                arrVacPtr[numOfArr] = &hospitalFloors[i][j];
                numOfArr++;
            }
        }
    }

    // variable for transferring patients to other rooms
    int count1 = numRooms - 1;
    // finds and moves patients marked as transfers
    for (unsigned int i = 0; i < FLOOR_ARRAY_SIZE; ++i)
    {
        for (unsigned int j = 0; j < ROOM_ARRAY_SIZE; ++j)
        {
            if (hospitalFloors[i][j] == TRANSFER)
            {
                **(arrVacPtr + count1) = OCCUPIED;
                hospitalFloors[i][j] = VACANT;
                arrVacPtr[count1] = &hospitalFloors[i][j];
                count1--;
            }
        }

    }
    return arrVacPtr;
}

//******************************************************
//                  newPatientInput
//******************************************************
int newPatientInput(int vacRooms)
{
    bool loopFlag = true;
    int numPatients = 0;

    // to validate number of new patients entered
    while (loopFlag)
    {
        cout << "Please enter the number of new patients (from 1 to " << vacRooms << "): ";
        cin >> numPatients;
        if (numPatients >= 1 && numPatients <= vacRooms)
        {
            loopFlag = false;
        }
    }
    return numPatients;
}

//******************************************************
//                     newPatient
//******************************************************
void newPatient(int newPatients, int &vacRooms, char **arrVacRooms)
{
    for (unsigned int countOfarr = vacRooms - 1; countOfarr >= 0; --countOfarr)
    {
        if (newPatients == 0)
            break;
        **(arrVacRooms + countOfarr) = OCCUPIED;
        vacRooms--;
        newPatients--;
    }
}
