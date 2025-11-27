/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 04:47:50 by marvin            #+#    #+#             */
/*   Updated: 2025/10/17 04:47:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie* zombie = new Zombie(name);
    return zombie;
}

Zombie* zombieHorde(int N, std::string name)
{
    Zombie* horde = new Zombie[N];
    
    for (int i = 0; i < N; i++)
        horde[i].setName(name);
    return horde;
}

int main(void)
{
    int nb = 5;
    std::cout << "=== Creating a horde of zombies ===" << std::endl;
    Zombie* horde = zombieHorde(nb, "Jack");
    
    std::cout << "\n=== Making them announce ===" << std::endl;
    for (int i = 0; i < nb; i++) {
        horde[i].announce();
    }
    
    std::cout << "\n=== Destroying the horde ===" << std::endl;
    delete[] horde;
    
    std::cout << "\n=== End of program ===" << std::endl;
    return 0;
}