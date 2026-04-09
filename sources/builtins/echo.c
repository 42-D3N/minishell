/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:45:16 by tle-pape          #+#    #+#             */
/*   Updated: 2025/06/07 15:57:21 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	detect_option(char *arg)
{
	unsigned long	i;

	i = 0;
	if (arg[i] != '-')
		return (0);
	i++;
	if (arg[i] != 'n')
		return (0);
	i++;
	while (arg[i] && arg[i] == 'n')
		i++;
	if (i != ft_strlen(arg))
		return (0);
	else
		return (1);
	return (0);
}

void	ft_echo(char **args)
{
	int	i;
	int	option;

	i = 0;
	option = 0;
	args++;
	while (args[i])
	{
		if (detect_option(args[i]))
			option++;
		else
			break ;
		i++;
	}
	while (args[i])
	{
		printf("%s", args[i]);
		i++;
		if (args[i])
			printf(" ");
	}
	if (option == 0)
		printf("\n");
}
