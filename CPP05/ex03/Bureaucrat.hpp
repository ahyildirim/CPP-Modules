#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class AForm;

class Bureaucrat{

    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat& operator=(const Bureaucrat& copy);
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;
        void increaseGrade();
        void decraseGrade();
        void signAForm(AForm& AForm);
        void executeForm(AForm const& form);
        
        class GradeTooHighException : public std::exception{
            public:
            virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
            virtual const char *what() const throw();
        };
        
    };
    
    
    std::ostream& operator<<(std::ostream& os, Bureaucrat& b);

#endif