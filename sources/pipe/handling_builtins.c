/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_builtins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 08:39:37 by tle-pape          #+#    #+#             */
/*   Updated: 2025/06/10 11:07:42 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ifelsebuiltins(t_exec_d *edata, t_list *cmdlist, t_data *data)
{
	int		exit_status;
	char	***args;

	exit_status = 0;
	if (p_strcmp(edata->node->args[0], "unset"))
		ft_unset(edata->node->env, edata->node->args);
	else if (p_strcmp(edata->node->args[0], "export"))
		exit_status = ft_export(edata->node, edata->node->args);
	else if (p_strcmp(edata->node->args[0], "env"))
		exit_status = ft_env(edata->node, false);
	else if (p_strcmp(edata->node->args[0], "echo"))
		ft_echo(edata->node->args);
	else if (p_strcmp(edata->node->args[0], "cd"))
		exit_status = ft_cd(edata->node->env, edata->node->args);
	else if (p_strcmp(edata->node->args[0], "pwd"))
		ft_pwd();
	else if (p_strcmp(edata->node->args[0], "exit"))
	{
		args = &edata->node->args;
		if (ft_arrsize((void **)edata->node->args) <= 2)
			free(edata);
		exit_status = ft_exit(*args, cmdlist, data);
	}
	return (exit_status);
}

void	builtin(t_exec_d *edata, t_list *cmdlist, t_data *data, int mode)
{
	int		fd;
	int		stdout_fd;

	fd = 0;
	stdout_fd = 0;
	if (mode == 1 && edata->node->outpath)
		builtin_redir(edata->node, &fd, &stdout_fd, 0);
	edata->status = ifelsebuiltins(edata, cmdlist, data);
	if (mode == 1 && edata->node->outpath)
		builtin_redir(edata->node, &fd, &stdout_fd, 1);
}

int	is_builtin(char *cmd)
{
	if (!cmd || !cmd[0])
		return (0);
	if (p_strcmp(cmd, "echo") == 1 || p_strcmp(cmd, "cd") == 1)
		return (1);
	if (p_strcmp(cmd, "pwd") == 1 || p_strcmp(cmd, "export") == 1)
		return (1);
	if (p_strcmp(cmd, "unset") == 1 || p_strcmp(cmd, "env") == 1)
		return (1);
	if (p_strcmp(cmd, "exit") == 1)
		return (1);
	return (0);
}
