/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:30:39 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/06/10 11:50:37 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//# define _POSIX_C_SOURCE 200109L
# define _XOPEN_SOURCE 500
# define CHARSET "abcdefghijklmnopqrstuvwxyzABC\
	DEFGHIJKLMNOPQRSTUVWXYZ0123456789"
# define BPROMPT "\001\e[93m\002\001\e[4m\002"
# define TPROMPT "\001\e[24m\002 \001\e[97m\002"
# define EPROMPT "\001\e[31m\002\001\e[4m\002"

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <fcntl.h>
# include <termios.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include "structs.h"
# include "parsing.h"
# include "builtin.h"

int		set_handlers(void);
t_list	*init_env(char **envp);
int		p_strcmp(char *str, char *ref);
int		check_symb(char *s);
char	*prompt_loop(char *prompt, int mode);
int		error(t_data *d, int err_code, char *message);
void	cmd_go(t_list *cmdlist, t_data **data);
int		ft_is_file(char *s);
char	*ft_is_cmd(char *cmd);
void	*null_free(void	*fwee);
char	*multi_join(char **strs);
int		is_builtin(char *cmd);
char	**tab_envp(t_list *t_envp);
char	*get_full_path(char **cmd_path, char *cmd);
char	*get_path(t_list *envp, char *cmd);
int		setup_node(t_list **lstnode, t_cmd **node);
void	init_exec_data(t_exec_d *data, t_list *cmdlist);
void	builtin_redir(t_cmd *node, int *fd, int *stdout_fd, int mode);
void	lilfree(t_exec_d *ed, t_list *cmdlist, int mode);
int		wait_status(t_exec_d *ed, t_list *cmdlist);
void	cmd_error(t_exec_d *ed, t_list *cmdlist);
void	builtin(t_exec_d *edata, t_list *cmdlist, t_data *data, int mode);
void	handle_outfd(t_exec_d *ed, int pipe_fd[2], int fd);
void	handle_infd(t_exec_d *ed, int fd);

#endif