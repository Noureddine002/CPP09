NAME = PmergeMe
CFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++

SRCS = main.cpp PmergeMe.cpp
OBJS = $(SRCS:.cpp=.o)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

%.o:%.cpp PmergeMe.hpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all