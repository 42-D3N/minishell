SOURCES = 	ft_dprintf.c\
			funcs/ft_dhandle.c\
			funcs/ft_dprintf_putchar.c\
			funcs/ft_dprintf_puthex.c\
			funcs/ft_dprintf_putnbr.c\
			funcs/ft_dprintf_putpointer.c\
			funcs/ft_dprintf_putstr.c\
			funcs/ft_dprintf_putuint.c
HEADERS = ft_dprintf.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJECTS = $(SOURCES:.c=.o)
NAME = libftdprintf.a

%.o: %.c $(HEADERS)
	$(CC) -o $@ -c $< $(CFLAGS)

objects : $(OBJECTS) $(HEADERS)

all: $(NAME)

$(NAME) : $(OBJECTS)
	ar -cr $(NAME) $(OBJECTS)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
