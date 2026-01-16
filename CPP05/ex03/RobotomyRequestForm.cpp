/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 09:50:37 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/11 13:36:26 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
{
    *this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

void  RobotomyRequestForm::executeAction() const
{
        static bool init = false;
        if (!init) {
            srand(time(0));
            init = true;
        }
        double val = (double)rand() / RAND_MAX;
        if (val < 0.5)
            std::cout << _target << " has been robotomized successfully" << std::endl;
        else
            std::cout << "Robotomy of " << _target << " failed" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    
}