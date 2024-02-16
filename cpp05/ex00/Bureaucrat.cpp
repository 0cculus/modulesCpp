#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string newName, unsigned int newGrade)
{

}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
	this->name = copy.name;
	this->grade = copy.grade;
	(*this) = copy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	this->name = copy.name;
	this->grade = copy.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

void Bureaucrat::setGrade(unsigned int newGrade)
{
	if (newGrade < 1)
		throw GradeTooHighException();
	if (newGrade > 150)
		throw GradeTooLowException();
	this->grade = newGrade;
}

void Bureaucrat::setName(std::string newName)
{
	this->name = newName;
}

unsigned int Bureaucrat::getGrade()
{
	return (this->grade);
}

std::string Bureaucrat::getName()
{
	return (this->name);
}
