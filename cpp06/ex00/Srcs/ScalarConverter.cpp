#include "../Includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &cpy)
{
    if (this != &cpy)
        *this = cpy;
}

ScalarConverter const &ScalarConverter::operator=(ScalarConverter const &other)
{
    (void)other;
    return (*this);
}

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
        if (s[i] == '-')
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
        (*nbrAfterPoint)--;
        return (FLOAT);
    }
       
    if (point_bool)
        return (DOUBLE);
    return (INT);
}

// Convert functions
void ScalarConverter::convert(std::string str)
{
    int nbrAfterPoints = 0;
    int type = whichType(str, &nbrAfterPoints);
    if (type == -1)
        return;
    if (type == ALPHA)
    {
        if (str == "nan" || str == "+inf" || str == "-inff" || str == "+inf" || str == "+inff")
        {
            std::cout << "Char   : Impossible" << std::endl;
            std::cout << "Int    : Impossible" << std::endl;
            std::cout << "Float  : " << str << std::endl;
            std::cout << "Double : " << str << std::endl;
        }
        else if (!str[1])
        {
            std::cout << "Char   : " << str << std::endl;
            std::cout << "Int    : " << static_cast<int>(str[0]) << std::endl;
            std::cout << "Float  : " << static_cast<float>(str[0]) << std::endl;
            std::cout << "Double : " << static_cast<double>(str[0]) << std::endl;
        }
        else
        {
            std::cout << "Char   : " << str << std::endl;
            std::cout << "Int    : Impossible" << std::endl;
            std::cout << "Float  : Impossible" << std::endl;
            std::cout << "Double : Impossible" << std::endl;
        }
    }
    long double nb = strtold(str.c_str(), NULL);
    if (type == INT)
    {
        if (nb < std::numeric_limits<int>::min() || nb > std::numeric_limits<int>::max())
            std::cout << INT_OVERFLOW << std::endl;
        std::cout << "Char   : Non displayable" << std::endl;
        std::cout << "Int    : " << static_cast<int>(nb) << std::endl;
        std::cout << "Float  : " << static_cast<float>(nb) << ".0f" << std::endl;
        std::cout << "Double : " << static_cast<double>(nb) << ".0" << std::endl;
    }
    else if (type == FLOAT)
    {
        if (nb < -std::numeric_limits<float>::max() || nb > std::numeric_limits<float>::max())
            std::cout << FLOAT_OVERFLOW << std::endl;
        std::cout << "Char   : Non displayable" << std::endl;
        std::cout << "Int    : " << static_cast<int>(nb) << std::endl;
        std::cout << "Float  : " << std::fixed << std::setprecision(nbrAfterPoints) << static_cast<float>(nb) << "f" << std::endl;
        std::cout << "Double : " << static_cast<double>(nb) << std::endl;
    }
    else if (type == DOUBLE)
    {
        if (nb < -std::numeric_limits<float>::max() || nb > std::numeric_limits<float>::max())
            std::cout << DOUBLE_OVERFLOW << std::endl;
        std::cout << "Char   : Non displayable" << std::endl;
        std::cout << "Int    : " << static_cast<int>(nb) << std::endl;
        std::cout << "Float  : " << static_cast<float>(nb) << "f" << std::endl;
        std::cout << "Double : " << std::fixed << std::setprecision(nbrAfterPoints) << static_cast<double>(nb) << std::endl;
    }
}
