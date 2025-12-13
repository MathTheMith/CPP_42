/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 09:19:59 by mvachon           #+#    #+#             */
/*   Updated: 2025/12/12 14:33:48 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() 
{
	_type = "WrongCat";
	std::cout << "Constructor WrongCat called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
	*this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "Constructor WrongCat deleted" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat sound" << std::endl;
}