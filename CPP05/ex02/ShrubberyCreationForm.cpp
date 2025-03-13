#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{
    std::cout << "Default ShrubberyCreationForm Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm Name Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm("ShrubberyCreationForm", 145, 137)
{
    std::cout << "ShrubberyCreationForm Copy Constructor Called" << std::endl;
    *this = copy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
    std::cout << "ShrubberyCreationForm Copy Assignation Called" << std::endl;
    if (this != &copy)
        this->_target = copy._target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm Destrucotr Called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    if (this->getExecuteGrade() < executor.getGrade())
        throw AForm::GradeTooLowException();
    if (!this->getIsSigned())
        throw AForm::NotSigned();
    std::string name = this->_target + "_shrubbery";
    std::ofstream outFile(name.c_str());
    if (!outFile.is_open())
        std::cout << "An error occured while creating output file" << std::endl;
    outFile << "       _-_        \n";
    outFile << "    /~~   ~~\\     \n";
    outFile << " /~~         ~~\\  \n";
    outFile << "{               }\n";
    outFile << " \\  _-     -_  / \n";
    outFile << "   ~  \\\\ //  ~  \n";
    outFile << " _- -  | | _- _  \n";
    outFile << "   _ - | |   -_  \n";
    outFile << "       | |       \n";
    outFile << "       | |       \n";
    outFile << "______/__ \\______\n";
}