# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/20 16:31:21 by tzi-qi            #+#    #+#              #
#    Updated: 2022/08/20 16:31:23 by tzi-qi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_printf_utils.c

OBJ = $(SRC:%.c=%.o)

INC = ./
HEAD = -I $(INC)

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(HEAD)

LIBCR = ar -rcs

RM = rm -rf

all: $(NAME) 

$(NAME): $(OBJ)
	$(LIBCR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: 
	$(CC) $(CFLAGS) $(SRC) -o test.out && ./test.out
	$(RM) ./test.out

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) 

re: fclean all