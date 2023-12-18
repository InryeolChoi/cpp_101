#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		RobotomyRequestForm();

	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &other);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
		~RobotomyRequestForm();

		// override
		void execute(Bureaucrat const & executor);
};