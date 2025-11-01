/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:29:54 by marvin            #+#    #+#             */
/*   Updated: 2025/10/17 12:29:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB {
private:
    std::string name;
    Weapon *weapon;

public:
    HumanB(std::string new_name) : name(new_name), weapon(NULL) {}

    void setWeapon(Weapon& newWeapon) {
        weapon = &newWeapon;
    }

    void attack();
};

#endif