#include "RPN.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw RPN::WrongInput();

		RPN rpn(av[1]);
		if (rpn.expr_checkExpr() == false)
			throw RPN::WrongExpr();
		if (rpn.expr_checkStack() == false)
			throw RPN::WrongExpr();
		rpn.expr_calculate();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}