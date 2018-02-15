#ifndef FILLARR_HPP_INCLUDED
#define FILLARR_HPP_INCLUDED


void fillArr(std::ifstream &westFil, std::ifstream &eastFil, std::string west[], std::string east[], int wday[], int eday[])
{
    while (!westFil.eof())
    {
        if (westFil.eof())
            break;
        for (int i = 0; i < 5; i++)
        {
            westFil >> wday[i];
            getline(westFil, west[i]);
        }

    }
    while(!eastFil.eof())
    {
        if (eastFil.eof())
            break;
        for (int i = 0; i < 7; i++)
        {
            eastFil >> eday[i];
            getline(eastFil, east[i]);
        }
    }

    return;
}

#endif // FILLARR_HPP_INCLUDED
