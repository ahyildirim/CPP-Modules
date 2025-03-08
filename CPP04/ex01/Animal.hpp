#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class Animal
{
	protected:
		std::string _type;

	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal& copy);
		Animal& operator=(const Animal& copy);
		virtual ~Animal();

		std::string getType() const;
		virtual void makeSound() const;
};

#endif