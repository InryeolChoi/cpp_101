#pragma once
#include <map>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <sstream>
#include <fstream>
#include <string>

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

		// member function : data.csv
		void datamap_init();

		// member function : input.txt
		void input_init();
		void input_match(std::string date, float value);

		// member function : check
		int check_date(std::string date);
		int check_dateOfyear(int year);
		int check_dateOfmonth(int month);
		int check_dateOfday(int year, int month, int day);
		int check_exRt(std::string exRt);
		int check_value(float value, std::string &str);


		// Exception
		class UnavailableToOpen : public std::exception
		{
			const char *what() const throw();
		};
		class NotVaildFile : public std::exception
		{
			const char *what() const throw();
		};
		class BadInput : public std::exception
		{
			const char *what() const throw();
		};
};