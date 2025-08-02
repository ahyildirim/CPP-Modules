#include "iter.hpp"

void printInt(const int& n) {
	std::cout << n << " ";
}

void printString(const std::string& str) {
	std::cout << str << " ";
}

void doubleInt(int& n) {
	n *= 2;
}

void yell(std::string& str) {
	for (size_t i = 0; i < str.length(); ++i) {
		str[i] = toupper(str[i]);
	}
}

int main()
{
	int intArray[] = {1, 2, 3, 4, 5};
	std::string strings[] = {"Ahmet", "Hakan", "Yıldırım"};

	std::cout << "Original int array: ";
	iter(intArray, 5, printInt);
	std::cout << std::endl;

	iter(intArray, 5, doubleInt);
	std::cout << "Doubled int array: ";
	iter(intArray, 5, printInt);
	std::cout << std::endl;

	std::cout << "Original string array: ";
	iter(strings, 3, printString);
	std::cout << std::endl;

	iter(strings, 3, yell);
	std::cout << "Yelled string array: ";
	iter(strings, 3, printString);

	return 0;
}