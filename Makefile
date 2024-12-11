# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sconiat <sconiat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 12:15:49 by sconiat           #+#    #+#              #
#    Updated: 2024/09/28 18:55:09 by sconiat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################################
## SOURCES

SOURCES = server \
		server_utils \
		client

OBJ_DIR	= obj/

OBJ		= $(foreach item, $(SOURCES), $(OBJ_DIR)$(item).o)

#######################################
## ARGUMENTS

CC		= cc
FLAGS	= -Wall -Wextra -Werror -g
LIBFT	= libft/libft.a

#######################################
## RULES

all: client server

client: $(OBJ_DIR)client.o $(LIBFT)
	$(CC) $(FLAGS) $< $(MAIN) $(LIBFT) -o $@

server: $(OBJ_DIR)server.o $(OBJ_DIR)server_utils.o $(LIBFT)
	$(CC) $(FLAGS) obj/server.o obj/server_utils.o $(MAIN) $(LIBFT) -o $@

$(OBJ_DIR)%.o: %.c $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(LIBFT):
	$(MAKE) -C libft/


clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C libft/ clean

fclean: clean
	rm -rf server client
	$(MAKE) -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
