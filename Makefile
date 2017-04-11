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
	make -C ./libft clean
	rm -f $(SRCO)

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean all
