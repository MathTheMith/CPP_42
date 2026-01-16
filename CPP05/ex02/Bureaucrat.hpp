/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:47:46 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/11 13:40:54 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat{
    
    private:
    const std::string _name;
    int _grade;
    
    public:
    
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();
    
    void incrementGrade();
    void decrementGrade();
    int getGrade() const;
    std::string getName() const;
    void setGrade(int grade);
    void signForm(AForm& form);
    void executeForm(AForm const & form) const;
};

class GradeTooLowException : public std::exception {
public:
    virtual const char* what() const throw();
};

class GradeTooHighException : public std::exception {
public:
    virtual const char* what() const throw();
};


std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif