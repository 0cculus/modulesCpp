#ifndef HARL_HPP_
# define HARL_HPP_

# define MAX_LEVEL 4

# include <iostream>
# include <string>

class Harl
{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	public:
		Harl();
		void complain(std::string level);
};

#endif
