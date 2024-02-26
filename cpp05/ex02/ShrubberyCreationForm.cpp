#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string newTarget) : AForm("shrubbery", 145, 137)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy)
{
	(*this) = copy
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	this->target = copy.getTarget();
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string ShrubberyCreationForm::getTarget()
{
	return (this->target);
}

void ShrubberyCreationForm::execute(Bureaucrat& const executor) const
{
	if (this->getGradeToExecute() < executor.getGrade())
		throw AForm::GradeTooLowException();
	if (!this->getIsSigned())
		throw std::invalid_argument("Current Shrubbery Form is not signed\n");

	fstream art("ascii.txt", std::fstream::in);
	ostream filename();
	file << this->getTarget() << "_shrubbery.form";
	fstream file(filename, std::fstream::out | std::fstream::trunc);

	if (art.fail() | file.fail())
		throw std::invalid_argument("Files have been tempered\n");
	std::string current;
	while (getLine(art, current))
		file << current ::std::endl;
}
