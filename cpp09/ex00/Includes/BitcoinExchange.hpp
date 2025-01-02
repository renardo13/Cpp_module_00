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
    std::set<std::string>::const_iterator it_value = btc.value.begin();

    while (it_date != btc.date.end() && it_value != btc.value.end())
    {
        os << *it_date << " : " << *it_value << std::endl;
        ++it_date;
        ++it_value;
    }
    
    return os;
}