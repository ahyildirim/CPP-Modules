#include "Zombie.hpp"

int main()
{
	Zombie zombie("Ahmet");
	Zombie *z;
	zombie.announce();

	z = zombie.newZombie("Hakan");
	z->announce();
	zombie.randomChump("Yildirim");
	delete z;
}