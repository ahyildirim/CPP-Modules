#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("Dexter Morgan");
	ClapTrap b("James Doakes");
	ClapTrap c("Lila West");
	ClapTrap d(b);

	a.setAttackDamage(5);
	b.setAttackDamage(5);
	c.setAttackDamage(5);
	d.setAttackDamage(5);

	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(10);
	d.attack(a.getName());
	a.takeDamage(d.getAttackDamage());
	a.beRepaired(10);
	for(int i = 0; i < 10; i++)
		c.attack(b.getName());
	b.takeDamage(100);
	return 0;
}