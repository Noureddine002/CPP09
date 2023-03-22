/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntanjaou <ntanjaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:05:36 by ntanjaou          #+#    #+#             */
/*   Updated: 2023/03/22 15:05:37 by ntanjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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