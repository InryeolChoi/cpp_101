#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	idx = 0;
	size = 0;
}

int	PhoneBook::AddContact(void)
{
	std::string str;

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
	if (idx < 7)
		idx++;
	else
		idx = 0;
	if (size < 8)
		size++;
	return (0);
}

void	PhoneBook::SearchContact(void)
{
	if (size == 0)
		std::cout << "No contact has been uploaded" << std::endl;
	else
	{
		std::cout << std::endl;
		std::cout << std::setw(10) << "index" << " | ";
		std::cout << std::setw(10) << "first name" << " | ";
		std::cout << std::setw(10) << "last name" << " | ";
		std::cout << std::setw(10) << "nickname" << std::endl;
		for (int i = 0; i < size; i++) {
			std::cout << std::setw(10) << i + 1 << " | ";
			std::cout << std::setw(10) << contacts[i].get_fname() << " | ";
			std::cout << std::setw(10) << contacts[i].get_lname() << " | ";
			std::cout << std::setw(10) << contacts[i].get_nickname() << std::endl;
		}
		std::cout << std::endl;
	}
}
