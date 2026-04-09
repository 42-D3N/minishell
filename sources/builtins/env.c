/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:36:47 by tle-pape          #+#    #+#             */
/*   Updated: 2025/06/07 15:58:13 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_env(t_cmd *node, bool exp)
{
	char	*str;
	t_list	*next;

	str = NULL;
	next = node->env;
	if (node->args[1])
		return (ft_dprintf(STDERR_FILENO, EPROMPT"mini-fail :\001\e[24m\002 " \
			"Error [env] : Too many arguments\001\e[97m\002\n"), 1);
	while (next)
	{
		str = ft_strchr((char *)next->content, '=');
		if (ft_strncmp((char *)next->content, ".placeholder.", 13) != 0)
		{
			if (!str && exp == true)
				printf("export %s\n", (char *)next->content);
			else if (exp == true)
				printf("export ");
			if (str)
				printf("%s\n", (char *)next->content);
		}
		next = next->next;
	}
	return (0);
}
