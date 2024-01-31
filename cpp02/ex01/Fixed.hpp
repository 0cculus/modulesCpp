#ifndef FIXED_HPP_
# define FIXED_HPP_

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int rawVal;
		static const int bitLength = 8;
	public:
		Fixed(void);
		Fixed(int const newRawVal);
		Fixed(float const newRawVal);
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& copy);
		~Fixed(void);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt(void) const;
		float toFloat(void) const;
};

std::ostream& operator<<(std::ostream& ostm, const Fixed& ref);

#endif
