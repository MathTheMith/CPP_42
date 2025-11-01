/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 00:44:36 by marvin            #+#    #+#             */
/*   Updated: 2025/10/22 00:44:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cctype>

bool isEmptyField(const std::string& str)
{
    std::string::size_type i = 0;

    while (i < str.length())
    {
        if (!std::isspace(static_cast<unsigned char>(str[i])))
            return false;
        i++;
    }
    return true;
}

std::string change_name(std::string str)
{
	if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

bool is_valid_number(std::string str)
{
    if (str.empty())
        return false;
    
    int i = 0;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return false;
        i++;
    }
    return true;
}

int main() {
	PhoneBook pb;
	std::string answer;
    while (1)
	{
		std::cout << "Choose between ADD, SEARCH, EXIT" << std::endl;
    	std::getline(std::cin, answer);

		if (answer == "EXIT")
			break;
		if (answer == "ADD")
			pb.addContact();
		if (answer == "SEARCH")
			pb.searchContact();
	}
}