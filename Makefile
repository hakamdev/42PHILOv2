# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 17:10:26 by ehakam            #+#    #+#              #
#    Updated: 2021/12/17 19:48:37 by ehakam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
WFLAGS	= -Wall -Wextra -Werror
DEBUG	= -g -fsanitize=address
SRC		= src/*.c 
NAME	= philo

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(WFLAGS) $(SRC) -o $(NAME) -O3

clean:

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re