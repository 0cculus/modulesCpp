#include "HumanB.hpp"

HumanB::HumanB(std::string newName)
{
	this->name = newName;
	this->wpn = NULL;
}

HumanB::HumanB(const HumanB& copy)
{
	this->wpn = copy.getWeapon();
	this->setName(copy.getName());
	(*this) = copy;
}

HumanB& HumanB::operator=(const HumanB& copy)
{
	this->wpn = copy.getWeapon();
	this->setName(copy.getName());
	return (*this);
}

HumanB::~HumanB()
{
}

Weapon* HumanB::getWeapon() const
{
	return (this->wpn);
}

std::string HumanB::getName() const
{
	return (this->name);
}

void HumanB::setWeapon(Weapon& newWpn)
{
	this->wpn = &newWpn;
}

void HumanB::setName(std::string newName)
{
	this->name = newName;
}

void HumanB::attack()
{
	if (this->wpn)
		std::cout << this->getName() << " attacks with their " << this->wpn->getType() << std::endl;
	else
		std::cout << this->getName() << " has no weapon to use..." << std::endl;
}

