#ifndef FORM_HPP_
# define FORM_HPP_

# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		bool isSigned;
		const std::string name;
		const unsigned int gradeToSign;
		const unsigned int gradeToExecute;
	public:
		Form();
		Form(std::string newName, unsigned int newGradeToSign, unsigned int newGradeToExecute);
		~Form();

		static void checkGrade(unsigned int grade);
		bool getIsSigned() const;
		std::string getName() const;
		unsigned int getGradeToSign() const;
		unsigned int getGradeToExecute() const;
		void beSigned(Bureaucrat& bc);

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

std::ostream& operator<<(std::ostream& ostm, const Form& ref);

#endif
