#include "../Includes/AForm.hpp"

AForm::AForm() : _name("workContract"), _signedGrade(0),
_executeGrade(150), _isSigned(0)
{

}

AForm::~AForm() {}

AForm::AForm(std::string const name, int AFormBool, int signedGrade, int executeGrade)  : _name(name),
_signedGrade(signedGrade), _executeGrade(executeGrade),_isSigned(AFormBool)
{
    if (this->_signedGrade < 0)
        throw(GradeTooHighException());
    else if (this->_signedGrade > 150)
        throw(GradeTooLowException());
}

AForm::AForm(AForm const& cpy) : _signedGrade(cpy._signedGrade), 
_executeGrade(cpy._executeGrade), _isSigned(cpy._isSigned)
{
    *this = cpy;
}


//operator
AForm const& AForm::operator=(AForm const &other)
{
    if(this != &other)
    {
        this->_isSigned = other._isSigned;
        this->_isSigned = other._executeGrade;
        this->_isSigned = other._signedGrade;
    }
    return(*this);
}

std::ostream& operator<<(std::ostream& buffer, AForm const& src)
{
    std::cout << "Type of contract : " << src.getName() << std::endl;
    std::cout << "Grade value : " << src.getexecuteGrade() << std::endl;
    std::cout << "Is the contract signed ? yes 1 no 0: " << src.getIsSigned();
    return(buffer);
}

//getter
std::string AForm::getName() const
{
    return(this->_name);
}

int AForm::getSignedGrade() const
{
    return(this->_signedGrade);
}

int AForm::getexecuteGrade() const
{
    return(this->_executeGrade);
}

int AForm::getIsSigned() const
{
    return(this->_isSigned);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if(bureaucrat.getGrade() <= this->_signedGrade)
        this->_isSigned = 1;
    else
        std::cout << "Contract couldn't be signed, because the grade is not high enough" << std::endl;
}

// exceptions implementation
const char *AForm::GradeTooHighException::what() const throw()
{
    return("* Grade is too high *");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return("* Grade is too low *");
}

const char *AForm::FormNotSigned::what() const throw()
{
    return("* Form is not signed ! *");
}
const char *AForm::CannotExecuteForm::what() const throw()
{
    return("* Contract cannot be executed ! *");
}

