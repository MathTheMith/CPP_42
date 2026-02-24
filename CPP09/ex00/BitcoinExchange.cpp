#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <cerrno>
#include <cmath>

BitcoinExchange::BitcoinExchange() {}

bool isNumber(float f)
{
    return !std::isnan(f) && !std::isinf(f);
}

std::string DecrementDate(int &year, int &month, int &day)
{
    int daysInMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    if ((month == 02 && day == 29) && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
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
        if ((month == 02 && day == 29) && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
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

int BitcoinExchange::ParseDate(const std::string &dateStr, const std::string &line)
{
    size_t firstDash = dateStr.find('-');
    size_t secondDash = dateStr.find('-', firstDash + 1);

    if (firstDash == std::string::npos || secondDash == std::string::npos)
    {
        std::cout << "Error : bad input => " << line << std::endl;
        return -1;
    }

    int year  = std::atoi(dateStr.substr(0, firstDash).c_str());
    int month = std::atoi(dateStr.substr(firstDash + 1, secondDash - firstDash - 1).c_str());
    int day   = std::atoi(dateStr.substr(secondDash + 1).c_str());

    int daysInMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if ((month == 02 && day == 29) && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        daysInMonth[2] = 29;

    if (month < 1 || month > 12 || day < 1 || day > daysInMonth[month])
    {
        std::cout << "Error : bad input => " << line << std::endl;
        return -1;
    }

    _date = dateStr;
    while (true)
    {
        std::map<std::string, std::string>::iterator it = _values.find(_date);
        if (it != _values.end())
        {
            _price = static_cast<float>(std::atof(it->second.c_str()));
            return 1;
        }
        if ((year == 2009 && month == 1 && day < 2) || year < 2009)
            return -1;

        _date = DecrementDate(year, month, day);
    }
}

int BitcoinExchange::ParseValue(const std::string &valueStr, const std::string &line)
{
    errno = 0;
    char *end;
    float value = std::strtof(valueStr.c_str(), &end);

    if (end == valueStr.c_str() || *end != '\0' || errno == ERANGE)
    {
        std::cout << "Error: not a valid number => " << valueStr << std::endl;
        return -1;
    }
    if (!isNumber(value))
    {
        std::cout << "Error: value is NaN or infinite => " << valueStr << std::endl;
        return -1;
    }
    if (value < 0)
    {
        std::cout << "Error: not a positive number => " << valueStr << std::endl;
        return -1;
    }
    if (value > 1000)
    {
        std::cout << "Error: value must be lower than 1000 => " << valueStr << std::endl;
        return -1;
    }
    (void)line;
    _value = value;
    return 0;
}

int BitcoinExchange::ParseLine(const std::string &line)
{
    if (line == "date | value")
        return -1;

    size_t pipePos = line.find(" | ");
    if (pipePos == std::string::npos)
    {
        std::cout << "Error : bad input => " << line << std::endl;
        return -1;
    }

    std::string dateStr  = line.substr(0, pipePos);
    std::string valueStr = line.substr(pipePos + 3);

    if (dateStr.empty() || valueStr.empty())
    {
        std::cout << "Error : bad input => " << line << std::endl;
        return -1;
    }

    if (ParseDate(dateStr, line) == -1)
        return -1;

    return ParseValue(valueStr, line);
}

void BitcoinExchange::IsFileValid(const std::string &doc)
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
            std::cout << _date << " => " << _value << " = " << _price * _value << std::endl;
    }
    file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) { *this = other; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _value = other._value;
    return *this;
}

std::map<std::string, std::string> &BitcoinExchange::GetValue() { return _values; }

void BitcoinExchange::SetValue(const std::map<std::string, std::string> &values) { _values = values; }

BitcoinExchange::~BitcoinExchange() {}