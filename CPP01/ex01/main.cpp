#include "Zombie.hpp"

int main()
{
	Zombie	*z1 = zombieHorde(5, "Ahmet");
	Zombie	*z2 = zombieHorde(3, "Hakan");

	for (int i = 0; i < 5; i++)
		z1[i].announce();
	for (int i = 0; i < 3; i++)
		z2[i].announce();
	
	delete[](z1);
	delete[](z2);
}