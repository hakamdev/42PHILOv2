# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 17:10:26 by ehakam            #+#    #+#              #
#    Updated: 2021/12/14 23:19:10 by ehakam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
WFLAGS	= -Wall -Wextra -Werrors
DEBUG	= -g -fsanitize=address
SRC		= src/*.c 
NAME	= philo

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(DEBUG) $(SRC) -o $(NAME)

clean:

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re