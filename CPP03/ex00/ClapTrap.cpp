#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("ClapTrap"), _hitpoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
	std::cout << "ClapTrap copy assignation operator called" << std::endl;
	_name = copy._name;
	_hitpoints = copy._hitpoints;
	_energyPoints = copy._energyPoints;
	_attackDamage = copy._attackDamage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

//SETTER FUNCTIONS
void ClapTrap::setHitpoints(int hitpoints)
{
	_hitpoints = hitpoints;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
	_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage)
{
	_attackDamage = attackDamage;
}

//GETTER FUNCTIONS
std::string ClapTrap::getName() const
{
	return _name;
}

int ClapTrap::getHitpoints() const
{
	return _hitpoints;
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return _energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const
{
	return _attackDamage;
}

void ClapTrap::attack(const std::string& target)
{
	if(this->getHitpoints() <= 0)
		return;
	
	if(this->getEnergyPoints() < 5)
	{
		std::cout << "ClapTrap " << this->getName() << " has not enough energy points to attack!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(this->getHitpoints() <= 0)
		return;
	
	std::cout << "ClapTrap " << this->getName() << " takes " << amount << " points of damage!" << std::endl;
	this->_hitpoints -= amount;
	if((int)amount > this->getHitpoints())
	{
		std::cout << "ClapTrap " << this->getName() << " is died!" << std::endl;
		this->_hitpoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(this->getHitpoints() <= 0)
		return;

	if(this->getEnergyPoints() <= 0)
	{
		std::cout << "ClapTrap " << this->getName() << " has not enough energy points to repair!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->getName() << " is repaired for " << amount << " points!" << std::endl;
	this->_hitpoints += amount;
	this->_energyPoints--;
}