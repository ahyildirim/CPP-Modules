#include "WrongDog.hpp"

WrongDog::WrongDog() : WrongAnimal("Wrong Dog")
{
	std::cout << "Wrong Dog default constructor called" << std::endl;
}

WrongDog::WrongDog(const WrongDog& copy) : WrongAnimal(copy)
{
	std::cout << "Wrong Dog copy constructor called" << std::endl;
	*this = copy;
}

WrongDog& WrongDog::operator=(const WrongDog& copy)
{
	std::cout << "Wrong Dog copy assignation operator called" << std::endl;
	this->_type = copy._type;
	return *this;
}

WrongDog::~WrongDog()
{
	std::cout << "Wrong Dog destructor called" << std::endl;
}

void WrongDog::makeSound() const
{
	std::cout << "Woof Woof!" << std::endl;
}