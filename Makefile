
CC = cc
CFLAGS = -Wall -Wextra -Werror
sources = ft_address.c ft_hexa.c ft_int.c ft_printf.c ft_putchar.c ft_putstr.c ft_uns.c
objects =  $(sources:.c=.o)
NAME = libftprintf.a

%.o:%.c
	$(CC) $(CFLAGS) -c $<
	ar rcs $(NAME) $@

$(NAME) : $(objects)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -rf $(objects)
fclean:
	rm -rf $(NAME) $(objects)
re: fclean all
