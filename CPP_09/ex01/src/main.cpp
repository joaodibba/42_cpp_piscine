#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <cstdlib>



double calculateRPN(const std::string &expression)
{
    std::istringstream iss(expression);
    std::string token;
    std::stack<double> stack;

    while (iss >> token)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (stack.size() < 2)
                throw std::runtime_error("Insufficient operands for operator");

            double op2 = stack.top();
            stack.pop();
            double op1 = stack.top();
            stack.pop();

            if (token == "+")
                stack.push(op1 + op2);
            else if (token == "-")
                stack.push(op1 - op2);
            else if (token == "*")
                stack.push(op1 * op2);
            else if (token == "/")
            {
                if (op2 == 0)
                    throw std::runtime_error("Division by zero");
                stack.push(op1 / op2);
            }
        }
        else
        {
            char *endptr;
            double value = std::strtod(token.c_str(), &endptr);

            if (*endptr != '\0')
                throw std::runtime_error("Invalid token: " + token);

            stack.push(value);
        }
    }

    if (stack.size() != 1)
        throw std::runtime_error("Invalid RPN expression");

    return static_cast<double>(stack.top());
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: ./btc [expression]" << std::endl;
        return 1;
    }
    try
    {
        std::cout << calculateRPN(static_cast<std::string>(av[1])) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}