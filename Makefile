# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 17:10:26 by ehakam            #+#    #+#              #
#    Updated: 2022/01/03 16:44:31 by ehakam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
WFLAGS	= -Wall -Wextra -Werror
DEBUG	= -g -fsanitize=address
SRC		=	src/ft_aton.c \
			src/ft_delete.c \
			src/ft_error.c \
			src/ft_init.c \
			src/ft_is_number.c \
			src/ft_philo.c \
			src/ft_routine.c \
			src/ft_state.c \
			src/ft_subroutines.c \
			src/ft_time.c
NAME	= philo

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(WFLAGS) $(SRC) -o $(NAME)

clean:

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re