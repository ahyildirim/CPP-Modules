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
    return "There is no Form"
}

AForm *Intern::makeForm(const std::string name, const std::string target)
{
    int i = -1;
    const std::string nameList[3] = {"PresidentialPardonForm", "ShrubberyCreationForm", "RobotomyRequestForm"};
    AForm *form;

    while (++i < 3)
        if (!nameList[i].compare(name))
            break;
    
    std::cout << "i: " << i << std::endl; //Debug;
    switch(i)
    {
        case 0:
            form = new PresidentialPardonForm(target);
        case 1:
            form = new ShrubberyCreationForm(target);
        case 2:
            form = new RobotomyRequestForm(target);
        default:
            
    }
}

