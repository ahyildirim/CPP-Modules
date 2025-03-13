#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm{
    private:
        const std::string _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& copy);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
        ~PresidentialPardonForm();

        virtual void execute(Bureaucrat const& executor) const;
};

#endif