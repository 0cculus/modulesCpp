#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string newName, unsigned int newGrade)
{
	this->name = newName;	
	if (newGrade < 1)
		throw GradeTooHighException();
	if (newGrade > 150)
		throw GradeTooLowException();
	this->grade = newGrade;
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

unsigned int Bureaucrat::getGrade() const
{
	return (this->grade);
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

void Bureaucrat::increment()
{
	if ((this->grade - 1) < 1)
		throw GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrement()
{
	if ((this->grade + 1) > 150)
		throw GradeTooLowException();
	this->grade++;
}

std::ostream& operator<<(std::ostream& ostm, const Bureaucrat& ref)
{
	ostm << "Name: " << ref.getName() << ", Grade: " << ref.getGrade();
	return (ostm);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error: Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error: Grade is too low");
}
