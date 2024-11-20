#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cerrno>
#include <cstring>
#include <limits>
#include <cmath>

bool isCharLiteral(const std::string& literal) {
    return (literal.length() == 3 && literal.front() == '\'' && literal.back() == '\'');
}

// Функция для проверки специальных значений
bool isSpecialLiteral(const std::string& literal) {
    return (literal == "nan" || literal == "nanf" ||
            literal == "+inf" || literal == "+inff" ||
            literal == "-inf" || literal == "-inff" ||
            literal == "inf" || literal == "inff");
}

// Основной метод конвертации
void ScalarConverter::convert(const std::string& literal) {
    char charValue = 0;
    int intValue = 0;
    float floatValue = 0.0f;
    double doubleValue = 0.0;

    bool isChar = false;
    bool isInt = false;
    bool isFloat = false;
    bool isDouble = false;
    bool isSpecial = isSpecialLiteral(literal);

    // Определение типа литерала
    if (isCharLiteral(literal)) {
        isChar = true;
        charValue = literal[1];
        intValue = static_cast<int>(charValue);
        floatValue = static_cast<float>(charValue);
        doubleValue = static_cast<double>(charValue);
    }
    else {
        char* endPtr = NULL;
        errno = 0;

        // Попытка преобразования к int
        long tempLong = std::strtol(literal.c_str(), &endPtr, 10);
        if (*endPtr == '\0' && errno == 0 &&
            tempLong >= std::numeric_limits<int>::min() &&
            tempLong <= std::numeric_limits<int>::max()) {
            isInt = true;
            intValue = static_cast<int>(tempLong);
            floatValue = static_cast<float>(intValue);
            doubleValue = static_cast<double>(intValue);
        }
        else {
            // Попытка преобразования к double
            errno = 0;
            double tempDouble = std::strtod(literal.c_str(), &endPtr);
            if ((*endPtr == 'f' && *(endPtr + 1) == '\0') || (*endPtr == '\0')) {
                if (errno == 0) {
                    if (literal.find('f') != std::string::npos) {
                        isFloat = true;
                        floatValue = static_cast<float>(tempDouble);
                        doubleValue = tempDouble;
                        intValue = static_cast<int>(floatValue);
                    }
                    else {
                        isDouble = true;
                        doubleValue = tempDouble;
                        floatValue = static_cast<float>(doubleValue);
                        intValue = static_cast<int>(doubleValue);
                    }
                }
            }
        }
    }

    // Вывод результатов
    std::cout << "char: ";
    if (isChar) {
        if (std::isprint(charValue))
            std::cout << "'" << charValue << "'";
        else
            std::cout << "Non displayable";
    }
    else if (isInt || isFloat || isDouble) {
        if (intValue >= std::numeric_limits<char>::min() &&
            intValue <= std::numeric_limits<char>::max()) {
            charValue = static_cast<char>(intValue);
            if (std::isprint(charValue))
                std::cout << "'" << charValue << "'";
            else
                std::cout << "Non displayable";
        }
        else {
            std::cout << "impossible";
        }
    }
    else {
        std::cout << "impossible";
    }
    std::cout << std::endl;

    std::cout << "int: ";
    if (isChar || isInt || isFloat || isDouble) {
        if (isSpecial) {
            std::cout << "impossible";
        }
        else {
            std::cout << intValue;
        }
    }
    else {
        std::cout << "impossible";
    }
    std::cout << std::endl;

    std::cout << "float: ";
    if (isChar || isInt || isFloat || isDouble) {
        if (isSpecial) {
            if (literal.find("nan") != std::string::npos)
                std::cout << "nanf";
            else if (literal.find("+inf") != std::string::npos || literal.find("inf") != std::string::npos)
                std::cout << "+inff";
            else if (literal.find("-inf") != std::string::npos)
                std::cout << "-inff";
        }
        else {
            std::cout << std::fixed << std::setprecision(1) << floatValue << "f";
        }
    }
    else {
        std::cout << "impossible";
    }
    std::cout << std::endl;

    std::cout << "double: ";
    if (isChar || isInt || isFloat || isDouble) {
        if (isSpecial) {
            if (literal.find("nan") != std::string::npos)
                std::cout << "nan";
            else if (literal.find("+inf") != std::string::npos || literal.find("inf") != std::string::npos)
                std::cout << "+inf";
            else if (literal.find("-inf") != std::string::npos)
                std::cout << "-inf";
        }
        else {
            std::cout << std::fixed << std::setprecision(1) << doubleValue;
        }
    }
    else {
        std::cout << "impossible";
    }
    std::cout << std::endl;
}
