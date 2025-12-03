/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:33:50 by marvin            #+#    #+#             */
/*   Updated: 2025/10/22 12:33:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/DiamondTrap.hpp"

int main()
{
    std::cout << "scavtrap" << std::endl;
    ScavTrap st("Bob");
    st.attack("Ennemy");
    st.takeDamage(30);
    st.beRepaired(20);
    st.guardGate();

    std::cout << "\nfragtrap" << std::endl;
    FragTrap ft("Jack");
    ft.attack("Ennemy");
    ft.beRepaired(20);
    ft.takeDamage(30);
    ft.highFivesGuys();

    std::cout << "\ndiamondtrap" << std::endl;
    DiamondTrap dt("Paul");
    dt.attack("Ennemy2");

    std::cout << "\nClaptrap\n";
    ClapTrap p("Jhon");
    // dt.takeDamage(30);
    // dt.beRepaired(20);
    p.attack("Ennemy");
    p.takeDamage(30);
    p.beRepaired(20);

    std::cout << "\n";

    return 0;
}
