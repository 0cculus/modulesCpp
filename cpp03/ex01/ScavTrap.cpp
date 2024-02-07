#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string newName) : ClapTrap(newName)
{
	this->energyPoints = 50;
	this->hitPoints = 100;
	this->attackDmg = 20;
	this->name = newName;
	std::cout << "ScavTrap " << this->name << ": This time it'll be awesome, I promise!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
	this->energyPoints = copy.energyPoints;
	this->hitPoints = copy.hitPoints;
	this->attackDmg = copy.attackDmg;
	this->name = copy.name;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
	this->energyPoints = copy.energyPoints;
	this->hitPoints = copy.hitPoints;
	this->attackDmg = copy.attackDmg;
	this->name = copy.name;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << ": It's the only way to stop the voices!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << this->name << ": I'm guarding this gate! Still haven't found the Vault?" << std::endl;
}
