CC = cc
CFLAGS += -Wall -Werror -Wextra
NAME = push_swap

LFT_DIR = ./libft	

SRCS = main.c utils.c
OBJS = $(SRCS:.c=.o)



all: $(NAME)

makelft:
	make -C $(LFT_DIR) bonus

$(NAME): makelft $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

clean: 
	make clean -C $(LFT_DIR)
	rm -fr $(OBJS)

fclean: clean
	rm -fr $(NAME)

re: fclean all

