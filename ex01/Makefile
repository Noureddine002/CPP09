# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntanjaou <ntanjaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 15:05:39 by ntanjaou          #+#    #+#              #
#    Updated: 2023/03/22 15:05:40 by ntanjaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN
CFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++

SRCS = main.cpp RPN.cpp
OBJS = $(SRCS:.cpp=.o)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

%.o:%.cpp RPN.hpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all