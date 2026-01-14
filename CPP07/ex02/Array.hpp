/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:41:15 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/14 16:00:44 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
    private:
        T *_array;
    public:
        Array();
        Array(unsigned int nb);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();
};

#endif