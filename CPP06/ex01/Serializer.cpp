/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:09:47 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/13 15:39:03 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
    
}

Serializer::Serializer(const Serializer& other)
{
    *this = other;
}
Serializer& Serializer::operator=(const Serializer& other)
{
    return *this;
}

static Data* deserialize(uintptr_t raw)
{
    
}

static uintptr_t serialize(Data* ptr)
{
    
}

Serializer::~Serializer()
{

}