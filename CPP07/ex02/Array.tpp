/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:42:05 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/14 17:29:25 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
template <typename T>
Array<T>::Array()
{
    _array = new T[6];
}

template <typename T>
Array<T>::Array(unsigned int nb)
{
    _array = new int(nb);
    std::cout << nb << std::endl;
}

template <typename T>
Array<T>::Array(const Array& other)
{
    *this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (this != &other)
    {
        this->_array = other._array;
    }
    return this;
}

template <typename T>
Array<T>::~Array()
{

}