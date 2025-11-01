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
    int rawValue;
    static const int _fractionalBits = 8;

public :	
	friend std::ostream &operator<<(std::ostream &os, const Fixed &f);
	Fixed();
	Fixed( int const raw );
	Fixed(float const f);
	Fixed(const Fixed &a);
	Fixed &operator=(const Fixed &a);
	~Fixed();

	int toInt( void ) const;
	float toFloat( void ) const;
};