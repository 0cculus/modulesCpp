#ifndef ZOMBIE_HPP_
# define ZOMBIE_HPP_

# include <iostream> 
# include <string>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie(std::string newName);
		Zombie(const Zombie& copy);
		~Zombie(void);

		void announce(void);
		std::string getName(void) const;
		void setName(std::string newName);
};

Zombie* zombieHorde(int n, std::string name);

#endif
