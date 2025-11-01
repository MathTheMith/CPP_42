/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 07:35:41 by marvin            #+#    #+#             */
/*   Updated: 2025/10/15 07:35:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

bool isEmptyField(const std::string& str);
std::string change_name(std::string str);
bool is_valid_number(std::string str);

class PhoneBook {

private:
    Contact contacts[8];
    int nextIndex;
    int contactCount;
    
    void displayContactList();
    void displayContactDetails(int index);
    std::string getValidInput(std::string prompt);
    std::string getValidPhoneNumber();

public:
    PhoneBook();
    void addContact();
    void searchContact();
};

#endif