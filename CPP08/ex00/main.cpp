/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:26:51 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/30 18:41:26 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main()
{
    try
    {
        std::vector<int> v;
        v.push_back(1);
        v.push_back(3);
        v.push_back(5);

        std::vector<int>::iterator it = easyfind(v, 3);
        std::cout << "Found: " << *it << std::endl;

        it = easyfind(v, 42);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::list<int> l;
    l.push_back(10);
    l.push_back(20);

    try
    {
        std::list<int>::iterator it = easyfind(l, 20);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
