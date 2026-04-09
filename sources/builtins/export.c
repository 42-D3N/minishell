/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:06:28 by tle-pape          #+#    #+#             */
/*   Updated: 2025/06/09 12:12:05 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static bool	ft_iswhitespacebeforeequalsymbol(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (ft_iswhitespace(str[i]) == 1)
			return (true);
		i++;
	}
	return (false);
}

static bool	ft_forbidden_char(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[0]) || str[0] == '=')
		return (true);
	while (str[i] && str[i] != '=')
	{
		if (ft_isalnum(str[i]) == 0 && str[i] != '_')
			return (true);
		i++;
	}
	return (false);
}

static void	ft_lstadd_whitespace_content(t_list *start, char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	tmp = malloc(sizeof(char) * ft_strlen(str));
	while (str[i] && str[i] != '=' && ft_iswhitespacebeforeequalsymbol(str + i))
	{
		j = 0;
		while (str[i] && !ft_iswhitespace(str[i]))
		{
			tmp[j] = str[i];
			j++;
			i++;
		}
		tmp[j] = '\0';
		ft_lstadd_content(start, tmp);
		i++;
	}
	ft_lstadd_content(start, str + i);
}

void	export_init(int *i, t_list **start, int *status, t_cmd *node)
{
	(*i) = -1;
	(*start) = node->env;
	(*status) = 0;
}

int	ft_export(t_cmd *node, char **new_env)
{
	int		i;
	int		exit_status;
	t_list	*start;

	new_env++;
	export_init(&i, &start, &exit_status, node);
	if (!new_env || !*new_env)
	{
		ft_env(node, true);
		return (0);
	}
	while (new_env[++i])
	{
		if (ft_forbidden_char(new_env[i]) == true || !new_env[i][0])
		{
			ft_dprintf(STDERR_FILENO, EPROMPT"mini-fail :\001\e[24m\002 expo" \
				"rt: `%s': not a valid identifier\001\e[97m\002\n", new_env[i]);
			exit_status = 1;
		}
		else if (ft_iswhitespacebeforeequalsymbol(new_env[i]) == true)
			ft_lstadd_whitespace_content(start, new_env[i]);
		else
			ft_lstadd_content(start, new_env[i]);
	}
	return (exit_status);
}
