#include "FragTrap.hpp"

FragTrap::FragTrap(std::string newName) : ClapTrap(newName)
{
	this->energyPoints = 100;
	this->hitPoints = 100;
	this->attackDmg = 30;
	this->name = newName;
	std::cout << "FragTrap " << this->name << ": Eat bomb, baddie!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
	this->energyPoints = copy.energyPoints;
	this->hitPoints = copy.hitPoints;
	this->attackDmg = copy.attackDmg;
	this->name = copy.name;
}

FragTrap& FragTrap::operator=(const FragTrap& copy)
{
	this->energyPoints = copy.energyPoints;
	this->hitPoints = copy.hitPoints;
	this->attackDmg = copy.attackDmg;
	this->name = copy.name;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << ": My servos... are seizing..." << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << this->name << ": Up top! High five! Secret handshake!" << std::endl;
}
