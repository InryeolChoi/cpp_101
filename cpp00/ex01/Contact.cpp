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

void	Contact::setContact()
{
	std::cout << "first name : ";
	std::cin >> this->first_name;
	std::cout << "last name : ";
	std::cin >> this->last_name;
	std::cout << "nickname : ";
	std::cin >> this->nickname;
	std::cout << "phone number : ";
	std::cin >> this->phone_number;
	std::cout << "darkest secret : ";
	std::cin >> this->darkest_secret;
}