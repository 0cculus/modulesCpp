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

		/* Base functions */
		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt(void) const;
		float toFloat(void) const;

		/* Boolean operators */
		bool operator==(const Fixed& src);
		bool operator!=(const Fixed& src);
		bool operator<=(const Fixed& src);
		bool operator>=(const Fixed& src);
		bool operator<(const Fixed& src);
		bool operator>(const Fixed& src);

		/* Arithmetic operators */
		Fixed operator+(const Fixed& src);
		Fixed operator-(const Fixed& src);
		Fixed operator/(const Fixed& src);
		Fixed operator*(const Fixed& src);

		/* Iteration operators */
		Fixed& operator++(void);
		Fixed& operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);

		/* Overloaded functions */
		Fixed& min(Fixed& a, Fixed& b);
		const Fixed& min(const Fixed& a, const Fixed& b);
		Fixed& max(Fixed& a, Fixed& b);
		const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& ostm, const Fixed& ref);

#endif
