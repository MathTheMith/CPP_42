/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 09:19:59 by mvachon           #+#    #+#             */
/*   Updated: 2025/12/03 09:28:03 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() 
{
	type = "WrongCat";
	std::cout << "Constructor WrongCat called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat *other)
{
	if (this != other)
		this->type = other->type;
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