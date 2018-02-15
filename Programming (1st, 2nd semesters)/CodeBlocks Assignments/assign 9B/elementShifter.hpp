#ifndef ELEMENTSHIFTER_HPP_INCLUDED
#define ELEMENTSHIFTER_HPP_INCLUDED

using std::unique_ptr;
// elementShifter
//   precondition: is passed array of ints and size of array
//   postcondition: returns a unique pointer
//   purpose: makes copy of int array with elements shifted
//            one position toward the end of the array
unique_ptr<int[]> elementShifter(int arrSize, int *arrOfInt)
{
    int ptrSize = arrSize + 1;

    unique_ptr<int[]> shiftedArray(new int [ptrSize]);

    shiftedArray[0] = 0;
    for (int i = 0; i < arrSize; i++)
    {
        shiftedArray[i + 1] = *(arrOfInt + i);
    }

    return shiftedArray;
}


#endif // ELEMENTSHIFTER_HPP_INCLUDED
