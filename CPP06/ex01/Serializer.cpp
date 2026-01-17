/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:09:47 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/17 09:34:03 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
    // std::cout << "Serializer created" << std::endl;
}

Serializer::Serializer(const Serializer& other)
{
    *this = other;
}
Serializer& Serializer::operator=(const Serializer& other)
{
    (void)other;
    return *this;
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Serializer::~Serializer()
{
    // std::cout << "Serializer deleted" << std::endl;
}