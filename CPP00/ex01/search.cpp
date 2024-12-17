#include "PhoneBook.hpp"

std::string ft_strtrim(std::string str, size_t width)
{
	if(str.length() > width)
		return (str.substr(0, width) + ".");
	else
		return (str);
}

void PhoneBook::SEARCH(void)
{
        std::cout << std::setw(10) << CYAN << "Index" << "|"
                  << std::setw(10) << "First Name" << "|"
                  << std::setw(10) << "Last Name" << "|"
                  << std::setw(10) << "Nickname" << RESET << std::endl;

	for(int i = 0; i < count; i++)
	{
		std::cout << std::setw(10) << i << CYAN << "|" << RESET;
		std::cout << std::setw(10) << ft_strtrim(person[i].getName(), 10) << CYAN << "|" << RESET;
		std::cout << std::setw(10) << ft_strtrim(person[i].getSurname(), 10) << CYAN << "|" << RESET;
		std::cout << std::setw(10) << ft_strtrim(person[i].getNick(), 10) << CYAN << "|" << std::endl;
	}

	int index;

	std::cout << "Please select an index for detailed information> ";
	std::cin >> index;

	while(!std::cin.fail() && count && (index < 0 || index >= count))
	{
		std::cout << "Invalid index, please try again> ";
		std::cin >> index;
	}

	std::cout << "First Name: " << person[index].getName() << std::endl;
	std::cout << "Last Name: " << person[index].getSurname() << std::endl;
	std::cout << "Nickname: " << person[index].getNick() << std::endl;
	std::cout << "Phone Number: " << person[index].getNumber() << std::endl;
	std::cout << "Darkest Secret: " << person[index].getDarkest() << std::endl;
	std::cin.ignore();
}