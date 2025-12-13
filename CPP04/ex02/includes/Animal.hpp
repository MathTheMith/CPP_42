/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:37:43 by marvin            #+#    #+#             */
/*   Updated: 2025/10/22 14:37:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {

protected:
    std::string _type;

public:
    Animal();
    Animal(const Animal &other);
    virtual Animal &operator=(const Animal &other);
    virtual ~Animal();

    virtual void makeSound() const;
	std::string getType() const;
};

#endif
