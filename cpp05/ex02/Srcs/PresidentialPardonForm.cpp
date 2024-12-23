#include "../Includes/AForm.hpp"
#include "../Includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential form", false, 25, 5) , _target("Presidential form") {}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& cpy) : AForm(cpy)
{
    *this = cpy;
}

PresidentialPardonForm const& PresidentialPardonForm::operator=(PresidentialPardonForm const& other)
{
    if(this != &other)
        this->_target = other._target;
    return(*this);
}

PresidentialPardonForm::PresidentialPardonForm(std::string target, int signedGrade) : AForm("Presidential form", false, signedGrade, 5) , _target(target) {}


void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    if(!this->getIsSigned())
        throw FormNotSigned();
    if (executor.getGrade() > this->getexecuteGrade())
        throw CannotExecuteForm();
    std::cout << "Informs that " << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
