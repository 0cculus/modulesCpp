#include "Zombie.hpp"

Zombie* newZombie(std::string newName)
{
	Zombie* src = new Zombie(newName);
	return (src);
}
