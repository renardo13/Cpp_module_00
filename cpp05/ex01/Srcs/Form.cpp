#include "Form.hpp"

Form::Form() : _name("Form"), _signedGrade(150),
_executeGrade(150), _isSigned(false)
{

}

Form::~Form() {}

Form::Form(std::string const name, int formBool, int signedGrade, int executeGrade)  : _name(name),
_signedGrade(signedGrade), _executeGrade(executeGrade),_isSigned(formBool)
{
    if (this->_signedGrade < 0)
        throw(GradeTooHighException());
    else if (this->_signedGrade > 150)
        throw(GradeTooLowException());
}   

Form::Form(Form const& cpy) : _signedGrade(cpy._signedGrade), 
_executeGrade(cpy._executeGrade), _isSigned(cpy._isSigned)
{
    *this = cpy;
}

//operator
Form const& Form::operator=(Form const &other)
{
    if(this != &other)
    {
        this->_isSigned = other._isSigned;
        this->_isSigned = other._executeGrade;
        this->_isSigned = other._signedGrade;
    }
    return(*this);
}

std::ostream& operator<<(std::ostream& buffer, Form const& src)
{
    std::cout << "Type of contract : " << src.getName() << std::endl;
    std::cout << "The grade minimum to sign form is " << src.getexecuteGrade() << std::endl;
    return(buffer);
}

//getter
std::string Form::getName() const
{
    return(this->_name);
}

int Form::getSignedGrade() const
{
    return(this->_signedGrade);
}

int Form::getexecuteGrade() const
{
    return(this->_executeGrade);
}

int Form::getIsSigned() const
{
    return(this->_isSigned);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->_signedGrade)
    {
        std::cout << "Form is signed !" << std::endl;
        this->_isSigned = 1;
    }
    else
        std::cout << "Form couldn't be signed, because the grade is not high enough" << std::endl;
}

// exceptions implementation
const char *Form::GradeTooHighException::what() const throw()
{
    return("* Grade is too high *");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return("* Grade is too low *");
}
