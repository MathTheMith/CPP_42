/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:49:44 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/09 15:21:53 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Form{

    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExec;
    public:
        Form();
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form(); 
};
    