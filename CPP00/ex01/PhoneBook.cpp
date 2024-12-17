#include "PhoneBook.hpp"

int main()
{
	std::string input;
	PhoneBook p;

	p.i = 0;
	p.count = 0;

	while(1)
	{
		std::cout << RED << "------PHONEBOOK------" << RESET << std::endl;
		std::cout << GREEN << "1." << RESET << "ADD" << std::endl;
		std::cout << GREEN << "2." << RESET << "SEARCH" << std::endl;
		std::cout << GREEN << "3." << RESET << "EXIT" << std::endl;

		if(!std::getline(std::cin, input))
			break;

		if(input.empty())
			continue;
		else if(!input.compare("ADD"))
			p.ADD();
		else if(!input.compare("SEARCH"))
		{
			if(p.count)
				p.SEARCH();
			else
			{
				std::cout << RED << "There is no one on the phone book." << RESET << std::endl;
				continue;
			}
		}
		else if(!input.compare("EXIT"))	
			break;
		else
			std::cout << RED << "Please enter a valid command." << RESET << std::endl;
	}
	return (0);
}
