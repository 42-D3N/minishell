SOURCES = 	get_next_line.c\
			get_next_line_utils.c
HEADERS = get_next_line.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJECTS = $(SOURCES:.c=.o)
NAME = libftgnl.a

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
