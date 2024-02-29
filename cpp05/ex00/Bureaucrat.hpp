#ifndef BUREAUCRAT_HPP_
# define BUREAUCRAT_HPP_

# include <iostream>
# include <string>

class Bureaucrat
{
	private:
		const std::string name;
		unsigned int grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string newName, unsigned int newGrade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(const Bureaucrat& copy);
		~Bureaucrat();

		void setGrade(unsigned int newGrade);
		unsigned int getGrade() const;
		std::string getName() const;
		void increment();
		void decrement();

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
