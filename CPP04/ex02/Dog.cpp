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

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : brain(new Brain()) 
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
	delete brain;
	std::cout << "Constructor Dog deleted" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog sound" << std::endl;
}