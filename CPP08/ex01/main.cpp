/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:49:44 by mvachon           #+#    #+#             */
/*   Updated: 2026/02/27 10:29:53 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <iostream>

int main(void)
{
    Span TSpan(5);
    
    try
    {
        for (int i = 0; i < 2; i+=1)
            TSpan.addNumber(i);
        int LongTS = TSpan.longestSpan();
        int ShortTS = TSpan.shortestSpan();
        std::cout << "TSpan-> Longest: " << LongTS << "  Shortest: " << ShortTS << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    // int nb = 100000;
    // Span BigSpan(nb);
    // try
    // {
    //     for (int i = 1; i < nb; i++)
    //         BigSpan.addNumber(rand() % nb);
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    // int LongBS = BigSpan.longestSpan();
    // int ShortBS = BigSpan.shortestSpan();
    // std::cout << "BigSpan-> Longest: " << LongBS << "  Shortest: " << ShortBS << std::endl;
}