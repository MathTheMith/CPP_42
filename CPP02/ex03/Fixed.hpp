/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 03:01:25 by marvin            #+#    #+#             */
/*   Updated: 2025/10/22 03:01:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>

class Fixed{
private:
    int _rawValue;
    static const int _fractionalBits = 8;

public :	
	Fixed();
	Fixed( int const raw );
	Fixed(float const f);
	Fixed(const Fixed &a);
	Fixed &operator=(const Fixed &a);
	~Fixed();

	friend std::ostream &operator<<(std::ostream &os, const Fixed &f);

	bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

	Fixed operator+(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;

	Fixed &operator++();
	Fixed &operator++(int);
	Fixed &operator--();
	Fixed &operator--(int);

	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);

	int toInt( void ) const;
	float toFloat( void ) const;
};

class Point{

private:
	Fixed const a;
	Fixed const b;
};
