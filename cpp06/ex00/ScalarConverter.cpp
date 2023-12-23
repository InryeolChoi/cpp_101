#include "ScalarConverter.hpp"

// orthodox canonical form
ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	if (this != &other) {}
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
	if (this != &other) {}
	return (*this);
}

ScalarConverter::~ScalarConverter()
{}

// constructor overload
ScalarConverter::ScalarConverter(std::string str) : input(str)
{
	_double = atof(this->input.c_str());
}


// exception
const char *ScalarConverter::NotEnoughArgs::what() const throw()
{
	return ("You need 1 argument");
}