/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 00:44:07 by marvin            #+#    #+#             */
/*   Updated: 2025/10/22 00:44:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

PhoneBook::PhoneBook()
{
    nextIndex = 0;
    contactCount = 0;
}

void PhoneBook::displayContactList()
{
    int i = 0;
    std::cout << std::right << std::setw(10) << "index" << "|";
    std::cout << std::right << std::setw(10) << "first name" << "|";
    std::cout << std::right << std::setw(10) << "last name" << "|";
    std::cout << std::right << std::setw(10) << "nickname" << "|";
    std::cout << std::endl;

    while (i < contactCount)
    {
        std::cout << std::right << std::setw(10) << i << "|";
        std::cout << std::right << std::setw(10) << change_name(contacts[i].getFirstName()) << "|";
        std::cout << std::right << std::setw(10) << change_name(contacts[i].getLastName()) << "|";
        std::cout << std::right << std::setw(10) << change_name(contacts[i].getNickname()) << "|";
        std::cout << std::endl;
        i++;
    }
}

void PhoneBook::displayContactDetails(int index)
{
    std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << contacts[index].getDarkestSecret() << std::endl;
}

std::string PhoneBook::getValidInput(std::string prompt)
{
    std::string input;
    
    std::cout << prompt;
    std::getline(std::cin, input);
    
    if (input.empty() || isEmptyField(input))
    {
        std::cout << "Error: field cannot be empty!" << std::endl;
        return "";
    }
    
    return input;
}

std::string PhoneBook::getValidPhoneNumber()
{
    std::string phoneNumber;
    
    std::cout << "Phone number: ";
    std::getline(std::cin, phoneNumber);
    
    if (phoneNumber.empty() || isEmptyField(phoneNumber))
    {
        std::cout << "Error: field cannot be empty!" << std::endl;
        return "";
    }
    
    if (!is_valid_number(phoneNumber))
    {
        std::cout << "Error: phone number must contain only digits!" << std::endl;
        return "";
    }
    
    return phoneNumber;
}

void PhoneBook::searchContact()
{
    if (contactCount == 0)
    {
        std::cout << "No contact added" << std::endl;
        return;
    }
    
    displayContactList();
    
    std::string answer;
    std::cout << "Enter index: ";
    std::getline(std::cin, answer);

    if (!is_valid_number(answer))
    {
        std::cout << "Invalid input: not a number" << std::endl;
        return;
    }

    int index = std::atoi(answer.c_str());
    if (index >= 0 && index < contactCount)
    {
        displayContactDetails(index);
    }
    else
    {
        std::cout << "Error: index out of range" << std::endl;
    }
}

void PhoneBook::addContact()
{
    std::string firstName = getValidInput("First name: ");
    if (firstName.empty())
        return;
    
    std::string lastName = getValidInput("Last name: ");
    if (lastName.empty())
        return;

    std::string nickname = getValidInput("Nickname: ");
    if (nickname.empty())
        return;

    std::string phoneNumber = getValidPhoneNumber();
    if (phoneNumber.empty())
        return;

    std::string darkestSecret = getValidInput("Darkest secret: ");
    if (darkestSecret.empty())
        return;
    
    contacts[nextIndex].setFirstName(firstName);
    contacts[nextIndex].setLastName(lastName);
    contacts[nextIndex].setNickname(nickname);
    contacts[nextIndex].setPhoneNumber(phoneNumber);
    contacts[nextIndex].setDarkestSecret(darkestSecret);
    
    if (contactCount < 8)
        contactCount++;
    
    nextIndex = (nextIndex + 1) % 8;
    std::cout << "Contact added successfully!" << std::endl;
}
