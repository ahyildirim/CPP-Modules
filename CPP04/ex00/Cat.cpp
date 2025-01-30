#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
}

Cat& Cat::operator=(const Cat& copy)
{
	std::cout << "Cat copy assignation operator called" << std::endl;
	this->_type = copy._type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow!" << std::endl;
}