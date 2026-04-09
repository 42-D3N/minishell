NAME = minishell

SRCS =	sources/main.c \
		sources/signal_handling.c \
		sources/prompt.c \
		sources/content.c \
		sources/utils.c \
		sources/structs/t_cmd.c \
		sources/structs/t_data.c \
		sources/heredoc/create_heredoc.c \
		sources/heredoc/handle_heredoc.c \
		sources/heredoc/handle_delimiter.c \
		sources/envp/restore_envp.c \
		sources/envp/handle_envp.c \
		sources/parsing/1.parsing_split.c \
		sources/parsing/2.parsing_heredoc.c \
		sources/parsing/3.parsing_redir.c \
		sources/parsing/3b.expand_redir.c \
		sources/parsing/4.parsing_command.c \
		sources/parsing/4b.expand_command.c \
		sources/pipe/mein.c \
		sources/pipe/side_utils.c \
		sources/pipe/path.c \
		sources/pipe/utils_exec.c \
		sources/pipe/handling_builtins.c \
		sources/pipe/exec_init.c \
		sources/builtins/env.c \
		sources/builtins/export.c \
		sources/builtins/unset.c \
		sources/builtins/cd.c \
		sources/builtins/pwd.c \
		sources/builtins/echo.c \
		sources/builtins/exit.c \
		sources/builtins/utils_builtins.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I/usr/include

all: $(NAME)

$(NAME): $(OBJS)
	(cd libft && make)
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -lreadline -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	(cd libft && make clean)
	$(RM) $(OBJS)

fclean: clean
	(cd libft && make fclean)
	$(RM) $(NAME)

re: fclean all
	(cd libft && make re)
	notify-send "Compiled ! "