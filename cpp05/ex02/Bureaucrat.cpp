#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name(""), grade(150)
{
}

Bureaucrat::Bureaucrat(std::string newName, unsigned int newGrade) : name(newName)
{
	if (newGrade < 1)
		throw GradeTooHighException();
	if (newGrade > 150)
		throw GradeTooLowException();
	this->grade = newGrade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : name(copy.name)
{
	this->grade = copy.grade;
	(*this) = copy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
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

void Bureaucrat::signForm(AForm& form)
{
	if (form.getGradeToSign() < this->getGrade())
	{
		std::cout << this-> name << " couldn't sign " << form.getName() << " because the form's rank is too high" << std::endl;
		throw Bureaucrat::GradeTooLowException();
	}
	else
	{
		std::cout << this-> name << " signed " << form.getName() << std::endl;
		form.beSigned(*this);
	}
}

void Bureaucrat::executeForm(AForm const& form)
{
	if (form.getGradeToExecute() < this->getGrade())
		std::cout << this-> name << " couldn't execute " << form.getName() << " because the form's rank is too high" << std::endl;
	try
	{
		form.execute(*this);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& ostm, const Bureaucrat& ref)
{
	ostm << "Name: " << ref.getName() << ", Grade: " << ref.getGrade();
	return (ostm);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error: Bureaucrat grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error: Bureaucrat grade is too low");
}
