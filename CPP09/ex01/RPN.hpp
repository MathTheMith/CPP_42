/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 06:59:43 by mvachon           #+#    #+#             */
/*   Updated: 2026/02/24 08:40:07 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
    private:
        std::stack<double> _stack;
    public:
        RPN();
        void solveRPN(std::string listArg);
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();
};

#endif