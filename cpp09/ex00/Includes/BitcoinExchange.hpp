
#ifndef BTC_HPP
#define BTC_HPP

#include <iostream>
#include <cstdlib>
#include <limits>
#include <cctype>
#include <list>
#include <fstream>
#include <sstream>
#include <string>

class Btc
{
    public:
        Btc() {};
        ~Btc() {};
        Btc(const Btc &other)
        {
            this->date = other.date;
        }
        Btc &operator=(const Btc &other)
        {
            if (this != &other)
                this->date = other.date;
            return *this;
        }
        std::string date;
};

bool isAllChar(const std::string &str)
{
    if (!str.empty())
    {
        for (size_t i = 0; i < str.size(); ++i)
        {
            if (isdigit(str[i]))
                return false;
        }
    }
    return true;
}

bool isAllDigit(const std::string &str)
{
    if (!str.empty())
    {
        for (size_t i = 0; i < str.size(); ++i)
        {
            if (isalpha(str[i]))
                return false;
        }
    }
    return true;
}

std::ostream &operator<<(std::ostream &os, std::list<std::string> &btc)
{
    std::list<std::string>::iterator it_date = btc.begin();

    while (it_date != btc.end())
    {
        os << *it_date;
        ++it_date;
        os << std::endl;
    }
    return os;
}

#endif
