#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void check_leaks()
{
	system("leaks ex01");
}

int main()
{
	atexit(check_leaks);
	Animal *animal[10]; // "객체를 가리키는 포인터" 들의 배열

	for (size_t i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}
	std::cout << std::endl << std::endl;

	for (size_t i = 0; i < 10; i++)
		delete animal[i];

	std::cout << "====" << "====" << "====" << std::endl << std::endl;
	Dog *d1 = new Dog();
	Dog *d2 = new Dog();

	delete d1;
	delete d2;

	std::cout << "====" << "====" << "====" << std::endl << std::endl;

	Cat *c1 = new Cat();
	Cat *c2 = new Cat();

	delete c1;
	delete c2;

	return 0;
}