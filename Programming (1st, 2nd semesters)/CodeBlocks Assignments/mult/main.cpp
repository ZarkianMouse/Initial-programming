#include <iostream>

using namespace std;

int main()
{
    int x, y;
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter 2 numbers: ";
        cin >> x >> y;
        cout << "Product = " << x * y << endl;
    }

    return 0;
}
