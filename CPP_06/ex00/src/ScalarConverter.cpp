#include "../includes/ScalarConverter.hpp"
#include <iostream>
#include <climits>
#include <cfloat>
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
    std::cout << std::fixed << std::setprecision(1);
    if (std::isnan(value) || std::isinf(value) || value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << value << "f" << std::endl;
}

void printDouble(double value)
{
    std::cout << std::fixed << std::setprecision(1);
    if (std::isnan(value) || std::isinf(value) || value < -std::numeric_limits<double>::max() || value > std::numeric_limits<double>::max())
        std::cout << "double: impossible" << std::endl;
    else
        std::cout << "double: " << value << std::endl;
}

bool isIntLiteral(const std::string &literal)
{
    if (literal.empty())
        return false;
    char *end;
    long value = std::strtol(literal.c_str(), &end, 10);
    return (*end == '\0' && value <= INT_MAX && value >= INT_MIN);
}

bool isFloatLiteral(const std::string &str)
{
    bool hasDecimal = false, hasExponent = false;
    size_t i = 0;

    if (str.empty() || str.size() == 1)
        return false;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!std::isdigit(str[i]) && str[i] != '.' && str[i] != 'e' && str[i] != 'E' && str[i] != '+' && str[i] != '-' && str[i] != 'f' && str[i] != 'F')
        {
            return false;
        }
    }
    if (str[0] == '+' || str[0] == '-')
        i = 1;
    for (; i < str.size(); i++)
    {
        if (str[i] == '.')
        {
            if (hasDecimal || hasExponent)
                return false;
            hasDecimal = true;
        }
        else if (str[i] == 'e' || str[i] == 'E')
        {
            if (hasExponent)
                return false;
            hasExponent = true;
            if (i + 1 < str.size() && (str[i + 1] == '+' || str[i + 1] == '-'))
                i++;
        }
    }
    return true;
}

bool isDoubleLiteral(const std::string &literal)
{
    if (literal.empty())
        return false;

    size_t i = 0;

    while (i < literal.length() && std::isspace(literal[i]))
    {
        i++;
    }

    if (i < literal.length() && (literal[i] == '+' || literal[i] == '-'))
    {
        i++;
    }

    if (i == literal.length() || !std::isdigit(literal[i]))
    {
        return false;
    }

    char *end;
    double value = std::strtod(literal.c_str() + i, &end);

    return (*end == '\0' && value <= DBL_MAX && value >= DBL_MIN);
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
