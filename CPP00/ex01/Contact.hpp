/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 00:41:42 by marvin            #+#    #+#             */
/*   Updated: 2025/10/22 00:41:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
    std::string firstName;    
    std::string lastName;     
    std::string nickname;     
    std::string phoneNumber;  
    std::string darkestSecret;

public:
    Contact();

    std::string getFirstName();
    std::string getLastName();
    std::string getNickname();
    std::string getPhoneNumber();
    std::string getDarkestSecret();

    void setFirstName(std::string str);
    void setLastName(std::string str);
    void setNickname(std::string str);
    void setPhoneNumber(std::string str);
    void setDarkestSecret(std::string str);
};

#endif
