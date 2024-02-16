#ifndef BUREAUCRAT_HPP_
# define BUREAUCRAT_HPP_

# include <iostream>
# include <string>

class Bureaucrat
{
	private:
		std::string name;
		unsigned int grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string newName, unsigned int newGrade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(const Bureaucrat& copy);
		~Bureaucrat();

		void setGrade(unsigned int newGrade);
		void setName(std::string newName);
		unsigned int getGrade();
		std::string getName();

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

std::ostream& operator<<(std::ostream& ostm, const Bureaucrat& ref);

#endif
