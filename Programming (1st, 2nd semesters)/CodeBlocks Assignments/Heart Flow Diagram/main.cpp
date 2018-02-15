#include <iostream>

using namespace std;

const int ROWS = 2;
const int COLUMNS = 2;

void fillArrays (char [][COLUMNS], string [][COLUMNS]);
void outputBloodFlow (char [][COLUMNS], string [][COLUMNS]);
int main()
{
    char bloodFlowMatrix[ROWS][COLUMNS];
    string labelingMatrix[ROWS][COLUMNS];

    fillArrays(bloodFlowMatrix, labelingMatrix);
    outputBloodFlow(bloodFlowMatrix, labelingMatrix);




    return 0;
}

void fillArrays(char flowMatrix[][COLUMNS], string labelMatrix[][COLUMNS])
{
    // initializes all values to default, the motion of the blood flow will be recorded later
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLUMNS; j++)
        {
            flowMatrix[i][j] = 'E';
            if (i == 0)
            {
                if (j == 0)
                    labelMatrix[i][j] = "Right Atrium";
                else
                    labelMatrix[i][j] = "Left Atrium";
            }
            else
            {
                if (j == 0)
                    labelMatrix[i][j] = "Right Ventricle";
                else
                    labelMatrix[i][j] = "Left Ventricle";
            }
        }
    }
}

void outputBloodFlow(char flowMatrix[][COLUMNS], string labelMatrix[][COLUMNS])
{
    // outputs blood flow diagram to standard
    for (int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLUMNS; j++)
        {
            cout << labelMatrix[i][j]<< " = " << flowMatrix[i][j];
            if (i == 0)
            {
                if (j == 0)
                    cout << "      ||      ";
                else
                    cout << "\n---------------------------------------------\n";
            }
            else
            {
                if (j == 0)
                    cout << "   ||   ";
                else
                    cout << endl;
            }
        }
    }
}
