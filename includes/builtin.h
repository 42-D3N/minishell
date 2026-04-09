/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:47:15 by tle-pape          #+#    #+#             */
/*   Updated: 2025/06/10 11:06:40 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"
# include <sys/wait.h>
# include <errno.h>
# include <stdio.h>
# include <dirent.h>
# include <stdbool.h>

size_t	ft_strlenc(char *str, int c);
char	*cwd(void);
void	ft_lstadd_content(t_list *start, char *new);
void	ft_lstreplace_content(t_list *start, char *new);
int		is_bash_exec(char *path);
void	*del(void *content);
int		ft_export(t_cmd *node, char **new_env);
void	ft_unset(t_list *start, char **args);
int		ft_env(t_cmd *node, bool exp);
int		ft_cd(t_list *envp, char **args);
int		ft_exit(char **args, t_list *cmds, t_data *data);
void	ft_pwd(void);
void	ft_echo(char **args);

#endif
