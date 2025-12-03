#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _rawValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int raw) {
    std::cout << "Int constructor called" << std::endl;
    _rawValue = raw << _fractionalBits;
}

Fixed::Fixed(const float f) {
    std::cout << "Float constructor called" << std::endl;
    _rawValue = roundf(f * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &a) {
    std::cout << "Copy constructor called" << std::endl;
    _rawValue = a._rawValue;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &a) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &a)
        _rawValue = a._rawValue;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Fixed &f) {
    os << f.toFloat();
    return os;
}

int Fixed::toInt(void) const {
    return (_rawValue >> _fractionalBits);
}

float Fixed::toFloat(void) const {
    return static_cast<float>(_rawValue) / (1 << _fractionalBits);
}
