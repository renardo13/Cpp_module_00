#include "BitcoinExchange.hpp"

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
    double year = std::strtod(year_str.c_str(), NULL);
    double month = std::strtod(month_str.c_str(), NULL);
    double day = std::strtod(day_str.c_str(), NULL);
    if (year < 0 || year > 2025)
        return "Error: year is invalid";
    if (month < 1 || month > 12)
        return "Error: month is invalid";
    if (day < 1 || day > 31 || (month == 2 && day > 29) ||
        ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30))
        return "Error: day is invalid";
    std::string value = res.substr(sep_pos + 1);
    double nb = strtod(value.c_str(), NULL);
    if (nb < 0)
        return ("Error: value is not a positive number");
    if (nb > std::numeric_limits<int>::max())
        return ("Error: value is too large");
    return (res);
}

std::vector<std::string> split_input(std::string sep, const char *file_name)
{
    std::string line;
    std::ifstream file(file_name);
    std::vector<std::string> vec;
    if (!file.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        return vec;
    }
    std::getline(file, line);
    while (std::getline(file, line))
    {
        if (line.empty() || line[0] == ' ')
            continue;
        size_t sep_pos = line.find(sep);
        if (sep_pos == std::string::npos)
            vec.push_back(is_date_valid(line));
        else
        {
            std::string date_part = line.substr(0, sep_pos);
            std::string value_part = line.substr(sep_pos + 1);
            std::string concat_str;
            if (sep == "|")
                concat_str = date_part + value_part;
            else
                concat_str = date_part + " " + value_part;
            vec.push_back(is_date_valid(concat_str));
        }
    }
    file.close();
    return vec;
}

std::string toString(float res)
{
    std::ostringstream oss;
    oss << res;
    std::string str = oss.str();
    return str;
}

std::vector<std::string> calcul_exchange_rate(std::vector<std::string> amount, std::vector<std::string> rate)
{
    std::vector<std::string> final_set;
    std::vector<std::string>::iterator rate_it = rate.begin();
    std::vector<std::string>::iterator amount_it = amount.begin();

    for (; amount_it != amount.end(); amount_it++)
    {

        if (isAllChar(*amount_it))
            final_set.push_back(*amount_it);
        else
        {
            for (; rate_it != rate.end(); rate_it++)
            {
                std::string rate_date = *rate_it;
                std::string amount_date = *amount_it;
                if (rate_date.substr(0, 9) == amount_date.substr(0, 9)) // check only the date with substr
                {
                    std::string nb_amount = amount_date.substr(amount_date.find(' ') + 1);
                    float nb_am = strtod(nb_amount.c_str(), NULL);
                    std::string nb_rate = rate_date.substr(rate_date.find(' '));
                    float nb = strtod(nb_rate.c_str(), NULL);
                    float res = nb_am * nb;
                    final_set.push_back(amount_date.substr(0, amount_date.find(' ')) + " =>" + nb_amount + " = " + toString(res));
                    rate_it = rate.begin();
                    break;
                }
            }
        }
    }
    return (final_set);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        std::vector<std::string> amount;
        std::vector<std::string> rate;
        std::vector<std::string> final_set;

        amount = split_input("|", "input.txt");
        rate = split_input(",", av[1]);
        final_set = calcul_exchange_rate(amount, rate);
        std::cout << final_set;
    }
    else
    {
        std::cout << "Error: could not open file." << std::endl;
    }
}
