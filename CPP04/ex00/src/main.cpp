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
#include "../includes/WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const WrongAnimal* wrong_meta = new WrongAnimal();
	const Animal* d = new Dog();
	const Animal* c = new Cat();
	const WrongAnimal* w = new WrongCat();
	std::cout << d->getType() << std::endl;
	std::cout << c->getType() << std::endl;
	std::cout << w->getType() << std::endl;
	d->makeSound();
	c->makeSound();
	w->makeSound();
	meta->makeSound();

	delete meta;
	delete wrong_meta;
	delete d;
	delete c;
	delete w;
	return 0;
}