# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/23 12:36:49 by rbaticle          #+#    #+#              #
#    Updated: 2024/12/10 12:43:51 by rbaticle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS += -Wall -Werror -Wextra
NAME = push_swap
RM = rm -fr

LFT_DIR = ./libft
LFT = $(LFT_DIR)/libft.a

SRC_DIR = ./srcs/
HEADER_DIR = ./includes/
SRCS_NAMES = utils.c utils_2.c push_elements.c \
	   operations.c operations_2.c best_element.c \
	   sort.c get_cost.c
SRCS = main.c $(addprefix $(SRC_DIR), $(SRCS_NAMES))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

makelft:
	@make -C $(LFT_DIR) bonus

$(NAME): makelft $(OBJS)
	$(CC) $(CFLAGS) -I $(HEADER_DIR) $(OBJS) $(LFT) -o $(NAME)

debug: makelft
	$(CC) $(CFLAGS) -I $(HEADER_DIR) -g $(SRCS) $(LFT) -o $(NAME)

fsanitize: makelft
	$(CC) $(CFLAGS) -I $(HEADER_DIR) -fsanitize=address -g $(SRCS) $(LFT) -o $(NAME)

clean: 
	@make clean -C $(LFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	@make fclean -C $(LFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: re clean fclean debug fsanitize
