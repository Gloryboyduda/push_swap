NAME = push_swap.a
SRCS = find_biggest.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
OBJS = $(SRCS:.c=.o)
CC = cc
CCFLAGS = -Wall -Wextra -Werror -g
AR = ar rcs $(NAME)
INCLUDES = push_swap.h 

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(OBJS)

%.o: %.c $(INCLUDES)
	$(CC) $(CCFLAGS) -c $< -o $@
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all


.PHONY: all clean fclean re