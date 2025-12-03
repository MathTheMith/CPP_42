/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap_utils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 08:12:01 by mvachon           #+#    #+#             */
/*   Updated: 2025/12/03 08:12:22 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void ClapTrap::attack(const std::string& target)
{
    if (_hit_points == 0 || _energy_points == 0)
    {
        std::cout << "No more hit points or energy points" << std::endl;
        return;
    }

    std::cout << "ClapTrap " << _name << " attacks " << target 
              << ", causing " << _attack_damage << " points of damage!" << std::endl;
    _energy_points--;
}


void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hit_points == 0 || _energy_points == 0)
    {
        std::cout << "No more hit points or energy points" << std::endl;
        return;
    }

    _hit_points -= amount;

    std::cout << "ClapTrap " << _name << " takes " << amount 
              << " points of damage, remaining HP: " << _hit_points << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hit_points == 0 || _energy_points == 0)
    {
        std::cout << "No more hit points or energy points" << std::endl;
        return;
    }

    _hit_points += amount;
    _energy_points--;

    std::cout << "ClapTrap " << _name << " is repaired by " << amount
              << " points, current HP: " << _hit_points << std::endl;
}