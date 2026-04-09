/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:09:20 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/06/10 11:21:49 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_atoi(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == 43 || str[i] == 45)
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
			i++;
		else
			return (0);
	}
	return (1);
}

static void	free_all(t_list *cmds, t_data *data)
{
	ft_lstclear(&((t_cmd *)cmds->content)->env, free);
	ft_lstclear(&cmds, free_cmd);
	if (data)
		free(data);
}

int	ft_exit(char **args, t_list *cmds, t_data *data)
{
	int	exit_status;

	printf("exit\n");
	if (ft_arrsize((void **)args) == 1)
		exit_status = 0;
	else if (is_atoi(args[1]))
	{
		if (args[2])
		{
			ft_dprintf(STDERR_FILENO, EPROMPT"mini-fail :\001\e[24m\002" \
				" Error : too many arguments, expected 1.\001\e[97m\002\n");
			return (1);
		}
		else
			exit_status = ft_atoi(args[1]) % 256;
	}
	else
	{
		ft_dprintf(STDERR_FILENO, EPROMPT"mini-fail :\001\e[24m\002 Error" \
			" : %s : numeric argument required.\001\e[97m\002\n", args[1]);
		exit_status = 2;
	}
	free_all(cmds, data);
	exit (exit_status);
}
