/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:21:27 by mvachon           #+#    #+#             */
/*   Updated: 2025/12/03 12:55:37 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "../includes/FragTrap.hpp"
#include "../includes/ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap{

	protected :
		std::string _name;
        std::string _CtName;
	public :
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap &operator=(const DiamondTrap &a);

		~DiamondTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif