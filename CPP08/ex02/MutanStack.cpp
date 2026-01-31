/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutanStack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 20:46:01 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/31 09:07:25 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutanStack.hpp"

MutanStackClass::MutanStackClass()
{
}

MutanStackClass::MutanStackClass(const MutanStackClass& other)
{
    *this = other;
}
MutanStackClass& MutanStackClass::operator=(const MutanStackClass& other)
{
    if (this != &other)
    {

    }
    return *this;
}

MutanStackClass::~MutanStackClass()
{
}