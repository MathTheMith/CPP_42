/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 08:23:07 by mvachon           #+#    #+#             */
/*   Updated: 2026/02/21 11:49:56 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::string, std::string> GetData()
{
    std::map<std::string, std::string> values;

    std::ifstream file("data.csv");

    if (!file.is_open())
    {
        std::cout << "Error : can't open the file" << std::endl;
        return values;
    }

    std::string line;
    while (std::getline(file, line))
    {
        size_t pos = line.find(',');
        if (pos != std::string::npos)
        {
            values[line.substr(0, pos)] = line.substr(pos + 1);
        }
    }

    file.close();
    return values;
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange btcExchange;

    btcExchange.SetValue(GetData());
    btcExchange.IsFileValid(av[1]);
}