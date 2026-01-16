/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 10:03:36 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/16 11:27:49 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 5, 25), _target(target)
{
    // std::cout << "PresidentialPardonForm created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
{
    *this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

void  PresidentialPardonForm::executeAction() const
{
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    // std::cout << "PresidentialPardonForm deleted" << std::endl;
}