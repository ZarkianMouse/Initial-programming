#ifndef SETCOLOR_PERMISSIVE_HPP_INCLUDED
#define SETCOLOR_PERMISSIVE_HPP_INCLUDED

#include <windows.h>            //This is the header file for windows.
#include <stdio.h>              //C standard library header file
void setColor(int ForgC, std::string candle[], int choice)
{
     WORD wColor;
     //This handle is needed to get the current background attribute

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          /*
          0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
		  0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
          */
          int color1, color2;
          if (candle[choice] == "Prophesy")
          {
              color1 = 0xA1;
              color2 = 0x2B;
          }

          else if (candle[choice] == "Peace")
          {
              color1 = 0xF1;
              color2 = 0x17D;
          }

          else if (candle[choice] == "Love")
          {
              color1 = 0xF3;
              color2 = 0x0F;
          }

          else if (candle[choice] == "Joy")
          {
              color1 = 0xF5;
              color2 = 0x3F;
          }

          else if (candle[choice] == "Faith")
          {
              color1 = 0xE8;
              color2 = 0x2B;
          }

          else if (candle[choice] == "Hope")
          {
              color1 = 0xF4;
              color2 = 0X3A;
          }

          else if (candle[choice] == "Repentance")
          {
              color1 = 0xF1;
              color2 = 0X2A;
          }

          else if (candle[choice] == "Holy Communion")
          {
              color1 = 0xF1;
              color2 = 0x3E;
          }

          else
          {
              color1 = 0xF1;
              color2 = 0x0D;
          }

          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & color1) + (ForgC & color2);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

#endif // SETCOLOR_PERMISSIVE_HPP_INCLUDED
