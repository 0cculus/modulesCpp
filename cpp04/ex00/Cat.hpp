#ifndef CAT_HPP_
# define CAT_HPP_

# include <iostream>
# include <string>
# include "Animal.hpp"

class Cat : public Animal
{
	private:
	public:
		Cat();
		Cat(std::string newType);
		Cat(const Cat& copy);
		Cat& operator=(const Cat& copy);
		~Cat();

		void makeSound();
};

#endif
