# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/23 12:36:49 by rbaticle          #+#    #+#              #
#    Updated: 2024/12/05 15:55:28 by rbaticle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS += -Wall -Werror -Wextra
NAME = push_swap
RM = rm -fr

LFT_DIR = ./libft
LFT = $(LFT_DIR)/libft.a

SRCS = main.c utils.c operations.c \
	   operations_2.c best_element.c sort.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

makelft:
	@make -C $(LFT_DIR) bonus

$(NAME): makelft $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFT) -o $(NAME)

debug: makelft
	$(CC) $(CFLAGS) -g $(SRCS) $(LFT) -o $(NAME)

fsanitize: makelft
	$(CC) $(CFLAGS) -fsanitize=address $(SRCS) $(LFT) -o $(NAME)

clean: 
	@make clean -C $(LFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	@make fclean -C $(LFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: re clean fclean debug fsanitize
