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

const int Fixed::_fractionalBits = 8;

std::ostream &operator<<(std::ostream &os, const Fixed &f) {
    os << f.toFloat();
    return os;
}

bool Fixed::operator>(const Fixed &other) const {
    return this->_rawValue > other._rawValue;
}

bool Fixed::operator<(const Fixed &other) const {
    return this->_rawValue < other._rawValue;
}


bool Fixed::operator>=(const Fixed &other) const {
    return this->_rawValue >= other._rawValue;
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->_rawValue <= other._rawValue;
}

bool Fixed::operator==(const Fixed &other) const {
    return this->_rawValue == other._rawValue;
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->_rawValue != other._rawValue;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;

    result._rawValue = this->_rawValue + other._rawValue;
    return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;

    result._rawValue = this->_rawValue - other._rawValue;
    return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;

    result._rawValue = (this->_rawValue << _fractionalBits) / other._rawValue;
    return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;

    result._rawValue = (this->_rawValue * other._rawValue) >> _fractionalBits;
    return (result);
}

Fixed &Fixed::operator++()
{
    _rawValue++;
    return *this;
}

Fixed &Fixed::operator++(int)
{
    Fixed temp = *this;
    _rawValue++;
    return *this;
}

Fixed &Fixed::operator--()
{
    _rawValue--;
    return *this;
}

Fixed &Fixed::operator--(int)
{
    Fixed temp = *this;
    _rawValue--;
    return *this;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    if (a < b)
        return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    if (a < b)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    if (a > b)
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    if (a > b)
        return a;
    return b;
}

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	_rawValue = 0;
}

Fixed::Fixed(const Fixed &a)
{
	// std::cout << "Copy constructor called" << std::endl;
	_rawValue = a._rawValue;
}

Fixed &Fixed::operator=(const Fixed &a)
{
    // std::cout << "Copy assignment operator called" << std::endl;

    if (this != &a)
        this->_rawValue = a._rawValue;

    return *this;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(float const f) {
    _rawValue = roundf(f * (1 << _fractionalBits));
}

int Fixed::toInt( void ) const
{
   return (_rawValue >> _fractionalBits);
}

float Fixed::toFloat(void) const {
    return static_cast<float>(_rawValue) / (1 << _fractionalBits);
}

Fixed::Fixed( int const raw ){
	_rawValue = raw << _fractionalBits;
}

