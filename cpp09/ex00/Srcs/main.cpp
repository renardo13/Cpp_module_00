#include "BitcoinExchange.hpp"
/* The exercise is aim to learn how to match differents values ordered in key / value, like a dictionnary the most efficiently */
// I use an associative contener to do that

char const *is_date_valid(char *res)
{
    if (!res)
        return ("Error: date is missing");
    char *tmp_line = new char[strlen(res) + 1];
    std::strcpy(tmp_line, res);
    int year = strtod(strtok(tmp_line, "-"), NULL);
    if (year < 0 || year > std::numeric_limits<int>::max())
        return (delete[] tmp_line, "Error: year is invalid");
    int month = strtod(strtok(NULL, "-"), NULL);
    if (month < 1 || month > 12)
        return (delete[] tmp_line, "Error: month is invalid");
    int day = strtod(strtok(NULL, "-"), NULL);
    if (day < 1 || day > 31)
        return (delete[] tmp_line, "Error: day is invalid");
    return (delete[] tmp_line, res);
}

char const * is_value_valid(char * value)
{
    double nb = strtod(value, NULL);
    if (nb < 0)
        return("Error: value is negative");
    if (nb > std::numeric_limits<int>::max())
        return("Error: value is too big");
    return(value);
}

void split_input(Btc &btc, const char *sep, const char *file_name)
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
        size_t sep_pos = line.find(sep);
        if (sep_pos != std::string::npos)
        {
            std::string date_part = line.substr(0, sep_pos);
            std::string value_part = line.substr(sep_pos + 1);
            // const char* valid_date = is_date_valid(const_cast<char*>(date_part.c_str()));
            // const char* valid_value = is_value_valid(const_cast<char*>(value_part.c_str()));
            std::string concatenated = date_part + value_part;
            btc.date.insert(concatenated); 

            
        }
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
    while(it_rate_date != it_amount_date)
    {
        it_rate_date++;
    }
    ite_rate_date = rate.value.begin();
    while(it_rate_date != it_amount_date)
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
        std::cout << amount << std::endl;
        // calcul_price(rate, amount);
    }
    else
        std::cout << "Error: could not open file." << std::endl;
}