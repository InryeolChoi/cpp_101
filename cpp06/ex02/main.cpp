#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <cstdio>

static Base *generate(void)
{
	switch(rand() % 3)
	{
		case 0:
			return (new A());
			break ;
		case 1:
			return (new B());
			break ;
		case 2:
			return (new C());
			break ;
		default:
			std::cerr << "error : rand() malfunctioned" << std::endl;
			return (NULL);			
	}
}

static void identify(Base *test)
{
	if (dynamic_cast<A *>(test))
		std::cout << "pointer type : A" << std::endl;
	else if (dynamic_cast<B *>(test))
		std::cout << "pointer type : B" << std::endl;
	else if (dynamic_cast<C *>(test))
		std::cout << "pointer type : C" << std::endl;
	else
		std::cout << "unknown pointer type" << std::endl;
}

static void identify(Base &test)
{
	try
	{
		A &a = dynamic_cast<A&>(test);
		std::cout << "reference type is A" << std::endl;
		static_cast<void>(a);
	}
	catch (std::exception &e) {}
	try
	{
		B &b = dynamic_cast<B&>(test);
		std::cout << "reference type is B" << std::endl;
		static_cast<void>(b);
	}
	catch (std::exception &e) {}
	try
	{
		C &c = dynamic_cast<C&>(test);
		std::cout << "reference type is C" << std::endl;
		static_cast<void>(c);
	}
	catch (std::exception &e) {}
}

int main(void)
{
	srand(time(NULL));
	Base *Test = generate();
	if (Test == NULL)
		return (1);
	else
	{
		identify(Test);
		identify(*Test);
		delete (Test);
	}
	return (0);
}