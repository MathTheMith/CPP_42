/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:15:46 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/14 10:44:38 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data test;
    test.str = "42";
    test.nb = 42;
    test._void = 42;

    uintptr_t raw = Serializer::serialize(&test);
    Data* result = Serializer::deserialize(raw);

    std::cout << result->str << std::endl;
    std::cout << result->nb << std::endl;
    std::cout << result->_void << std::endl;
}
