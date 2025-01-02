#include "BitcoinExchange.hpp"

Date::Date() {};

Date::~Date() {};

Date::Date(Date const &cpy)
{
    if (this != &cpy)
        *this = cpy;
}

Date const &Date::operator=(Date const &other)
{
    (void)other;
    return (*this);
}

std::ostream &operator<<(std::ostream &stream, Date const &date)
{
    stream << date.year << "-" << date.month << "-" << date.day << std::endl;
    return (stream);
}

std::ostream &operator<<(std::ostream &os, const std::set<Date> &dates) {
if (dates.empty()) {
        os << "Le set est vide." << std::endl;
    }
    return os;
}
