/* The Supreme (Very Basic) Statistical Calculator of Awesomeness
Program Copyright of Naomi Burhoe c. 2016
Purpose: to perform simple statistical calculations including:
         a. summation of available data
         b. calculating the average of some data
         c. finding the largest number in data
         d. finding the most frequent number in data
         e. calculating the total amount of numbers in data
         f. finding the median in a set of data
*/

#include <iostream>
#include <iomanip>
#include <limits>
using std::cin;
using std::cout;
using std::endl;

// constant for size of array
const int SIZE = 100;

// functional prototypes for program
void fillUp(int [], int);  // function initialization
void menu();               // shows choices that can be made
int getSum(int [], int);   // used to find sum
void avg(int[], int, int); // used to find average
int biggest(int [], int);  // used to find biggest num
int smallest(int [], int); // used to find smallest num
void mode(int [], int);    // used to find most frequent num
int getAmount(int [], int);// used to find total amount of nums
void median(int [], int);  // used to find median num

int main()
{
    // variables used for in program for various statistical measurements
    int frequency[SIZE];
    char command;
    int value = 0;
    int sum = 0;
    int total = 0;
    int maxNum = 0;

    // to set frequency to 0
    fillUp(frequency, SIZE);

    // call to show menu function
    menu();

    //variable to govern calculator loop
    bool loopFlag = true;
    do
    {
        cout << "Input a letter: " << endl;
        cin >> command;

        switch(command)
        {
            case 'N' :
                cin >> value;
                frequency[value]++;
                cout << "OK" << endl;
                break;
            case 'S' :
                sum = getSum(frequency, SIZE);
                cout << sum << endl;
                break;
            case 'A' :
                avg(frequency, SIZE, sum);
                break;
            case 'B' :
                maxNum = biggest(frequency, SIZE);
                cout << maxNum << endl;
                break;
            case 'F' :
                mode(frequency, SIZE);
                break;
            case 'H' :
                total = getAmount(frequency, SIZE);
                cout << total << endl;
                break;
            case 'M' :
                median(frequency, SIZE);
                break;
            case 'Q' :
                loopFlag = false;
                cout << "END" << endl;
                break;
            default :
                cout << "Error" << endl;
                break;
        }
        cin.clear();
        cin.ignore();
    } while (loopFlag);
}

// fillUp sets initial values of the frequency
// array to zero
// precondition: is passed the array and the size of the array
// postcondition: returns nothing, updates frequency values
void fillUp(int arr[], int sizeArr)
{
    for (int i = 0; i < sizeArr; i++)
    {
        arr[i] = 0;
    }
}

// menu displays the choices that a user can
// make for the statistical calculator
void menu()
{
    cout << "Your choices are: " << endl;
    cout << "N - Numbers" << endl;
    cout << "S - Sum of numbers" << endl;
    cout << "A - Average of numbers" << endl;
    cout << "B - Biggest of numbers" << endl;
    cout << "F - Most frequent of numbers" << endl;
    cout << "M - Median number" << endl;
    cout << "Q - Quit" << endl;
}

// getSum is used to find the sum of the numbers inputted
// precondition: is passed the function and its size
// postcondition: returns the total sum
int getSum(int arr[], int sizeArr)
{
    int sum = 0;
    for (int i = 0; i < sizeArr; i++)
    {
        sum = sum + (i * arr[i]);
    }
    return sum;
}

// avg is used to find the average of the numbers inputted
// precondition: is passed an array, the size of the array,
//               and the sum of the variables
// postcondition: returns nothing, outputs avg to std
void avg(int arr[], int sizeArr, int sum)
{
    double average = 0;
    int total = 0;
    if (sum = 0)
    {
        sum = getSum(arr, sizeArr);
    }
    for (int i = 0; i < sizeArr; i++)
    {
        total += arr[i];
    }
    if (total == 0 || sum == 0)
    {
        cout << "ERROR" << endl;
        return;
    }
    else
    {
        average = static_cast<double>(sum) / total;
        cout << "The average is: " << average << endl;
        return;
    }
}

// biggest seeks to find the largest number that has been inputted
// precondition: is passed an array and its size
// postcondition: returns the largest number
int biggest(int arr[], int sizeArr)
{
    int largest = 0;
    int countItem = 0;
    for(int i = 0; i < sizeArr; i++)
    {
        countItem = arr[i];
        if (countItem > 0)
        {
            largest = i;
        }
    }
    return largest;
}

// smallest is like biggest except that
// it is used to find the smallest number
// in the data set rather than the biggest
int smallest(int arr[], int sizeArr)
{
    int minimum = 0;
    int countItem = 0;
    for(int i = 0; i < sizeArr; i++)
    {
        countItem = arr[i];
        if (countItem > 0)
        {
            minimum = i;
            return minimum;
        }
    }
    return minimum;
}

// mode finds that number which has been inputted the most
// precondition: is passed an array and its size
// outputs the mode to std output
void mode(int arr[], int sizeArr)
{
    int modeCount = arr[0];
    int modeIndex = 0;
    for (int i = 1; i < sizeArr; i++)
    {
        if (modeCount < arr[i])
        {
            modeCount = arr[i];
            modeIndex = i;
        }
    }
    cout << "Most Frequent: " << modeIndex << endl;
}

// getAmount should calculate the total amount of numbers
// that have been inputted thus far
// precondition: is passed an array and its size
// postcondition: returns the total value
int getAmount(int arr[], int sizeArr)
{
    int total = 0;
    for (int i = 0; i < sizeArr; i++)
    {
        total = total + arr[i];
    }
    return total;
}

// median should be able to find the median of the data set
// precondition: is passed an array and its size
// outputs the value of the median to std
void median(int arr[], int sizeArr)
{
    int medianArray[sizeArr];
    for (int i = 0; i < sizeArr; i++)
    {
        medianArray[i] = arr[i];
    }

    int minNum = 0;
    int maxNum = 0;
    int smallCount = 0;
    int largeCount = 0;
    int total = getAmount(arr, sizeArr);
    for (int i = 0; i < (sizeArr - (2 * i)); i++)
    {
        minNum = smallest(medianArray, sizeArr);
        maxNum = biggest(medianArray, sizeArr);
        if (minNum == maxNum)
        {
            if ((minNum == 0) && (medianArray[minNum] == 0))
            {
                cout << "ERROR\n";
                return;
            }
            cout << "The median is: " << minNum << endl;
            return;
        }
        else
        {
            medianArray[minNum]--;
            medianArray[maxNum]--;
        }
    }
    return;
}

