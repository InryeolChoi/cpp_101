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
	const Animal* i = new Cat();
	const WrongAnimal* k = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();
	k->makeSound();

	delete meta;
	delete j;
	delete i;
	delete k; 

	return 0;
}