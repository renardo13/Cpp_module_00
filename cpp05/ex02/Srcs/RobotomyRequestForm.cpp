#include "../Includes/AForm.hpp"
#include "../Includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy form", false, 72, 45) , _target("Robotomy form") {}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& cpy) : AForm(cpy)
{
    *this = cpy;
}

RobotomyRequestForm const& RobotomyRequestForm::operator=(RobotomyRequestForm const& other)
{
    if(this != &other)
        this->_target = other._target;
    return(*this);
}

RobotomyRequestForm::RobotomyRequestForm(std::string target, int signedGrade) : AForm("Robotomy form", false, signedGrade, 45) , _target(target) {}


void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    if(!this->getIsSigned())
    {
        std::cout << "The robotomy failed" << std::endl;
        throw FormNotSigned();
    }
    if (executor.getGrade() > this->getexecuteGrade())
    {
        std::cout << "The robotomy failed" << std::endl;
        throw CannotExecuteForm();
    }
    std::cout << "** BRRRRRH **" << std::endl;
    std::cout << this->_target << " has been has been robotomized successfully 50% of the time." << std::endl;
}
