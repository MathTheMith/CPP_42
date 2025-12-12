/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:40:02 by marvin            #+#    #+#             */
/*   Updated: 2025/10/22 14:40:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal()
{
	std::cout << "Constructor Animal called" << std::endl;
}

Animal &Animal::operator=(const Animal *other)
{
	if (this != other)
		this->type = other->type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Constructor Animal deleted" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const {return type;}