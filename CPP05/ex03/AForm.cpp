/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:53:11 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/11 13:45:23 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm()
    : _name("AForm"), _gradeToExec(20), _gradeToSign(10), _isSigned(false)
{
    std::cout << "AForm created" << std::endl;
}

AForm::AForm(std::string name, const int gradeToExec, const int gradeToSign)
    : _name(name), _gradeToExec(gradeToExec), _gradeToSign(gradeToSign), _isSigned(false)
{
    std::cout << "AForm created" << std::endl;
}

AForm::AForm(const AForm& other)
    : _name(other._name),
      _gradeToExec(other._gradeToExec),
      _gradeToSign(other._gradeToSign),
      _isSigned(other._isSigned)
{}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        this->_isSigned = other._isSigned;
    return *this;
}

int AForm::getGradeToExec() const {return _gradeToExec;}
int AForm::getGradeToSign() const {return _gradeToSign;}
std::string AForm::getName() const {return _name;}
bool AForm::getIsSigned() const {return _isSigned;}

void AForm::beSigned(Bureaucrat& other)
{
    if (other.getGrade() <= this->getGradeToSign())
        this->_isSigned = true;
    else
    {
        throw GradeTooLowException();
    }
}

const char* FormNotSigned::what() const throw()
{
    return "Form is not signed";
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned())
        throw FormNotSigned();

    if (executor.getGrade() >= getGradeToExec())
        throw GradeTooLowException();

    executeAction();
}

AForm::~AForm()
{
    std::cout << "AForm deleted" << std::endl;
}