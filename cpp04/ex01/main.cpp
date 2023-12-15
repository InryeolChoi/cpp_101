#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <cstdlib>

// void check_leaks()
// {
// 	system("leaks ex01");
// }

int main()
{
	// atexit(check_leaks);

	// 1. Animal 타입의 배열 만들기
	std::cout << "< Animal 타입 배열 생성/소멸 >" << std::endl;
	Animal *animal[10]; // "객체를 가리키는 포인터" 들의 배열

	for (size_t i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}
	std::cout << std::endl;

	for (size_t i = 0; i < 10; i++)
		delete animal[i];
	std::cout << std::endl;

	// 2. 깊은 복사 확인 1
	std::cout << "< 깊은 복사 확인 1 >" << std::endl;
	Dog *d1 = new Dog();
	Dog *d2 = new Dog(*d1);

	std::cout << "before : " << std::endl;
	std::cout << "d1 : " << d1->getBrain()->getidea(1) << ", ";
	std::cout << "d2 : " << d2->getBrain()->getidea(1) << std::endl;

	std::cout << "after : " << std::endl;
	std::cout << "d1 : " << d1->getBrain()->getidea(1) << ", ";
	std::cout << "d2 : " << d2->getBrain()->getidea(1) << std::endl;

	delete d1;
	delete d2;
	std::cout << std::endl;

	// 3. 깊은 복사 확인 2
	std::cout << "< 깊은 복사 확인 2 >" << std::endl;
	Cat *c1 = new Cat();
	Cat *c2 = new Cat();

	std::cout << "before : " << std::endl;
	std::cout << "c1 : " << c1->getBrain()->getidea(1) << ", ";
	std::cout << "c2 : " << c2->getBrain()->getidea(1) << std::endl;

	*c1 = *c2;
	std::cout << "after : " << std::endl;
	std::cout << "c1 : " << c1->getBrain()->getidea(1) << ", ";
	std::cout << "c2 : " << c2->getBrain()->getidea(1) << std::endl;

	delete c1;
	delete c2;

	// 3. 깊은 복사 확인 2
	std::cout << "< 깊은 복사 확인 2 >" << std::endl;
	WrongCat *c1 = new Cat();
	Cat *c2 = new Cat();

	std::cout << "before : " << std::endl;
	std::cout << "c1 : " << c1->getBrain()->getidea(1) << ", ";
	std::cout << "c2 : " << c2->getBrain()->getidea(1) << std::endl;

	*c1 = *c2;
	std::cout << "after : " << std::endl;
	std::cout << "c1 : " << c1->getBrain()->getidea(1) << ", ";
	std::cout << "c2 : " << c2->getBrain()->getidea(1) << std::endl;

	return 0;
}