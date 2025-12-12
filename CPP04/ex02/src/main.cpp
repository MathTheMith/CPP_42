/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:36:56 by marvin            #+#    #+#             */
/*   Updated: 2025/10/22 14:36:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int main()
{
	Animal* array[6];
	int i = 0;
	while (i < 6)
	{
		if (i < 3)
			array[i] = new Dog();
		else
			array[i] = new Cat();
		i++; 
	}
	i = 0;
	while (i < 6)
	{
		delete array[i];
		i++;
	}
	return 0;
}