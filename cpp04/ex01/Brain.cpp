#include "Brain.hpp"

Brain::Brain()
{
	this->currentIndex = 0;
}

Brain::Brain(const Brain& copy)
{
	for (int i = 0; i < MAX_IDEAS; i++)
		this->ideas[i] = copy.ideas[i];
	this->currentIndex = copy.currentIndex;
	(*this) = copy;
}

Brain& Brain::operator=(const Brain& copy)
{
	for (int i = 0; i < MAX_IDEAS; i++)
		this->ideas[i] = copy.ideas[i];
	this->currentIndex = copy.currentIndex;
	return (*this);
}

Brain::~Brain()
{
}

const std::string Brain::getIdea(int index) const
{
	const std::string msg = "Out of range index";
	if (index > MAX_IDEAS || index < 0)
		return (msg);
	else
		return (this->ideas[index]);
}

void Brain::setIdea(std::string newIdea)
{
	if (this->currentIndex < MAX_IDEAS)
		this->ideas[currentIndex++] = newIdea;
	else
		std::cout << "Too many ideas..." << std::endl;
}
