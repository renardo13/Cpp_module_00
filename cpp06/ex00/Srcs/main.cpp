#include <iostream>
#include <stdio.h>
#include "../Includes/ScalarConverter.hpp"

int main(int ac, char **av)
{
    if(ac == 2)
    {
        ScalarConverter convertor;
        convertor.convert(av[1]);
    }
    else
    {
        std::cout << "Invalid arguments" << std::endl;
    }
}