# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <cstdlib>
# include <ctime>

Base* generate()
{
	int r = std::rand() % 3;
	switch (r)
	{
		case 0:
			return new A();
			break;
		case 1:
			return new B();
			break;
		case 2:
			return new C();
			break;
		default:
			std::cerr << "Error: Invalid random number generated." << std::endl;
			return NULL;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a; // Kullanılmadı uyarısını engelle
		std::cout << "A" << std::endl;
		return;
	} catch (...) {}

	try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return;
	} catch (...) {}

	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return;
	} catch (...) {}

	std::cout << "Unknown type" << std::endl;
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(0))); // Rastgele sayı üreteci için tohumlama

	Base* basePtr = generate();
	if (basePtr)
	{
		std::cout << "Using pointer:" << std::endl;
		identify(basePtr);
		delete basePtr;
	}

	Base& baseRef = *generate();
	std::cout << "Using reference:" << std::endl;
	identify(baseRef);
	delete &baseRef;

	return 0;
}
