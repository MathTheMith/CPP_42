/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:54:39 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/17 11:41:24 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base()
{}

Base::~Base()
{}

void Base::identify(Base *p)
{
    A* a_ptr = dynamic_cast<A*>(p);
    B* b_ptr = dynamic_cast<B*>(p);
    C* c_ptr = dynamic_cast<C*>(p);
    if (a_ptr != NULL)
        std::cout << "Pointer found A" << std::endl;
    else if (b_ptr != NULL)
        std::cout << "Pointer found B" << std::endl;
    else if (c_ptr != NULL)
        std::cout << "Pointer found C" << std::endl;
}

void Base::identify(Base &p)
{
    try
    {
        A &a_ref = dynamic_cast<A&>(p);
        (void)a_ref;
        std::cout << "Reference found A" << std::endl;
        return;
    }
    catch(const std::exception& e)
    {
        // std::cout << "Not A" << std::endl;
    }
    
    try
    {
        B &b_ref = dynamic_cast<B&>(p);
        (void)b_ref;
        std::cout << "Reference found B" << std::endl;
        return;
    }
    catch(const std::exception& e)
    {
        // std::cout << "Not B" << std::endl;
    }
    
    try
    {
        C &c_ref = dynamic_cast<C&>(p);
        (void)c_ref;
        std::cout << "Reference found C" << std::endl;
        return;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Unknown type" << std::endl;
    }
}

Base* Base::generate()
{
    int i = rand() % 3;
    if (i == 0)
    {
        std::cout << "A called" << std::endl;
        return new A;
    }
    else if (i == 1)
    {
        std::cout << "B called" << std::endl;
        return new B;
    }
    else
    {
        std::cout << "C called" << std::endl;
        return new C;
    }
}
