/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 10:30:00 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/30 14:19:50 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

int main()
{
    std::cout << "=== Test 1: Empty array ===" << std::endl;
    {
        Array<int> empty;
        std::cout << "Size: " << empty.size() << std::endl;
    }
    
    std::cout << "\n=== Test 2: Array of integers ===" << std::endl;
    {
        Array<int> numbers(0);
        std::cout << "Size: " << numbers.size() << std::endl;
        
        for (unsigned int i = 0; i < numbers.size(); i++)
            numbers[i] = i * 10;
        
        std::cout << "Values: ";
        for (unsigned int i = 0; i < numbers.size(); i++)
            std::cout << numbers[i] << " ";
        std::cout << std::endl;
    }
    
    std::cout << "\n=== Test 3: Copy constructor ===" << std::endl;
    {
        Array<int> original(3);
        original[0] = 10;
        original[1] = 20;
        original[2] = 30;
        
        Array<int> copy(original);
        
        std::cout << "Original: ";
        for (unsigned int i = 0; i < original.size(); i++)
            std::cout << original[i] << " ";
        std::cout << std::endl;
        
        std::cout << "Copy: ";
        for (unsigned int i = 0; i < copy.size(); i++)
            std::cout << copy[i] << " ";
        std::cout << std::endl;
        
        copy[0] = 999;
        
        std::cout << "After modifying copy[0] = 999:" << std::endl;
        std::cout << "Original[0]: " << original[0] << std::endl;
        std::cout << "Copy[0]: " << copy[0] << std::endl;
    }
    
    std::cout << "\n=== Test 4: Array of strings ===" << std::endl;
    {
        Array<std::string> strings(3);
        strings[0] = "Hello";
        strings[1] = "World";
        strings[2] = "42";
        
        std::cout << "Strings: ";
        for (unsigned int i = 0; i < strings.size(); i++)
            std::cout << strings[i] << " ";
        std::cout << std::endl;
    }
    
    std::cout << "\n=== Test 5: Out of bounds exception ===" << std::endl;
    {
        Array<int> arr(3);
        try
        {
            std::cout << "Trying to access index 5..." << std::endl;
            arr[5] = 100;
        }
        catch (const std::exception& e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }
    
    return 0;
}