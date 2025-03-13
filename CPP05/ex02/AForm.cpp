#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("AForm"), _signGrade(150), _executeGrade(150)
{
    std::cout << "Default AForm Constructor Called" << std::endl;
    this->_isSigned = false;
}

AForm::AForm(const std::string& name, const int signGrade, const int executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
    std::cout << "AForm Name Constructor Called" << std::endl;
    if (signGrade > 150 || executeGrade > 150)
        throw AForm::GradeTooLowException();
    if (signGrade < 1 || executeGrade < 1)
        throw AForm::GradeTooHighException();
    this->_isSigned = false;
}

AForm::AForm(const AForm& copy) : _name(copy._name), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade), _isSigned(copy._isSigned)
{
    std::cout << "AForm Copy Constructor Called" << std::endl;
    *this = copy;
}

AForm& AForm::operator=(const AForm& copy)
{
    std::cout << "AForm Copy Assignation Operator Called" << std::endl;
    if (this != &copy)
        this->_isSigned = copy._isSigned;
    return *this;
}

AForm::~AForm()
{

}

std::string AForm::getName() const
{
    return this->_name;
}

int AForm::getSignGrade() const
{
    return this->_signGrade;
}

int AForm::getExecuteGrade() const
{
    return this->_executeGrade;
}

bool AForm::getIsSigned() const
{
    return this->_isSigned;
}

void AForm::beSigned(Bureaucrat& b)
{
    if (this->getIsSigned())
        throw AForm::AlreadySigned();
    if (b.getGrade() <= this->_signGrade)
        this->_isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade too High!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade too Low!";
}

const char *AForm::AlreadySigned::what() const throw()
{
    return "Form already signed!";
}

const char *AForm::NotSigned::what() const throw()
{
    return "Form is not signed!";
}


std::ostream& operator<<(std::ostream& os, AForm& f)
{
    os << "AForm; " << f.getName() << ", sign grade, " << f.getSignGrade() << " execute grade, " << f.getExecuteGrade() << " sign status, " << f.getIsSigned() << std::endl;
    return os;
}
