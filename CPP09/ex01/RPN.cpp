/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 06:59:51 by mvachon           #+#    #+#             */
/*   Updated: 2026/02/24 08:42:54 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
    // std::cout << "Constructor called" << std::endl;
}

int checkOperator(int operator_)
{
    if (operator_ == '+')
        return 1;
    if (operator_ == '-')
        return 2;
    if (operator_ == '*')
        return 3;
    if (operator_ == '/')
        return 4;
    throw std::runtime_error("Error: Unknown operator");
}

void RPN::solveRPN(std::string listArg)
{
    double nbAdded = 0;
    if (listArg.empty())
        return;
    for(int i = 0; listArg[i]; i++)
    {
        if (listArg[i] >= '0' && listArg[i] <= '9')
            _stack.push(listArg[i] - '0');
        else
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Error: Not enough operands");
            int operator_ = checkOperator(listArg[i]);
            nbAdded = _stack.top();
            _stack.pop();               
            switch (operator_)
            {
                case 1 : nbAdded = _stack.top() + nbAdded; break;
                case 2 : nbAdded = _stack.top() - nbAdded; break;
                case 3 : nbAdded = _stack.top() * nbAdded; break;
                case 4 :
                    if (nbAdded == 0)
                         throw std::runtime_error("Error: Division by 0");
                    nbAdded = _stack.top() / nbAdded; break;
                default:
                    throw std::runtime_error("Error: Unknown operator");
            }
            _stack.pop();
            _stack.push(nbAdded);
        }
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Error: too many operands or incomplete expression");
    std::cout << _stack.top() << std::endl;  
}
RPN::RPN(const RPN& other)
{
    *this = other;
}
RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
    {
        this->_stack = other._stack;
    }
    return *this;
}
RPN::~RPN()
{
    // std::cout << "Destructor called" << std::endl;
    
}