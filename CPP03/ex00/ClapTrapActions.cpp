/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrapActions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 08:12:01 by mvachon           #+#    #+#             */
/*   Updated: 2025/12/12 08:43:41 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void ClapTrap::attack(const std::string& target)
{
    if (this->_hit_points <= 0 || this->_energy_points <= 0)
    {
        std::cout << "No more hit points or energy points" << std::endl;
        return;
    }

    std::cout << "Player " << this->_name << " attacks " << target 
              << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
    this->_energy_points--;
}


void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hit_points <= 0)
    {
        std::cout << "No more hit points" << std::endl;
        return;
    }

    this->_hit_points -= amount;

    std::cout << "Player " << this->_name << " takes " << amount 
              << " points of damage, remaining HP: " << this->_hit_points << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hit_points <= 0 || this->_energy_points <= 0)
    {
        std::cout << "No more hit points or energy points" << std::endl;
        return;
    }

    this->_hit_points += amount;
    this->_energy_points--;

    std::cout << "Player " << this->_name << " is repaired by " << amount
              << " points, current HP: " << this->_hit_points << std::endl;
}