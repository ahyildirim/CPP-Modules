#include "PhoneBook.hpp"

void Contact::setName(std::string name)
{
	_name = name;
}

std::string Contact::getName(void)
{
	return _name;
}
void Contact::setSurname(std::string surname)
{
	_surname = surname;
}

std::string Contact::getSurname(void)
{
	return _surname;
}
void Contact::setNick(std::string nick)
{
	_nick = nick;
}

std::string Contact::getNick(void)
{
	return _nick;
}
void Contact::setNumber(std::string number)
{
	_number = number;
}

std::string Contact::getNumber(void)
{
	return _number;
}
void Contact::setDarkest(std::string darkest)
{
	_darkest = darkest;
}

std::string Contact::getDarkest(void)
{
	return _darkest;
}