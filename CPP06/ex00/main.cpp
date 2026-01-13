/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 14:51:26 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/13 13:24:57 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int main()
{
    std::string inputs[] = {
        "0",
        "nan",
        "3.14",
        "42.0f",
        "nanf",
        // "-inf",
        // "300",
        // "non_number"
    };

    for (size_t i = 0; i < sizeof(inputs)/sizeof(inputs[0]); ++i)
    {
        std::cout << "\n--- Testing literal: " << inputs[i] << " ---\n";
        ScalarConverter::Converter(inputs[i]);
    }

    return 0;
}
