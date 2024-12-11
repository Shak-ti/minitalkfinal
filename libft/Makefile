# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sconiat <sconiat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 09:36:07 by sconiat           #+#    #+#              #
#    Updated: 2024/09/23 10:57:18 by sconiat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################################
## SOURCES

SRC_FILES	= ft_atoi \
			ft_strlen \
		  ft_split \
		  ft_bzero \
		  ft_calloc \
		  ft_memmove \
		  ft_memset \
		  ft_printf \
		  ft_choice \
		  ft_putnbr_hex \
		  ft_putnbr_u \
		  ft_putptr_hex \
		  ft_putstr \
		  ft_putnbr \
		  ft_putchar

OBJ_FILES	= $(addsuffix .o, $(SRC_FILES))

INC			= libft.h

#######################################
## ARGUMENTS

NAME		= libft.a
CC			= cc
FLAGS		= -Wall -Wextra -Werror

#######################################
## RULES

all: $(NAME)

$(NAME) : $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

%.o: %.c
	$(CC) $(FLAGS) -I $(INC) -c $< -o $@

clean:
	rm -rf $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
