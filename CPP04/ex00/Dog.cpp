#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = copy;
}

Dog& Dog::operator=(const Dog& copy)
{
	std::cout << "Dog copy assignation operator called" << std::endl;
	this->_type = copy._type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const 
{
	std::cout << "Woof Woof!" << std::endl;
}