#ifndef WRONGCAT_HPP_
# define WRONGCAT_HPP_

# include <iostream>
# include <string>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:
	public:
		WrongCat();
		WrongCat(std::string newType);
		WrongCat(const WrongCat& copy);
		WrongCat& operator=(const WrongCat& copy);
		~WrongCat();

		void makeSound();
};

#endif
