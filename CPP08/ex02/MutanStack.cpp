/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutanStack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 20:46:01 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/30 20:47:47 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutanStack.hpp"

MutanStack::MutanStack()
{
}

MutanStack::MutanStack(const MutanStack& other)
{
    *this = other;
}
MutanStack& MutanStack::operator=(const MutanStack& other)
{
    if (this != &other)
    {

    }
    return *this;
}

MutanStack::MutanStack()
{
}