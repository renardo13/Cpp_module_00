#pragma once

#include <iostream>
#include <cstring>
#include <fstream>
#include <set>
#include <cstdlib>

class Date : public std::set<char *>
{
    public:
        Date();
        ~Date();
        Date(Date const& cpy);
        Date const& operator=(Date const& other);
       

        char* year;
        char* mounth;
        char* day;
};
std::ofstream& operator<<(std::ofstream&, const Date&);

class ExchangeRate : public std::set<float>
{
    public:
        ExchangeRate() {};
        ~ExchangeRate() {};
        // ExchangeRate (ExchangeRate const& cpy);
        // ExchangeRate const& operator=(ExchangeRate const& other);

        std::set<Date> date;
        std::set<double> value;
    

};

class BitcoinAmount : public std::set<float>
{
    public:
        BitcoinAmount() {};
        ~BitcoinAmount() {};
        BitcoinAmount(BitcoinAmount const& cpy);
        BitcoinAmount const& operator=(BitcoinAmount const& other);
        
        float key;
        float value;
};