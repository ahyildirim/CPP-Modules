#ifndef AForm_HPP
#define AForm_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class AForm{

    private:
        const std::string _name;
        const int _signGrade;
        const int _executeGrade;
        bool _isSigned;
    public:
        AForm();
        AForm(const std::string& name, const int signGrade, const int executeGrade);
        AForm(const AForm& copy);
        AForm& operator=(const AForm& copy);
        virtual ~AForm();

        std::string getName() const;
        int getSignGrade() const;
        int getExecuteGrade() const;
        bool getIsSigned() const;

        void beSigned(Bureaucrat& b);

        virtual void execute(Bureaucrat const & executor) const = 0; 
    
        class GradeTooHighException : public std::exception{
            public:
            virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
            virtual const char *what() const throw();
        };
        class AlreadySigned : public std::exception{
            public:
            virtual const char *what() const throw();
        };
        class NotSigned : public std::exception{
            public:
            virtual const char *what() const throw();
        };
    };

    std::ostream& operator<<(std::ostream& os, AForm& f);
    
#endif