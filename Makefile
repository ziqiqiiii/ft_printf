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
	$(CC) $(CFLAG) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all