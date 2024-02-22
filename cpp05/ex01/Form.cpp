#include "Form.hpp"

Form::Form(): name(""), gradeToSign(150), gradeToExecute(150)
{
	this->isSigned = false;
}

Form::Form(std::string newName, unsigned int newGradeToSign, unsigned int newGradeToExecute) : name(newName), gradeToSign(newGradeToSign), gradeToExecute(newGradeToExecute)
{
	this->isSigned = false;
	this->checkGrade(newGradeToSign);
	this->checkGrade(newGradeToExecute);
}

Form::~Form()
{
}

void Form::checkGrade(unsigned int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

void Form::beSigned(Bureaucrat& bc)
{
	if (bc.getGrade() > this->gradeToSign)
		throw GradeTooHighException();
	this->isSigned = true;
}

bool Form::getIsSigned() const
{
	return (this->isSigned);
}

std::string Form::getName() const
{
	return (this->name);
}

unsigned int Form::getGradeToSign() const
{
	return (this->gradeToSign);
}

unsigned int Form::getGradeToExecute() const
{
	return (this->gradeToExecute);
}

std::ostream& operator<<(std::ostream& ostm, const Form& ref)
{
	ostm << "Form: " << ref.getName();
	return (ostm);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Error: Form grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Error: Form grade is too low");
}
