#ifndef CHECKOPEN_HPP_INCLUDED
#define CHECKOPEN_HPP_INCLUDED

bool checkOpen(std::ifstream &file, std::ifstream &otherFile)
{
    if (!file || !otherFile)
        return false;
    else
        return true;
}

#endif // CHECKOPEN_HPP_INCLUDED
