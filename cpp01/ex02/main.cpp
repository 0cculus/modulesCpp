#include <iostream>
#include <string>

int main()
{
	std::string src = "HI THIS IS BRAIN";
	std::string& stringREF = src;
	std::string* stringPTR = &src;

	std::cout << &src << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << src << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}
