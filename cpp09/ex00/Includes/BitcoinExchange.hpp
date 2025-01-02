#pragma once

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <set>
#include <cstdlib>
#include <limits>

class Btc
{
public:
    Btc() {};
    ~Btc() {};

    std::set<std::string> date;
    std::set<std::string> value;
};
std::ostream &operator<<(std::ostream &os, Btc const &btc)
{
    std::set<std::string>::const_iterator it_date = btc.date.begin();

    while (it_date != btc.date.end())
    {
        std::string date_str = *it_date;
        size_t pos = 0;
        while ((pos = date_str.find(' ', pos)) != std::string::npos)
        {
            pos += 1;
            date_str.replace(pos, 0 , ":");
            pos += 2;
        }
        os << date_str;

        ++it_date;
        std::cout << std::endl;
    }
    return os;
}
