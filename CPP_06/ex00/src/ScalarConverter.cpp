#include "../includes/ScalarConverter.hpp"
#include <iostream>
#include <climits>
#include <cctype>
#include <cmath>
#include <string>

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter Default Constructor" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter Destructor" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
    std::cout << "ScalarConverter Copy Constructor" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
    (void)copy;
    if (this == &copy)
        std::cout << "ScalarConverter copy assignment operator called" << std::endl;
    return *this;
}

bool isCharLiteral(const std::string &literal)
{
    return literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]);
}

void printChar(double value)
{
    if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else
    {
        char c = static_cast<char>(value);
        std::cout << "char: " << (std::isprint(c) ? "'" + std::string(1, c) + "'" : "Non displayable") << std::endl;
    }
}

void printInt(double value)
{
    if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void printFloat(float value)
{
    if (std::isnan(value) || std::isinf(value) || value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << value << "f" << std::endl;
}

void printDouble(double value)
{
    if (std::isnan(value) || std::isinf(value) || value < -std::numeric_limits<double>::max() || value > std::numeric_limits<double>::max())
        std::cout << "double: impossible" << std::endl;
    else
        std::cout << "double: " << value << std::endl;
}

bool isIntLiteral(const std::string &literal)
{
    char *end;
    long value = std::strtol(literal.c_str(), &end, 10);
    return (*end == '\0' && value <= INT_MAX && value >= INT_MIN);
}

bool isFloatLiteral(const std::string &literal)
{
    if (literal.empty())
        return false;

    if (literal[literal.length() - 1] == 'f' || literal[literal.length() - 1] == 'F')
    {
        std::string trimmed_literal = literal.substr(0, literal.length() - 1);

        char *end;
        float value = std::strtof(trimmed_literal.c_str(), &end);

        return (*end == '\0' && value != HUGE_VALF && value != -HUGE_VALF);
    }

    return false;
}

bool isDoubleLiteral(const std::string &literal)
{
    char *end;
    double value = std::strtod(literal.c_str(), &end);
    return (*end == '\0' && value != HUGE_VAL && value != -HUGE_VAL);
}

bool isPseudoLiteral(const std::string &literal)
{
    return literal == "-inf" || literal == "+inf" || literal == "inf" || literal == "nan" || literal == "-inff" || literal == "+inff" || literal == "inff" || literal == "nanf";
}

void printPseudoLiteral(const std::string &literal)
{
    double value = std::strtod(literal.c_str(), NULL);
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << value << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{

    if (literal.empty())
    {
        std::cout << "Error: Empty literal" << std::endl;
        return;
    }

    std::cout << std::fixed << std::setprecision(1);

    if (isPseudoLiteral(literal))
        printPseudoLiteral(literal);
    else if (isCharLiteral(literal))
    {
        char c = literal[0];
        printChar(c);
        printInt(c);
        printFloat(static_cast<float>(c));
        printDouble(static_cast<double>(c));
    }
    else if (isIntLiteral(literal))
    {
        int value = std::strtol(literal.c_str(), NULL, 10);
        printChar(value);
        printInt(static_cast<int>(value));
        printFloat(static_cast<float>(value));
        printDouble(value);
    }
    else if (isDoubleLiteral(literal))
    {
        double value = std::strtod(literal.c_str(), NULL);
        printChar(value);
        printInt(value);
        printFloat(static_cast<float>(value));
        printDouble(value);
    }
    else if (isFloatLiteral(literal))
    {
        float value = std::strtof(literal.c_str(), NULL);
        printChar(value);
        printInt(value);
        printFloat(value);
        printDouble(static_cast<double>(value));
    }
    else
        std::cout << "Error: Invalid literal" << std::endl;
}
