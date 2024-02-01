#include "Harl.hpp"

Harl::Harl(){}

void Harl::debug(void)
{
	std::cout << "Za Monolit" << std::endl;
}

void Harl::info(void)
{
	std::cout << "Only Mercs would want info..." << std::endl;
}

void Harl::warning(void)
{
	std::cout << "Warning, anomalies nearby" << std::endl;
}

void Harl::error(void)
{
	std::cout << "Error, vrag Monolita" << std::endl;
}

void Harl::complain(std::string level)
{
	std::string typeLevel[MAX_LEVEL] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*levelFunction[MAX_LEVEL])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < MAX_LEVEL; i++)
		if (level == typeLevel[i])
			(this->*levelFunction[i])();
}
