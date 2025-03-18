#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called." << std::endl;
}

Intern::Intern(const Intern& copy)
{
    std::cout << "Intern copy constructor called." << std::endl;
    *this = copy;
}

Intern& Intern::operator=(const Intern& copy)
{
    std::cout << "Intern copy assignment operator called." << std::endl;
    if (this != &copy)
        *this = copy;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called." << std::endl;
}

const char* Intern::NotAFormException::what() const throw()
{
    return "There is no Form";
}

AForm *Intern::createShrubberyCreationForm(const std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(const std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(const std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string name, const std::string target)
{
    AForm *(Intern::*forms[])(const std::string) = {
        &Intern::createShrubberyCreationForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm
    };
	std::string formNames[] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
	};
	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return (this->*forms[i])(target);
		}
	}
	throw NotAFormException();
	return NULL;
}

