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
	type = "Dog";
	std::cout << "Constructor Dog called" << std::endl;
}

Dog &Dog::operator=(const Dog *other)
{
	if (this != other)
		this->type = other->type;
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