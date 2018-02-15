#ifndef ORIGFILL_HPP_INCLUDED
#define ORIGFILL_HPP_INCLUDED


void origFill(std::ifstream &input, char initRoom[][8], const int floors, const int rooms)
{
    for (int i = 0; i < floors; i++)
    {
        for (int j = 0; j < rooms; j++)
        {
            input >> initRoom[i][j];
        }
    }
    return;
}

#endif // ORIGFILL_HPP_INCLUDED
