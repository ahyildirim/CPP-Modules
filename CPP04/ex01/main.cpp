#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal *animal[10];
	for (int i = 0; i < 10; ++i)
	{
		if (i % 2 == 0)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}

	for (int i = 0; i < 10; ++i)
	{
		std::cout << "Animal " << i << " is a " << animal[i]->getType() << std::endl;
		animal[i]->makeSound();
		std::cout << std::endl;
	}

	for (int i = 0; i < 10; ++i)
		delete animal[i];

	Dog *dog1 = new Dog();

	dog1->setIdea(0, "I am a dog");
	dog1->setIdea(5, "I love bones");
	dog1->setIdea(10, "I am a good boy");
	dog1->setIdea(99, "My name is Brian");

	Dog *dog2 = new Dog(*dog1);

	std::cout << "Dog 1 ideas:" << std::endl;
	dog1->getIdeas();

	std::cout << "Dog 2 ideas:" << std::endl;
	dog2->setIdea(5, "I hate bones");
	dog2->getIdeas();
	std::cout << "------------NEW DOG1 IDEAS--------------" << std::endl;
	dog1->getIdeas();
	delete dog1;
	delete dog2;

	Dog *a = new Dog();
	Dog *b(a);

	std::cout << "-----------DOG A IDEAS--------------" << std::endl;
	a->setIdea(2, "Ahmet");
	a->getIdeas();
	std::cout << "-----------DOG B IDEAS--------------" << std::endl;
	b->setIdea(2, "Hakan");
	b->getIdeas();
	std::cout << "-----------NEW DOG A IDEAS--------------" << std::endl;
	a->getIdeas();

	delete b;

	return 0;
}