#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// void sss()
// {
// 	system("leaks ex00");
// }

int main()
{
	// atexit(sss);
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();			// virtual 있음 -> cat()의 makeSound
	const WrongAnimal* k = new WrongCat();	// virtual 없음 -> WrongAnimal()의 makeSound
	std::cout << std::endl;

	std::cout << "meta's type is " << meta->getType() << " " << std::endl;
	std::cout << "j's type is " << j->getType() << " " << std::endl;
	std::cout << "i's type is " << i->getType() << " " << std::endl;
	std::cout << "k's type is " << k->getType() << " " << std::endl;
	std::cout << std::endl;

	meta->makeSound();
	j->makeSound();
	i->makeSound();
	k->makeSound();
	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;
	delete k;

	return 0;
}