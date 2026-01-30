/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:52:25 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/16 17:32:04 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void print_double_int(char a)
{
    std::cout << a << a << std::endl;
}

int main( void )
{
    std::string str = "hello";
    ::iter(str, str.size(), print_double_int);
}