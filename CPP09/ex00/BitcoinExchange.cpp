/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 08:30:24 by mvachon           #+#    #+#             */
/*   Updated: 2026/02/22 09:11:00 by mvachon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <limits>
#include <cerrno>
#include <cmath>

BitcoinExchange::BitcoinExchange()
{
}

bool isNumber(float f)
{
    return !std::isnan(f) && !std::isinf(f);
}

int toInt(const std::string &str)
{
    std::stringstream ss(str);
    int result;
    ss >> result;

    return result;
}

std::vector<std::string> split(const std::string &str, char delimiter)
{
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;

    while (std::getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;
}

std::string DecrementDate(int &year, int &month, int &day)
{
    int daysInMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[2] = 29;

    day--;

    if (day < 1)
    {
        month--;

        if (month < 1)
        {
            month = 12;
            year--;
        }

        daysInMonth[2] = 28;
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            daysInMonth[2] = 29;

        day = daysInMonth[month];
    }

    std::stringstream ss;
    ss << year << "-";
    if (month < 10) ss << "0";
    ss << month << "-";
    if (day < 10) ss << "0";
    ss << day;

    return ss.str();
}

int BitcoinExchange::ParseDate(std::vector<std::string> date, std::string line)
{
    if (date.size() != 3)
    {
        std::cout << "Error : bad input => " << line << std::endl;
        return -1;
    }

    int day = toInt(date[2]);
    int month = toInt(date[1]);
    int year = toInt(date[0]);

    int daysInMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[2] = 29;

    if (month < 1 || month > 12 || day < 1 || day > daysInMonth[month])
    {
        std::cout << "Error : bad input => " << line << std::endl;
        return -1;
    }

    while (true)
    {
        std::map<std::string, std::string>::iterator it = GetValue().find(_date);
        
        if (it != GetValue().end())
        {
            _price = static_cast<float>(std::atof(it->second.c_str()));
            return 1;
        }

        if ((year == 2009 && month == 1 && day < 2)|| year < 2009)
        {
            std::cout << "Error: no earlier date available." << std::endl;
            return -1;
        }

        _date = DecrementDate(year, month, day);
    }
}

int BitcoinExchange::ParseValue(const std::vector<std::string> &eachWord)
{
    if (eachWord.size() < 3)
    {
        std::cout << "Error: not enough words\n";
        return -1;
    }

    errno = 0;
    char *end;
    float value = std::strtof(eachWord[2].c_str(), &end);

    if (end == eachWord[2].c_str() || *end != '\0' || errno == ERANGE)
    {
        std::cout << "Error: not a valid number => " << eachWord[2] << std::endl;
        return -1;
    }

    if (!isNumber(value))
    {
        std::cout << "Error: value is NaN or infinite => " << eachWord[2] << std::endl;
        return -1;
    }

    if (value < 0)
    {
        std::cout << "Error: not a positive number => " << eachWord[2] << std::endl;
        return -1;
    }

    if (value > 1000)
    {
        std::cout << "Error: value must be lower than 1000 => " << eachWord[2] << std::endl;
        return -1;
    }
    _value = value;
    return 0;
}

int BitcoinExchange::ParseLine(std::string line)
{
    if (line == "date | value")
        return -1;

    std::vector<std::string> eachWord = split(line, ' ');
    _date = eachWord[0];
    if (eachWord.size() != 3)
    {
        std::cout << "Error : bad input => " << line << std::endl;
        return -1;
    }
    std::vector<std::string> date = split(eachWord[0], '-');
    if (ParseDate(date, line) == -1)
        return -1;

    if (eachWord[1] != "|")
    {
        std::cout << "Error : bad '|' input => " << eachWord[1] << std::endl;
        return -1;
    }
    return ParseValue(eachWord);
}

void BitcoinExchange::IsFileValid(std::string doc)
{
    std::ifstream file(doc.c_str());

    if (!file.is_open())
    {
        std::cout << "Error : can't open the file" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        if (ParseLine(line) == 0)
            std::cout << _date << " => " << _value << " = "  << _price * _value << std::endl;
    }
    file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        this->_value = other._value;
    return *this;
}

std::map<std::string, std::string> &BitcoinExchange::GetValue()
{
    return _values;
}

void BitcoinExchange::SetValue(const std::map<std::string, std::string> &values)
{
    _values = values;
}

BitcoinExchange::~BitcoinExchange()
{
}