/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:47:30 by marvin            #+#    #+#             */
/*   Updated: 2025/10/22 14:47:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Animal.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << "Constructor Dog called" << std::endl;
}

Dog::Dog(const Dog &other)
{
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Constructor Dog deleted" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog sound" << std::endl;
}