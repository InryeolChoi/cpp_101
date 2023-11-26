#include "PhoneBook.hpp"

int main(int ac, char **av)
{
	std::string cmd;
	PhoneBook 	phonebook;

	if (ac != 1)
	{
		(void) av;
		return (1);
	}
	std::cout << "Welcome to World of PhoneBook" << std::endl;
	std::cout << "================================" << std::endl;
	while (std::cin.good())
	{
		std::cout << "type the command" << std::endl;
		std::cout << "(option : ADD, SEARCH, EXIT)" << std::endl;
		std::cout << "cmd > ";
		getline(std::cin, cmd);
		if (!std::cin.good())
		{
			std::cout << std::endl;
			break ;
		}
		if (cmd == "ADD") 
		{
			if (phonebook.AddContact())
			{
				std::cout << "You've typed wrong" << std::endl;
				std::cout << "================================" << std::endl;
				continue ;
			}
		}
		else if (cmd == "SEARCH")
		{
			if (phonebook.SearchContact())
				continue ;
		}
		else if (cmd == "EXIT")
			return (0);
		else
			std::cout << "wrong cmd. Please type again" << std::endl;
		std::cout << "================================" << std::endl;
	}
}
