#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = copy;
}

Dog& Dog::operator=(const Dog& copy)
{
	std::cout << "Dog copy assignation operator called" << std::endl;
	if (this != &copy)
	{
		this->_type = copy._type;
		this->_brain = new Brain(*copy._brain);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

void Dog::makeSound() const 
{
	std::cout << "Woof Woof!" << std::endl;
}

void Dog::setIdea(int i, std::string idea)
{
	_brain->setIdea(i, idea);
}

void Dog::getIdeas() const
{
	for (int i = 0; i < 100; i++)
		std::cout << "IDEA i: " <<_brain->getIdea(i) << std::endl;
}