#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE 

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
	private:
		std::string _name;
		std::string _surname;
		std::string _nick;
		std::string _number;
		std::string _darkest;

	public:
		void setName(std::string name);
		void setSurname(std::string surname);
		void setNick(std::string nick);
		void setNumber(std::string number);
		void setDarkest(std::string darkest);

		std::string getName(void);
		std::string getSurname(void);
		std::string getNick(void);
		std::string getNumber(void);
		std::string getDarkest(void);
};


class PhoneBook
{
	public:
		Contact person[8];
		void ADD();
		void SEARCH();
		int count;
		int i;
};

#endif