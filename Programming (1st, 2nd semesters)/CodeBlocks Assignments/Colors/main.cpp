#include <windows.h>            //This is the header file for windows.
#include <stdio.h>              //C standard library header file

void SetColor(int ForgC);

int main()
{
    printf("Test color");       //Here the text color is white
    SetColor(30);               //Function call to change the text color
    printf("Test color");       //Now the text color is green
    return 0;
}

void SetColor(int ForgC)
{
     WORD wColor;
     //This handle is needed to get the current background attribute

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF1) + (ForgC & 0x0D);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}
