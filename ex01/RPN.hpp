/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntanjaou <ntanjaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:05:55 by ntanjaou          #+#    #+#             */
/*   Updated: 2023/03/22 15:05:56 by ntanjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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