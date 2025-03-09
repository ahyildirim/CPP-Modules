#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("randomAAnimal")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type)
{
	std::cout << "AAnimal type constructor called" << std::endl;
	this->_type = type;
}

AAnimal::AAnimal(const AAnimal& copy)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = copy;
}

AAnimal& AAnimal::operator=(const AAnimal& copy)
{
	std::cout << "AAnimal copy assignation operator called" << std::endl;
	this->_type = copy._type;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const
{
	return this->_type;
}

void AAnimal::makeSound() const
{
	std::cout << "Random AAnimal makes a sound" << std::endl;
}