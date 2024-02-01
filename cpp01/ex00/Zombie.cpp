#include "Zombie.hpp"

Zombie::Zombie(std::string newName)
{
	this->name = newName;
}

Zombie::Zombie(const Zombie& copy)
{
	this->name = copy.getName();
	(*this) = copy;
}

Zombie::~Zombie(void)
{
	std::cout << this->getName() << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::getName(void) const
{
	return (this->name);
}

