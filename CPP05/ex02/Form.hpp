#ifndef FORM_HPP
#define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class Form{

    private:
        const std::string _name;
        const int _signGrade;
        const int _executeGrade;
        bool _isSigned;
    public:
        Form();
        Form(const std::string& name, const int signGrade, const int executeGrade);
        Form(const Form& copy);
        Form& operator=(const Form& copy);
        ~Form();

        std::string getName();
        int getSignGrade();
        int getExecuteGrade();
        bool getIsSigned();

        void beSigned(Bureaucrat& b);
    
        class GradeTooHighException : public std::exception{
            public:
            virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
            virtual const char *what() const throw();
        };
    };

    std::ostream& operator<<(std::ostream& os, Form& f);
    
#endif