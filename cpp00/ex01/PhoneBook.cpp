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
		return ();
	if (contacts[idx].set_lname())
		return ();
	if (contacts[idx].set_nickname())
		return ();
	if (contacts[idx].set_pnum())
		return ();	
	if (contacts[idx].set_secret())
		return ();
	size++;
	idx++;
}

void	PhoneBook::SearchContact(void)
{
	if (size == 0)
		std::cout << "No contact has been uploaded" << std::endl;
	else
	{
		std::cout << "index | first name | last name | nickname | phone number | secret" << std::endl;
		for (int i = 0; i < size; i++) {
			std::cout << contacts[i].get_fname() << " | ";
			std::cout << contacts[i].get_lname() << " | ";
			std::cout << contacts[i].get_nickname() << " | ";
			std::cout << contacts[i].get_pnum() << " | ";
			std::cout << contacts[i].get_secret() << std::endl;
		}
	}
}
