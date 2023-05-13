# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmeurant <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 16:08:31 by dmeurant          #+#    #+#              #
#    Updated: 2023/04/19 23:03:31 by dmeurant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = *.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = fractol
OBJ = $(srcs:.c=.o)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(SRCS) minilibx-linux/libmlx_Linux.a -o $(NAME) -lXext -lX11 -lm

all:$(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re : fclean all