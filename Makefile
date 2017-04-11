.PHONY: clean, fclean, re

.SUFFIXES:

NAME = libftprintf.a

CC = gcc

SRCC = *.c libft/*.c

SRCO = *.o

CFLAGS = -Wall -Wextra -Werror

all: $(NAME) libft/libft.h

%.o: %.c
	$(CC) -c $(SRCC)

$(NAME): $(SRCO)
	ar rc $(NAME) $(SRCO) && ranlib $(NAME)

clean:
	rm -f $(SRCO)

fclean: clean
	rm -f $(NAME)

re: fclean all
