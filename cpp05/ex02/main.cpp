#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{

std::cout << "-----RobotForm-----" << std::endl;
std::cout << std::endl;
std::cout << "---test1 ok---" << std::endl;
std::cout << std::endl;

	try
	{
		Bureaucrat bob("bob", 45);
		AForm *robot = new RobotomyRequestForm("zach");
		std::cout << bob << std::endl;
		std::cout << *robot << std::endl;
		bob.signForm(*robot);
		bob.executeForm(*robot);
		delete robot;
	}	
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "---test2 error not signed---" << std::endl;
	std::cout << std::endl;

	try
	{
		Bureaucrat bob("bob", 45);
		AForm *robot = new RobotomyRequestForm("bob");
		std::cout << bob << std::endl;
		std::cout << *robot << std::endl;
		bob.executeForm(*robot);
		delete robot;

	}	
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "---test3 error to low---" << std::endl;
	std::cout << std::endl;

	try
	{
		Bureaucrat bob("bob", 50);
		AForm *robot = new RobotomyRequestForm("bob");
		std::cout << bob << std::endl;
		std::cout << *robot << std::endl;
		bob.signForm(*robot);
		bob.executeForm(*robot);
		delete robot;

	}	
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "-----ShrubberyForm-----" << std::endl;
	std::cout << std::endl;
	std::cout << "---test1 ok---" << std::endl;
	std::cout << std::endl;

	try
	{
		Bureaucrat bob("bob", 130);
		AForm *shrubs = new ShrubberyCreationForm("sebb");
		std::cout << *shrubs << std::endl;
		std::cout << bob << std::endl;
		bob.signForm(*shrubs);
		for (int i = 0; i < 7;i++)
			bob.decrement();
		bob.executeForm(*shrubs);
		delete shrubs;
	}	
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "---test2 error to low---" << std::endl;
	std::cout << std::endl;

	try
	{
		Bureaucrat bob("bob", 145);
		AForm *shrubs = new ShrubberyCreationForm("sebb");
		std::cout << *shrubs << std::endl;
		std::cout << bob << std::endl;
		bob.signForm(*shrubs);
		bob.executeForm(*shrubs);
		delete shrubs;

	}	
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "---test3 error not signed---" << std::endl;
	std::cout << std::endl;

	try
	{
		Bureaucrat bob("bob", 150);
		AForm *shrubs = new ShrubberyCreationForm("sebb");
		std::cout << *shrubs << std::endl;
		std::cout << bob << std::endl;
		bob.executeForm(*shrubs);
		delete shrubs;

	}	
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "-----PresidentForm-----" << std::endl;
	std::cout << std::endl;
	std::cout << "---test 1 ok---" << std::endl;

	try 
	{
		Bureaucrat bob("bob", 2);
		AForm *pres = new PresidentialPardonForm("oli");
		std::cout << *pres << std::endl;
		std::cout << bob << std::endl;
		bob.signForm(*pres);
		bob.executeForm(*pres);
		delete pres;
	}
	catch (std::exception & e) 
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "---test 2 error to low---" << std::endl;

	try 
	{
		Bureaucrat bob("bob", 7);
		AForm *pres = new PresidentialPardonForm("oli");
		std::cout << *pres << std::endl;
		std::cout << bob << std::endl;
		bob.signForm(*pres);
		bob.executeForm(*pres);
		delete pres;
	}
	catch (std::exception & e) 
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "---test 3 error not signed---" << std::endl;

	try 
	{
		AForm *pres = new PresidentialPardonForm("oli");
		Bureaucrat bob("bob", 27);
		std::cout << *pres << std::endl;
		std::cout << bob << std::endl;
		bob.signForm(*pres);
		bob.executeForm(*pres);
		delete pres;
	}
	catch (std::exception & e) 
	{
		std::cout << e.what() << std::endl;
	}
	return 14;
}
