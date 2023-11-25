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

int	Contact::set_fname(void)
{
	std::string str;

	getline(std::cin, str);
	this->first_name = str;
	return (0);
}

int	Contact::set_lname(void)
{
	std::string str;

	getline(std::cin, str);
	this->last_name = str;
	return (0);
}

int	Contact::set_nickname(void)
{
	std::string str;

	getline(std::cin, str);
	this->nickname = str;
	return (0);
}

int	Contact::set_pnum(void)
{
	std::string str;

	getline(std::cin, str);
	this->phone_number = str;
	return (0);
}

int	Contact::set_secret(void)
{
	std::string str;

	getline(std::cin, str);
	this->darkest_secret = str;
	return (0);
}
