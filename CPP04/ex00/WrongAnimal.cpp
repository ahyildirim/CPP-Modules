#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("randomWrongAnimal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	std::cout << "Wrong Animal type constructor called" << std::endl;
	this->_type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	std::cout << "Wrong Animal copy constructor called" << std::endl;
	*this = copy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy)
{
	std::cout << "Wrong Animal copy assignation operator called" << std::endl;
	this->_type = copy._type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Animal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->_type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Wrong Random Animal makes a sound" << std::endl;
}