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

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ScavTrap st("Bob");
    FragTrap t("Jack");
    // ClapTrap p("Jhon");
    st.attack("Ennemy");
    st.takeDamage(30);
    st.beRepaired(20);
    st.guardGate();
    t.attack("Ennemy");
    t.takeDamage(30);
    t.beRepaired(20);
    t.highFivesGuys();
    // p.attack("Ennemy");
    // p.takeDamage(30);
    // p.beRepaired(20);

    return 0;
}
