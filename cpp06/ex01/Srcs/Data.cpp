#include"../Includes/Data.hpp"

Data::Data() {}

Data::~Data() {}

Data::Data(Data const &cpy)
{
    if (this != &cpy)
        *this = cpy;
}

Data const &Data::operator=(Data const &other)
{
    (void)other;
    return (*this);
}