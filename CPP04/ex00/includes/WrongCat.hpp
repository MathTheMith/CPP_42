/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 09:19:05 by mvachon           #+#    #+#             */
/*   Updated: 2025/12/13 12:23:45 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{

public:
	WrongCat();
	WrongCat(const WrongCat &other);
    WrongCat &operator=(const WrongCat &other);
	~WrongCat();
	
	void makeSound() const;
};

#endif