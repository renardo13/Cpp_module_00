#include "../Includes/AForm.hpp"
#include "../Includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Mr Jack", false, 150, 10) , _target("Mr Jack") {}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& cpy)
{
    *this = cpy;
}

PresidentialPardonForm const& PresidentialPardonForm::operator=(PresidentialPardonForm const& other)
{
    if(this != &other)
        this->_target = other._target;
    return(*this);
}

PresidentialPardonForm::PresidentialPardonForm(std::string target, int grade) : AForm("Mr Jack", false, 150, grade) , _target(target) {}


void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    if(this->getIsSigned() && executor.getGrade() > this->getRequiredGrade())
    {
        std::cout << "** The form is signed **" << std::endl;
    }
    


}