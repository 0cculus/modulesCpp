#ifndef FIXED_HPP_
# define FIXED_HPP_

# include <iostream>

class Fixed
{
	private:
		int rawVal;
		static const int bitLength = 8;
	public:
		Fixed(void);
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& copy);
		~Fixed(void);

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
