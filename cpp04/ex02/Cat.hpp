#ifndef CAT_HPP_
# define CAT_HPP_

# include <iostream>
# include <string>
# include <cstring>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* brain;
	public:
		Cat();
		Cat(std::string newType);
		Cat(const Cat& copy);
		Cat& operator=(const Cat& copy);
		~Cat();

		void makeSound();
		Brain* getBrain();
};

#endif
