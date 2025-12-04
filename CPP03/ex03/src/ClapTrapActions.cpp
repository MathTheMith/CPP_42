/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrapActions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 08:12:01 by mvachon           #+#    #+#             */
/*   Updated: 2025/12/04 10:15:37 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

void ClapTrap::attack(const std::string& target)
{
    if (this->_hit_points <= 0 || this->_energy_points <= 0)
    {
        std::cout << "ClapTrap " << this->_name 
                  << " can't attack: no hit points or energy points!" << std::endl;
        return;
    }

    std::cout << "ClapTrap " << this->_name << " attacks " << target 
              << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
    this->_energy_points--;
}


void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hit_points <= 0)
    {
        std::cout << "ClapTrap " << this->_name 
                  << " is already destroyed!" << std::endl;
        return;
    }

    this->_hit_points -= amount;
    
    if (this->_hit_points < 0)
        this->_hit_points = 0;

    std::cout << "ClapTrap " << this->_name << " takes " << amount 
              << " points of damage, remaining HP: " << this->_hit_points << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hit_points <= 0)
    {
        std::cout << "ClapTrap " << this->_name 
                  << " can't be repaired: destroyed!" << std::endl;
        return;
    }
    
    if (this->_energy_points <= 0)
    {
        std::cout << "ClapTrap " << this->_name 
                  << " can't be repaired: no energy points!" << std::endl;
        return;
    }

    this->_hit_points += amount;
    this->_energy_points--;

    std::cout << "ClapTrap " << this->_name << " is repaired by " << amount
              << " points, current HP: " << this->_hit_points << std::endl;
}