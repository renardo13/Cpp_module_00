#include "../Includes/AForm.hpp"
#include "../Includes/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", false, 145, 137) , _target("Shrubbery") {}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& cpy) : AForm(cpy)
{
    *this = cpy;
}

ShrubberyCreationForm const& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& other)
{
    if(this != &other)
        this->_target = other._target;
    return(*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target, int signedGrade) : AForm("Shrubbery", false, signedGrade, 137) , _target(target) {}


void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    if(!this->getIsSigned())
        throw FormNotSigned();
    if (executor.getGrade() > this->getexecuteGrade())
        throw CannotExecuteForm();
    std::ofstream   form;
    std::string filename = this->_target + "_shrubbery";
    form.open(filename.c_str());
    if(form.is_open())
        form << ASCII_TREE;
    else
        std::cout << "Couldn't open file" << std::endl;
}
