/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 08:54:06 by mvachon           #+#    #+#             */
/*   Updated: 2026/02/24 09:15:39 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    // std::cout << "Constructor called" << std::endl;
}
PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    (void)other;
    return *this;
}
PmergeMe::~PmergeMe()
{
    // std::cout << "Destructor called" << std::endl;
}