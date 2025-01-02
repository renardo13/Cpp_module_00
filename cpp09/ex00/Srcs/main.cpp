#include "BitcoinExchange.hpp"


/* The exercise is aim to learn how to match differents values ordered in key / value, like a dictionnary the most efficiently */
// I use an associative contener to do that

Date const get_date (char *date)
{
    Date Date;

    Date.year = strtok(date, "-");
    Date.mounth = strtok(NULL, "-");
    Date.day = strtok(NULL, "-");
    return (Date);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        std::string line;
        std::ifstream file(av[1]);
        if (!file.is_open())
        {
            std::cout << "Error: could not open file." << std::endl;
            return(-1);
        }
        std::getline(file, line);
        ExchangeRate ExchangeRate;
        while (std::getline(file, line))
        {
            
            char *res;

            res = std::strtok(const_cast<char*>(line.c_str()), ",");
            ExchangeRate.date.insert(get_date(res));
            res = std::strtok(NULL, ",");
            ExchangeRate.value.insert(std::strtod(res, NULL));

            // rate.value = res[1];
            // std::cout << rate.key << std::endl;
            // std::cout << rate.value << std::endl;

        }
        file.close();
    }
    else
        std::cout << "Error: could not open file." << std::endl;
    
}