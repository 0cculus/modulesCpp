#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	WrongAnimal* wa = new WrongAnimal("WrongAnimal");
	WrongAnimal* wc = new WrongCat("WrongCat");
	Animal* c = new Cat("Cat");
	Animal* d = new Dog("Dog");
	Animal* a = new Animal("Animal");

	wa->makeSound();
	wc->makeSound();
	c->makeSound();
	d->makeSound();
	a->makeSound();

	delete wa;
	delete wc;
	delete c;
	delete d;
	delete a;
}
