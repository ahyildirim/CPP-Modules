#ifndef INTERN_HPP
#define INTERN_HPP

# include <iostream>
# include <string>

class AForm;

class Bureaucrat;

class Intern{
    public:
        Intern();
        Intern(const Intern& copy);
        Intern& operator=(const Intern& copy);
        ~Intern();

        AForm *makeForm(const std::string name, const std::string target);
	
		AForm *createPresidentialPardonForm(const std::string target);
		AForm *createRobotomyRequestForm(const std::string target);
		AForm *createShrubberyCreationForm(const std::string target);

        class NotAFormException : public std::exception{
            public:
            virtual const char *what() const throw();
        };
};

#endif