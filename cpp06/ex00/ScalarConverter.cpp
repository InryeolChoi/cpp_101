#include "ScalarConverter.hpp"

// orthodox canonical form
ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(ScalarConverter const &other): input()
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
	_double = atof(input.c_str());
	type = checkType();
	convertInput();
	printInput();
}

// member function
int ScalarConverter::checkType()
{
	// nan과 +inf, -inf
	if (getInput().compare("+inf") == 0 || getInput().compare("-inf") == 0 ||
		getInput().compare("+inff") == 0 || getInput().compare("-inff") == 0 ||
		getInput().compare("nan") == 0)
		return (NAN_INF);

	// '+', '-', 'f', '.' 거르기
	else if (getInput().length() == 1 && (getInput()[0] == '+' || getInput()[0] == '-' || getInput()[0] == 'f' || getInput()[0] == '.'))
		return (CHAR);

	// '+123+', '-123-' 거르기
	else if (getInput().find_first_of("+-") != getInput().find_last_of("+-"))
		return (ERROR);

	// int
	else if (getInput().find_first_not_of("+-0123456789") == std::string::npos)
		return (INT);

	// double
	else if (getInput().find_first_not_of("+-0123456789.") == std::string::npos)
	{
		if (getInput().find_first_of(".") != getInput().find_last_of("."))
			return (ERROR);
		else if (isdigit(getInput()[getInput().find_first_of(".") + 1]) == false)
			return (ERROR);
		else if (getInput().find_first_of(".") == 0)
			return (ERROR);
		return (DOUBLE);
	}

	// float
	else if (getInput().find_first_not_of("+-0123456789.f") == std::string::npos)
	{
		if (getInput().find_first_of("f") != getInput().find_last_of("f") || 
			getInput().find_first_of(".") != getInput().find_last_of(".") || 
			getInput().find_first_of("f") - getInput().find_last_of(".") == 1)
			return (ERROR);
		else if (getInput().find_first_of(".") == 0)
			return (ERROR);
		else if (getInput()[getInput().find_first_of("f") + 1] != '\0')
			return (ERROR);	
		return (FLOAT);
	}

	// char
	else if ( (getInput().length() == 1 && std::isprint(getInput()[0])) || 
			  (getInput().length() == 1 && std::isalpha(getInput()[0])) )
		return (CHAR);
	
	else
		return (ERROR);
}

// member function
void ScalarConverter::convertInput()
{
	void (ScalarConverter::*convert_fun[])(void) = {&ScalarConverter::convert_char, &ScalarConverter::convert_int, 
													&ScalarConverter::convert_float, &ScalarConverter::convert_double};
	int types[] = {CHAR, INT, FLOAT, DOUBLE};
	int i;

	if (getType() == NAN_INF)
		return ;

	for (i = 0; i < 4; i++) {
		if (getType() == types[i])
		{
			(this->*convert_fun[i])();
			break;
		}
	}
	if (i == 4)
		throw ScalarConverter::TypeError();
}

void ScalarConverter::convert_char()
{
	_char = static_cast<char>(getInput()[0]);
	_double = static_cast<double>(getChar());
	_float = static_cast<float>(getChar());
	_int = static_cast<int>(getChar());
}

void ScalarConverter::convert_int()
{
	_int = static_cast<int>(getDouble());
	_char = static_cast<unsigned char>(getInt());
	_float = static_cast<float>(getFloat());
}

void ScalarConverter::convert_double()
{
	_char = static_cast<char>(getDouble());
	_float = static_cast<float>(getDouble());
	_int = static_cast<int>(getDouble());
}

void ScalarConverter::convert_float()
{
	_float = static_cast<float>(getDouble());
	_char = static_cast<char>(getFloat());
	_int = static_cast<int>(getFloat());
}

// member function
void ScalarConverter::printInput()
{
	// display char
	if (getType() != NAN_INF && getDouble() >= 0 && getDouble() <= UCHAR_MAX)
	{
		if (isprint(getChar()))
			std::cout << "char : '" << getChar() << "'" << std::endl;
		else
			std::cout << "char : Non displayable" << std::endl;
	}
	else
		std::cout << "char : impossible" << std::endl;

	// display int
	if (getType() != NAN_INF && getDouble() >= std::numeric_limits<int>::min() && getDouble() <= std::numeric_limits<int>::max())
		std::cout << "int : " << getInt() << std::endl;
	else
		std::cout << "int : impossible" << std::endl;
	
	// display float
	if (getType() != NAN_INF)
	{
		if (getFloat() - getInt() == 0)
			std::cout << "float : " << getFloat() << ".0f" << std::endl;
		else
			std::cout << "float : " << getFloat() << "f" << std::endl;
	}
	else
	{
		if (getInput() == "nan" || getInput() == "nanf")
			std::cout << "float : nanf" << std::endl;
		else if (getInput()[0] == '+')
			std::cout << "float : +inff" << std::endl;
		else
			std::cout << "float : inff" << std::endl;
	}

	// display double
	if (getType() != NAN_INF)
	{
		if (getDouble() - getInt() == 0 || \
			getDouble() < std::numeric_limits<int>::min() || \
			getDouble() > std::numeric_limits<int>::max())
			std::cout << "double : " << getDouble() << ".0" << std::endl;
		else
			std::cout << "double : " << getDouble() << std::endl;
	}
	else
	{
		if (getInput() == "nan" || getInput() == "nanf")
			std::cout << "double : nan" << std::endl;
		else if (getInput()[0] == '+')
			std::cout << "double : +inf" << std::endl;
		else
			std::cout << "double : -inf" << std::endl;
	}
}


// get() 계열 함수
int ScalarConverter::getType() {
	return (type);
}

std::string ScalarConverter::getInput() {
	return (input);
}

char ScalarConverter::getChar() {
	return (_char);
}

double ScalarConverter::getDouble() {
	return (_double);
}

float ScalarConverter::getFloat() {
	return (_float);
}

int	ScalarConverter::getInt() {
	return (_int);
}

// exception
const char *ScalarConverter::NotEnoughArgs::what() const throw()
{
	return ("You need 1 argument");
}

const char *ScalarConverter::TypeError::what() const throw()
{
	return ("Wrong type");
}
