#include "BitcoinExchange.hpp"

// orthodox canonical form
BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	csv_file.close();
}

// constructor overload
BitcoinExchange::BitcoinExchange(std::string filename)
{
	std::string line, key, value;
	csv_file.open("data.csv", ios::in);

	while (!csv_file.eof())
	{
		std::getline(csv_file, line);	
	}
}

// Exception
const char *BitcoinExchange::NotVaildFile::what() const throw()
{
	return ("Error : could not open file.");
}