/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:29:53 by tle-pape          #+#    #+#             */
/*   Updated: 2025/06/07 15:59:29 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_right_key(char *ref, char *new)
{
	int	ref_len;
	int	new_len;

	ref_len = ft_strlenc(ref, '=');
	new_len = ft_strlenc(new, '=');
	if (ref_len == new_len && new_len == (int)ft_strlen(new)
		&& !ft_strncmp(ref, new, ref_len))
		return (1);
	return (0);
}

void	ft_unset(t_list *start, char **args)
{
	int		i;
	t_list	*next;

	i = 1;
	if (!args[i])
		return ;
	while (args[i])
	{
		next = start;
		while (next)
		{
			if (is_right_key((char *)next->content, args[i]))
				break ;
			next = next->next;
		}
		if (next)
		{
			free(next->content);
			next->content = ft_strdup(".placeholder.");
		}
		i++;
	}
}
