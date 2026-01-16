/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 14:24:05 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/16 11:11:03 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat boss("Boss", 1);
    Bureaucrat junior("Junior", 150);
    Intern someRandomIntern;

    AForm* form;

    std::cout << "\n--- Test 1: RobotomyRequestForm ---\n";
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form)
    {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    std::cout << "\n--- Test 2: ShrubberyCreationForm ---\n";
    form = someRandomIntern.makeForm("shrubbery creation", "home");
    if (form)
    {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    std::cout << "\n--- Test 3: PresidentialPardonForm ---\n";
    form = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
    if (form)
    {
        junior.signForm(*form);
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    std::cout << "\n--- Test 4: Unknown form ---\n";
    form = someRandomIntern.makeForm("unknown form", "Nobody");
    if (!form)
        std::cout << "Form was not created (as expected)\n";

    return 0;
}
