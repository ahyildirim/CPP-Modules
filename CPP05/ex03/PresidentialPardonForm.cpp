#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Default")
{
    std::cout << "PresidentialPardonForm Default Constructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm Name Constructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm("PresidentialPardonForm", 25, 5)
{
    std::cout << "PresidentialPardonForm Copy Constructor Called" << std::endl;
    *this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
    std::cout << "PresidentialPardonForm Copy Assignation Operator Called" << std::endl;
    if (this != &copy)
        this->_target = copy._target;
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    if (this->getExecuteGrade() < executor.getGrade())
        throw AForm::GradeTooLowException();
    if (!this->getIsSigned())
        throw AForm::NotSigned();
    
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}