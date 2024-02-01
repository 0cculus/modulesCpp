#include "Zombie.hpp"

void randomChump(std::string newName)
{
	Zombie src(newName);
	src.announce();
}
