/* Character Deletion using Unique Pointers
   Copyright of Naomi Burhoe c. 2017

   Purpose: to remove repeated characters from
            arrays
*/
#include <iostream>
#include <memory>
#include <iomanip>

using std::cout;
using std::endl;
using std::end;
using std::unique_ptr;

// used to specify sizes of arrays to be searched
const int SIZE = 10;

// declares a function to search for and delete
// repeated characters
unique_ptr<char[]> deleteRepeats(char [], int*);

int main()
{
    // test case for repeated character detection
    char originalArray[SIZE];
    originalArray [0] = 'a';
    originalArray [1] = 'b';
    originalArray [2] = 'b';
    originalArray [3] = 'c';
    originalArray [4] = 'a';
    originalArray [5] = 'c';
    originalArray [6] = 'a';
    originalArray [7] = 'c';
    originalArray [8] = 'b';
    originalArray [9] = 'c';

    // creates a pointer variable for keeping track
    // of deleted characters
    int *deleteCount = new int;
    *deleteCount = 0; // initializes count to 0

    // creates a unique pointer variable to store
    // the new, non-repeated array of characters
    unique_ptr<char[]> noRepeats(new char[SIZE]);

    // call to function that searches for and deletes
    // repeated characters
    noRepeats = deleteRepeats(originalArray, deleteCount);


    // outputs new array and number of deleted characters
    // to standard
    cout << "Unique Array:\n";
    for (int i = 0; i < SIZE; i++)
    {
        if (noRepeats[i] != '-')
            cout << noRepeats[i] << endl;

    }
    cout << "Deleted characters: " << *deleteCount << endl;

    delete deleteCount;
    deleteCount = nullptr;

    return 0;
}

// deleteRepeats:
// precondition: receives an array of characters and a pointer variable
// to keep track of deleted characters
// postcondition: returns a new array of characters (a unique array) that
// doesn't contain any repeated characters (letter characters)
unique_ptr<char[]> deleteRepeats(char origArray[], int *deleteCount)
{
    unique_ptr<char[]> newArray(new char[SIZE]);

    // initializes the array to a non-letter character
    // for easier maintenance of array
    for (int i = 0; i < SIZE; i++)
    {
        newArray[i] = '-';
    }

    // temporary characters for storage of array entities
    // whilst searching for repeated characters
    char c1 = '-', c2 = '-';
    for (int i = 0; i < SIZE; i++)
    {
        // keeps track of individual deleted characters
        int deletes = 0;

        c1 = origArray[i]; // sets first storage character

        // searches for repeated characters
        for (int j = 0; j < SIZE; j++)
        {

            c2 = newArray[j]; // sets second storage character

            // ignores any repeated characters
            if (c1 == c2)
                deletes++;
        }

        // stores unique values in new array
        if (deletes == 0)
        {
            newArray[i] = c1;
        }

        // updates number of deleted characters
        else
        {
            *deleteCount = *deleteCount + deletes;
        }
    }
    return newArray;
}
