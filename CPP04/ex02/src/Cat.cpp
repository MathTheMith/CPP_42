/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:44:18 by marvin            #+#    #+#             */
/*   Updated: 2025/10/22 14:44:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/Brain.hpp"

Cat::Cat() : brain(new Brain())
{
	_type = "Cat";
	std::cout << "Constructor Cat called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Constructor Cat deleted" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat sound" << std::endl;
}