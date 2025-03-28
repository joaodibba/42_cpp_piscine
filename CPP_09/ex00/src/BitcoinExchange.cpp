#include "../include/BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <cctype>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
    : _data(other._data) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other)
        _data = other._data;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string &s) const {
    size_t start = 0;
    while (start < s.length() && std::isspace(s[start]))
        ++start;

    size_t end = s.length();
    while (end > start && std::isspace(s[end - 1]))
        --end;

    return s.substr(start, end - start);
}

bool BitcoinExchange::load(const std::string &filepath) {
    std::ifstream file(filepath.c_str());
    if (!file.is_open())
        return false;

    std::string line;
    std::getline(file, line); // skip header

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date, valueStr;

        if (!std::getline(iss, date, ','))
            continue;
        if (!std::getline(iss, valueStr))
            continue;

        date = trim(date);
        valueStr = trim(valueStr);

        char* endPtr = NULL;
        double value = std::strtod(valueStr.c_str(), &endPtr);

        if (*endPtr != '\0' ||
            value > std::numeric_limits<int>::max() ||
            value < -std::numeric_limits<int>::max())
            continue;

        _data[date] = value;
    }

    file.close();
    return true;
}

const std::map<std::string, double> &BitcoinExchange::getData() const {
    return _data;
}

bool BitcoinExchange::findByDate(const std::string &date, double &value) const {
    std::map<std::string, double>::const_iterator it = _data.find(date);
    if (it == _data.end())
        return false;
    value = it->second;
    return true;
}
