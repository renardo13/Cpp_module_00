#pragma once

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <sstream>
#include <math.h>

#define TYPE_NOT_FOUND "Type was not found.\n"
#define INT_OVERFLOW "Int overflow.\n"
#define FLOAT_OVERFLOW "Float overflow.\n"
#define DOUBLE_OVERFLOW "Double overflow.\n"

enum type
{
    ALPHA, //0
    INT, //1
    FLOAT, //2
    DOUBLE, //3
};

class ScalarConverter
{
    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(ScalarConverter const &cpy);
        ScalarConverter const& operator=(ScalarConverter const &other);

        static void convert(std::string str);

};

//parsing functions
int noPrintable(std::string s);
int isAlpha(std::string s);
int isDigit(std::string s);
int whichType(std::string s);

//converting functions
int stringToInt(const std::string& str);
float stringToFloat(std::string s);
double stringToDouble(std::string s);
