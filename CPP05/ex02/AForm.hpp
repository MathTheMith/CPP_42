/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:49:44 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/16 12:54:21 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{

    private:
        const std::string _name;
        const int _gradeToExec;
        const int _gradeToSign;
        bool _isSigned;
        
    protected:
            virtual void executeAction() const = 0;

    public:
        AForm();
        AForm(std::string name, const int gradeToExec, const int gradeToSign);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        std::string getName() const;
        int getGradeToSign() const;
        int getGradeToExec() const;
        bool getIsSigned() const;
        virtual void execute(Bureaucrat const & executor) const;
        void beSigned(Bureaucrat& other);
        virtual ~AForm(); 
};
    
class FormNotSigned : public std::exception
{
    public:
        virtual const char* what() const throw();
};

#endif