/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:47:39 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/16 14:16:44 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat alice("Alice", 2);
        std::cout << alice << std::endl;

        alice.incrementGrade();
        std::cout << alice << std::endl;

        alice.incrementGrade(); 
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bob("Bob", 20);
        std::cout << bob << std::endl;
        Bureaucrat bobTest(bob);
        bobTest.setGrade(200);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
