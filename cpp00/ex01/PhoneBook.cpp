#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : idx(0), size(0) {}

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

void	PhoneBook::TableOfContact()
{
	std::cout << std::endl;
	std::cout << std::setw(10) << "index" << " | ";
	std::cout << std::setw(10) << "first name" << " | ";
	std::cout << std::setw(10) << "last name" << " | ";
	std::cout << std::setw(10) << "nickname" << std::endl;
	for (size_t i = 0; i < size; i++) {
		std::string fname = contacts[i].get_fname();
		std::string lname = contacts[i].get_lname();
		std::string nickname = contacts[i].get_nickname();

		if (fname.length() > 10) {
			fname = fname.substr(0, 9);
			fname += ".";
		}
		if (lname.length() > 10) {
			lname = lname.substr(0, 9);
			lname += ".";
		}
		if (nickname.length() > 10) {
			nickname = nickname.substr(0, 9);
			nickname += ".";
		}
		std::cout << std::setw(10) << i << " | ";
		std::cout << std::setw(10) << fname << " | ";
		std::cout << std::setw(10) << lname << " | ";
		std::cout << std::setw(10) << nickname << std::endl;
	}
	std::cout << std::endl;
}

int	PhoneBook::FindContact()
{
	std::string cmd;

	std::cout << "which one do you want to select? ";
	getline(std::cin, cmd);
	if (cmd.empty() || cmd.find(" ") != std::string::npos || cmd.size() != 1)
	{
		std::cout << "You've typed wrong number" << std::endl;
		std::cout << "================================" << std::endl;
		return (1);
	}
	std::istringstream iss(cmd);
	int index;
	if (!(iss >> index))
	{
		std::cout << "invalid index has come out" << std::endl;
		std::cout << "================================" << std::endl;
		return (1);
	}
	if (index > static_cast<int>(size))
	{
		std::cout << "You've typed wrong number" << std::endl;
		std::cout << "================================" << std::endl;
		return (1);
	}
	std::cout << " first name : " << contacts[index].get_fname() << std::endl;
	std::cout << " last name : " << contacts[index].get_lname() << std::endl;
	std::cout << " nickname : " << contacts[index].get_nickname() << std::endl;
	std::cout << " phone number : " << contacts[index].get_pnum() << std::endl;
	std::cout << " darkest secret : " << contacts[index].get_secret() << std::endl;
	return (0);
}

int	PhoneBook::SearchContact(void)
{
	if (size == 0)
		std::cout << "No contact has been uploaded" << std::endl;
	else
	{
		TableOfContact();
		if (FindContact())
			return (1);
	}
	return (0);
}
