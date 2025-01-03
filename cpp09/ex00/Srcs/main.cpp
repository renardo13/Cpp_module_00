#include "BitcoinExchange.hpp"
/* The exercise is aim to learn how to match differents values ordered in key / value, like a dictionnary the most efficiently */
// I use an associative contener to do that

std::string is_value_valid(std::string value)
{
    double nb = strtod(value.c_str(), NULL);
    if (nb < 0)
        return ("Error: value is negative");
    if (nb > std::numeric_limits<int>::max())
        return ("Error: value is too big");
    return (value);
}
std::string is_date_valid(const std::string &res)
{
    if (res.empty())
        return "Error: date is missing";
    size_t sep_pos = res.find(" ");
    if (sep_pos == std::string::npos)
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

void split_input(Btc &btc, std::string sep, const char *file_name)
{
    std::string line;
    std::ifstream file(file_name);
    if (!file.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        return;
    }
    std::getline(file, line);
    while (std::getline(file, line))
    {
        if (line.empty() || line[0] == ' ')
            continue;
        size_t sep_pos = line.find(sep);
        std::string date_part = line.substr(0, sep_pos);
        std::string value_part = line.substr(sep_pos + 1);
        std::string concat_str;
        if (sep == "|")
            concat_str = date_part + value_part;
        else
            concat_str = date_part + " " + value_part;
        btc.date.insert(is_date_valid(concat_str));
    }
    file.close();
}

void calcul_price(Btc rate, Btc amount)
{
    std::set<std::string>::iterator it_rate_date;
    std::set<std::string>::iterator it_amount_date;
    std::set<std::string>::iterator ite_rate_date;
    std::set<std::string>::iterator ite_amount_date;

    it_rate_date = rate.date.begin();
    it_amount_date = amount.date.begin();
    while (it_rate_date != it_amount_date)
    {
        it_rate_date++;
    }
    ite_rate_date = rate.value.begin();
    while (it_rate_date != it_amount_date)
    {
        it_rate_date++;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        Btc rate;
        Btc amount;
        split_input(rate, ",", av[1]);
        split_input(amount, "|", "input.txt");
        std::cout << rate << std::endl;
        std::cout << amount << std::endl;
        // calcul_price(rate, amount);
    }
    else
        std::cout << "Error: could not open file." << std::endl;
}