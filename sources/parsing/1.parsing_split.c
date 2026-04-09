/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.parsing_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:24:04 by tle-pape          #+#    #+#             */
/*   Updated: 2025/06/09 11:51:44 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*join_n_free(char *s1, char *s2, int len)
{
	char	*result;
	char	*s2cpy;

	s2cpy = malloc((sizeof(char) * len) + 1);
	if (!s2cpy)
		return (free(s1), NULL);
	ft_strlcpy(s2cpy, s2, len + 1);
	result = ft_strjoin(s1, s2cpy);
	free(s1);
	free(s2cpy);
	return (result);
}

static char	on_quote(char c, char quote)
{
	if (!quote)
		return (c);
	else if (quote == c)
		return (0);
	return (quote);
}

int	on_symb(char *s, int start, t_list *token)
{
	token->content = join_n_free(token->content, &s[start], 2);
	if (!token->content)
		return (0);
	if (check_symb(token->content) > 0)
		return (start + 2);
	ft_strlcpy(token->content, token->content, ft_strlen(token->content));
	return (start + 1);
}

int	split_token(char *s, int start, t_list *token, t_data *d)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	token->content = ft_strdup("");
	if (!token->content)
		return (0);
	if (s[start] == '>' || s[start] == '<' || s[start] == '|')
		return (on_symb(s, start, token));
	while (s[start + i] != '\0' && (!ft_iswhitespace(s[start + i]) || quote))
	{
		if (s[start + i] == '\'' || s[start + i] == '"')
			quote = on_quote(s[start + i], quote);
		else if ((s[start + i] == '>' || s[start + i] == '<'
				|| s[start + i] == '|') && !quote)
			return (start + i);
		token->content = join_n_free(token->content, &s[start + i], 1);
		if (!token->content)
			return (error(d, FATAL, ERROR_FAILED_MALLOC));
		i++;
	}
	if (quote != 0)
		return (sfree(&token->content), error(d, ERROR, ERROR_UNC_QUOTES));
	return (start + i);
}

int	banana_split(char *s, t_data *data)
{
	int		i;
	t_list	*token;

	i = 0;
	while (s[i] != '\0')
	{
		if (!ft_iswhitespace(s[i]))
		{
			token = ft_lstnew(NULL);
			if (!token)
				return (free_data(data), free(s),
					error(data, FATAL, ERROR_FAILED_MALLOC));
			i = split_token(s, i, token, data) - 1;
			ft_lstadd_back(&data->tokens, token);
			if (i == -1 || !token->content)
				return (free_data(data), free(s), 0);
		}
		if (s[i] != '\0')
			i++;
	}
	free(s);
	return (heredoctor(data, &data->tokens));
}
