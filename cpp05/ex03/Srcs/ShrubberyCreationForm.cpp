#include "../Includes/AForm.hpp"
#include "../Includes/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery form", false, 145, 137), _target("Shrubbery form") {}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &cpy) : AForm(cpy)
{
    *this = cpy;
}

ShrubberyCreationForm const &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
    if (this != &other)
        this->_target = other._target;
    return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target, int signedGrade) : AForm(target, false, signedGrade, 137), _target(target) {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!this->getIsSigned())
        throw FormNotSigned();
    if (executor.getGrade() > this->getexecuteGrade())
        throw CannotExecuteForm();
    std::ofstream form;
    std::string filename = this->_target + "_shrubbery";
    form.open(filename.c_str());
    if (form.is_open())
    {
        std::cout << "*Success ! the tree was drawn !*" << std::endl;
        form << ASCII_TREE;
    }
    else
        throw std::runtime_error("Couldn't open file");
}
