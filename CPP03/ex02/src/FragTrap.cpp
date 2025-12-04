/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:29:01 by marvin            #+#    #+#             */
/*   Updated: 2025/10/22 14:29:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"
#include "../includes/ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
{
    *this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &a)
{
    if (this != &a)
    {
        this->_attack_damage = a._attack_damage;
        this->_energy_points = a._energy_points;
        this->_hit_points = a._hit_points;
    }
    return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor FragTrap called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap ask for a positive high-fives request" << std::endl;
}