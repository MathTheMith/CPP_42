/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:36:49 by mvachon           #+#    #+#             */
/*   Updated: 2025/12/11 11:36:49 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/DiamondTrap.hpp"

#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

void print_separator(std::string title)
{
    std::cout << BLUE << "\n========================================" << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << "========================================\n" << RESET << std::endl;
}

void test_claptrap()
{
    print_separator("CLAPTRAP TEST");
    
    std::cout << YELLOW << "--- Construction ---" << RESET << std::endl;
    ClapTrap ct1;
    ClapTrap ct2("John");
    
    std::cout << "\n" << YELLOW << "--- Copy ---" << RESET << std::endl;
    ClapTrap ct3(ct2);
    ClapTrap ct4 = ct2;
    
    std::cout << "\n" << YELLOW << "--- Basic actions ---" << RESET << std::endl;
    ct2.attack("Target1");
    ct2.takeDamage(5);
    ct2.beRepaired(3);
    
    std::cout << "\n" << YELLOW << "--- Energy limit test ---" << RESET << std::endl;
    for (int i = 0; i < 11; i++) {
        std::cout << "Action " << i + 1 << ": ";
        ct2.attack("Target");
    }
    
    std::cout << "\n" << YELLOW << "--- HP zero test ---" << RESET << std::endl;
    ClapTrap ct5("Dying");
    ct5.takeDamage(15);
    ct5.attack("Ghost");
    ct5.beRepaired(5);
    
    std::cout << "\n" << RED << "--- Destruction ---" << RESET << std::endl;
}

void test_scavtrap()
{
    print_separator("SCAVTRAP TEST");
    
    std::cout << YELLOW << "--- Construction ---" << RESET << std::endl;
    ScavTrap st1;
    ScavTrap st2("Bob");
    
    std::cout << "\n" << YELLOW << "--- Copy ---" << RESET << std::endl;
    ScavTrap st3(st2);
    ScavTrap st4 = st2;
    
    std::cout << "\n" << YELLOW << "--- Basic actions ---" << RESET << std::endl;
    st2.attack("Enemy1");
    st2.takeDamage(30);
    st2.beRepaired(20);
    st2.guardGate();
    
    std::cout << "\n" << YELLOW << "--- Energy limit test (50 points) ---" << RESET << std::endl;
    ScavTrap st5("Energetic");
    for (int i = 0; i < 52; i++) {
        if (i % 10 == 0)
            std::cout << "\nAction " << i + 1 << "-" << i + 10 << ":" << std::endl;
        st5.attack("Dummy");
    }
    
    std::cout << "\n" << RED << "--- Destruction ---" << RESET << std::endl;
}

void test_fragtrap()
{
    print_separator("FRAGTRAP TEST");
    
    std::cout << YELLOW << "--- Construction ---" << RESET << std::endl;
    FragTrap ft1;
    FragTrap ft2("Jack");
    
    std::cout << "\n" << YELLOW << "--- Copy ---" << RESET << std::endl;
    FragTrap ft3(ft2);
    FragTrap ft4 = ft2;
    
    std::cout << "\n" << YELLOW << "--- Basic actions ---" << RESET << std::endl;
    ft2.attack("Enemy2");
    ft2.takeDamage(40);
    ft2.beRepaired(25);
    ft2.highFivesGuys();
    
    std::cout << "\n" << YELLOW << "--- High damage test ---" << RESET << std::endl;
    FragTrap ft5("Tough");
    ft5.takeDamage(90);
    ft5.beRepaired(50);
    ft5.takeDamage(65);
    ft5.attack("LastEnemy");
    
    std::cout << "\n" << RED << "--- Destruction ---" << RESET << std::endl;
}

void test_diamondtrap()
{
    print_separator("DIAMONDTRAP TEST");
    
    std::cout << YELLOW << "--- Construction ---" << RESET << std::endl;
    DiamondTrap dt1;
    DiamondTrap dt2("Paul");
    
    std::cout << "\n" << YELLOW << "--- Copy ---" << RESET << std::endl;
    DiamondTrap dt3(dt2);
    DiamondTrap dt4 = dt2;
    
    std::cout << "\n" << YELLOW << "--- whoAmI test ---" << RESET << std::endl;
    dt1.whoAmI();
    dt2.whoAmI();
    dt3.whoAmI();
    
    std::cout << "\n" << YELLOW << "--- Basic actions ---" << RESET << std::endl;
    dt2.attack("Enemy3");
    dt2.takeDamage(50);
    dt2.beRepaired(30);
    
    std::cout << "\n" << YELLOW << "--- Specific methods test ---" << RESET << std::endl;
    dt2.guardGate();
    dt2.highFivesGuys(); 
    
    std::cout << "\n" << YELLOW << "--- Inherited stats test ---" << RESET << std::endl;
    DiamondTrap dt5("TestStats");
    std::cout << "Testing with 100 HP (FragTrap), 50 Energy (ScavTrap), 30 Attack (FragTrap)" << std::endl;
    for (int i = 0; i < 52; i++) {
        if (i % 10 == 0)
            std::cout << "\nActions " << i + 1 << "-" << i + 10 << ":" << std::endl;
        dt5.attack("Training");
    }
    
    std::cout << "\n" << YELLOW << "--- Combined limits test ---" << RESET << std::endl;
    DiamondTrap dt6("Combined");
    dt6.takeDamage(95);
    dt6.beRepaired(10);
    dt6.attack("Final");
    dt6.takeDamage(20);
    dt6.attack("Ghost");
    dt6.whoAmI();
    
    std::cout << "\n" << RED << "--- Destruction ---" << RESET << std::endl;
}

int main()
{
    test_claptrap();
    test_scavtrap();
    test_fragtrap();
    test_diamondtrap();
    
    print_separator("END OF TESTS");
    return 0;
}
