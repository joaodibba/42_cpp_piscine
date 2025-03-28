#include "../include/BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

bool canOpenFile(const std::string &filename) {
    std::ifstream file(filename.c_str());
    return file.is_open();
}

bool parseValue(const std::string &str) {
    std::istringstream iss(str);
    double value;

    iss >> value;

    if (iss.fail() || !iss.eof()) {
        std::cerr << "Error: not a number." << std::endl;
        return false;
    }

    if (value < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }

    return true;
}


bool isValidDate(const std::string &dateStr) {
    if (dateStr.length() != 10 || dateStr[4] != '-' || dateStr[7] != '-')
        return false;

    int year = std::atoi(dateStr.substr(0, 4).c_str());
    int month = std::atoi(dateStr.substr(5, 2).c_str());
    int day = std::atoi(dateStr.substr(8, 2).c_str());

    if (year < 1900 || month < 1 || month > 12 || day < 1)
        return false;

    struct tm t = {};
    t.tm_year = year - 1900;
    t.tm_mon = month - 1;
    t.tm_mday = day;
    t.tm_hour = 0;
    t.tm_min = 0;
    t.tm_sec = 0;
    t.tm_isdst = -1;

    time_t temp = mktime(&t);
    return !(temp == -1 || t.tm_year != year - 1900 || t.tm_mon != month - 1 || t.tm_mday != day);
}


int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./btc [filename]" << std::endl;
        return 1;
    }

    if (!canOpenFile(argv[1])) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange exchange;
    if (!exchange.load("data.csv")) {
        std::cerr << "Error: could not load exchange database." << std::endl;
        return 1;
    }

    std::ifstream input(argv[1]);
    std::string line;
    std::getline(input, line); // skip header

    while (std::getline(input, line)) {
        size_t sep = line.find('|');
        if (sep == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = exchange.trim(line.substr(0, sep));
        std::string valueStr = exchange.trim(line.substr(sep + 1));
        float value;

        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (!parseValue(valueStr))
            continue;

        double rate;
        if (!exchange.findByDate(date, rate)) {
            const std::map<std::string, double>& db = exchange.getData();
            std::map<std::string, double>::const_iterator it = db.lower_bound(date);

            if (it == db.begin() && (it == db.end() || it->first > date)) {
                std::cerr << "Error: no earlier date in DB." << std::endl;
                continue;
            }

            if (it == db.end() || it->first != date)
                --it;

            rate = it->second;
        }

        std::cout << date << " => " << std::setprecision(0) << value << " = "
                  << std::fixed << std::setprecision(1) << (rate * value) << std::endl;
    }

    return 0;
}