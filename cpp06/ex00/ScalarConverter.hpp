#pragma once
#include <iostream>

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter operator=(ScalarConverter const &other);
		~ScalarConverter();
};