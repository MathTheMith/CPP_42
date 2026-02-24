/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:42:05 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/30 14:20:17 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <stdexcept>

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n) : _array(NULL), _size(n)
{
    if (n > 0)
        this->_array = new T[n]();
}

template <typename T>
Array<T>::Array(const Array& other) : _array(NULL), _size(0)
{
    *this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (this != &other)
    {
        delete[] this->_array;
        
        this->_size = other._size;
        
        if (other._size > 0)
        {
            this->_array = new T[other._size];
            
            for (unsigned int i = 0; i < other._size; i++)
            {
                this->_array[i] = other._array[i];
            }
        }
        else
        {
            this->_array = NULL;
        }
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= this->_size)
        throw std::out_of_range("Array: index out of bounds");
    return this->_array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= this->_size)
        throw std::out_of_range("Array: index out of bounds");
    return this->_array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return this->_size;
}

template <typename T>
Array<T>::~Array()
{
    delete[] this->_array;
}