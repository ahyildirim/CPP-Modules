#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap a("Ahmet");
	ClapTrap b("Mehmet");

	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(10);

	ScavTrap c("Hasan");
	ScavTrap d("Huseyin");

	c.attack(d.getName());
	d.takeDamage(c.getAttackDamage());
	d.beRepaired(10);
	d.guardGate();
	d.guardGate();
	d.guardGate();
	return 0;
}