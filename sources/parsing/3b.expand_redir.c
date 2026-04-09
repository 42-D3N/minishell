/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3b.expand_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 23:08:11 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/06/09 11:54:01 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	on_dollar(t_data *data, char *s, int start, char quote)
{
	int		i;
	char	*envname;
	char	*value;

	i = 0;
	envname = get_dollar_name(s, start + 1, &i);
	if (!envname)
		return (-1);
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

static char	on_quote(char c, char quote)
{
	if (!quote)
		return (c);
	return (0);
}

int	expand_redir(t_list	*arg, t_data *data)
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
		if ((s[i] == '\'' || s[i] == '"') && (!quote || s[i] == quote))
			quote = on_quote(s[i], quote);
		else if (quote != '\'' && s[i] == '$')
			i = on_dollar(data, s, i, quote);
		else
			arg->content = join_n_free(arg->content, &s[i], 1);
		if (!s || i == -1)
			return (free(s), 0);
		i++;
	}
	free(s);
	return (1);
}
