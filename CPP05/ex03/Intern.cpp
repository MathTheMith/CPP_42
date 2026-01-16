/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 10:03:36 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/11 14:23:35 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern&) {}

Intern& Intern::operator=(const Intern&)
{
    return *this;
}

Intern::~Intern() {}


static AForm* createShrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(std::string target)
{
    return new RobotomyRequestForm(target);
}

static AForm* createPresidential(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    std::string forms[3] =
    {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*creators[3])(std::string) =
    {
        &createShrubbery,
        &createRobotomy,
        &createPresidential
    };

    for (int i = 0; i < 3; i++)
    {
        if (name == forms[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return creators[i](target);
        }
    }

    std::cout << "Intern couldn’t create " << name << std::endl;
    return NULL;
}
