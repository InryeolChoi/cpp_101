#include "Phonebook.hpp"

void	PhoneBook::AddContact(void)
{
	std::string str;

	if (idx > 8)
		idx = 0;
	contacts[idx++].setContact();
}

void	PhoneBook::SearchContact(void)
{
	for (int i = 0; i < 4; i++) {
		std::cout << contacts[idx].get_fname() << " | ";
		std::cout << contacts[idx].get_lname() << " | ";
		std::cout << contacts[idx].get_nickname() << " | ";
		std::cout << contacts[idx].get_pnum() << " | ";
		std::cout << contacts[idx].get_secret();
		std::cout << std::endl;
	}
}