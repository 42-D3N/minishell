/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mein.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 08:12:44 by tle-pape          #+#    #+#             */
/*   Updated: 2025/06/09 18:58:23 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_child(int *fd, int *exit_code, t_data **data, int *pipe_fd)
{
	(*fd) = 0;
	(*exit_code) = 0;
	free((*data));
	rl_clear_history();
	close((*pipe_fd));
}

void	exec_child(t_exec_d *ed, int pipe_fd[2], t_list *cmdlist, t_data **data)
{
	int	fd;
	int	exit_code;

	init_child(&fd, &exit_code, data, &pipe_fd[0]);
	handle_infd(ed, fd);
	handle_outfd(ed, pipe_fd, fd);
	if (p_strcmp(ed->node->args[0], "exit")
		&& ft_arrsize((void **)ed->node->args) <= 2)
		free(ed->pids);
	if (is_builtin(ed->node->args[0]) != 0)
		builtin(ed, cmdlist, NULL, 0);
	else if (is_builtin(ed->node->cmdpath) == 0)
	{
		if (!ed->node->cmdpath[0])
			ft_dprintf(STDERR_FILENO, EPROMPT"mini-fail :\001\e[24m\002 %s: " \
				"command not found\001\e[97m\002\n", ed->node->args[0]);
		else if (execve(ed->node->cmdpath, ed->node->args, ed->node->envp))
			cmd_error(ed, cmdlist);
		exit_code = 127;
	}
	if (ed->status)
		exit_code = ed->status;
	lilfree(ed, cmdlist, 1);
	exit(exit_code);
}

void	exec_parent(t_cmd *node, int *pipe_fd, t_cmd *next_cmd)
{
	if (node->infd != -1)
		close(node->infd);
	if (node->inpath)
	{
		free(node->inpath);
		node->inpath = NULL;
	}
	if (next_cmd && !next_cmd->inpath)
		next_cmd->infd = pipe_fd[0];
	else
		close(pipe_fd[0]);
	close(pipe_fd[1]);
}

void	exec_lol(t_exec_d *ed, t_data **data, t_list *cmdlist)
{
	pipe(ed->pipe_fd);
	ed->pids[ed->j] = fork();
	if (ed->pids[ed->j] == 0)
		exec_child(ed, ed->pipe_fd, cmdlist, data);
	else
	{
		if (ed->node->isnext)
			exec_parent(ed->node, ed->pipe_fd, ed->cmdlist_s->content);
		else
			exec_parent(ed->node, ed->pipe_fd, NULL);
	}
}

void	cmd_go(t_list *cmdlist, t_data **data)
{
	t_exec_d	*ed;

	ed = ft_calloc(1, sizeof(t_exec_d));
	init_exec_data(ed, cmdlist);
	while (ed->cmdlist_s)
	{
		if (!setup_node(&ed->cmdlist_s, &ed->node))
		{
			if (ed->cmdlist_s)
				continue ;
			else
				break ;
		}
		if (is_builtin(ed->node->args[0]) && !ed->node->isnext && ed->j == 0)
		{
			builtin(ed, cmdlist, *data, 1);
			break ;
		}
		exec_lol(ed, data, cmdlist);
		ed->j++;
	}
	(*data)->exit_status = wait_status(ed, cmdlist);
}
