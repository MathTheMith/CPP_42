/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 08:29:56 by mvachon           #+#    #+#             */
/*   Updated: 2026/02/21 12:03:49 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
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
        void IsFileValid(std::string doc);
        int ParseLine(std::string line);
        int ParseValue(const std::vector<std::string> &eachWord);
        int ParseDate(std::vector<std::string> eachWord, std::string line);
        void CheckNearestDate(std::map<std::string, std::string>::iterator it, std::string date);
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();
        void SetValue(const std::map<std::string, std::string> &value);
        void SetPrice(float price) {_price = price;}
        std::map<std::string, std::string> &GetValue();
};

std::vector<std::string> split(const std::string &str, char delimiter);

#endif