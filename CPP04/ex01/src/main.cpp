/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:30:08 by mvachon           #+#    #+#             */
/*   Updated: 2025/12/13 12:30:08 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int main()
{
    const int size = 4;
    Animal* animals[size];

    std::cout << "----- Creating animals -----\n" << std::endl;

    for (int i = 0; i < size; i++)
    {
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n----- Deleting animals -----\n" << std::endl;

    for (int i = 0; i < size; i++)
        delete animals[i];


    std::cout << "\n----- Testing deepcopy -----\n" << std::endl;
    Dog dog1;
    dog1.getBrain()->setIdea(0, "I want a bone");

    Dog dog2(dog1);

    std::cout << "Dog1 idea: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;

    dog2.getBrain()->setIdea(0, "I want to sleep");

    std::cout << "After modification:" << std::endl;
    std::cout << "Dog1 idea: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;

    return 0;
}
