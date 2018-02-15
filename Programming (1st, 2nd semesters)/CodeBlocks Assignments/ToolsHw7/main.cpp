#include <iostream>
#include <vector>
using namespace std;


int main()
{
    char choice;


    long double xK, xKm1;
    int i = 1;
    bool loopFlag = true;
    while(loopFlag)
    {
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 'c')
        {
            xKm1 = xK;
            xK = (1 / xKm1) + 1;

        }

        else if (choice == 'r')
        {
            cout << "Enter initial guess: ";
            cin >> xK;
        }

        else if (choice == 'q')
        {
            loopFlag = false;
        }

        cout << "x" << i << " = " << xK << endl;
        i++;
    }

    return 0;
}
