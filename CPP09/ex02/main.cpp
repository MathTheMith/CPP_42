/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 08:54:05 by mvachon           #+#    #+#             */
/*   Updated: 2026/02/24 09:23:47 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
#include <cerrno>
#include <limits>

long getInt(const char* str) {
    if (str == '\0')
        return false;

    char* end;
    errno = 0;
    long val = std::strtol(str, &end, 10);
    if (val > std::numeric_limits<int>::max())
        return -1;
    if (!(*end == '\0' && errno == 0))
        return (-1);
    return val;
}

int main(int ac, char **av)
{
    std::list<long> list;
    long nb = 0;
    
    for(int i = 1; i < ac; i++)
    {
        nb = getInt(av[i]);
        if (nb == -1)
        {
            std::cout << "not good" << std::endl;
            return 1;
        }
        list.push_back(nb);
    }
    for(int i = 0; i < list.size(); i++)
    {
        
    }
}