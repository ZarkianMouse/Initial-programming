#ifndef REVERSE_HPP_INCLUDED
#define REVERSE_HPP_INCLUDED

void reverse(char cstring[])
{
    int length = strlen(cstring);
    char *ptr1 = nullptr;
    char *ptr2 = nullptr;
    char *temp = new char;
    ptr1 = &cstring[0];
    ptr2 = &cstring[length - 1];

    if (length %2 != 0)
    {
        for (int i = 0; i < length; i++)
        {
            *temp = *ptr1;
            *ptr1 = *ptr2;
            *ptr2 = *temp;

            ptr1++;
            ptr2--;

            if(ptr1 == ptr2)
                break;
        }
    }
    else
    {
        for (int i = 0; i < (length / 2); i++)
        {
            *temp = *ptr1;
            *ptr1 = *ptr2;
            *ptr2 = *temp;

            ptr1++;
            ptr2--;
        }
    }


    delete temp;
    temp = nullptr;
}

#endif // REVERSE_HPP_INCLUDED
