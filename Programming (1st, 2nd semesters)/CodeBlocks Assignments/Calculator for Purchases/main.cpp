/*  Calculator for Purchasing a Vehicle
    Copyright of Zarkian Programs Inc. (c) 2017
    Created by Naomi Burhoe 1/11/2017

    Purpose: to calculate the cost of purchasing a vehicle
    under certain conditions, and to determine which vehicle
    would be better to purchase
*/
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int getCarCost();
float getGasCost();
int getFuelEff();
int getMileage();
float totalCalculator(int, int, float, int);
void compareCars(float [], int);

bool validateInput(int, int, int, string);
bool validateFloatInput(float, float, float, string);

int main()
{
    cout << "Thanks for choosing the Car Purchase Calculator.\n"
         << "Let's get started\n";

    int numCars = 0;
    bool loopFlag = true;
    string msg("You can only compare up to 10 cars at a time");
    do
    {
        cout << "How many cars would you like to compare? ";
        cin >> numCars;
        loopFlag = validateInput(numCars, 0, 10, msg);
    } while (loopFlag);

    int carCost[numCars], carFuelEff[numCars], mileage;
    float gasCost, totalCost[numCars];
    gasCost = getGasCost();
    mileage = getMileage();


    for (int i = 0; i < numCars; i++)
    {
        cout << "\nCar #" << (i + 1) << endl;
        carCost[i] = getCarCost();
        carFuelEff[i] = getFuelEff();
        totalCost[i] = totalCalculator(carCost[i], carFuelEff[i], gasCost, mileage);
    }

    cout << "\nCost of Gas: $" << gasCost << "/gal" << endl
         << "Intended Mileage: " << mileage << " miles" << endl;
    for (int i = 0; i < numCars; i++)
    {
         cout << "Car #" << (i + 1) << endl
         << "Car cost: $" << carCost[i] << endl
         << "Fuel Efficiency: " << carFuelEff[i] << "mpg" << endl
         << "Total Cost: $" << totalCost[i] << endl;
    }

    compareCars(totalCost, numCars);

    return 0;
}

int getCarCost()
{
    int cost = 0;
    string msg("You have entered an incorrect value");
    bool loopFlag = true;
    do
    {
        cout << "Please enter the cost of the car: ";
        cin >> cost;
        loopFlag = validateInput(cost, 0, 99999999, msg);
    } while (loopFlag);
    return cost;
}

float getGasCost()
{
    float cost = 0;
    string msg("You have entered an incorrect value");
    bool loopFlag = true;
    do
    {
        cout << "Please enter the cost of gas: ";
        cin >> cost;
        loopFlag = validateFloatInput(cost, 0.000, 10.000, msg);
    } while (loopFlag);
    return cost;
}

int getFuelEff()
{
    int fuelEff = 0;
    string msg("You have entered an incorrect value");
    bool loopFlag = true;

    do
    {
        cout << "Please enter the car's mileage per gallon: ";
        cin >> fuelEff;
        loopFlag = validateInput(fuelEff, 0, 999, msg);
    } while (loopFlag);
    return fuelEff;
}
int getMileage()
{
    int mileage = 0;
    string msg("You have entered an incorrect value");
    bool loopFlag = true;
    do
    {
        cout << "Please enter how many miles you wish\n to drive the car before getting a new one: ";
        cin >> mileage;
        loopFlag = validateInput(mileage, 0, 300999, msg);
    } while (loopFlag);
    return mileage;
}

float totalCalculator(int carCost, int fuelEff, float gasCost, int mileage)
{
    return carCost + (mileage / fuelEff) * gasCost;
}

void compareCars(float totalCost[], int numCars)
{
    float minCost = 0;
    int carNum = 0;
    int tieCount = 0;
    for (int i = 0; i < numCars; i++)
    {
        if (i == (numCars - 1))
        {
            if (tieCount == numCars)
                cout << "\nPurchase the cheaper car.\n";
            else
                cout << "\nThe minimum total cost is $" << minCost << endl
                     << "Purchase car #" << carNum << endl;
        }

        else
        {
            if (totalCost[i] < totalCost[i + 1])
            {
                minCost = totalCost[i];
                carNum = i + 1;
            }

            else if (totalCost[i] > totalCost[i + 1])
            {
                minCost = totalCost[i + 1];
                carNum = i + 2;
            }

            else
                tieCount++;
        }
    }
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

// this function is used to determine if values the user inputs
// match up to values required by the game (see getUserChoice() function for menu)
bool validateFloatInput(float userChoice, float range1, float range2, string message)
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
