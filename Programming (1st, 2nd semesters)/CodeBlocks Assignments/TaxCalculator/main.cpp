#include <iostream>
#include <iomanip>

using namespace std;

int bracketCheck(double, int []);
double taxOwed1(double [], double [], double, int);
double taxCalc1(double, double);
double findREff(double, double);
int main()
{
    double income, taxOwed, rEff;
    int bArr[] = {0, 9325, 37950, 91900, 191650, 416700, 418100};
    double rates[] = {.1, .15, .25, .28, .33, .35, .396};
    double bDiff[] = {9324.99, 28625.00, 53950.00, 99750.00, 225050.00, 1400.00};
    int bracketCheck(double, int []);
    cout << "Enter taxable income amt: ";
    cin >> income;

    int bracket = bracketCheck(income, bArr);
    cout << "Bracket = " << bracket-- << endl;

    taxOwed = taxOwed1(rates, bDiff, income, bracket);
    rEff = findREff(income, taxOwed);
    cout << "Tax Owed = $" << fixed << setprecision(2) << taxOwed << endl
         << "rEff = " << fixed << setprecision(3) << rEff << endl;
    return 0;
}

int bracketCheck(double income, int bArr[])
{
    int bracket = 0;
    for (int i = 0; i < 7; i++)
    {
        bracket = i;
        if (income < bArr[i])
            return bracket;

    }
    return bracket;
}


double tC1(double rate, double income)
{
    return rate * income;
}


double taxOwed1(double r[], double i[], double iO, int b)
{
    double tD = 0.00;
    switch(b)
    {
        case 0 : return tC1(r[b], iO);
        case 1 : tD = iO - i[b - 1];
                 return tC1(r[b - 1], i[b - 1]) + tC1(r[b], tD);
        case 2 : tD = iO - i[b - 1] - i[b - 2];
                 return tC1(r[b - 2], i[b - 2]) + tC1(r[b - 1], i[b - 1]) + tC1(r[b], tD);
        case 3 : tD = iO - i[b - 1] - i[b - 2] - i[b - 3];
                 return tC1(r[b - 3], i[b - 3]) + tC1(r[b - 2], i[b - 2]) + tC1(r[b - 1], i[b - 1]) + tC1(r[b], tD);
        case 4 : tD = iO - i[b - 1] - i[b - 2] - i[b - 3] - i[b - 4];
                 return tC1(r[b - 4], i[b - 4]) + tC1(r[b - 3], i[b - 3]) + tC1(r[b - 2], i[b - 2]) + tC1(r[b - 1], i[b - 1]) + tC1(r[b], tD);
        case 5 : tD = iO - i[b - 1] - i[b - 2] - i[b - 3] - i[b - 4] - i[b - 5];
                 return tC1(r[b - 5], i[b - 5]) + tC1(r[b - 4], i[b - 4]) + tC1(r[b - 3], i[b - 3]) + tC1(r[b - 2], i[b - 2]) + tC1(r[b - 1], i[b - 1]) + tC1(r[b], tD);
        case 6 : tD = iO - i[b - 1] - i[b - 2] - i[b - 3] - i[b - 4] - i[b - 5] - i[b - 6];
                 return tC1(r[b - 6], i[b - 6]) + tC1(r[b - 5], i[b - 5]) + tC1(r[b - 4], i[b - 4]) + tC1(r[b - 3], i[b - 3]) + tC1(r[b - 2], i[b - 2]) + tC1(r[b - 1], i[b - 1]) + tC1(r[b], tD);
    }
}


double findREff(double income, double taxOwed)
{
    return taxOwed / income;
}
