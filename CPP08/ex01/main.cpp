/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:49:44 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/30 19:58:50 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void)
{
    Span TSpan(5);
    
    try
    {
        for (int i = 0; i < 7; i++)
            TSpan.addNumber(i);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // int nb = 100000;
    // Span BigSpan(nb);
    // try
    // {
    //     srand (time(NULL));
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
    
    int LongTS = TSpan.longestSpan();
    int ShortTS = TSpan.shortestSpan();
    std::cout << "TSpan-> Longest: " << LongTS << "  Shortest: " << ShortTS << std::endl;
}