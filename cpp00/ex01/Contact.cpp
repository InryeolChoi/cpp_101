#include "Contact.hpp"

std::string	Contact::get_fname() {
	return (this->first_name);
}

std::string	Contact::get_lname() {
	return (this->last_name);
}

std::string Contact::get_nickname() {
	return (this->nickname);
}

std::string Contact::get_pnum() {
	return (this->phone_number);
}

std::string Contact::get_secret() {
	return (this->darkest_secret);
}

void	Contact::set_fname(void)
{
	int			n;
	std::string str;

	std::cin >> n;
	getline(std::cin, str);
	std::cin.ignore();
	this->first_name = str;
}

void	Contact::set_lname(void)
{
	int			n;
	std::string str;

	std::cin >> n;
	getline(std::cin, str);
	std::cin.ignore();
	this->last_name = str;
}

void	Contact::set_nickname(void)
{
	int			n;
	std::string str;

	std::cin >> n;
	getline(std::cin, str);
	std::cin.ignore();
	this->nickname = str;
}

void	Contact::set_pnum(void)
{
	int			n;
	std::string str;

	std::cin >> n;
	getline(std::cin, str);
	std::cin.ignore();
	this->phone_number = str;
}

void	Contact::set_secret(void)
{
	int			n;
	std::string str;

	std::cin >> n;
	getline(std::cin, str);
	std::cin.ignore();
	this->darkest_secret = str;
}
