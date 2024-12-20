#include "../Includes/AForm.hpp"

AForm::AForm() : _name("workContract"), _grade(0),
_requiredGrade(150), _isSigned(0)
{

}

AForm::~AForm() {}

AForm::AForm(std::string const name, int AFormBool, int signedGrade, int requiredGrade)  : _name(name),
_grade(signedGrade), _requiredGrade(requiredGrade),_isSigned(AFormBool)
{
    if (this->_grade < 0)
        throw(GradeTooHighException());
    else if (this->_grade > this->_requiredGrade)
        throw(GradeTooLowException());
}

AForm::AForm(AForm const& cpy) : _grade(cpy._grade), 
_requiredGrade(cpy._requiredGrade), _isSigned(cpy._isSigned)
{
    *this = cpy;
}


//operator
AForm const& AForm::operator=(AForm const &other)
{
    if(this != &other)
    {
        this->_isSigned = other._isSigned;
        this->_isSigned = other._requiredGrade;
        this->_isSigned = other._grade;
    }
    return(*this);
}

std::ostream& operator<<(std::ostream& buffer, AForm const& src)
{
    std::cout << "Type of contract : " << src.getName() << std::endl;
    std::cout << "Grade value : " << src.getRequiredGrade() << std::endl;
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
    return(this->_grade);
}

int AForm::getRequiredGrade() const
{
    return(this->_requiredGrade);
}

int AForm::getIsSigned() const
{
    return(this->_isSigned);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if(bureaucrat.getGrade() <= this->_requiredGrade && bureaucrat.getGrade() >= 0)
        this->_isSigned = 1;
    else
        throw(AForm::GradeTooLowException());
}

// exceptions implementation
const char *AForm::GradeTooHighException::what() const throw()
{
    return("* Grade is too hight to sign the contract ! *");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return("* Grade is too low to sign the contract ! *");
}
