#pragma once
#include <string>

enum DataCategory
{
	CATEGORY_ERROR,
	CATEGORY_CHARACTER,
	CATEGORY_INTEGER,
	CATEGORY_FLOATING,
	CATEGORY_DOUBLE_PRECISION,
	CATEGORY_INFINITY
};

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();

	static bool isCharacter(const std::string &input);
	static bool isInteger(const std::string &input);
	static bool isFloatLiteral(const std::string &input);
	static bool isDoubleLiteral(const std::string &input);
	static bool isInfinityLiteral(const std::string &input);

	static void processCharacter(const std::string &input);
	static void processInteger(const std::string &input);
	static void processFloat(const std::string &input);
	static void processDouble(const std::string &input);
	static void processInfinity(const std::string &input);
	static void handleInvalidInput();

public:
	static void convert(const std::string &input);
};
