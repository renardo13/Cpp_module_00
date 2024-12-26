#include "../Includes/ScalarConverter.hpp"

void alphaPrint(std::string str)
{
    if (str == "nan" || str == "+inf" || str == "+inf")
    {
        std::cout << "Char   : Impossible" << std::endl;
        std::cout << "Int    : Impossible" << std::endl;
        std::cout << "Float  : " << str << 'f' << std::endl;
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

void numberPrint(std::string str, int type, int nbrAfterPoint)
{
    int int_overflow = 0;
    int float_overflow = 0;
    int double_overflow = 0;
    long double nb = strtold(str.c_str(), NULL); // Put the number in a very tall type to handle overflow

    // check all kind of overflow to print the correspondant message
    if (nb < std::numeric_limits<int>::min() || nb > std::numeric_limits<int>::max())
        int_overflow = 1;
    if (nb < -std::numeric_limits<float>::max() || nb > std::numeric_limits<float>::max())
        float_overflow = 1;
    if (nb < -std::numeric_limits<double>::max() || nb > std::numeric_limits<double>::max())
        double_overflow = 1;

    // Char conversion
    if (isPrint(nb))
        std::cout << "Char   : " << static_cast<char>(nb) << std::endl;
    else
        std::cout << "Char   : Non displayable" << std::endl;
    // Int conversion
    if (int_overflow)
        std::cout << "Int    : Overflow" << std::endl;
    else
    {
        if (type == INT)
            nb = static_cast<int>(nb);
        std::cout << "Int    : " << static_cast<int>(nb) << std::endl;
    }
    // Float conversion
    if (float_overflow)
        std::cout << "Float  : Overflow" << std::endl;
    else
    {
        if (int_overflow && type == INT)
            std::cout << "Float  : Impossible to convert because it has overflow an int" << std::endl;
        else
        {
            if (type == FLOAT)
                nb = static_cast<float>(nb);
            std::cout << "Float  : " << std::fixed << std::setprecision(nbrAfterPoint) << static_cast<float>(nb);
            if (!nbrAfterPoint)
                std::cout << ".0";
            std::cout << "f" << std::endl;
        }
    }
    // Double conversion
    if (double_overflow)
        std::cout << "Double : Overflow" << std::endl;
    else
    {
        if ((int_overflow && type == INT) || (float_overflow && type == FLOAT))
            std::cout << "Double : Impossible to convert because it has overflow a type int or float" << std::endl;
        else
        {
            if (type == DOUBLE)
                nb = static_cast<double>(nb);
            std::cout << "Double : " << std::fixed << std::setprecision(nbrAfterPoint) << static_cast<double>(nb);
            if (!nbrAfterPoint)
                std::cout << ".0";
            std::cout << std::endl;
        }
    }
}
