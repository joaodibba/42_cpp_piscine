#include "../includes/ScalarConverter.hpp"

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
    return literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'';
}

bool isIntLiteral(const std::string &literal)
{
    if (literal.empty())
        return false;
    size_t i = 0;
    if (literal[i] == '-' || literal[i] == '+')
        i++;
    for (; i < literal.length(); i++)
    {
        if (!isdigit(literal[i]))
            return false;
    }
    return true;
}

bool isFloatLiteral(const std::string &literal)
{
    if (literal == "-inff" || literal == "+inff" || literal == "inff" || literal == "nanf")
        return true;

    bool hasDot = false;
    bool hasDigit = false;
    size_t i = 0;

    if (i < literal.length() && (literal[i] == '-' || literal[i] == '+'))
        i++;

    for (; i < literal.length(); i++)
    {
        char c = literal[i];
        if (isdigit(c))
            hasDigit = true;
        else if (c == '.' && !hasDot)
            hasDot = true;
        else if (c == 'f' && i == literal.length() - 1)
            return hasDigit && hasDot;
        else
            return false;
    }
    return false;
}

bool isDoubleLiteral(const std::string &literal)
{
    if (literal == "-inf" || literal == "+inf" || literal == "inf" || literal == "nan")
        return true;

    bool hasDot = false;
    bool hasDigit = false;
    size_t i = 0;

    if (i < literal.length() && (literal[i] == '-' || literal[i] == '+'))
        i++;

    for (; i < literal.length(); i++)
    {
        if (std::isdigit(literal[i]))
            hasDigit = true;
        else if (literal[i] == '.' && !hasDot)
            hasDot = true;
        else
            return false;
    }
    return hasDigit && hasDot;
}

static bool isPseudoLiteral(const std::string &literal)
{
    return literal == "-inf" || literal == "+inf" || literal == "inf" || literal == "nan" ||
           literal == "-inff" || literal == "+inff" || literal == "inff" || literal == "nanf";
}

void ScalarConverter::convert(const std::string &literal)
{
    std::cout << std::fixed << std::setprecision(1);
    double value = std::strtod(literal.c_str(), NULL);

    if (isCharLiteral(literal))
    {
        char c = literal[1];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
        return;
    }

    if (isPseudoLiteral(literal))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;

        if (literal == "-inf" || literal == "+inf" || literal == "inf" ||
            literal == "-inff" || literal == "+inff" || literal == "inff")
        {
            float f = static_cast<float>(value);
            std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << value << std::endl;
        }
        else // nan
        {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        return;
    }

    bool floatLiteral = isFloatLiteral(literal);
    bool doubleLiteral = isDoubleLiteral(literal);
    bool intLiteral = isIntLiteral(literal);

    if (!floatLiteral && !doubleLiteral && !intLiteral)
    {
        std::cout << "Error: Invalid literal" << std::endl;
        return;
    }

    if (std::isnan(value) || std::isinf(value) ||
        value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else
    {
        char c = static_cast<char>(value);
        if (std::isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }

    if (std::isnan(value) || std::isinf(value) ||
        value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;

    float fvalue = static_cast<float>(value);
    std::cout << "float: " << fvalue << "f" << std::endl;

    std::cout << "double: " << value << std::endl;
}
