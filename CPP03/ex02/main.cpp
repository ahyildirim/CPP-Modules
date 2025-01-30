#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap a("Harvey Specter");
	ScavTrap b("Mike Ross");
	FragTrap c("Jessica Pearson");

	a.attack("Travis Tanner");
	a.beRepaired(10);
	b.attack("Logan Sanders");
	b.takeDamage(10);
	b.guardGate();
	c.attack("Daniel Hardman");
	c.highFivesGuys();
	return 0;
}