#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat base constructor called" << std::endl;
}

Cat::Cat(std::string newType) : Animal(newType)
{
	std::cout << "Cat overlaod constructor called" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& copy)
{
	std::cout << "Cat assignment operator called" << std::endl;
	this->setType(copy.getType());
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound()
{
	std::cout << "Meow meow" << std::endl;
}
