#pragma once
#include <iostream>
#include <cmath>
#include <cstdlib>

class ScalarConverter
{
	private:
		std::string input;
		int			type;
		char		_char;
		double 		_double;
		float 		_float;
		int 		_int;

	public:
		//orthodox canonical form
		ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter &operator=(ScalarConverter const &other);
		~ScalarConverter();

		// constructor overload
		ScalarConverter(std::string str);



		// member function
		void print();


		// exception
		class NotEnoughArgs : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};