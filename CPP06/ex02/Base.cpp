/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:54:39 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/14 13:40:57 by mvachon          ###   ########.fr       */
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
    A* a_ptr = dynamic_cast<A*>(&p);
    B* b_ptr = dynamic_cast<B*>(&p);
    C* c_ptr = dynamic_cast<C*>(&p);
    if (a_ptr != NULL)
        std::cout << "Reference found A" << std::endl;
    else if (b_ptr != NULL)
        std::cout << "Reference found B" << std::endl;
    else if (c_ptr != NULL)
        std::cout << "Reference found C" << std::endl;
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
