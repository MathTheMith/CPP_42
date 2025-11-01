/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:36:36 by marvin            #+#    #+#             */
/*   Updated: 2025/10/22 12:36:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() 
	: hit_point(100), energy_point(10), attack_damage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: name(name), hit_point(100), energy_point(10), attack_damage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (hit_point == 0 || energy_point == 0)
    {
        std::cout << "No more hit points or energy points" << std::endl;
        return;
    }

    std::cout << name << " attacks " << target 
              << ", causing " << attack_damage << " points of damage!" << std::endl;
    energy_point--;
}


void ClapTrap::takeDamage(unsigned int amount)
{
    if (hit_point == 0 || energy_point == 0)
    {
        std::cout << "No more hit points or energy points" << std::endl;
        return;
    }

    hit_point -= amount;

    std::cout << name << " takes " << amount 
              << " points of damage, remaining HP: " << hit_point << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hit_point == 0 || energy_point == 0)
    {
        std::cout << "No more hit points or energy points" << std::endl;
        return;
    }

    hit_point += amount;
    energy_point--;

    std::cout << name << " is repaired by " << amount
              << " points, current HP: " << hit_point << std::endl;
}
