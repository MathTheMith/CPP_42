/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 00:42:02 by marvin            #+#    #+#             */
/*   Updated: 2025/10/22 00:42:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() 
    : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {}

std::string Contact::getFirstName() { return firstName; }
std::string Contact::getLastName() { return lastName; }
std::string Contact::getNickname() { return nickname; }
std::string Contact::getPhoneNumber() { return phoneNumber; }
std::string Contact::getDarkestSecret() { return darkestSecret; }

void Contact::setFirstName(std::string str) { firstName = str; }
void Contact::setLastName(std::string str) { lastName = str; }
void Contact::setNickname(std::string str) { nickname = str; }
void Contact::setPhoneNumber(std::string str) { phoneNumber = str; }
void Contact::setDarkestSecret(std::string str) { darkestSecret = str; }
