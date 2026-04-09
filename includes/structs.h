/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 21:45:12 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/06/07 17:11:04 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minishell.h"

typedef struct s_cmd
{
	int		infd;
	char	*cmdpath;
	char	**args;
	char	**envp;
	char	*inpath;
	char	*outpath;
	t_list	*env;
	bool	isnext;
}	t_cmd;

typedef struct s_data
{
	t_list	*cmds;
	t_list	*tokens;
	t_list	*parsed_cmd;
	t_list	*p_token;
	t_list	*envp;
	int		exec_code;
	int		exit_status;
}	t_data;

typedef struct s_exec_d
{
	int		status;
	int		i;
	int		j;
	pid_t	*pids;
	int		pipe_fd[2];
	t_cmd	*node;
	t_list	*cmdlist_s;
}	t_exec_d;

enum e_code
{
	OK,
	ERROR,
	FATAL
};

t_cmd	*init_cmd(t_list *envp);
void	free_cmd(void *content);
t_data	*init_data(void);
void	free_data(t_data *data);

#endif