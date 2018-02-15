#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::stringstream;
using std::cout;

int main()
{
    int num = 55555;
    stringstream ss;
    ss << num;
    string str = ss.str();
    cout << str.length();
    return 0;
}
