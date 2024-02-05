#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog base constructor called" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(std::string newType) : Animal(newType)
{
	std::cout << "Dog overlaod constructor called" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = copy.brain;
}

Dog& Dog::operator=(const Dog& copy)
{
	std::cout << "Dog assignment operator called" << std::endl;
	this->setType(copy.getType());
	this->brain = copy.brain;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

void Dog::makeSound()
{
	std::cout << "Bork bork" << std::endl;
}

Brain* Dog::getBrain()
{
	return (this->brain);
}
