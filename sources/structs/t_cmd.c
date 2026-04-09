/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 21:47:55 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/06/05 12:58:30 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd	*init_cmd(t_list *envp)
{
	t_cmd	*command;

	command = malloc(sizeof(t_cmd));
	if (!command)
		return (NULL);
	command->args = NULL;
	command->cmdpath = NULL;
	command->env = envp;
	command->envp = NULL;
	command->isnext = false;
	command->infd = -1;
	command->inpath = NULL;
	command->outpath = NULL;
	return (command);
}

void	free_cmd(void *content)
{
	t_cmd	*cmd;

	cmd = content;
	if (cmd)
	{
		cmd = (t_cmd *)cmd;
		if (cmd->args)
			ft_arrfree((void **)cmd->args);
		if (cmd->cmdpath)
			free(cmd->cmdpath);
		if (cmd->envp)
			free(cmd->envp);
		if (cmd->inpath)
			free(cmd->inpath);
		if (cmd->outpath)
			free(cmd->outpath);
		free(cmd);
	}
}
