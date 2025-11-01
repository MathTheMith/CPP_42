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
#include "Fixed.hpp"

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

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return rawValue;
}


void Fixed::setRawBits( int const raw ){
	rawValue = raw << _fractionalBits;
}

