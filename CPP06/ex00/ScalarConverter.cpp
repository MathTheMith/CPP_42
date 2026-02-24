/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 14:31:59 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/31 16:03:45 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <iomanip>
#include <cmath> 

ScalarConverter::ScalarConverter()
{
    // std::cout << "ScalarConverter created" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}
void ScalarConverter::Converter(const std::string& literal)
{
    if (literal.length() == 1 && !std::isdigit(literal[0]))
    {
        char c = literal[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return;
    }

    std::string cleanLiteral = literal;
    if (literal.length() > 1 && literal[literal.length() - 1] == 'f')
        cleanLiteral = literal.substr(0, literal.length() - 1);

    std::string specials[] = {"nan", "+inf", "-inf", "inf"};
    
    int i = 0;
    while (i < 4)
    {
        if (cleanLiteral == specials[i])
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << cleanLiteral;
            if (cleanLiteral != "nan")
                std::cout << "f";
            else
                std::cout << "f";
            std::cout << std::endl;
            std::cout << "double: " << cleanLiteral << std::endl;
            return;
        }
        i++;
    }

    double d = 0;
    bool valid = true;

    std::stringstream ss(cleanLiteral);
    ss >> d;
    if (ss.fail() || !ss.eof())
        valid = false;
    if (!valid || std::isnan(d) || std::isinf(d) || 
        d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else if (d < 32 || d > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

    if (!valid || std::isnan(d) || std::isinf(d) ||
        d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;

    if (!valid)
    {
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
    else
    {
        std::cout << "float: " << static_cast<float>(d) << 
            (std::floor(static_cast<float>(d)) != static_cast<float>(d) ? "f" : ".0f") << std::endl;
        std::cout << "double: " << d <<
            (std::floor(static_cast<float>(d)) != static_cast<float>(d) ? "" : ".0") << std::endl;
    }
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter deleted" << std::endl;
}