#pragma once

#include <string>

class ScalarConverter {
private:
    // Приватный конструктор для предотвращения создания объектов
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);

public:
    // Статический метод для конвертации
    static void convert(const std::string& literal);
};

