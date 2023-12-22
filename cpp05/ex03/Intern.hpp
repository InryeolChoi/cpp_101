#pragma once
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Form;

class Intern
{
	public:
		// orthodox canonical form
		Intern();
		Intern(Intern const &other);
		Intern &operator=(Intern const &other);
		~Intern();
	
		// member function
		AForm *makeForm(std::string s1, std::string s2);

		// exception
		class FormNotFoundException: public std::exception {
			virtual const char*	what() const throw();
		};
};