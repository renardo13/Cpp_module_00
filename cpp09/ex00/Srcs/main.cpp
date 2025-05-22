#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <sstream>
#include <cstdlib>
#include <limits>

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

std::string is_date_valid(const std::string &res)
{
    if (res.empty())
        return "Error: date is missing";

    size_t sep_pos = res.find(" ");
    if (sep_pos == std::string::npos || !isAllDigit(res))
        return "Error: bad input";

    std::string date = res.substr(0, sep_pos);
    size_t first_dash = date.find("-");
    size_t second_dash = date.find("-", first_dash + 1);
    if (first_dash == std::string::npos || second_dash == std::string::npos)
        return "Error: invalid date format (expected YYYY-MM-DD)";

    std::string year_str = date.substr(0, first_dash);
    std::string month_str = date.substr(first_dash + 1, second_dash - first_dash - 1);
    std::string day_str = date.substr(second_dash + 1);

    int year = std::atoi(year_str.c_str());
    int month = std::atoi(month_str.c_str());
    int day = std::atoi(day_str.c_str());

    if (year < 2001 || year > 2025)
        return "Error: year is invalid";

    if (month < 1 || month > 12)
        return "Error: month is invalid";

    bool is_leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    if (day < 1 || day > 31)
        return "Error: day is invalid";
    if (month == 2) {
        if ((is_leap && day > 29) || (!is_leap && day > 28))
            return "Error: day is invalid";
    }
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return "Error: day is invalid";

    std::string value = res.substr(sep_pos + 1);
    double nb = std::strtod(value.c_str(), NULL);
    if (nb < 0)
        return "Error: value is not a positive number";
    if (nb > std::numeric_limits<int>::max())
        return "Error: value is too large";

    return res;
}

std::list<std::string> split_input(const std::string &sep, const char *file_name)
{
    std::string line;
    std::ifstream file(file_name);
    std::list<std::string> lst;
    if (!file.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        return lst;
    }
    std::getline(file, line);
    while (std::getline(file, line))
    {
        if (line.empty() || line[0] == ' ')
            continue;
        size_t sep_pos = line.find(sep);
        if (sep_pos == std::string::npos)
            lst.push_back(is_date_valid(line));
        else
        {
            std::string date_part = line.substr(0, sep_pos);
            std::string value_part = line.substr(sep_pos + 1);
            std::string concat_str;
            if (sep == "|")
                concat_str = date_part + value_part;
            else
                concat_str = date_part + " " + value_part;
            lst.push_back(is_date_valid(concat_str));
        }
    }
    file.close();
    return lst;
}

std::string toString(float res)
{
    std::ostringstream oss;
    oss << res;
    return oss.str();
}

std::list<std::string> calcul_exchange_rate(std::list<std::string> amount, std::list<std::string> rate)
{
    std::list<std::string> final_set;
    std::list<std::string>::iterator rate_it = rate.begin();
    std::list<std::string>::iterator amount_it = amount.begin();
    int match_flag;

    for (; amount_it != amount.end(); ++amount_it)
    {
        match_flag = 0;
        if (isAllChar(*amount_it))
        {
            final_set.push_back(*amount_it);
        }
        else
        {
            std::string amount_date = *amount_it;
            for (; rate_it != rate.end(); ++rate_it)
            {
                std::string rate_date = *rate_it;
                if (rate_date.substr(0, 10) == amount_date.substr(0, 10))
                {
                    std::string nb_amount = amount_date.substr(amount_date.find(' ') + 1);
                    float nb_am = std::strtod(nb_amount.c_str(), NULL);
                    std::string nb_rate = rate_date.substr(rate_date.find(' '));
                    float nb = std::strtod(nb_rate.c_str(), NULL);
                    float res = nb_am * nb;
                    final_set.push_back(amount_date.substr(0, amount_date.find(' ')) + " =>" + nb_amount + " = " + toString(res));
                    rate_it = rate.begin();
                    match_flag = 1;
                    break;
                }
                else if (rate_date.substr(0, 10) > amount_date.substr(0, 10)) // Si la date dépasse
                {
                    // Réinitialiser l'itérateur à la date précédente
                    std::string rate_date = *(--rate_it);
                    std::string nb_amount = amount_date.substr(amount_date.find(' ') + 1);
                    float nb_am = std::strtod(nb_amount.c_str(), NULL);
                    std::string nb_rate = rate_date.substr(rate_date.find(' '));
                    float nb = std::strtod(nb_rate.c_str(), NULL);
                    float res = nb_am * nb;
                    final_set.push_back(amount_date.substr(0, amount_date.find(' ')) + " => " + nb_amount + " = " + toString(res));
                    match_flag = true;
                    break;
                }
            }
            if (!match_flag)
            {
                std::string nb_amount = amount_date.substr(amount_date.find(' ') + 1);
                float nb_am = std::strtod(nb_amount.c_str(), NULL);
                std::string nb_rate = rate.back().substr(rate.back().find(' '));
                float nb = std::strtod(nb_rate.c_str(), NULL);
                float res = nb_am * nb;
                final_set.push_back(amount_date.substr(0, amount_date.find(' ')) + " =>" + nb_amount + " = " + toString(res));
            }
        }
    }
    return final_set;
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        std::list<std::string> amount;
        std::list<std::string> rate;
        std::list<std::string> final_set;

        amount = split_input("|", av[1]);
        rate = split_input(",", "data.csv");
        final_set = calcul_exchange_rate(amount, rate);

        std::list<std::string>::iterator it = final_set.begin();
        for (; it != final_set.end(); ++it)
        {
            std::cout << *it << std::endl;
        }
    }
    else
    {
        std::cout << "Error: could not open file." << std::endl;
    }
}
