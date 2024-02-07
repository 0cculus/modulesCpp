#ifndef SCAVTRAP_HPP_
# define SCAVTRAP_HPP_

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
	public:
		ScavTrap(std::string newName);
		ScavTrap(const ScavTrap& copy);
		ScavTrap& operator=(const ScavTrap& copy);
		~ScavTrap();

		void guardGate();
};

#endif
