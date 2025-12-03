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

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed{

private:
    int _rawValue;
    static const int _fractionalBits;

public :
	Fixed();
	Fixed(const Fixed &a);
	Fixed &operator=(const Fixed &a);
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw );

};

#endif
