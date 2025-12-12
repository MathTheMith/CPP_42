/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:04:22 by marvin            #+#    #+#             */
/*   Updated: 2025/10/22 14:04:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "../includes/ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{

	public:
		static const int FtHitPoints = 100;
		static const int FtAttackDamage = 30;
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		FragTrap &operator=(const FragTrap &a);

		virtual ~FragTrap();
		void highFivesGuys() const;

};

#endif