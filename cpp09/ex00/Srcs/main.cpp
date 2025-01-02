#include "BitcoinExchange.hpp"
/* The exercise is aim to learn how to match differents values ordered in key / value, like a dictionnary the most efficiently */
// I use an associative contener to do that

Date get_date (char *tmp_date)
{ 
    Date date;

    date.year = strtok(tmp_date, "-");
    date.month = strtok(NULL, "-");
    date.day = strtok(NULL, "-");
    std::cout << "DATE : " << date << std::endl;
    return (date);
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
            char *line_copy = new char[line.size() + 1];
            std::strcpy(line_copy, line.c_str());
            char *res = std::strtok(line_copy, ",");
            Date date = get_date(res);
            ExchangeRate.date.insert(date);
            // res = std::strtok(NULL, ",");
            // ExchangeRate.value.insert(strtod(res));
            // std::cout << line << std::endl;
            delete[] line_copy;

        }
        std::cout << ExchangeRate.date << std::endl;
        file.close();
    }
    else
        std::cout << "Error: could not open file." << std::endl;
    
}