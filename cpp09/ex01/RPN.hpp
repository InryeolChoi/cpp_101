#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stack>

class RPN
{
	private:
		RPN();
		std::stack<std::string> stack;
		std::stack<int> answer;
		std::string mathexpr;

	public:
		RPN(std::string str);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		bool expr_checkExpr();
		bool expr_checkStack();
		void expr_calculate();
		int expr_operate(std::string &op, int a, int b);

		// exception
		class WrongInput : public std::exception
		{
			const char *what() const throw();
		};
		class WrongExpr : public std::exception
		{
			const char *what() const throw();
		};
};