#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Wrong Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
	std::cout << "Wrong Cat copy constructor called" << std::endl;
	*this = copy;
}

WrongCat& WrongCat::operator=(const WrongCat& copy)
{
	std::cout << "Wrong Cat copy assignation operator called" << std::endl;
	this->_type = copy._type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "Wrong Cat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow Meow!" << std::endl;
}