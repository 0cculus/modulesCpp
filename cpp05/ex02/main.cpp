#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{
	{
		try
		{
			Bureaucrat b1("bubu", 62);
			Form f1("form a1", 12, 123);
			b1.signForm(f1);
			f1.beSigned(b1);
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat bubu("Bubu", 120);
			std::cout << bubu << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat brubru = Bureaucrat("Brubru", 12);
			std::cout << brubru << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat bubu("Bubu", 150);
			std::cout << bubu << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat brubru = Bureaucrat("Brubru", 1);
			std::cout << brubru << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
