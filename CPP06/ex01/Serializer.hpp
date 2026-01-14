/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:01:43 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/14 10:44:10 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <stdint.h>
#include <iostream>

struct Data
{
    std::string str;
    int nb;
    uintptr_t _void;
};

class Serializer
{
    private:
    
    public:
        static Data* deserialize(uintptr_t raw);
        static uintptr_t serialize(Data* ptr);
        Serializer();
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer& other);
        ~Serializer();
};

#endif