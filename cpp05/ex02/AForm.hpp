#ifndef FORM_HPP_
# define FORM_HPP_

# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	priavte:
		bool isSigned;
		const std::string name;
		const unsigned int gradeToSign;
		const unsigned int gradeToExecute;
	public:
		AForm();
		AForm(std::string newName, unsigned int newGradeToSign, unsigned int newGradeToExecute);
		virtual ~AForm();

		static void checkGrade(unsigned int grade);
		bool getIsSigned() const;
		std::string getName() const;
		unsigned int getGradeToSign() const;
		unsigned int getGradeToExecute() const;
		void beSigned(Bureaucrat& bc);
		virtual void execute(Bureaucrat& const executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& ostm, const AForm& ref);

#endif
