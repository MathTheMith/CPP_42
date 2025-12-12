/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:37:43 by marvin            #+#    #+#             */
/*   Updated: 2025/10/22 14:37:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongAnimal_HPP
#define WrongAnimal_HPP

#include <iostream>
#include <string>

class WrongAnimal {

protected:
    std::string type;

public:
    WrongAnimal();
    ~WrongAnimal();
    WrongAnimal(const WrongAnimal *other);
    WrongAnimal &operator=(const WrongAnimal *other);
    void makeSound() const;   
	std::string getType() const;
};

#endif
