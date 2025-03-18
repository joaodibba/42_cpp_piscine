#include "../includes/ScalarConverter.hpp"
#include <iostream>
#include <limits>
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
    try
    {
        std::stoi(literal);
    }
    catch (const std::exception &e)
    {
        return false;
    }
    return true;
}

bool isFloatLiteral(const std::string &literal)
{
    try
    {
        std::stof(literal);
    }
    catch (const std::exception &e)
    {
        return false;
    }
    return true;
}

bool isDoubleLiteral(const std::string &literal)
{
    try
    {
        std::stod(literal);
    }
    catch (const std::exception &e)
    {
        return false;
    }
    return true;
}

bool isPseudoLiteral(const std::string &literal)
{
    return literal == "-inf" || literal == "+inf" || literal == "inf" || literal == "nan" || literal == "-inff" || literal == "+inff" || literal == "inff" || literal == "nanf";
}

void printPseudoLiteral(const std::string &literal)
{
    try
    {
        double value = std::strtod(literal.c_str(), nullptr);
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
        std::cout << "double: " << value << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: Invalid literal" << std::endl;
        return;
    }
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
        int value = std::stoi(literal);
        printChar(value);
        printInt(static_cast<int>(value));
        printFloat(static_cast<float>(value));
        printDouble(value);
    }
    else if (isDoubleLiteral(literal))
    {
        double value = std::stod(literal);
        printChar(value);
        printInt(value);
        printFloat(static_cast<float>(value));
        printDouble(value);
    }
    else if (isFloatLiteral(literal))
    {
        float value = std::stof(literal);
        printChar(value);
        printInt(value);
        printFloat(value);
        printDouble(static_cast<double>(value));
    }
    else
        std::cout << "Error: Invalid literal" << std::endl;
}
