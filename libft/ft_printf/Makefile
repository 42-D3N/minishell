SOURCES = 	ft_printf.c\
			funcs/ft_handle.c\
			funcs/ft_printf_putchar.c\
			funcs/ft_printf_puthex.c\
			funcs/ft_printf_putnbr.c\
			funcs/ft_printf_putpointer.c\
			funcs/ft_printf_putstr.c\
			funcs/ft_printf_putuint.c
HEADERS = ft_printf.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJECTS = $(SOURCES:.c=.o)
NAME = libftprintf.a

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
