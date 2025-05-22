#include "RPN.hpp"
#include <stack>
#include <iostream>
#include <sstream>
#include <string>

int isOperator(char c)
{
    if (c == '*' || c == '/' || c == '+' || c == '-')
        return (1);
    return (0);
}

int parse_input(const std::string &s)
{
    std::istringstream ss(s);
    std::string token;
    while (ss >> token)
    {
        if (token.size() == 1 && !isdigit(token[0]) && !isOperator(token[0]))
        {
            std::cout << "Invalid character: " << token << std::endl;
            return (-1);
        }
        if (isdigit(token[0]) && isdigit(token[1]))
        {
            std::cout << "Number should be less than 10." << std::endl;
            return (-1);
        }
        if (token.size() > 1 && !isdigit(token[0]))
        {
            std::cout << "Invalid number: " << token << std::endl;
            return (-1);
        }
    }
    return (0);
}

int do_op(int nb1, int nb2, char op)
{
    if (op == '*')
        return (nb1 * nb2);
    if (op == '/')
        return (nb1 / nb2);
    if (op == '-')
        return (nb1 - nb2);
    if (op == '+')
        return (nb1 + nb2);
    return (0);
}

int main(int ac, char **av)
{
    int i;
    int nb1;
    int nb2;

    if (ac == 2)
    {
        if (parse_input(av[1]))
            return (-1);
        else
        {
            std::stack<int> stack;
            i = -1;
            while (av[1][++i])
            {
                if (std::isdigit(av[1][i]))
                {
                    stack.push(av[1][i] - 48);
                }
                else if (isOperator(av[1][i]))
                {
                    if (av[1][i] == '/' && stack.top() == 0)
                    {
                        std::cout << "Division by zero is not allowed\n";
                        return (-1);
                    }
                    if (stack.size() < 2)
                    {
                        std::cout << "Error: Not enough operands for operation." << std::endl;
                        return (-1);
                    }
                    nb1 = stack.top();
                    stack.pop();
                    nb2 = stack.top();
                    stack.pop();
                    stack.push(do_op(nb2, nb1, av[1][i]));
                }
            }
            if (stack.size() != 1)
            {
                std::cout << "Error: Not enough operators." << std::endl;
                return (-1);
            }
            std::cout << stack.top() << std::endl;
        }
    }
    else
        std::cout << "Wrong input format should be ./RPN \"expression\" " << std::endl;

    return 0;
}
