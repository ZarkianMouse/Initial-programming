#include <iostream>

using namespace std;

int f1(int n, int m)
{
    if(n < m)
        return 0;
    else if(n==m)
        return m + f1(n-1, m);
    else
        return n + f1(n-2, m-1);
}
int main()
{
    cout << f1(5, 4)<< endl;
    return 0;
}
