NAME	= run_tests
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I..
LIBFT	= ../libft.a

SRCS	= test_libft.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C ..

%.o: %.c minunit.h ../libft.h
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all run clean fclean re
