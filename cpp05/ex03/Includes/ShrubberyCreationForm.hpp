#pragma once

#include <iostream>
#include <exception>
#include "AForm.hpp"
#include <fstream>

# define ASCII_TREE "       ooo xxoo ooo oxxoo\n"\
"    ooxoxo oo  oxoxooo xoo\n"\
"   oooo xxoxoo ooo ooox xoxo\n"\
"  oxo o oxoxo  xoxxoxo oooox\n"\
"   oxo xooxoooo o oooox xxoo\n"\
"     ooxo oooooo oxoxo oooo\n"\
"        oooooooo  oooo xoox\n"\
"           oooooo  / /o\n"\
"              \\ \\ / /\n"\
"               |   /\n"\
"               |  |\n"\
"               |  |\n"\
"               |  |\n"\
"               |  |\n"\
"   ____________|__|___________\n"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    public:
        //canonical class
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm const &cpy);
        ShrubberyCreationForm const& operator=(ShrubberyCreationForm const& other);

        ShrubberyCreationForm(std::string const target, int grade);
        void execute(Bureaucrat const& executor) const;
};
