# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/23 12:36:49 by rbaticle          #+#    #+#              #
#    Updated: 2024/12/18 15:32:48 by rbaticle         ###   ########.fr        #
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
	   sort.c get_mediane.c parsing.c
SRCS = main.c $(addprefix $(SRC_DIR), $(SRCS_NAMES))
OBJS = $(SRCS:.c=.o)

CHECKER = checker
CHECKER_SRCS_NAMES = bonus/checker.c parsing.c operations.c \
					operations_2.c utils.c utils_2.c
CHECKER_SRCS = $(addprefix $(SRC_DIR), $(CHECKER_SRCS_NAMES))
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

all: $(NAME)

bonus: $(CHECKER)

$(LFT):
	@make -C $(LFT_DIR) bonus

$(NAME): $(LFT) $(OBJS)
	$(CC) $(CFLAGS) -I $(HEADER_DIR) $(OBJS) -L $(LFT_DIR) -lft -o $(NAME)

$(CHECKER): $(LFT) $(CHECKER_OBJS)
	$(CC) $(CFLAGS) -I $(HEADER_DIR) $(CHECKER_OBJS) -L $(LFT_DIR) -lft -o $(CHECKER)

debug: $(LFT)
	$(CC) $(CFLAGS) -I $(HEADER_DIR) -g $(SRCS) -L $(LFT_DIR) -lft -o $(NAME)

fsanitize: $(LFT)
	$(CC) $(CFLAGS) -I $(HEADER_DIR) -fsanitize=address -g $(SRCS) $(LFT) -o $(NAME)

clean: 
	@make clean -C $(LFT_DIR)
	$(RM) $(OBJS) $(CHECKER_OBJS)

fclean: clean
	@make fclean -C $(LFT_DIR)
	$(RM) $(NAME) $(CHECKER)

re: fclean all

.PHONY: re clean fclean debug fsanitize
