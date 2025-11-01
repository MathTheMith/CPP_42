/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:11:04 by marvin            #+#    #+#             */
/*   Updated: 2025/10/17 13:11:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string first_type)
	: type(first_type) {}

std::string& Weapon::getType()
{
	return type;
}

void Weapon::setType(std::string new_type)
{
    type = new_type;
}
