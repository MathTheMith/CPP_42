/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:54:41 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/14 13:39:18 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <cstdlib> 
#include <ctime> 
#include <iostream>

class Base
{
    private:
    

    public:
        Base();
        Base* generate(void);
        void identify(Base* p);
        void identify(Base& p);
        virtual ~Base();
};

#endif