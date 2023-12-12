#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

// void sss()
// {
// 	system("leaks ex00");
// }

int main()
{
	// atexit(sss);
	Animal *animal[10]; // "객체를 가리키는 포인터" 들의 배열

	for (size_t i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}


	for (size_t i = 0; i < 10; i++)
		delete animal[i];
	return 0;
}