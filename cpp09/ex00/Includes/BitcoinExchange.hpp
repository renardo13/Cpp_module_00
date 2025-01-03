#pragma once

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <set>
#include <cstdlib>
#include <limits>
#include <cctype>

class Btc
{
public:
    Btc() {};
    ~Btc() {};

    std::set<std::string> date;
    bool operator<(const std::string &a) const
    {
        return (this->date.substr(0, 10) < a.substr(0, 10));  // Comparer les 10 premiers caractères (la date)
    }
    
};
std::ostream &operator<<(std::ostream &os, Btc const &btc)
{
    std::set<std::string>::const_iterator it_date = btc.date.begin();

    while (it_date != btc.date.end())
    {
        os << *it_date;
        ++it_date;
        std::cout << std::endl;
    }
    return os;
}
