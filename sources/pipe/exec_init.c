/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 09:18:48 by tle-pape          #+#    #+#             */
/*   Updated: 2025/06/09 11:17:36 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	setup_node(t_list **lstnode, t_cmd **node)
{
	(*node) = (t_cmd *)(*lstnode)->content;
	(*node)->envp = tab_envp((*node)->env);
	if (!(*node)->args)
	{
		(*lstnode) = (*lstnode)->next;
		return (0);
	}
	if (!is_builtin((*node)->args[0]))
		(*node)->cmdpath = get_path((*node)->env, (*node)->args[0]);
	if (!(*node)->cmdpath)
	{
		if (access((*node)->args[0], F_OK) == 0 \
		|| is_bash_exec((*node)->args[0]))
			(*node)->cmdpath = ft_strdup((*node)->args[0]);
		else
			(*node)->cmdpath = ft_strdup("");
	}
	if ((*lstnode)->next)
		(*node)->isnext = true;
	(*lstnode) = (*lstnode)->next;
	return (1);
}

void	init_exec_data(t_exec_d *data, t_list *cmdlist)
{
	data->pipe_fd[0] = 0;
	data->pipe_fd[1] = 0;
	data->node = NULL;
	data->status = 0;
	data->i = 0;
	data->j = 0;
	data->cmdlist_s = cmdlist;
	if (((t_cmd *)cmdlist->content)->args
		&& !(p_strcmp(((t_cmd *)cmdlist->content)->args[0], "exit")
			&& !cmdlist->next))
		data->pids = ft_calloc(sizeof(int), ft_lstsize(cmdlist));
	else if (!((t_cmd *)cmdlist->content)->args && cmdlist->next)
		data->pids = ft_calloc(sizeof(int), ft_lstsize(cmdlist));
	else
		data->pids = NULL;
}

void	builtin_redir(t_cmd *node, int *fd, int *stdout_fd, int mode)
{
	if (mode == 0)
	{
		*stdout_fd = dup(STDOUT_FILENO);
		*fd = open(node->outpath, O_WRONLY | O_APPEND);
		dup2(*fd, STDOUT_FILENO);
	}
	else
	{
		dup2(*stdout_fd, STDOUT_FILENO);
		close(*stdout_fd);
		close(*fd);
	}
}
