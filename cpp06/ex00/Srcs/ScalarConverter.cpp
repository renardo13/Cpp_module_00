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

// Convert functions
void ScalarConverter::convert(std::string str)
{
    // nbrAfterPoints variable to count the fractionnal part and in function set the precision of the print.
    int nbrAfterPoints = 0;
    int type = whichType(str, &nbrAfterPoints);

    if (type == -1)
        return;
    if (type == ALPHA)
        alphaPrint(str);
    else 
        numberPrint(str, type, nbrAfterPoints);
}
