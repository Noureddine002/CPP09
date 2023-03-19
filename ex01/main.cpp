#include "RPN.hpp"

int main(int ac, char **av) 
{
    if(ac == 2)
    {
        RPN op;
        op.operate(av[1]);
    }
    else
    {
        std::cerr << "The number or args is WRONG !" << std::endl;
    }
    return 0;
}