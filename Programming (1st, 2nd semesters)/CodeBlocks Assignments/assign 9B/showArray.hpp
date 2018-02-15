#ifndef SHOWARRAY_HPP_INCLUDED
#define SHOWARRAY_HPP_INCLUDED

// showArray
//   precondition: is passed array and its size
//   postcondition: returns nothing
//   purpose: displays contents of array
void showArray(int *arr, int arrSize)
{
    std::cout << "The array consists of:\n";
    for (int i = 0; i < arrSize; i++)
    {
        std::cout << *(arr + i) << " ";
    }

    std::cout << std::endl << std::endl;
}



#endif // SHOWARRAY_HPP_INCLUDED
