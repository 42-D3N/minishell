/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:02:00 by tle-pape          #+#    #+#             */
/*   Updated: 2025/06/10 11:32:36 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"

# define ERROR_UNC_QUOTES "Syntax error : Unclosed quotes"
# define ERROR_FAILED_MALLOC "Malloc error: Not enough space"
# define ERROR_UNEX_SYMB "Syntax error : Unexpected token"
# define ERROR_HD_FILE "File error : couldn't open heredoc file"
# define ERROR_RD_FILE "File error : couldn't open redirected file"
# define WARNING_DELIM "Warning : heredoc ended by EOF, expected delimiter"

int		banana_split(char *s, t_data *data);
int		heredoctor(t_data *data, t_list **tokens);
int		in_n_out(t_data *data, t_list **tokens, t_list **cmds);
int		add_to_node(t_data *data, t_list **tokens, t_list **cmds);
char	*create_tmp(void);
char	*get_content(char *path);
int		store_content(char *path, char *content);
void	*join_n_free(char *s1, char *s2, int len);
char	*get_dollar_name(char *s, int start, int *i);
void	*write_to_heredoc(char *delimiter, char heredoc_path[22], int exit_s);
t_list	*restore_envp(void);
char	*findenv(char *envname, t_list **envp);
char	*get_env_and_find(char *envname);
int		store_envp(t_list *envp);
int		handle_delimiter(char *delimiter);
void	sfree(void **content);

int		expand_redir(t_list	*arg, t_data *data);
int		expand_var(t_list	*arg, t_data *data);

#endif
