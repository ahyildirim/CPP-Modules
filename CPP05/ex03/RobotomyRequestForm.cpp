#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default")
{
    std::cout << "RobotomyRequestForm Default Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm Name Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm("RobotomyRequestForm", 72, 45)
{
    std::cout << "RobotomyRequestForm Copy Constructor Called" << std::endl;
    *this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called." << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
    std::cout << "RobotomyRequestForm Copy Assignation Operator Called" << std::endl;
    if (this != &copy)
        this->_target = copy._target;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    if (this->getExecuteGrade() < executor.getGrade())
        throw AForm::GradeTooLowException();
    if (!this->getIsSigned())
        throw AForm::NotSigned();
    
    std::cout << "Loud Drill Noises..." << std::endl;
    srand(time(NULL));
    int randomNbr = rand() % 2;
    if (randomNbr == 1)
        std::cout << this->_target << " has been robotomized" << std::endl;
    else
        std::cout << "Robotomy failed." << std::endl;
}