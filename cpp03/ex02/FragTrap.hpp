#ifndef FRAGTRAP_HPP_
# define FRAGTRAP_HPP_

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
	public:
		FragTrap(std::string newName);
		FragTrap(const FragTrap& copy);
		FragTrap& operator=(const FragTrap& copy);
		~FragTrap();

		void highFivesGuys();
};

#endif
