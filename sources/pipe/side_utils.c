/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:39:18 by tle-pape          #+#    #+#             */
/*   Updated: 2025/06/09 18:09:04 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	lilfree(t_exec_d *ed, t_list *cmdlist, int mode)
{
	if (mode == 1)
		ft_lstclear(&ed->node->env, free);
	ft_lstclear(&cmdlist, free_cmd);
	if (ed->pids)
		free(ed->pids);
	free(ed);
}

int	wait_status(t_exec_d *ed, t_list *cmdlist)
{
	int	return_status;

	return_status = 0;
	if (ed->j == 0)
		return_status = ed->status;
	while (ed->i < ed->j)
	{
		waitpid(ed->pids[ed->i], &ed->status, 0);
		ed->i++;
		if (WIFEXITED(ed->status))
			return_status = WEXITSTATUS(ed->status);
		else if (WIFSIGNALED(ed->status))
			return_status = WTERMSIG(ed->status) + 128;
	}
	lilfree(ed, cmdlist, 0);
	return (return_status);
}

void	cmd_error(t_exec_d *ed, t_list *cmdlist)
{
	ft_dprintf(STDERR_FILENO, EPROMPT"mini-fail :\001\e[24m\002 %s", \
		ed->node->args[0]);
	perror(" ");
	ft_dprintf(STDERR_FILENO, "\001\e[97m\002\n");
	lilfree(ed, cmdlist, 1);
	exit(127);
}
