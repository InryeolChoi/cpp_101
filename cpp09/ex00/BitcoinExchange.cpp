#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(std::string filename)
{
	data.open("./data.csv");
	input.open(filename.c_str());

	if (!data || !data.is_open())
		throw UnavailableToOpen();	
	if (!input || !input.is_open())
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

// member function : data.csv
void BitcoinExchange::datamap_init()
{
	std::string tmp_line;

	if (std::getline(data, tmp_line).eof())
		throw NotVaildFile();
	if (tmp_line != "date,exchange_rate")
		throw NotVaildFile();
	while (std::getline(data, tmp_line))
	{
		size_t keysize = tmp_line.find(',');
		std::string key = tmp_line.substr(0, keysize);
		std::string value = tmp_line.substr(keysize + 1);

		if (check_date(key))
			throw NotVaildFile();
		else if (check_exRt(value))
			throw NotVaildFile();
		data_map[key] = std::atof(value.c_str());
	}
}

// member function : input.txt
void BitcoinExchange::input_init()
{
	std::string tmp_line;

	if (std::getline(input, tmp_line).eof())
		throw NotVaildFile();

	while (std::getline(input, tmp_line))
	{
		if (tmp_line.find('|') == std::string::npos)
			std::cout << "Error : bad input => " << tmp_line << std::endl;
		else
		{
			std::string date = tmp_line.substr(0, tmp_line.find('|') - 1);
			float value = std::atof(tmp_line.substr(tmp_line.find('|') + 1).c_str());
			
			if (check_date(date) == 1)
				continue ;
			else if (check_value(value) == 1)
				continue ;
			else
				input_match(date, value);
		}
	}
}

void BitcoinExchange::input_match(std::string date, float value)
{
	std::map<std::string, float>::const_iterator iter;
	float result;
	
	iter = data_map.find(date);
	if (iter != data_map.end())
		result = iter->second * value;
	else
	{
		iter = data_map.lower_bound(date); // date보다 큰 값 중 가장 작은 값
		if (iter == data_map.begin())
		{
			std::cout << "Error : invalid date" <<std::endl;
			return ;
		}
		--iter;
		result = iter->second * value;
	}

	std::cout << date << " => ";
	if (value == static_cast<int>(value))
		std::cout << static_cast<int>(value) << " = " << result;
	else
		std::cout << value << " = " << result;
	std::cout << std::endl;
}


// member function : check
int BitcoinExchange::check_date(std::string date)
{
	std::istringstream ss(date);
	int year, month, day, idx = 0;
	std::string str;

	while (std::getline(ss, str, '-'))
	{
		if (idx == 0)
		{
			std::istringstream(str) >> year;
			if (check_dateOfyear(year)) return 1;
		}
		else if (idx == 1)
		{
			std::istringstream(str) >> month;
			if (check_dateOfmonth(month)) return 1;
		}
		else if (idx == 2)
		{
			std::istringstream(str) >> day;
			if (check_dateOfday(year, month, day)) return 1;
		}
		idx++;
	}
	return 0;
}

int BitcoinExchange::check_dateOfyear(int year)
{
	if (year < 1000 || year > 9999)
	{
		std::cout << "Error : bad input" << std::endl;
		return 1;
	}
	return 0;
}

int BitcoinExchange::check_dateOfmonth(int month)
{
	if (month < 1 || month > 12)
	{
		std::cout << "Error : bad input" << std::endl;
		return 1;
	}
	return 0;
}

int BitcoinExchange::check_dateOfday(int year, int month, int day)
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

int BitcoinExchange::check_exRt(std::string exRt)
{
	char *ptr = NULL;

	// double로 변환 시도
	double value = std::strtod(exRt.c_str(), &ptr);
	if (value == 0.0 && !std::isdigit(exRt[0]))
		return 1;
	
	// ptr이 null이 아닌 경우 문자 포함 간주
	if (*ptr && std::strcmp(ptr, "f"))
		return 1;
	
	// 음수면 실패로 간주 
	if (value < 0)
		return 1;
	return 0;
}

int BitcoinExchange::check_value(float value)
{
	if (value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return 1;
	}
	else if (value >= static_cast<float>(std::numeric_limits<int>::max()))
	{
		std::cout << "Error: too large a number" << std::endl;
		return 1;
	}	
	else
		return 0;
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