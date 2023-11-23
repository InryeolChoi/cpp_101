#include "Phonebook.hpp"

int main(void)
{
	std::string cmd;
	PhoneBook 	phonebook;

	std::cout << "Welcome to World of PhoneBook" << std::endl;
	while (1)
	{
		std::cout << "type the command" << std::endl;
		std::cout << "(option : add, search, exit)" << std::endl;
		std::cout << "cmd > ";
		std::cin >> cmd;

		if (cmd == "add")
			phonebook.AddContact();
		else if (cmd == "search")
			phonebook.SearchContact();
		else if (cmd == "exit")
			return (0);
		else
			std::cout << "wrong cmd. Please type again" << std::endl;
		std::cin.ignore();
	}
}
