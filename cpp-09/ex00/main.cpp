#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cctype>

// Function to check if the date is valid
bool isValidDate(const std::string &date)
{
	if (date.size() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (size_t i = 0; i < date.size(); ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}

	// Check the year, month, and day
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return false;

	// Check the day based on the month
	int days_in_month[] = {31, ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 29 : 28,
								  31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (day < 1 || day > days_in_month[month - 1])
		return false;

	return true;
}

// Function to check if the value is valid
bool isValidValue(const std::string &valueStr, float &value)
{
	std::istringstream iss(valueStr);
	iss >> value;
	if (iss.fail() || !iss.eof())
		return false;
	if (value < 0)
		return false;
	if (value > 1000)
		return false;
	return true;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./btc input_file" << std::endl;
		return 1;
	}

	std::string inputFile = argv[1];
	std::ifstream infile(inputFile.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange btc;
	try
	{
		btc = BitcoinExchange("data.csv");
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		infile.close();
		return 1;
	}

	std::string line;

	if (!std::getline(infile, line))
	{
		std::cerr << "Error: input file is empty." << std::endl;
		infile.close();
		return 1;
	}

	int lineNumber = 1;
	while (std::getline(infile, line))
	{
		lineNumber++;
		if (line.empty())
			continue;

		size_t sep = line.find('|');
		if (sep == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, sep);
		std::string valueStr = line.substr(sep + 1);

		date.erase(date.find_last_not_of(" \t\r\n") + 1);
		date.erase(0, date.find_first_not_of(" \t\r\n"));
		valueStr.erase(valueStr.find_last_not_of(" \t\r\n") + 1);
		valueStr.erase(0, valueStr.find_first_not_of(" \t\r\n"));

		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		float value;
		if (!isValidValue(valueStr, value))
		{
			bool isNumber = true;
			for (size_t i = 0; i < valueStr.size(); ++i)
			{
				if (valueStr[i] != '.' && !std::isdigit(valueStr[i]))
				{
					isNumber = false;
					break;
				}
			}
			if (!isNumber)
				std::cerr << "Error: not a positive number." << std::endl;
			else
				std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		try
		{
			float rate = btc.getRate(date);
			float result = value * rate;
			std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << result << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << "Error: " << e.what() << " on line " << lineNumber << std::endl;
		}
	}

	infile.close();
	return 0;
}
