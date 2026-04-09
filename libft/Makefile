SOURCES = 	ft_arrfree.c		ft_arrsize.c\
			ft_atoi.c			ft_atol.c\
			ft_bzero.c			ft_calloc.c\
			ft_isalnum.c		ft_isalpha.c\
			ft_isascii.c		ft_isdigit.c\
			ft_isprint.c		ft_iswhitespace.c\
			ft_itoa.c			ft_lstadd_back.c\
			ft_lstadd_front.c	ft_lstclear.c\
			ft_lstdelone.c		ft_lstindex.c\
			ft_lstiter.c		ft_lstlast.c\
			ft_lstmap.c			ft_lstnew.c\
			ft_lstsize.c		ft_memchr.c\
			ft_memcmp.c			ft_memcpy.c\
			ft_memmove.c		ft_memset.c\
			ft_putchar_fd.c		ft_putendl_fd.c\
			ft_putnbr_fd.c		ft_putstr_fd.c\
			ft_split.c			ft_strchr.c\
			ft_strdup.c			ft_striteri.c\
			ft_strjoin.c		ft_strlcat.c\
			ft_strlcpy.c		ft_strlen.c\
			ft_strmapi.c		ft_strncmp.c\
			ft_strnstr.c		ft_strrchr.c\
			ft_strtrim.c		ft_substr.c\
			ft_tolower.c		ft_toupper.c
HEADERS = libft.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJECTS = $(SOURCES:.c=.o)
NAME = libft.a
PRINTF = ft_printf/*.o ft_printf/*/*.o
DPRINTF = ft_dprintf/*.o ft_dprintf/*/*.o
GNL = getnextline/*.o

%.o: %.c $(HEADERS)
	$(CC) -o $@ -c $< $(CFLAGS)

all: $(NAME)

$(NAME) : $(OBJECTS)
	(cd ft_printf ; make objects)
	(cd ft_dprintf ; make objects)
	(cd getnextline ; make objects)
	ar -cr $(NAME) $(OBJECTS) $(PRINTF) $(DPRINTF) $(GNL)

clean:
	(cd ft_printf ; make clean)
	(cd ft_dprintf ; make clean)
	(cd getnextline ; make clean)
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
