#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class Bureaucrat;


class ShrubberyCreationForm : public AForm{
    private:
        const std::string _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& copy);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
        ~ShrubberyCreationForm();

        virtual void execute(Bureaucrat const& executor) const;
};

#endif