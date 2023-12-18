#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		PresidentialPardonForm();
		std::string target;

	public:
		PresidentialPardonForm(std::string str);
		PresidentialPardonForm(PresidentialPardonForm const &other);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
		~PresidentialPardonForm();

		// member function
		std::string getTarget();

		// override
		void execute(Bureaucrat const & executor);
};