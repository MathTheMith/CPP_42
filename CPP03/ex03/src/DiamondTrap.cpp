/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:22:42 by mvachon           #+#    #+#             */
/*   Updated: 2025/12/03 12:55:46 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/ScavTrap.hpp"

DiamondTrap::DiamondTrap() : _name("Default")
{
    std::cout << "DiamondTrap constructor called" << std::endl;
}


DiamondTrap::DiamondTrap(std::string name) : _name(name)
{
    ClapTrap ct;
    _CtName = ct.GetCtName() + "_clap_name";
	std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &a)
{
    if (this != &a)
    {
        FragTrap::_attack_damage = a.FragTrap::_attack_damage;
        ScavTrap::_energy_points = a.ScavTrap::_energy_points;
        FragTrap::_hit_points = a.FragTrap::_hit_points;
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}