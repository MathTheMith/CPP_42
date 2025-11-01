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
int main()
{
    ScavTrap st("Bob");
    ClapTrap p("Jhon");

    st.attack("Ennemy");
    st.takeDamage(30);
    st.beRepaired(20);
    st.guardGate();
    p.attack("Ennemy");
    p.takeDamage(30);
    p.beRepaired(20);

    return 0;
}
