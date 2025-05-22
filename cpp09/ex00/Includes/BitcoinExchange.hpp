
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

#endif
