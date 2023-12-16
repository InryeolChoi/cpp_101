#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <cstdlib>

/* 조건 : Animal 클래스를 추상클래스로 바꿀 것. */
/* 따라서 이름 역시 Animal에서 AAnimal로 바뀜 (맨 앞의 A : abstract) */

// void check_leaks()
// {
// 	system("leaks ex02");
// }

int main()
{
	// atexit(check_leaks);

	/* Dog와 Cat 클래스는 인스턴스화가 된다. */
	Dog *d1 = new Dog();
	Cat *c1 = new Cat();

	d1->makeSound();
	c1->makeSound();
	delete d1;
	delete c1;

	/* AAnimal 클래스는 인스턴스화가 안된다. (추상클래스이기 때문) */
	// AAnimal *animal = new AAnimal();

	/* WrongAnimal 클래스는 인스턴스화가 된다. (추상클래스는 아니기 때문) */
	WrongAnimal *wa = new WrongAnimal();
	delete wa;

	return 0;
}