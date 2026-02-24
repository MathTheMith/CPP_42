/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 06:59:53 by mvachon           #+#    #+#             */
/*   Updated: 2026/02/24 08:40:10 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int parseArgs(std::string &nbList, char **av)
{
    int j = 0;
    for(size_t i = 0; av[1][i]; i++)
    {
        if (isspace(av[1][i]) || av[1][i] == '\0')
            continue;
        else if (av[1][i] == '+' || av[1][i] == '-' || av[1][i] == '/' || av[1][i] == '*')
            nbList += av[1][i];
        else if (av[1][i] >= '0' && av[1][i] <= '9')
            nbList += av[1][i];
        else
            throw std::runtime_error("Error");
        j++;
    } 
    return 0;
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "The program need one argument" << std::endl;
        return 1;
    }
    std::string listArg;
    try
    {
        parseArgs(listArg, av);
        RPN RPN;
        RPN.solveRPN(listArg);
        // for(size_t i = 0; i < listArg.size(); i++)
        //     std::cout << listArg[i];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
}