/*
// COPYRIGHT (C)2015 The University of Akron, Department of Computer Science. All rights reserved.
//
// This program is intended exclusively for use by The University of Akron's Department of Computer Science
// as an assignment problem.
//
// THIS PROGRAM'S CONTENT IS PROTECTED
// The code and associated content are either the property of, or used with permission by, The University of Akron,
// Department of Computer Science and may be protected by copyright and other restrictions. Copyrights in the site
// content may also be owned by individuals and entities other than, and in addition to, The University of Akron,
// Department of Computer Science. The use of this code by you, or anyone else authorized by you, is prohibited,
// except for purposes of completing the final exam BST problem. Any unauthorized use of the coding may violate
// copyright laws, trademark laws, the laws of privacy and publicity, and communications regulations and statutes.

*/
#include <iostream>

// prototypes

template <class T>
void printarray(const T[], int);
void chew_system_stack();
template<class T>
int partition(T[], int , int);
template<class T>
void swap(T&, T&);

/*
 * Recursive version of fibonacci
   precondition: accepts an integer as an argument n
   postcondition: returns an integer which will be the nth term of the fibonacci sequence.
 */
int fibrecurse(int n)
{
    //base case 1: if n<=0 then return 0
    if(n<=0)
        return 0;
    //base case 2: if n=1 then return 1
    else if(n==1)
        return 1;
    //else recursively solve for the previous terms before n and return the sum
    else
      return fibrecurse(n-1)+fibrecurse(n-2);

}

/*
 * Iterative (loop) version of fibonacci
   precondition: accepts an integer as an argument n
   postcondition: returns an integer which will be the nth term of the fibonacci sequence.
 */
int fibiterate(int n)
{
    //variable declaration and initialization:
    int fib=0, op1=1, op2=0;

    //conditional for when n=1 set fib=1 to be returned:
    if(n==1)
        fib=1;


    //for loop which will begin iterating when n=2 otherwise the value of fib is returned by default:
    for(int i=2; i<=n; i++)
    {
       //fib will equal the sum of op1 and op2:
       fib=op1+op2;

       //op2 will be assigned op1 and op1 will be assigned fib this preserves and updates the two previous terms every iteration to return the proper result:
       op2=op1;
       op1=fib;

    }

    return fib;


}

/*
 * Recursive quicksort
   precondition: function will accept an array of any type along with the location of its first and last element in the array
   postcondtion: the array will be sorted and updated

 */
template <class T>
void quicksort(T ar[], int first, int last)
{
    //variable declaration:

    int pivot=0;

    //base case: stop calling quicksort and partition when the array can no longer be divided into sub arrays
    if(first<last)
    {
        //pivot will be be equal to the return of partition and partition will have done a preliminary sort on the array already:

        pivot=partition(ar, first, last);

        //recursively call quicksort on the arrays both left and right of the pivot point every time
        quicksort(ar, first, pivot-1);
        quicksort(ar, pivot+1, last);

    }
}

/*
   precondition: function will accept an array of any type along with the location of its first and last element in the array
   postcondition: function will return the value of pivot point and put all the values in the array less than the pivot value on the left half of the array:
*/
template<class T>
int partition(T ar[], int first, int last)
{
  //variable declaration:
  T pivotValue = 0;
  int midPoint = 0, pivotPoint = 0;

  //initialization of variables along with first and the mid element being swap so that the pivot-point is now the first element:
  midPoint=(first+last) / 2;
  swap(ar[first], ar[midPoint]);
  pivotPoint=first;
  pivotValue=ar[first];

  //for loop that will do a preliminary sort on the array

  for(int scan = first + 1; scan <= last; scan++)
  {
      //if the current element in the array is less than the pivotValue:
      if(ar[scan]<pivotValue)
      {
          //then pivot point position is incremented and its value is swapped with the value of the element it was compared with:
          pivotPoint++;
          swap(ar[scan], ar[pivotPoint]);

      }
  }

  //at the end the values of the first element and pivotPoint are swapped:
  swap(ar[pivotPoint], ar[first]);

  return pivotPoint;

}

/*
  precondition: function will accept to values passed by memory
  postcondition: the memory addresses will contain the value of the other:
*/
template<class T>
void swap(T &value1, T &value2)
{
    T temp = value2;
    value2 = value1;
    value1 = temp;
}

int main() {
    const int FIBLOOPS = 10;
    const int ARSIZ = 10;
    int ar[ARSIZ];

    std::cout << "Recursive fib: ";
    for(int i = 0; i < FIBLOOPS; ++i)
    {
        std::cout << fibrecurse(i) << " ";
    }
    std::cout << std::endl;
    std::cout << "Iterative fib: ";
    for(int i = 0; i < FIBLOOPS; ++i)
    {
        std::cout << fibiterate(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Quicksort:" << std::endl;
    // populate random array
    for(int i = 0; i < ARSIZ; ++i)
    {
        ar[i] = (i * 3037) % 2099;  // prime numbers! again!
    }
    printarray(ar, ARSIZ);
    quicksort(ar, 0, ARSIZ-1);
    printarray(ar, ARSIZ);

    //std::cout << "Chewing system stack:" << std::endl;
    //chew_system_stack();

    return 0;
}

/*  utility functions, do not modify  */
template <class T>
void printarray(const T ar[], int s)
{
    for(int i = 0; i < s; ++i)
    {
        std::cout << ar[i] << " ";
    }
    std::cout << std::endl;
}

void printstackpointer()
{
    void * stack_pointer;
    // inline assembly language to get stack pointer
    __asm__ __volatile__("movl  %%esp,%%eax"
                             :"=a"(stack_pointer)
                             );
    std::cout << stack_pointer << std::endl;
}

void chew_system_stack()
{
    // Feel free to play with this, but please
    // do NOT enable this for your final commit!
    printstackpointer();
    chew_system_stack();
}
/* end utilities */
