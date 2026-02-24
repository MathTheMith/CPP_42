/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:50:22 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/30 14:10:33 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T>
void iter(T* array, const std::size_t length, void (*f)(T&))
{
    for (std::size_t i = 0; i < length; ++i)
        f(array[i]);
}

template <typename T>
void iter(const T* array, const std::size_t length, void (*f)(const T&))
{
    for (std::size_t i = 0; i < length; ++i)
        f(array[i]);
}

#endif
