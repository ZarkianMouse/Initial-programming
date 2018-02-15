#include <iostream>
#include <memory>

class Examine
{
public :
    int sand;
    int dirt;
    Examine() : sand(1), dirt(1) {};
    Examine(int s, int d) : sand(s), dirt(d) {};
    const Examine& operator=(Examine&);

};


int main()
{
    Examine newEx;
    Examine ex2(5, 5);
    newEx = ex2;
    std::cout << "sand: " << newEx.sand << ", dirt: " << newEx.dirt << std::endl;
    return 0;
}

const Examine& Examine::operator=(Examine& obj)
{
    sand = obj.sand;
    dirt = obj.dirt;
    return *this;
}
