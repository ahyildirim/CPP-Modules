#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	AAnimal *animal[10];
	for (int i = 0; i < 10; ++i)
	{
		if (i % 2 == 0)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}

	for (int i = 0; i < 10; ++i)
	{
		std::cout << "AAnimal " << i << " is a " << animal[i]->getType() << std::endl;
		animal[i]->makeSound();
		std::cout << std::endl;
	}

	for (int i = 0; i < 10; ++i)
		delete animal[i];

	return 0;
}