#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(std::string str) : mathexpr(str)
{
	std::stack<std::string> tmp;
	std::istringstream iss(mathexpr);
	std::string token;

	while (iss >> token)
		tmp.push(token);

	while (!tmp.empty())
	{
		stack.push(tmp.top());
		tmp.pop();
	}
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		mathexpr = other.mathexpr;
		answer = other.answer;
	}
	return *this;
}

RPN::~RPN()
{}

// member function
bool RPN::expr_checkExpr()
{
	// 괄호 제외하기
	if (mathexpr.find_first_of("()") != std::string::npos)
		return (false);

	for (size_t i = 0; i < mathexpr.size(); i++)
	{
		char ch = mathexpr[i];
		if (ch == ' ')
			continue ;
		if (!std::isdigit(ch) && ch != '+' && ch != '-'
			&& ch != '/' && ch != '*')
		return (false);
	}
	return (true);
}

bool RPN::expr_checkStack()
{
	std::stack<std::string> tmp = stack;

	while (!tmp.empty())
	{
		std::string element = tmp.top();

		// 0 ~ 9 사이 숫자, 복합연산자 제외
		if (element.length() != 1)
			return false;

		// float, double, 음수 제외하기
		if (element.find_first_of("0123456789") != std::string::npos)
		{
			if (element.find_first_of("-.f") != std::string::npos)
				return false;
		}

		// 원소 뽑기
		tmp.pop();
	}
	return true;
}

void RPN::expr_calculate()
{
	while (!stack.empty())
	{
		std::string element = stack.top();
		stack.pop();
		if (element.find_first_of("0123456789") != std::string::npos)
			answer.push(std::atoi(element.c_str()));
		else
		{
			if (answer.size() < 2)
				throw RPN::WrongExpr();
			int y = answer.top();
			answer.pop();
			int x = answer.top();
			answer.pop();
			answer.push(expr_operate(element, x, y));
		}
	}

	std::cout << answer.top() << std::endl;
}

int	RPN::expr_operate(std::string &op, int a, int b)
{
	int result;

	if (op == "+")
		result = a + b;
	else if (op == "-")
		result = a - b;
	else if (op == "*")
		result = a * b;
	if (op == "/")
	{
		if (b == 0)
			throw RPN::WrongExpr();
		else
			result = a / b;
	}
	return (result);
}

// exception
const char *RPN::WrongInput::what() const throw()
{
	return ("Error");
}

const char *RPN::WrongExpr::what() const throw()
{
	return ("Error");
}
