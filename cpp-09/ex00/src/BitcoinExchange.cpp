#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <iostream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &filename)
{
	if (!loadDatabase(filename))
	{
		throw std::runtime_error("Error: could not load database from " + filename);
	}
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	this->rates = other.rates;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->rates = other.rates;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		return false;

	std::string line;
	// get rid of the header and ignore it
	if (!std::getline(file, line))
	{
		file.close();
		return false;
	}

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		std::istringstream iss(line);
		std::string date;
		std::string rateStr;

		if (std::getline(iss, date, ',') && std::getline(iss, rateStr))
		{
			// Remove spaces and tabs from the beginning and end of the strings
			date.erase(date.find_last_not_of(" \t\r\n") + 1);
			date.erase(0, date.find_first_not_of(" \t\r\n"));
			rateStr.erase(rateStr.find_last_not_of(" \t\r\n") + 1);
			rateStr.erase(0, rateStr.find_first_not_of(" \t\r\n"));

			// Check if the date is in the correct format
			if (date.size() != 10 || date[4] != '-' || date[7] != '-')
			{
				std::cerr << "Warning: invalid date format in database: " << date << std::endl;
				continue;
			}

			// Check if the rate is in the correct format
			char *end;
			float rate = std::strtof(rateStr.c_str(), &end);
			if (*end != '\0')
			{
				std::cerr << "Warning: invalid rate format in database: " << rateStr << std::endl;
				continue;
			}

			// Add the rate to the map
			rates[date] = rate;
		}
		else
		{
			std::cerr << "Warning: invalid line in database: " << line << std::endl;
			continue;
		}
	}

	file.close();
	return true;
}

// Get the rate for a specific date
float BitcoinExchange::getRate(const std::string &date) const
{
	std::map<std::string, float>::const_iterator it = rates.find(date);
	if (it != rates.end())
	{
		return it->second;
	}

	// If the date is not found, find the closest date before it
	it = rates.lower_bound(date);
	if (it == rates.begin())
		throw std::runtime_error("no valid date found for " + date);
	--it;
	return it->second;
}
