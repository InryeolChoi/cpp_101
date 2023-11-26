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

int	Contact::check_str(std::string str, int check)
{
	if (str.empty() || str.find(" ") != std::string::npos)
		return (1);
	for (size_t x = 0; x < str.length(); x++) {
		if (str[x] < 32 || str[x] > 126)
			return (1);
	}
	(void) check;
	return (0);
}

int	Contact::check_str(std::string str)
{
	if (str.empty() || str.find(" ") != std::string::npos)
		return (1);
	for (size_t x = 0; x < str.length(); x++) {
		if (str[x] < 32 || str[x] > 126)
			return (1);
	}
	return (0);
}

int	Contact::set_fname(void)
{
	std::string str;

	std::cout << "first name : ";
	getline(std::cin, str);
	if (check_str(str, SUBSTR))
		return (1);
	this->first_name = str;
	return (0);
}

int	Contact::set_lname(void)
{
	std::string str;

	std::cout << "last name : ";
	getline(std::cin, str);
	if (check_str(str, SUBSTR))
		return (1);
	this->last_name = str;
	return (0);
}

int	Contact::set_nickname(void)
{
	std::string str;

	std::cout << "nickname : ";
	getline(std::cin, str);
	if (check_str(str, SUBSTR))
		return (1);
	this->nickname = str;
	return (0);
}

int	Contact::set_pnum(void)
{
	std::string str;

	std::cout << "phone number : ";
	getline(std::cin, str);
	if (check_str(str))
		return (1);
	this->phone_number = str;
	return (0);
}

int	Contact::set_secret(void)
{
	std::string str;

	std::cout << "darkest secret : ";
	getline(std::cin, str);
	if (check_str(str))
		return (1);
	this->darkest_secret = str;
	return (0);
}
