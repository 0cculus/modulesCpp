#ifndef WRONGANIMAL_HPP_
# define WRONGANIMAL_HPP_

# include <iostream>
# include <string>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(std::string newType);
		WrongAnimal(const WrongAnimal& copy);
		WrongAnimal& operator=(const WrongAnimal& copy);
		virtual ~WrongAnimal();

		void makeSound();
		const std::string& getType() const;
		void setType(std::string newType);
};

#endif
