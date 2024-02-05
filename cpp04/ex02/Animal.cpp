#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal base constructor called" << std::endl;
}

Animal::Animal(std::string newType) : type(newType)
{
	std::cout << "Animal overlaod constructor called" << std::endl;
}

Animal::Animal(const Animal& copy) : type(copy.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
	(*this) = copy;
}

Animal& Animal::operator=(const Animal& copy)
{
	std::cout << "Animal assignment operator called" << std::endl;
	this->setType(copy.getType());
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound()
{
	std::cout << "This animal I have become!" << std::endl;
}

const std::string& Animal::getType() const
{
	return (this->type);
}

void Animal::setType(std::string newType)
{
	this->type = newType;
}
