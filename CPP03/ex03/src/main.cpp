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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:00:00 by mvachon           #+#    #+#             */
/*   Updated: 2025/12/04 10:00:00 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/DiamondTrap.hpp"

void print_separator(std::string title)
{
    std::cout << "\n========================================" << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << "========================================\n" << std::endl;
}

void test_claptrap()
{
    print_separator("TEST CLAPTRAP");
    
    std::cout << "--- Construction ---" << std::endl;
    ClapTrap ct1;
    ClapTrap ct2("John");
    
    std::cout << "\n--- Copie ---" << std::endl;
    ClapTrap ct3(ct2);
    ClapTrap ct4 = ct2;
    
    std::cout << "\n--- Actions basiques ---" << std::endl;
    ct2.attack("Target1");
    ct2.takeDamage(5);
    ct2.beRepaired(3);
    
    std::cout << "\n--- Test limites énergie ---" << std::endl;
    for (int i = 0; i < 11; i++) {
        std::cout << "Action " << i + 1 << ": ";
        ct2.attack("Target");
    }
    
    std::cout << "\n--- Test HP à zéro ---" << std::endl;
    ClapTrap ct5("Dying");
    ct5.takeDamage(15);
    ct5.attack("Ghost");
    ct5.beRepaired(5);
    
    std::cout << "\n--- Destruction ---" << std::endl;
}

void test_scavtrap()
{
    print_separator("TEST SCAVTRAP");
    
    std::cout << "--- Construction ---" << std::endl;
    ScavTrap st1;
    ScavTrap st2("Bob");
    
    std::cout << "\n--- Copie ---" << std::endl;
    ScavTrap st3(st2);
    ScavTrap st4 = st2;
    
    std::cout << "\n--- Actions basiques ---" << std::endl;
    st2.attack("Enemy1");
    st2.takeDamage(30);
    st2.beRepaired(20);
    st2.guardGate();
    
    std::cout << "\n--- Test limites énergie (50 points) ---" << std::endl;
    ScavTrap st5("Energetic");
    for (int i = 0; i < 52; i++) {
        if (i % 10 == 0)
            std::cout << "\nAction " << i + 1 << "-" << i + 10 << ":" << std::endl;
        st5.attack("Dummy");
    }
    
    std::cout << "\n--- Destruction ---" << std::endl;
}

void test_fragtrap()
{
    print_separator("TEST FRAGTRAP");
    
    std::cout << "--- Construction ---" << std::endl;
    FragTrap ft1;
    FragTrap ft2("Jack");
    
    std::cout << "\n--- Copie ---" << std::endl;
    FragTrap ft3(ft2);
    FragTrap ft4 = ft2;
    
    std::cout << "\n--- Actions basiques ---" << std::endl;
    ft2.attack("Enemy2");
    ft2.takeDamage(40);
    ft2.beRepaired(25);
    ft2.highFivesGuys();
    
    std::cout << "\n--- Test dégâts élevés ---" << std::endl;
    FragTrap ft5("Tough");
    ft5.takeDamage(90);
    ft5.beRepaired(50);
    ft5.takeDamage(65);
    ft5.attack("LastEnemy");
    
    std::cout << "\n--- Destruction ---" << std::endl;
}

void test_diamondtrap()
{
    print_separator("TEST DIAMONDTRAP");
    
    std::cout << "--- Construction ---" << std::endl;
    DiamondTrap dt1;
    DiamondTrap dt2("Paul");
    
    std::cout << "\n--- Copie ---" << std::endl;
    DiamondTrap dt3(dt2);
    DiamondTrap dt4 = dt2;
    
    std::cout << "\n--- Test whoAmI ---" << std::endl;
    dt1.whoAmI();
    dt2.whoAmI();
    dt3.whoAmI();
    
    std::cout << "\n--- Actions basiques ---" << std::endl;
    dt2.attack("Enemy3");  // Devrait utiliser ScavTrap::attack
    dt2.takeDamage(50);
    dt2.beRepaired(30);
    
    std::cout << "\n--- Test méthodes spécifiques ---" << std::endl;
    dt2.guardGate();      // De ScavTrap
    dt2.highFivesGuys();  // De FragTrap
    
    std::cout << "\n--- Test stats héritées ---" << std::endl;
    DiamondTrap dt5("TestStats");
    std::cout << "Test avec 100 HP (FragTrap), 50 Energy (ScavTrap), 30 Attack (FragTrap)" << std::endl;
    for (int i = 0; i < 52; i++) {
        if (i % 10 == 0)
            std::cout << "\nActions " << i + 1 << "-" << i + 10 << ":" << std::endl;
        dt5.attack("Training");
    }
    
    std::cout << "\n--- Test limites combinées ---" << std::endl;
    DiamondTrap dt6("Combined");
    dt6.takeDamage(95);
    dt6.beRepaired(10);
    dt6.attack("Final");
    dt6.takeDamage(20);
    dt6.attack("Ghost");
    dt6.whoAmI();
    
    std::cout << "\n--- Destruction ---" << std::endl;
}

int main()
{
    test_claptrap();
    test_scavtrap();
    test_fragtrap();
    test_diamondtrap();
    
    print_separator("FIN DES TESTS");
    std::cout << "Tous les tests sont terminés !" << std::endl;
    
    return 0;
}
