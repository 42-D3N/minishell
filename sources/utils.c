/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 21:22:36 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/06/10 11:34:07 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	p_strcmp(char *str, char *ref)
{
	if (!ft_strncmp(str, ref, ft_strlen(ref)))
		if (ft_strlen(str) == ft_strlen(ref))
			return (1);
	return (0);
}

int	error(t_data *d, int err_code, char *message)
{
	if (d)
	{
		if (message)
		{
			d->exit_status = 2;
			if (p_strcmp(message, ERROR_RD_FILE))
				d->exit_status = 1;
		}
		d->exec_code = err_code;
	}
	if (message)
	{
		ft_dprintf(STDERR_FILENO, EPROMPT"mini-fail :\001\e[24m\002 %s", \
			message);
		ft_dprintf(STDERR_FILENO, "\001\e[97m\002\n");
	}
	return (0);
}

void	sfree(void **content)
{
	if (*content)
	{
		free(*content);
		*content = NULL;
	}
}

int	check_symb(char *s)
{
	if (!s)
		return (0);
	if (p_strcmp(s, ">"))
		return (1);
	if (p_strcmp(s, ">>"))
		return (2);
	if (p_strcmp(s, "<"))
		return (3);
	if (p_strcmp(s, "<<"))
		return (4);
	if (p_strcmp(s, "|"))
		return (5);
	return (-1);
}
