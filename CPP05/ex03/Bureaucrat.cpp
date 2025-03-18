#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(150)
{
    std::cout << "Default Bureaucrat Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
    std::cout << "Bureaucrat Name Constructor Called" << std::endl;
    if (grade > 150)
        throw GradeTooLowException();
    if (grade < 1)
        throw GradeTooHighException();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
    std::cout << "Bureaucrat Copy Constructor Called" << std::endl;
    *this = copy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
    std::cout << "Bureaucrat Copy Assignation Operator Called" << std::endl;
    if (this != &copy)
        this->_grade = copy._grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat Destructor Called" << std::endl;
}

std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::increaseGrade()
{
    this->_grade--;
    if (this->_grade < 1)
        throw GradeTooHighException();
}

void Bureaucrat::decraseGrade()
{
    this->_grade++;
    if (this->_grade > 150)
        throw GradeTooLowException();
}

void Bureaucrat::signAForm(AForm& AForm)
{
    try{
        AForm.beSigned(*this);
        std::cout << this->getName() << " signed " <<  AForm.getName() << std::endl;
    }
    catch(const std::exception& e){
        std::cerr << this->getName() << " couldn't sign " << AForm.getName() << " because " << e.what() << std::endl;
    }   
}

void Bureaucrat::executeForm(AForm const& form)
{
    try{
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch(const std::exception& e){
        std::cerr << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
    
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too High!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too Low!";
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}