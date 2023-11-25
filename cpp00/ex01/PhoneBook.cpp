#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	idx = 0;
	size = 0;
}

int	PhoneBook::AddContact(void)
{
	std::string str;

	if (idx > 8)
		idx = 0;
	if (contacts[idx].set_fname())
		return (1);
	if (contacts[idx].set_lname())
		return (1);
	if (contacts[idx].set_nickname())
		return (1);
	if (contacts[idx].set_pnum())
		return (1);	
	if (contacts[idx].set_secret())
		return (1);
	size++; idx++;
	return (0);
}

void	PhoneBook::SearchContact(void)
{
	if (size == 0)
		std::cout << "No contact has been uploaded" << std::endl;
	else
	{
		std::cout << std::setw(10) << "index | ";
		std::cout << std::setw(10) << "first name | ";
		std::cout << std::setw(10) << "last name | ";
		std::cout << std::setw(10) << "nickname" << std::endl;
		for (int i = 0; i < size; i++) {
			std::cout << std::setw(10) << i << " | ";
			std::cout << std::setw(10) << contacts[i].get_fname() << " | ";
			std::cout << std::setw(10) << contacts[i].get_lname() << " | ";
			std::cout << std::setw(10) << contacts[i].get_nickname() << std::endl;
		}
	}
}
