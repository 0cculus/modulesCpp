#ifndef BRAIN_HPP_
# define BRAIN_HPP_

# include <iostream> 
# include <string>

# define MAX_IDEAS 100

class Brain
{
	private:
		std::string ideas[MAX_IDEAS];
		unsigned int currentIndex;
	public:
		Brain();
		Brain(const Brain& copy);
		Brain& operator=(const Brain& copy);
		~Brain();

		const std::string getIdea(int index) const;
		void setIdea(std::string newIdea);
};

#endif
