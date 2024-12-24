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
    for (int i = 0; s[i]; i++)
    {
        if ((s[i] < '0' || s[i] > '9') && !(s[i] == 'f' && !s[i + 1]) && s[i] != '.' && s[i] != '-')
            return (0);
    }
    return (1);
}

int whichType(std::string s)
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
    }
    if (s[s.length() - 1] == 'f' && point_bool)
        return (FLOAT);
    if (point_bool)
        return (DOUBLE);
    return (INT);
}

// Convert functions
void ScalarConverter::convert(std::string str)
{
    ScalarConverter nb;

    if (whichType(str) == -1)
        return;
    if (whichType(str) == INT)
    {
        int nb = stringToInt(str);
        std::cout << "Char   : Non displayable" << std::endl;
        if (nb < std::numeric_limits<int>::min() || nb > std::numeric_limits<int>::max())
            std::cout << INT_OVERFLOW << std::endl;
        std::cout << "Int    : " << static_cast<int>(nb) << std::endl;
        if (nb < std::numeric_limits<float>::min() || nb > std::numeric_limits<float>::max())
            std::cout << FLOAT_OVERFLOW << std::endl;
        std::cout << "Float  : " << static_cast<float>(nb) << ".0f" << std::endl;
        if (nb < std::numeric_limits<double>::min() || nb > std::numeric_limits<double>::max())
            std::cout << DOUBLE_OVERFLOW << std::endl;
        std::cout << "Double : " << static_cast<double>(nb) << ".0" << std::endl;
    }
    else if (whichType(str) == ALPHA)
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
    else if (whichType(str) == FLOAT)
    {
        float nb = stringToFloat(str);

        std::cout << "Char   : Non displayable" << std::endl;
        std::cout << "Int    : " << static_cast<int>(nb) << std::endl;
        std::cout << "Float  : " << static_cast<float>(nb) << "f" << std::endl;
        std::cout << "Double : " << static_cast<double>(nb) << std::endl;
    }
    else if (whichType(str) == DOUBLE)
    {
        double nb = stringToDouble(str);

        std::cout << "Char   : Non displayable" << std::endl;
        std::cout << "Int    : " << static_cast<int>(nb) << std::endl;
        std::cout << "Float  : " << static_cast<float>(nb) << "f" << std::endl;
        std::cout << "Double : " << static_cast<double>(nb) << std::endl;
    }
}

// converting functions

// This is not bit shifting we juste store the input of the user as an integer
int stringToInt(const std::string &str)
{
    std::istringstream stream(str);
    int result;
    stream >> result;
    return (result);
}

double stringToDouble(std::string s) // split the fractionnal part and the decimal part and convert it into double
{
    size_t pos = s.find('.');
    int decimal = 0;
    int sign = 1;

    if (s[0] == '-')
    {
        decimal = stringToInt(s.substr(1, pos));
        sign = -1;
    }
    else
        decimal = stringToInt(s.substr(0, pos));
    int mantisse = stringToInt(s.substr(pos + 1));

    double fractionalPart = mantisse / std::pow(10, s.size() - pos - 1);
    return ((decimal + fractionalPart) * sign);
}

float stringToFloat(std::string s)
{
    return (static_cast<float>(stringToDouble(s))); // We can downcast because a float is less precise than a double
}
