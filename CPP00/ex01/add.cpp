#include "PhoneBook.hpp"

int ft_isnumeric(std::string str)
{
	for(size_t i = 0; i < str.length(); i++)
	{
		if(!isdigit(str[i]))
			return(0);
	}
	return(1);
}

void PhoneBook::ADD(void)
{
	std::string input;
	std::cout << CYAN << "Name> " << RESET;
	std::getline(std::cin, input);
	while(input.empty())
	{
		std::cout << RED << "Name cannot be empty!" << RESET << std::endl << CYAN << "Name> " << RESET;
		std::getline(std::cin, input);
	}
	person[i].setName(input);
	std::cout << CYAN << "Surname> " << RESET;
	std::getline(std::cin, input);
	while(input.empty())
	{
		std::cout << RED << "Surname cannot be empty!" << RESET << std::endl << CYAN << "Surname> " << RESET;
		std::getline(std::cin, input);
	}
	person[i].setSurname(input);
	std::cout << CYAN << "Nickname> " << RESET;
	std::getline(std::cin, input);
	while(input.empty())
	{
		std::cout << RED << "Nickname cannot be empty!" << RESET << std::endl << CYAN << "Nickname> " << RESET;
		std::getline(std::cin, input);
	}
	person[i].setNick(input);
	std::cout << CYAN << "Number> " << RESET;
	std::getline(std::cin, input);
	while (input.empty() || !ft_isnumeric(input))
	{
		if (input.empty())
			std::cout << RED << "Phone Number cannot be empty!" << RESET << std::endl;
		else if (!ft_isnumeric(input))
			std::cout << RED << "Phone Number must be a number!" << RESET<< std::endl;
		std::cout << CYAN << "Phone Number> " << RESET;
		std::getline(std::cin, input);
	}
	person[i].setNumber(input);
	std::cout << CYAN << "Darkest Secret> " << RESET;
	std::getline(std::cin, input);
	while(input.empty())
	{
		std::cout << RED << "Darkest Secret cannot be empty!" << RESET << std::endl << CYAN << "Darkest Secret> " << RESET;
		std::getline(std::cin, input);
	}
	person[i].setDarkest(input);
	i++;
	i %= 8;
	if(count < 8)
		count++;
}