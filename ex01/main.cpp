#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        std::cerr << "Usage: " << argv[0] << " <expression>\n";
        return 1;
    }
    std::string expression(argv[1]);
    int result = evaluateRPN(expression);
    if (result == 0) {
        std::cerr << "Error\n";
    return 1;
    }
    std::cout << result << "\n";
    return 0;
}