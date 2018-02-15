#ifndef READGRID_HPP_INCLUDED
#define READGRID_HPP_INCLUDED

void readGrid(std::ifstream &inputFile, char initRoom[][8], const int FLOORS, const int ROOMS)
{
    for (int i = 0; i < FLOORS; i++)
    {
        for (int j = 0; j < ROOMS; j++)
        {
            inputFile >> initRoom[i][j];
        }
    }
    return;
}
#endif // READGRID_HPP_INCLUDED
