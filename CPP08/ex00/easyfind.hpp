/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:25:22 by mvachon           #+#    #+#             */
/*   Updated: 2026/02/27 10:22:44 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// easyfind.hpp
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>
#include <string>

class NotFound : public std::runtime_error
{
public:
    NotFound(const std::string& msg) : std::runtime_error(msg) {}
};

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw NotFound("Occurrence not found");
    return it;
}

#endif
