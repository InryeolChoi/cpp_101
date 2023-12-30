#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>

class BitcoinExchange
{
	private:
		fstream csv_file;
		map<std::string, std::string> csv_map;

		fstream txt_file;
		map<std::string, std::string> txt_map;
		BitcoinExchange();

	public:
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		// constructor overload
		BitcoinExchange(std::string filename);

		// Exception
		class NotVaildFile : public std::exception
		{
			const char *what() const throw();
		};
};