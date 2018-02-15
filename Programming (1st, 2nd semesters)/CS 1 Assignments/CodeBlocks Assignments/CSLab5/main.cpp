/* Program modifications copyright of Naomi Burhoe c. 2016
all other info used with permission
Program id: CSLab05.cpp
This is our template for CS Lab 05
REFACTORING PRACTICE PROGRAM
This program is used for the University of Akron, Department of Computer Science Laboratories
Goal: refactor main into functions
examine each portion in main and analyze the code for refactoring
Next build your function prototype
Next build your function by copying and pasting the code from main, into your function
repeat until complete */


#include<iostream>
#include <iomanip>

using namespace std; // forgive me for being lazy!

const double TAX_RATE = .05;

//functional prototypes for program
double getPrice();
int getNumber();
char getSaleType();
double calculateTotal(char, double, int);

int main()
{
   char saleType;
   int number;
   double price, total = 0;

   // local variables used to perform total cost calculation
    price = getPrice();
    number = getNumber();
    saleType = getSaleType();
    total = calculateTotal(saleType, price, number);

    // used to show results of cost calculation to user
    cout << setprecision(2) << fixed << showpoint << number << " items at $" << price << endl;
    cout << "Total bill $" << total;
    if ((saleType == 'R') || (saleType == 'r'))
    {
        cout << " includes sales tax.\n";
    }
    return 0;
}

// ask user to input price for specific items
double getPrice()
{
    double price;
    cout << "Enter a price: $";
    cin >> price;
    return price;
}

// ask user for total number of items purchased
int getNumber()
{
    int number;
    cout << "Enter number of items purchased: ";
    cin >> number;
    return number;
}

// ask user for type of sale (retail/wholesale)
char getSaleType()
{
    char saleType;
    cout << "Type W if this is wholesale purchase. \n"
        << "Type R if this is retail purchase. \n"
        << "then press return... \n";
    cin.ignore();
    cin.get(saleType);
    return saleType;
}

// function to calculate total cost of purchase
double calculateTotal(char saleType, double price, int number)
{
   //local variables for determining total cost
   double total = 0, subTotal = 0;

   if ((saleType == 'W') || (saleType == 'w'))
    {
        total = price * number;
    }
    else if ((saleType == 'R') || (saleType == 'r'))
    {
        subTotal = price * number;
        total = subTotal + subTotal * TAX_RATE;
    }
    else
    {
        cout << "Error in the input...";
    }
    return total;
}
