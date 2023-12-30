#pragma once
#include <iostream>
#include <cstdlib>
#include <limits>
#include <sstream>
#include <fstream>
#include <string>
#include <map>

class BitcoinExchange
{
	private:
		std::ifstream data;
		std::ifstream input;
		std::map<std::string, float> data_map;
		BitcoinExchange();

	public:
		BitcoinExchange(std::string filename);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		// member function
		void datamap_init();
		void input_init();
		int input_checkdate(std::string date);
		int input_checkvalue(float value);
		int input_checkday(int year, int month, int day);
		void input_match();

		// Exception
		class UnavailableToOpen : public std::exception
		{
			const char *what() const throw();
		};
		class NotVaildFile : public std::exception
		{
			const char *what() const throw();
		};
};