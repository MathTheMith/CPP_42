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

#include <iostream>

class Fixed {

private:
    int _rawValue;
    static const int _fractionalBits;

public:
    Fixed();
    Fixed(const int raw);
    Fixed(const float f);
    Fixed(const Fixed &a);

    ~Fixed();

    Fixed &operator=(const Fixed &a);

    int toInt(void) const;
    float toFloat(void) const;

    friend std::ostream &operator<<(std::ostream &os, const Fixed &f);
};

#endif
