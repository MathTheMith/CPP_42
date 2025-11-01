/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 03:01:57 by marvin            #+#    #+#             */
/*   Updated: 2025/10/22 03:01:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cmath>
#include "Fixed.hpp"

std::ostream &operator<<(std::ostream &os, const Fixed &f) {
    os << f.toFloat();
    return os;
}

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	rawValue = 0;
}

Fixed::Fixed(const Fixed &a)
{
	std::cout << "Copy constructor called" << std::endl;
	rawValue = a.rawValue;
}

Fixed &Fixed::operator=(const Fixed &a)
{
    std::cout << "Copy assignment operator called" << std::endl;

    if (this != &a)
    {
        this->rawValue = a.rawValue;
    }

    return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(float const f) {
    rawValue = roundf(f * (1 << _fractionalBits));
}

int Fixed::toInt( void ) const
{
   return (rawValue >> _fractionalBits);
}

float Fixed::toFloat(void) const {
    return static_cast<float>(rawValue) / (1 << _fractionalBits);
}

Fixed::Fixed( int const raw ){
	rawValue = raw << _fractionalBits;
}

