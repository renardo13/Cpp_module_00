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
       bool operator<(const Date& other) const {
        (void)other;
        return 1;
    }
          char* year;
        char* month;
        char* day;
        
};
std::ostream& operator<<(std::ostream&, Date const& date);
std::ostream& operator<<(std::ostream& os, const std::set<Date>& dates);

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