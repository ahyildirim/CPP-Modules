#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	setHitpoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	this->_isGuarding = false;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap name constructor called" << std::endl;
	setHitpoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	this->_isGuarding = false;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = copy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
	std::cout << "ScavTrap copy assignation operator called" << std::endl;
	setName(copy.getName());
	setHitpoints(copy.getHitpoints());
	setEnergyPoints(copy.getEnergyPoints());
	setAttackDamage(copy.getAttackDamage());
	this->_isGuarding = copy._isGuarding;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if(this->getHitpoints() <= 0)
		return;
	
	if(this->getEnergyPoints() < 5)
	{
		std::cout << "ScavTrap " << this->getName() << " has not enough energy points to attack!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void ScavTrap::guardGate()
{
	if (this->_isGuarding == true)
	{
		std::cout << "ScavTrap " << getName() << " now out of Gate keeper mode" << std::endl;
		this->_isGuarding = false;
	}
	else
	{
		std::cout << "ScavTrap " << getName() << " has entered in Gate keeper mode" << std::endl;
		this->_isGuarding = true;
	}
}
