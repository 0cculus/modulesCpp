#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <sstream>

int main()
{
	int max = 12;
	Animal* zoo[max];

	for (int i = 0; i < max; i++)
	{
		if (i % 2)
			zoo[i] = new Cat("kitton");
		else
			zoo[i] = new Dog("doggo");
	}
	for (int i = 0; i < max; i++)
		zoo[i]->makeSound();

	for (int i = 0; i < max; i++)
		delete zoo[i];

	Cat kitton = Cat("kitton");
	Cat katzen = Cat("katzen");

	for (int i = 0; i < MAX_IDEAS / 2; i++)
	{
		std::ostringstream oss;
		oss << i;
		kitton.getBrain()->setIdea(oss.str());
	}
	katzen = kitton;

	for (int i = MAX_IDEAS / 2; i < MAX_IDEAS; i++)
	{
		std::ostringstream oss;
		oss << i;
		kitton.getBrain()->setIdea(oss.str());
	}

	for (int i = 0; i < MAX_IDEAS; i++)
		std::cout << katzen.getType() << " " << katzen.getBrain()->getIdea(i) << std::endl;
	for (int i = 0; i < MAX_IDEAS; i++)
		std::cout << kitton.getType() << " " << kitton.getBrain()->getIdea(i) << std::endl;
}
