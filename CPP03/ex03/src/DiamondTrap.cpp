/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:22:42 by mvachon           #+#    #+#             */
/*   Updated: 2025/12/04 09:58:43 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/ScavTrap.hpp"

DiamondTrap::DiamondTrap() : _name("Default")
{
    this->ClapTrap::_name = "Default_clap_name";
    this->_hit_points = FragTrap::FtHitPoints;
    this->_attack_damage = FragTrap::FtAttackDamage;
    this->_energy_points = ScavTrap::StEnergyPoints;

    std::cout << "DiamondTrap constructor called" << std::endl;
}


DiamondTrap::DiamondTrap(std::string name) : _name(name)
{
    this->ClapTrap::_name = name + "_clap_name";
    this->_hit_points = FragTrap::FtHitPoints;
    this->_attack_damage = FragTrap::FtAttackDamage;
    this->_energy_points = ScavTrap::StEnergyPoints;

    std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) 
{
    *this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        this->ClapTrap::_name = other.ClapTrap::_name;
        this->_name = other._name;
        this->_attack_damage = other.FtAttackDamage;
        this->_energy_points = other.StEnergyPoints;
        this->_hit_points = other.FtHitPoints;
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

void DiamondTrap::whoAmI()
{
    std::cout << "My name: " << this->_name << 
        "\nMy ClapTrap name: " <<  ClapTrap::_name << std::endl;
}