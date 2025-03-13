#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Form"), _signGrade(150), _executeGrade(150)
{
    std::cout << "Default Form Constructor Called" << std::endl;
    this->_isSigned = false;
}

Form::Form(const std::string& name, const int signGrade, const int executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
    std::cout << "Form Name Constructor Called" << std::endl;
    if (signGrade > 150 || executeGrade > 150)
        throw Form::GradeTooLowException();
    if (signGrade < 1 || executeGrade < 1)
        throw Form::GradeTooHighException();
    this->_isSigned = false;
}

Form::Form(const Form& copy) : _name(copy._name), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade), _isSigned(copy._isSigned)
{
    std::cout << "Form Copy Constructor Called" << std::endl;
    *this = copy;
}

Form& Form::operator=(const Form& copy)
{
    std::cout << "Form Copy Assignation Operator Called" << std::endl;
    if (this != &copy)
        this->_isSigned = copy._isSigned;
    return *this;
}

Form::~Form()
{

}

std::string Form::getName()
{
    return this->_name;
}

int Form::getSignGrade()
{
    return this->_signGrade;
}

int Form::getExecuteGrade()
{
    return this->_executeGrade;
}

bool Form::getIsSigned()
{
    return this->_isSigned;
}

void Form::beSigned(Bureaucrat& b)
{
    if (this->getIsSigned())
        throw Form::AlreadySigned();
    if (b.getGrade() <= this->_signGrade)
        this->_isSigned = true;
    else
        throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade too High!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade too Low!";
}

const char *Form::AlreadySigned::what() const throw()
{
    return "Form already signed!";
}

std::ostream& operator<<(std::ostream& os, Form& f)
{
    os << "Form; " << f.getName() << ", sign grade, " << f.getSignGrade() << " execute grade, " << f.getExecuteGrade() << " sign status, " << f.getIsSigned() << std::endl;
    return os;
}
