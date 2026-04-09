/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:33:39 by tle-pape          #+#    #+#             */
/*   Updated: 2025/06/07 15:59:46 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_strucmp(char *new, char *node)
{
	int		new_l;
	int		node_l;

	if (!new || !node)
		return (0);
	new_l = ft_strlenc(new, '=');
	node_l = ft_strlenc(node, '=');
	if (new_l == node_l && ft_strncmp(new, node, new_l) == 0)
	{
		new_l = ft_strlen(new) - new_l;
		if (new_l > 0)
			return (1);
		else if (new_l == 0)
			return (-1);
	}
	return (0);
}

void	ft_lstreplace_content(t_list *start, char *new)
{
	int		same;
	t_list	*next;

	next = start;
	same = 0;
	new = ft_strdup(new);
	while (next)
	{
		same = ft_strucmp(new, (char *)next->content);
		if (same == 1 || same == -1)
			break ;
		next = next->next;
	}
	if (same == 1 || same == -1)
	{
		free(next->content);
		next->content = new;
	}
	else
		free(new);
}

void	ft_lstadd_content(t_list *start, char *new)
{
	int		same;
	t_list	*next;

	next = start;
	same = 0;
	new = ft_strdup(new);
	while (next)
	{
		same = ft_strucmp(new, (char *)next->content);
		if (same == 1)
			break ;
		else if (same == -1)
			return (free(new));
		if (ft_strncmp((char *)next->content, ".placeholder.", 13) == 0)
			break ;
		next = next->next;
	}
	if (same == 1 || (same == 0 && next))
	{
		free(next->content);
		next->content = new;
	}
	else if (!next)
		ft_lstadd_back(&start, ft_lstnew(new));
}

size_t	ft_strlenc(char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

void	*del(void *content)
{
	content = NULL;
	return (content);
}
