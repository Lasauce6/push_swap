# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/23 12:36:49 by rbaticle          #+#    #+#              #
#    Updated: 2024/11/23 12:36:50 by rbaticle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS += -Wall -Werror -Wextra
NAME = push_swap

LFT_DIR = ./libft	

SRCS = main.c utils.c
OBJS = $(SRCS:.c=.o)



all: $(NAME)

makelft:
	@make -C $(LFT_DIR) bonus

$(NAME): makelft $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

clean: 
	@make clean -C $(LFT_DIR)
	rm -fr $(OBJS)

fclean: clean
	@make fclean -C $(LFT_DIR)
	rm -fr $(NAME)

re: fclean all

