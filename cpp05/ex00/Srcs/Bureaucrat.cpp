#include "../Includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Lilou")
{
    std::cout << "Bureaucrat is added" << std::endl;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    if (grade > 150)
        throw(GradeTooLowException());
    if (grade < 0)
        throw(GradeTooHighException());
    std::cout << "Bureaucrat is added" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &cpy)
{
    *this = cpy;
}

// operators
Bureaucrat const &Bureaucrat::operator=(Bureaucrat const &other)
{
    if (this != &other)
        this->_grade = other._grade;
    return (*this);
}

std::ostream &operator<<(std::ostream &buffer, Bureaucrat const &src)
{
    std::cout << "Name of the Bureaucrat : " << src.getName() << std::endl;
    std::cout << "Grade value : " << src.getGrade();
    return (buffer);
}

void Bureaucrat::operator++(int)
{
    this->_grade--;
}

void Bureaucrat::operator--(int)
{
    this->_grade++;
}

// getter
std::string const Bureaucrat::getName() const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

// exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade of the bureaucrat is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade of the bureaucrat is too low");
}
