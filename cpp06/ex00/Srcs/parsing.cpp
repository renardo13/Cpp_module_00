#include "../Includes/ScalarConverter.hpp"

int noPrintable(std::string s)
{
    for (int i = 0; s[i]; i++)
    {
        if (s[i] < 32 || s[i] > 127)
        {
            return (1);
        }
    }
    return (0);
}

int isPrint(int nb)
{
    if (nb > 32 && nb < 127)
        return (1);
    return (0);
}

int isAlpha(std::string s)
{
    for (int i = 0; s[i]; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            return (0);
    }
    return (1);
}

// different from the real isDigit function
int isDigit(std::string s)
{
    int minus_bool = 0;

    for (int i = 0; s[i]; i++)
    {
        if (s[i] == '-' && i == 0)
        {
            minus_bool = 1;
            i++;
        }
        if (minus_bool && s[i] == '-')
            return (0);
        if ((s[i] < '0' || s[i] > '9') && !(s[i] == 'f' && !s[i + 1]) && s[i] != '.')
            return (0);
    }
    return (1);
}

int whichType(std::string s, int *nbrAfterPoint)
{
    int point_bool = 0;

    if (!s[0])
        return (std::cout << TYPE_NOT_FOUND, -1);
    if (noPrintable(s))
        return (std::cout << "Character are no printable " << TYPE_NOT_FOUND << std::endl, -1);
    if (isAlpha(s))
        return (ALPHA);
    if (!isDigit(s))
        return (std::cout << TYPE_NOT_FOUND, -1);
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == '.' && !point_bool)
            point_bool = 1;
        else if (s[i] == '.' && point_bool)
            return (std::cout << "Invalid float or double format, more that two points" << std::endl, -1);
        if (point_bool)
            (*nbrAfterPoint)++;
    }
    if (s[s.length() - 1] == 'f' && point_bool)
    {
        (*nbrAfterPoint) -= 2;
        return (FLOAT);
    }
    if (point_bool)
    {
        (*nbrAfterPoint)--;
        return (DOUBLE);
    }

    return (INT);
}

