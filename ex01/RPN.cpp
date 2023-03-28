/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntanjaou <ntanjaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:05:53 by ntanjaou          #+#    #+#             */
/*   Updated: 2023/03/22 15:05:54 by ntanjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {};

RPN::RPN(const RPN & cp)
{
    this->st = cp.st;
}

RPN & RPN::operator= (const RPN & cp)
{
    this->st = cp.st;
    return *this;
}

RPN::~RPN() {};

void RPN::operate(std::string str)
{
    int len = str.length();
    for (int i = 0; i < len; i++) 
    {
        if (str[i] == ' ')
            continue;
        else if (isdigit(str[i]) || (str[i] == '-' && isdigit(str[i+1]) && i+1 < len)) 
        {
            int num = 0;
            if (str[i] == '-') 
            {
                num = (str[i + 1] - '0') * (-1);
                i++;
            }
            else 
            {
                num = str[i] - '0';
            }
            this->st.push(num);
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') 
        {
            if (this->st.size() < 2) 
            {
                std::cout << "Error: Insufficient operands for operator " << str[i] <<  std::endl;
                return;
            }
            int a = this->st.top();
            this->st.pop();
            int b = this->st.top();
            this->st.pop();
            int result;
            switch(str[i]) 
            {
                case '+': result = b + a; break;
                case '-': result = b - a; break;
                case '*': result = b * a; break;
                case '/': 
                    if (a == 0) 
                    {
                        std::cout << "Error: Division by zero" <<  std::endl;
                        return;
                    }
                    result = b / a; break;
                default: break;
            }
            this->st.push(result);
        }
        else 
        {
            std::cout << "Error: Invalid character " << str[i] << std::endl;
            return;
        }
    }
    if (this->st.size() != 1) 
    {
        std::cout << "Error: Invalid expression" << std::endl;
        return;
    }
    std::cout << this->st.top() << std::endl;
}
