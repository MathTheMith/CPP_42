/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:47:43 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/16 14:15:36 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
    : _name("Jhon"), _grade(20)
{
    // std::cout << "Constructor Bureaucrat created" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) 
    : _name(name)
{
    setGrade(grade);
    // std::cout << "Constructor Bureaucrat created" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : _name(other._name), _grade(other._grade)
{}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        this->_grade = other.getGrade();
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    // std::cout << "Bureaucrat deleted" << std::endl;
}

const char* GradeTooHighException::what() const throw() {
    return "Grade of the Bureaucrat too high";
}

const char* GradeTooLowException::what() const throw() {
    return "Grade of the Bureaucrat too low";
}

void Bureaucrat::setGrade(int grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
        this->_grade = grade;
}

int Bureaucrat::getGrade() const {return this->_grade;}
std::string Bureaucrat::getName() const {return this->_name;}

void Bureaucrat::incrementGrade()
{
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}