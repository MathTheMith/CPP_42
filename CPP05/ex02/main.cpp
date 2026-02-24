/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 13:22:42 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/16 14:17:33 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 1500);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << "\n--- Attempt to execute without signature ---\n";
        boss.executeForm(shrub);

        std::cout << "\n--- Signing the forms ---\n";
        intern.signForm(shrub);
        intern.signForm(robot);
        boss.signForm(robot);
        boss.signForm(pardon);

        std::cout << "\n--- Executing the forms ---\n";
        intern.executeForm(shrub);
        boss.executeForm(shrub);

        boss.executeForm(robot);
        boss.executeForm(pardon);

        std::cout << "\n--- Test with a bureaucrat with too low grade ---\n";
        intern.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}