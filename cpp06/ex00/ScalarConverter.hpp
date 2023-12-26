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

		// enum
		enum type {
			NAN_INF, ERROR, CHAR, INT, FLOAT, DOUBLE
		};

		// member function
		int checkType();
		void convertInput();
		void convert_char();
		void convert_int();
		void convert_double();
		void convert_float();
		void printInput();

		// member function, get()
		std::string getInput() const;
		int 		getType() const;
		char		getChar() const;
		double		getDouble() const;
		float		getFloat() const;
		int			getInt() const;

	public:
		//orthodox canonical form
		ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter &operator=(ScalarConverter const &other);
		~ScalarConverter();

		// constructor overload
		ScalarConverter(std::string str);

		// exception
		class NotEnoughArgs : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class TypeError : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};