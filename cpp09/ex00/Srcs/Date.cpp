#include "BitcoinExchange.hpp"

Date::Date() {};

Date::~Date() {};

Date::Date(Date const& cpy)
{
    if (this != &cpy)
        *this = cpy;
}

Date const& Date::operator=(Date const& other)
{
    (void)other;
    return(*this);
}

std::ofstream& operator<<(std::ofstream& stream, Date const& date)
{
    stream << date.year << "-" << date.mounth << "-" << date.day << std::endl;
    return(stream);
}