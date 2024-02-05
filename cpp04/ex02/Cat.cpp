#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat base constructor called" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(std::string newType) : Animal(newType)
{
	std::cout << "Cat overlaod constructor called" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain(*copy.brain);
}

Cat& Cat::operator=(const Cat& copy)
{
	std::cout << "Cat assignment operator called" << std::endl;
	this->setType(copy.getType());
	*this->brain = *copy.brain;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

void Cat::makeSound()
{
	std::cout << "Meow meow" << std::endl;
}

Brain* Cat::getBrain()
{
	return (this->brain);
}
