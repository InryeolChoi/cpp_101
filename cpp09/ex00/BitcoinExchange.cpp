#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(std::string filename)
{
	data.open("./data.csv");
	input.open(filename.c_str());

	if (!data || !data.is_open() || !input || !input.is_open())
		throw UnavailableToOpen();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other) {}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	data.close();
	input.close();
}

// member function
void BitcoinExchange::datamap_init()
{
	std::string tmp_line;

	if (std::getline(input, tmp_line).eof())
		throw NotVaildFile();

	while (std::getline(data, tmp_line))
	{
		if (tmp_line.compare("date,exchange_rate") == 0)
			continue ;
		size_t keysize = tmp_line.find(',');
		std::string key = tmp_line.substr(0, keysize);
		float value = std::atof(tmp_line.substr(keysize + 1).c_str());
		data_map[key] = value;
	}
}

void BitcoinExchange::input_init()
{
	std::string tmp_line;

	if (std::getline(input, tmp_line).eof())
		throw NotVaildFile();

	while (std::getline(data, tmp_line))
	{
		if (tmp_line.compare("data | value") == 0)
			continue ;
		else if (tmp_line.find('|') == std::string::npos)
			std::cout << "Error : bad input =>" << tmp_line << std::endl;
		else
		{
			std::string date = tmp_line.substr(0, tmp_line.find('|') - 1);
			float value = std::atof(tmp_line.substr(tmp_line.find('|') + 1).c_str());
			
			if (input_checkdate(date) == 1)
				continue ;
			else if (input_checkvalue(value) == 1)
				continue ;
			else
				input_match();
		}
	}
}

int BitcoinExchange::input_checkdate(std::string date)
{
	std::istringstream ss(date);
	std::string str;
	int year, month, day;
	int idx = 0;

	while (std::getline(ss, str, '-'))
	{
		if (idx == 0) 
		{
			std::istringstream(str) >> year;
			if (year < 1000 || year > 9999)
			{
				std::cout << "Error : bad input" << std::endl;
				return 1;
			}
		}
		else if (idx == 1) 
		{
			std::istringstream(str) >> month;
			if (month < 1 || month > 12)
			{
				std::cout << "Error : bad input" << std::endl;
				return 1;
			}
		}
		else if (idx == 2)
		{
			std::istringstream(str) >> day;
			if (input_checkday(year, month, day))
				return 1;
		}
	}
	return 0;
}

int BitcoinExchange::input_checkday(int year, int month, int day)
{
	if (day < 1 || day > 31)
	{
		std::cout << "Error : bad input" << std::endl;
		return 1;
	}
	
	// 존재하지 않는 달
	if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
	{
		std::cout << "Error : incorrect days" << std::endl;
		return 1;
	}

	// 윤년 계산
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
	{
		if (day > 29 && month == 2)
		{
			std::cout << "Error : incorrect days" << std::endl;
			return 1;
		}

	}
	else if (day > 28 && month == 2)
	{
		std::cout << "Error : incorrect days" << std::endl;
		return 1;		
	}
	return 0;
}

int BitcoinExchange::input_checkvalue(float value)
{
	if (value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (1);
	}
	else if (value >= static_cast<float>(std::numeric_limits<int>::max()))
	{
		std::cout << "Error: too large a number" << std::endl;
		return (1);
	}	
	else
		return (0);
}


void BitcoinExchange::input_match()
{
	
}


// Exception
const char *BitcoinExchange::UnavailableToOpen::what() const throw()
{
	return ("Error : could not open file.");
}
const char *BitcoinExchange::NotVaildFile::what() const throw()
{
	return ("Error : not a valid file.");
}