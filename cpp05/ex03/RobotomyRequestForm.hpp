#pragma once
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
	private:
		RobotomyRequestForm();
		std::string target;

	public:
		RobotomyRequestForm(std::string str);
		RobotomyRequestForm(RobotomyRequestForm const &other);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
		~RobotomyRequestForm();

		// member function
		std::string getTarget();

		// override
		void execute(Bureaucrat const & executor) const;
};