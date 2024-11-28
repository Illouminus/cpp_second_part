#pragma once

#include <string>
#include <map>

class BitcoinExchange
{
private:
	std::map<std::string, float> rates;

	bool loadDatabase(const std::string &filename);

public:
	BitcoinExchange();
	BitcoinExchange(const std::string &filename);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	float getRate(const std::string &date) const;
};
