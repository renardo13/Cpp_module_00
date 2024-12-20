#include "Form.hpp"

Form::Form() : _name("workContract"), _signedGrade(0),
_requiredGrade(150), _isSigned(0)
{

}

Form::~Form() {}

Form::Form(std::string const name, int formBool, int signedGrade, int requiredGrade)  : _name(name),
_signedGrade(signedGrade), _requiredGrade(requiredGrade),_isSigned(formBool)
{
    if (this->_signedGrade < 0)
        throw(GradeTooHighException());
    else if (this->_signedGrade > 150)
        throw(GradeTooLowException());
}   

Form::Form(Form const& cpy) : _signedGrade(cpy._signedGrade), 
_requiredGrade(cpy._requiredGrade), _isSigned(cpy._isSigned)
{
    *this = cpy;
}

//operator
Form const& Form::operator=(Form const &other)
{
    if(this != &other)
    {
        this->_isSigned = other._isSigned;
        this->_isSigned = other._requiredGrade;
        this->_isSigned = other._signedGrade;
    }
    return(*this);
}

std::ostream& operator<<(std::ostream& buffer, Form const& src)
{
    std::cout << "Type of contract : " << src.getName() << std::endl;
    std::cout << "Grade value : " << src.getRequiredGrade() << std::endl;
    std::cout << "Is the contract signed ? yes 1 no 0: " << src.getIsSigned();
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

int Form::getRequiredGrade() const
{
    return(this->_requiredGrade);
}

int Form::getIsSigned() const
{
    return(this->_isSigned);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if(bureaucrat.getGrade() <= this->_requiredGrade && bureaucrat.getGrade() >= 0)
        this->_isSigned = 1;
    else
        throw(Form::GradeTooLowException());
}

// exceptions implementation
const char *Form::GradeTooHighException::what() const throw()
{
    return("* Grade is too hight to sign the contract ! *");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return("* Grade is too low to sign the contract ! *");
}
