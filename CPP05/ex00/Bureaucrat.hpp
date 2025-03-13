#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <string>

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

        const std::string getName();
        int getGrade();
        void increaseGrade();
        void decraseGrade();
        
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