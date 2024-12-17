#include "Zombie.hpp"

Zombie::Zombie()
{
	
}

void Zombie::setName(std::string name)
{
	this->_name = name;
}

std::string Zombie::getName(void)
{
	return this->_name;
}

Zombie::~Zombie(void)
{
	std::cout << getName() << " has destroyed." << std::endl;
}

void Zombie::announce(void)
{
	std::cout << getName() << " BraiiiiiiinnnzzzZ..." << std::endl;
}
