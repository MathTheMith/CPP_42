/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 04:46:18 by marvin            #+#    #+#             */
/*   Updated: 2025/10/17 04:46:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {
    name = "";
}

Zombie::Zombie(std::string zombieName) {
    name = zombieName;
}

Zombie::~Zombie(void) {
    std::cout << name << " has been destroyed" << std::endl;
}

void Zombie::setName(std::string z_name) {
    name = z_name;
}

void Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}