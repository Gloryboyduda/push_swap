NAME = push_swap
SRCS = commands/push.c commands/rev_rotate.c commands/rotate.c \
commands/swap.c utils/errors.c utils/node_utils.c utils/node_utils_2.c \
utils/split.c utils/stack_init.c utils/stack_utils.c algorithm.c main.c
OBJS = $(SRCS:.c=.o)
CC = cc
CCFLAGS = -Wall -Wextra -Werror -g
INCLUDES = push_swap.h 

all: $(NAME)

$(NAME): $(OBJS)
	$(SRCS) $(OBJS)

%.o: %.c $(INCLUDES)
	$(CC) $(CCFLAGS) -c $< -o $@
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all


.PHONY: all clean fclean re