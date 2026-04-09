/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_delimiter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:26:12 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/06/07 16:01:34 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	on_quote(char c, char quote)
{
	if (!quote)
		return (c);
	return (0);
}

static void	unquote_delimiter(char *s)
{
	int		i;
	int		j;
	char	quote;

	i = 0;
	j = 0;
	quote = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == '\'' || s[i] == '"') && (!quote || s[i] == quote))
			quote = on_quote(s[i], quote);
		else
			s[j++] = s[i];
		i++;
	}
	s[j] = '\0';
}

int	handle_delimiter(char *delimiter)
{
	int	is_quoted;

	is_quoted = 0;
	if (ft_strchr(delimiter, '\'') || ft_strchr(delimiter, '"'))
		is_quoted = 1;
	unquote_delimiter(delimiter);
	if (!store_content(".mctw.delimiter", delimiter))
		return (free(delimiter), -1);
	free(delimiter);
	return (is_quoted);
}
