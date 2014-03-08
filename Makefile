# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/08 10:47:52 by cmehay            #+#    #+#              #
#    Updated: 2014/03/08 11:57:59 by cmehay           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = puissance4
CC = clang
INCLUDES = -I ./srcs/ -I ./libft/includes/
CFLAGS = -g -Wall -Wextra -Werror $(INCLUDES)
LDFLAGS = -L ./srcs/ -lft
HEADERFILES = ./srcs/puissance4.h
SRCSDIR = ./srcs/
SRCS = $(addprefix $(SRCSDIR), $(SRCSFILES))
SRCSFILES = main.c
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

$(LIBFT):
	$(MAKE) -C libft/

%.o: %.c $(HEADERFILES)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(MAKE) -C libft/ $@
	/bin/rm -f $(OBJS)

fclean: clean
	$(MAKE) -C libft/ $@
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
