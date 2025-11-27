/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 22:30:56 by marvin            #+#    #+#             */
/*   Updated: 2025/10/20 22:30:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
    actions[0] = &Harl::debug;
    actions[1] = &Harl::info;
    actions[2] = &Harl::warning;
    actions[3] = &Harl::error;
    
    complain_type[0] = "DEBUG";
    complain_type[1] = "INFO";
    complain_type[2] = "WARNING";
    complain_type[3] = "ERROR";
}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my "
	"7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n" << std::endl;
	(this->*actions[1])();
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout <<  "I cannot believe adding extra bacon costs more money. "
	"You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n"<< std::endl;
	(this->*actions[2])();
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. "
	"I’ve been coming for years, whereas you started working here just last month.\n" << std::endl;
	(this->*actions[3])();
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain(std::string level)
{
	int i = 0;

	while (i < 4 && complain_type[i] != level)
		i++;

	switch (i)
	{
		case 0:
			(this->*actions[0])();
			break;
		case 1:
			(this->*actions[1])();
			break;
		case 2:
			(this->*actions[2])();
			break;
		case 3:
			(this->*actions[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}

