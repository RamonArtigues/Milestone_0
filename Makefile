# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rartigue <rartigue@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/19 00:00:00 by rartigue          #+#    #+#              #
#    Updated: 2026/05/19 00:00:00 by rartigue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

SRCS	= ft_isalpha.c \
		  ft_isdigit.c \
		  ft_isalnum.c \
		  ft_isascii.c \
		  ft_isprint.c \
		  ft_toupper.c \
		  ft_tolower.c \
		  ft_atoi.c \
		  ft_strlen.c \
		  ft_strncmp.c \
		  ft_strnstr.c \
		  ft_strlcpy.c \
		  ft_strlcat.c \
		  ft_strdup.c \
		  ft_strjoin.c \
		  ft_substr.c \
		  ft_split.c \
		  ft_memset.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
