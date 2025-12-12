/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:21:27 by mvachon           #+#    #+#             */
/*   Updated: 2025/12/12 08:26:05 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "../includes/FragTrap.hpp"
#include "../includes/ScavTrap.hpp"

class DiamondTrap :public FragTrap,
					public ScavTrap{

	private :
		std::string _name;

	public :
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap &operator=(const DiamondTrap &a);
		
		~DiamondTrap();

		void attack(const std::string& target);
		void whoAmI() const;
};

#endif