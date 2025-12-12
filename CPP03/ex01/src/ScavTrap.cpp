/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:06:11 by marvin            #+#    #+#             */
/*   Updated: 2025/10/22 14:06:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
    *this = other;
}


ScavTrap &ScavTrap::operator=(const ScavTrap &a)
{
    if (this != &a)
    {
        this->_attack_damage = a._attack_damage;
        this->_energy_points = a._energy_points;
        this->_hit_points = a._hit_points;
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor ScavTrap called" << std::endl;
}

void ScavTrap::guardGate()
{
    if (this->_hit_points <= 0 || this->_energy_points <= 0)
    {
        std::cout << "No more hit points or energy points" << std::endl;
        return;
    }

	std::cout << "Player " <<  this->_name << " is now in Gate keeper mode" << std::endl;
}