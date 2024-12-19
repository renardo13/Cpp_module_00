#include "../Includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
    std::cout << "Bureaucrat is add" << std::endl;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
    if(grade > 150)
        throw(GradeTooHighException());
    if(grade < 0)
        throw(GradeTooLowException());
    std::cout << "Bureaucrat is add" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &cpy)
{
    *this = cpy;
}

Bureaucrat const& Bureaucrat::operator=(Bureaucrat const &other)
{
    if(this != &other)
    {
        this->_grade = other._grade;
        this->_name = other._name;
    }
    return(*this);
}

std::string Bureaucrat::getName()
{
    return(this->_name);
}

int Bureaucrat::getGrade()
{
    return(this->_grade);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return("Grade is too hight");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Grade is too low");
}