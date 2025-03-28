#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
private:
    std::map<std::string, double> _data;
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    bool load(const std::string &filepath);
    const std::map<std::string, double> &getData() const;
    bool findByDate(const std::string &date, double &value) const;
    std::string trim(const std::string &s) const;
};

#endif