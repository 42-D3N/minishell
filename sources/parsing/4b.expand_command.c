/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4b.expand_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 23:13:47 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/06/09 11:54:07 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_dollar_name(char *s, int start, int *i)
{
	char	*name;

	if (s[start] == '?')
	{
		*i += 1;
		return (ft_strdup("?"));
	}
	else
	{
		while (ft_isalnum(s[start + *i]) > 0 || s[start + *i] == '_')
			*i += 1;
		name = ft_substr(s, start, *i);
		if (!name)
			return (free(s), NULL);
		return (name);
	}
}

static int	on_dollar(t_data *data, char *s, int start, char quote)
{
	int		i;
	char	*envname;
	char	*value;

	i = 0;
	envname = get_dollar_name(s, start + 1, &i);
	if (!envname)
		return (-3);
	if (p_strcmp(envname, "?"))
		value = ft_itoa(data->exit_status);
	else
		value = findenv(envname, &data->envp);
	free(envname);
	if (value)
		data->p_token->content
			= join_n_free(data->p_token->content, value, ft_strlen(value));
	if (i == 0 && (quote || s[start + i + 1] == '\0'))
		data->p_token->content
			= join_n_free(data->p_token->content, "$", 1);
	free(value);
	return (start + i);
}

static char	on_quote_add(t_list *token, char *s, int pos, char quote)
{
	char	c;

	if (s[pos] == '\'')
		c = -1;
	else
		c = -2;
	if (quote && quote != c)
	{
		token->content = join_n_free(token->content, &s[pos], 1);
		if (!token->content)
			return (-3);
		return (quote);
	}
	token->content = join_n_free(token->content, &c, 1);
	if (!token->content)
		return (-3);
	if (!quote)
		return (c);
	return (0);
}

int	expand_var(t_list	*arg, t_data *data)
{
	char	*s;
	char	quote;
	int		i;

	s = ft_strdup(arg->content);
	sfree(&arg->content);
	arg->content = ft_strdup("");
	if (!s || !arg->content)
		return (free(s), 0);
	quote = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '"')
			quote = on_quote_add(arg, s, i, quote);
		else if (quote != -1 && s[i] == '$')
			i = on_dollar(data, s, i, quote);
		else
			arg->content = join_n_free(arg->content, &s[i], 1);
		if (!s || quote == -3 || i == -1)
			return (free(s), 0);
		i++;
	}
	free(s);
	return (1);
}
