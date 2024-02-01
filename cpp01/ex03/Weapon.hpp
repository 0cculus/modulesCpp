#ifndef WEAPON_HPP_
# define WEAPON_HPP_

# include <string>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon();
		Weapon(std::string newType);
		Weapon(const Weapon& copy);
		Weapon& operator=(const Weapon& copy);
		~Weapon();

		std::string getType() const;
		void setType(std::string newType);
};

#endif
