#include <iostream>

using namespace std;

int main()
{
    const int FIRST_YEAR = 2008;
    const int LAST_YEAR = 2011;
    int oil = 50;
    int currentYear = FIRST_YEAR;
    while (currentYear <= LAST_YEAR) {
        oil *= 1.2;
        cout << currentYear << ": " << oil << endl;
        currentYear ++;
    }
}
