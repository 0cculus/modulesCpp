#include "AForm.hpp"

AForm::AForm(): name(""), gradeToSign(150), gradeToExecute(150)
{
	this->isSigned = false;
}

AForm::AForm(std::string newName, unsigned int newGradeToSign, unsigned int newGradeToExecute) : name(newName), gradeToSign(newGradeToSign), gradeToExecute(newGradeToExecute)
{
	this->isSigned = false;
	this->checkGrade(newGradeToSign);
	this->checkGrade(newGradeToExecute);
}

AForm::~AForm()
{
}

void AForm::checkGrade(unsigned int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

void AForm::beSigned(Bureaucrat& bc)
{
	if (bc.getGrade() > this->gradeToSign)
		throw GradeTooHighException();
	this->isSigned = true;
}

bool AForm::getIsSigned() const
{
	return (this->isSigned);
}

std::string AForm::getName() const
{
	return (this->name);
}

unsigned int AForm::getGradeToSign() const
{
	return (this->gradeToSign);
}

unsigned int AForm::getGradeToExecute() const
{
	return (this->gradeToExecute);
}

std::ostream& operator<<(std::ostream& ostm, const AForm& ref)
{
	ostm << "Form: " << ref.getName() << ", Grade to execute: " << ref.getGradeToExecute() << ", Grade to sign: " << ref.getGradeToSign() << ", Signed: " << ref.getIsSigned();
	return (ostm);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Error: Form grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Error: Form grade is too low");
}
