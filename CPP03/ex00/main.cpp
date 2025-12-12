/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:33:50 by marvin            #+#    #+#             */
/*   Updated: 2025/12/12 12:33:50 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define RESET   "\033[0m"

void print_separator(std::string title)
{
    std::cout << "\n" << BLUE << "========================================" << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << "========================================" << RESET << "\n" << std::endl;
}

void test_basic_construction()
{
    print_separator("TEST 1: BASIC CONSTRUCTION");
    
    std::cout << YELLOW << "Creating default ClapTrap:" << RESET << std::endl;
    ClapTrap robot1;
    
    std::cout << "\n" << YELLOW << "Creating named ClapTrap (Bob):" << RESET << std::endl;
    ClapTrap robot2("Bob");
    
    std::cout << "\n" << GREEN << "Testing robot2 (Bob):" << RESET << std::endl;
    robot2.attack("target");
    robot2.takeDamage(3);
    robot2.beRepaired(2);
}

void test_copy_constructor()
{
    print_separator("TEST 2: COPY CONSTRUCTOR");
    
    std::cout << YELLOW << "Creating original ClapTrap (Alice):" << RESET << std::endl;
    ClapTrap original("Alice");
    
    std::cout << "\n" << YELLOW << "Modifying original:" << RESET << std::endl;
    original.attack("enemy1");
    original.takeDamage(5);
    
    std::cout << "\n" << YELLOW << "Creating copy via copy constructor:" << RESET << std::endl;
    ClapTrap copy(original);
    
    std::cout << "\n" << GREEN << "Testing copy (should have same state as original):" << RESET << std::endl;
    copy.attack("enemy2");
    copy.beRepaired(3);
    
    std::cout << "\n" << GREEN << "Testing original again (should be independent):" << RESET << std::endl;
    original.attack("enemy3");
}

void test_assignment_operator()
{
    print_separator("TEST 3: ASSIGNMENT OPERATOR");
    
    std::cout << YELLOW << "Creating ClapTrap 1 (Charlie):" << RESET << std::endl;
    ClapTrap robot1("Charlie");
    
    std::cout << "\n" << YELLOW << "Creating ClapTrap 2 (Diana):" << RESET << std::endl;
    ClapTrap robot2("Diana");
    
    std::cout << "\n" << YELLOW << "Modifying robot1:" << RESET << std::endl;
    robot1.attack("target1");
    robot1.takeDamage(4);
    
    std::cout << "\n" << YELLOW << "Assigning robot1 to robot2:" << RESET << std::endl;
    robot2 = robot1;
    
    std::cout << "\n" << GREEN << "Testing robot2 after assignment:" << RESET << std::endl;
    robot2.attack("target2");
    robot2.beRepaired(2);
    
    std::cout << "\n" << GREEN << "Testing robot1 (should be independent):" << RESET << std::endl;
    robot1.attack("target3");
}

void test_self_assignment()
{
    print_separator("TEST 4: SELF-ASSIGNMENT");
    
    std::cout << YELLOW << "Creating ClapTrap (Eve):" << RESET << std::endl;
    ClapTrap robot("Eve");
    
    
    std::cout << "\n" << GREEN << "Testing after self-assignment:" << RESET << std::endl;
    robot.attack("target");
    robot.takeDamage(2);
}

void test_chain_assignment()
{
    print_separator("TEST 5: CHAIN ASSIGNMENT");
    
    std::cout << YELLOW << "Creating 3 ClapTraps:" << RESET << std::endl;
    ClapTrap robot1("Frank");
    ClapTrap robot2("Grace");
    ClapTrap robot3("Henry");
    
    std::cout << "\n" << YELLOW << "Modifying robot1:" << RESET << std::endl;
    robot1.attack("enemy");
    robot1.takeDamage(3);
    
    std::cout << "\n" << YELLOW << "Chain assignment: robot3 = robot2 = robot1" << RESET << std::endl;
    robot3 = robot2 = robot1;
    
    std::cout << "\n" << GREEN << "Testing robot3 (should have robot1's state):" << RESET << std::endl;
    robot3.attack("target");
    robot3.beRepaired(1);
}

void test_energy_depletion()
{
    print_separator("TEST 6: ENERGY DEPLETION & COPY");
    
    std::cout << YELLOW << "Creating ClapTrap (Igor) and depleting energy:" << RESET << std::endl;
    ClapTrap robot1("Igor");
    
    for (int i = 0; i < 10; i++) {
        robot1.attack("dummy");
    }
    
    std::cout << "\n" << YELLOW << "Creating copy of depleted robot:" << RESET << std::endl;
    ClapTrap robot2(robot1);
    
    std::cout << "\n" << GREEN << "Testing copy (should also be out of energy):" << RESET << std::endl;
    robot2.attack("target");
    robot2.beRepaired(5);
}

void test_hp_zero_copy()
{
    print_separator("TEST 7: ZERO HP & COPY");
    
    std::cout << YELLOW << "Creating ClapTrap (Julia) and reducing HP to 0:" << RESET << std::endl;
    ClapTrap robot1("Julia");
    robot1.takeDamage(15);
    
    std::cout << "\n" << YELLOW << "Creating copy with assignment operator:" << RESET << std::endl;
    ClapTrap robot2("Temp");
    robot2 = robot1;
    
    std::cout << "\n" << GREEN << "Testing copy (should also be at 0 HP):" << RESET << std::endl;
    robot2.attack("ghost");
    robot2.beRepaired(10);
}

int main(void)
{
    std::cout << BLUE << "\n╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║  CLAPTRAP COPY & ASSIGNMENT TESTS      ║" << std::endl;
    std::cout << "╚════════════════════════════════════════╝" << RESET << std::endl;
    
    test_basic_construction();
    test_copy_constructor();
    test_assignment_operator();
    test_self_assignment();
    test_chain_assignment();
    test_energy_depletion();
    test_hp_zero_copy();
    
    print_separator("ALL TESTS COMPLETED");
    
    std::cout << RED << "\nNote: Check if:" << std::endl;
    std::cout << "  1. Copy constructor is called when expected" << std::endl;
    std::cout << "  2. Assignment operator works correctly" << std::endl;
    std::cout << "  3. Objects remain independent after copy" << std::endl;
    std::cout << "  4. All attributes are properly copied (including _name!)" << std::endl;
    std::cout << "  5. Self-assignment doesn't cause issues" << RESET << std::endl;
    
    return 0;
}