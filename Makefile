NAME = push_swap
SRCS = commands/push.c commands/rev_rotate.c commands/rotate.c \
commands/swap.c utils/errors.c utils/node_utils.c utils/list_utils.c \
utils/list_utils2.c utils/split.c utils/stack_init.c utils/helpers.c \
algorithm.c main.c
OBJS = $(SRCS:.c=.o)
CC = cc
CCFLAGS = -Wall -Wextra -Werror -g
INCLUDES = push_swap.h 

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(INCLUDES)
	$(CC) $(CCFLAGS) -c $< -o $@
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all


.PHONY: all clean fclean re

OS = $(shell uname)

size ?= 10

ifeq ($(OS),Linux)
CHECKER = valgrind ./push_swap $(ARG) | ./checker_linux $(ARG)
else
CHECKER = ./push_swap $(ARG) | ./checker_Mac $(ARG)
endif

test:
	@$(eval ARG = $(shell seq -1000 1000 | shuf -n $(size)))
	@echo "Checker result: "
	$(CHECKER)
	@echo "Instructions count: "
	@./push_swap $(ARG) | wc -l