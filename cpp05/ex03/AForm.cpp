#include "AForm.hpp"

// orthodox canonical form
AForm::AForm() : name("_form"), isSigned(false), signGrade(1), exeGrade(1)
{
	std::cout << "The form " <<  name << " is initialized" << std::endl;
}

AForm::AForm(const AForm &other)
	: name(other.name), isSigned(false), 
		signGrade(other.signGrade), 
		exeGrade(other.exeGrade)
{}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->isSigned = other.isSigned;
	return (*this);
}

AForm::~AForm()
{}

// constructor overload
AForm::AForm(std::string name, int sign, int exec)
	: name(name), isSigned(false), signGrade(sign), exeGrade(exec)
{
	checkGrade(sign);
	checkGrade(exec);
	std::cout << "The form " <<  name << " is initialized" << std::endl;
}

// member function
void AForm::checkGrade(int grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
}

std::string AForm::getName() const
{
	return name;
}

int AForm::getSignGrade() const
{
	return signGrade;
}

int AForm::getExeGrade() const
{
	return exeGrade;
}

bool AForm::getIsSigned() const
{
	return isSigned;
}

void AForm::beSigned(Bureaucrat &member)
{
	if (isSigned == true)
		throw AlreadySignedException();
	
	// "폼의 등급 < 관료의 등급" 이면 폼이 더 높다.
	// 따라서 싸인이 불가. (예외처리)
	if (signGrade < member.getGrade())
		throw GradeTooLowException();
	isSigned = true;
}

// exception
const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *AForm::AlreadySignedException::what() const throw()
{
	return ("The form has been signed already");
}

// overloading operator <<
std::ostream& operator<<(std::ostream &output, AForm &form)
{
	output << form.getName() << ", ";
	if (form.getIsSigned())
		output << "signed" << ", ";
	else
		output << "not signed" << ", ";
	output << form.getSignGrade() << " signGrade, ";
	output << form.getExeGrade() << " exeGrade" << std::endl;
	return (output);
}