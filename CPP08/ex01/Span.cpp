/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:46:08 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/30 19:53:51 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>
#include <algorithm>

Span::Span(unsigned int maxNb) : _maxNb(maxNb)
{}

void Span::addNumber(int nb)
{
    if (_numbers.size() >= _maxNb)
        throw LenghtError("You've reached the limits of the countained.");
    else
        _numbers.push_back(nb);
}

int Span::shortestSpan()
{
    if (_numbers.size() < 2)
        throw LenghtError("The container isn't big enough.");

    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());

    int minSpan = std::numeric_limits<int>::max();

    for (size_t i = 1; i < tmp.size(); ++i)
    {
        int diff = tmp[i] - tmp[i - 1];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}


int Span::longestSpan()
{
    if (_numbers.size() < 2)
        throw LenghtError("The countainer isn't big enough.");

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());

    return max - min;
}


Span::~Span()
{}
