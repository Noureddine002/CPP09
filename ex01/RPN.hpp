#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <sstream>
#include <iostream>
#include <stack>

class RPN
{
    private:
        std::stack <int> st;
    public:
        RPN();
        RPN(const RPN & cp);
        RPN & operator= (const RPN & cp);
        ~RPN();
        void operate(std::string str);
};

#endif 