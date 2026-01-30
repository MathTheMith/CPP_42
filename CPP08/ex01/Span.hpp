/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:49:36 by mvachon           #+#    #+#             */
/*   Updated: 2026/01/30 19:22:06 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <stdexcept>

class LenghtError : public std::length_error
{
public:
    LenghtError(const std::string& msg) : std::length_error(msg) {}
};

class Span
{
    private:
        std::vector<int> _numbers;
        unsigned int _maxNb;
    public:
        Span(unsigned int maxNb);
        Span(const Span& other);
        Span& operator=(const Span& other);
        void addNumber(int nb);
        int shortestSpan();
        int longestSpan();
        ~Span();
};

#endif