/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:14:38 by marvin            #+#    #+#             */
/*   Updated: 2025/10/17 12:14:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "Memory address of string:   " << &string << std::endl;
    std::cout << "Memory address held by PTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by REF: " << &stringREF << std::endl;

    std::cout << "Value of string:            " << string << std::endl;
    std::cout << "Value pointed to by PTR:    " << *stringPTR << std::endl;
    std::cout << "Value pointed to by REF:    " << stringREF << std::endl;
    
    return 0;
}