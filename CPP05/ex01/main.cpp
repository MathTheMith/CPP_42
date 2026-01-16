/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:47:39 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/16 13:48:30 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        std::cout << "=== Bureaucrat creation ===" << std::endl;
        Bureaucrat bob("Bob", 5);
        Bureaucrat jim("Jim", 50);

        std::cout << bob << std::endl;
        std::cout << jim << std::endl;

        std::cout << "\n=== Form creation ===" << std::endl;
        Form taxForm("The Form", 20, 10);

        std::cout << "Form name: " << taxForm.getName() << std::endl;
        std::cout << "Grade required to sign: "
                  << taxForm.getGradeToSign() << std::endl;

        std::cout << "\n=== Jim tries to sign the form ===" << std::endl;
        jim.signForm(taxForm);

        std::cout << "\n=== Bob tries to sign the form ===" << std::endl;
        bob.signForm(taxForm);

        std::cout << "\n=== Final form status ===" << std::endl;
        std::cout << "Signed? "
                  << (taxForm.getIsSigned() ? "yes" : "no")
                  << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught in main: "
                  << e.what() << std::endl;
    }

    return 0;
}

