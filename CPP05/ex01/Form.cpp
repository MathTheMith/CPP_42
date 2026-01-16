/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:53:11 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/16 13:48:13 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form()
    : _name("Form"), _gradeToExec(20), _gradeToSign(10), _isSigned(false)
{
    std::cout << "Form created" << std::endl;
}

Form::Form(std::string name, const int gradeToExec, const int gradeToSign)
    : _name(name), _gradeToExec(gradeToExec), _gradeToSign(gradeToSign), _isSigned(false)
{

    if (gradeToExec < 1 || gradeToSign < 1)
        throw FormException();
    else if (gradeToExec > 150 || gradeToSign > 150)
        throw FormException();
    std::cout << "Form created" << std::endl;
}

Form::Form(const Form& other)
    : _gradeToExec(other.getGradeToExec()), _gradeToSign(other.getGradeToSign()), _isSigned(other.getIsSigned())
{
    *this = other;
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        this->_isSigned = other._isSigned;
    return *this;
}

int Form::getGradeToExec() const {return _gradeToExec;}
int Form::getGradeToSign() const {return _gradeToSign;}
std::string Form::getName() const {return _name;}
bool Form::getIsSigned() const {return _isSigned;}

const char* FormException::what() const throw() {
    return "The Form can be instanced";
}

void Form::beSigned(Bureaucrat& other)
{
    if (other.getGrade() <= this->getGradeToSign())
        this->_isSigned = true;
    else
    {
        throw GradeTooLowException();
    }
}

Form::~Form()
{
    std::cout << "Form deleted" << std::endl;
}