/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:53:11 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/09 14:59:10 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

Form::Form()
    : gradeToExec(20), gradeToSign(10), isSigned(0)
{
    std::cout << "Form created" << std::endl;
}

Form::Form(const Form& other)
    : gradeToExec(20), gradeToSign(10), isSigned(0)
{
    *this = other;
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

Form::~Form()
{
    std::cout << "Form deleted" << std::endl;
}