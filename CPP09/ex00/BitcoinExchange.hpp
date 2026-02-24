/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 08:29:56 by mvachon           #+#    #+#             */
/*   Updated: 2026/02/24 10:03:13 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

class BitcoinExchange
{
    private:
        std::map<std::string, std::string> _values;
        std::string _date;
        float _value;
        float _price;

    public:
        void IsFileValid(const std::string &doc);
        int ParseLine(const std::string &line);
        int ParseValue(const std::string &valueStr, const std::string &line);
        int ParseDate(const std::string &dateStr, const std::string &line);
        void CheckNearestDate(std::map<std::string, std::string>::iterator it, std::string date);
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();
        void SetValue(const std::map<std::string, std::string> &value);
        void SetPrice(float price) {_price = price;}
        std::map<std::string, std::string> &GetValue();
};


#endif