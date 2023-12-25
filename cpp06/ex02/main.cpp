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
		std::cout << "type : A" << std::endl;
	else if (dynamic_cast<B *>(test))
		std::cout << "type : B" << std::endl;
	else if (dynamic_cast<C *>(test))
		std::cout << "type : C" << std::endl;
	else
		std::cout << "unknown type" << std::endl;
}

static int i = 0;
static std::string classes[] = {"A", "B", "C"};

static void identify(Base &test)
{
	while (i < 3)
	{
		void *foo = NULL;
		Base &unused = (Base &)foo;
		try
		{
			if (i == 0)
				unused = dynamic_cast<A &>(test);
			else if (i == 1)
				unused = dynamic_cast<B &>(test);
			else if (i == 2)
				unused = dynamic_cast<C &>(test);
			else
				std::cout << "unknow type" << std::endl;
			(void)unused;
		}
		catch (std::exception &e)
		{
			i++;
			identify(test);
			return;
		}
		std::cout << classes[i] << " is the identified type" << std::endl;
		i = 0;
		break;
	}
}

int main(void)
{
	srand(time(NULL));
	for (int j = 0; j < 5; j++)
	{
		Base *Test = generate();
		if (Test == NULL)
			return (1);
		else
		{
			identify(Test);
			identify(*Test);
			delete (Test);

			std::cout << std::endl;
		}
	}
	return (0);
}