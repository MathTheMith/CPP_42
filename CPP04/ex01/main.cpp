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

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	int nb = 2;
	Animal* array[nb];
	int i = 0;
	while (i < nb)
	{
		if (i < nb / 2)
			array[i] = new Dog();
		else
			array[i] = new Cat();
		i++; 
	}
	i = 0;
	while (i < nb)
	{
		delete array[i];
		i++;
	}
	return 0;
}