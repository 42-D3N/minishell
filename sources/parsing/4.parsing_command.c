/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.parsing_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 22:03:11 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/06/10 11:32:36 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	**array_append(char **array, char *s)
{
	char	**new_array;
	int		i;

	new_array = malloc((ft_arrsize((void **)array) + 2) * sizeof(char *));
	if (!new_array)
		return (NULL);
	i = 0;
	while (array && array[i])
	{
		new_array[i] = array[i];
		i++;
	}
	free(array);
	new_array[i] = ft_strdup(s);
	free(s);
	new_array[i + 1] = NULL;
	if (!new_array[i])
		return (ft_arrfree((void **)new_array), NULL);
	return (new_array);
}

static char	on_custom_quote(char c, char quote)
{
	if (!quote)
		return (c);
	return (0);
}

int	parse_token(char *s, int start, t_cmd *cmd)
{
	char	quote;
	char	*new;

	quote = 0;
	new = ft_strdup("");
	if (!new)
		return (-1);
	while (s[start] != '\0' && (!ft_iswhitespace(s[start]) || quote))
	{
		if ((s[start] == -1 || s[start] == -2) && (!quote || s[start] == quote))
			quote = on_custom_quote(s[start], quote);
		else
			new = join_n_free(new, &s[start], 1);
		if (!new)
			return (-1);
		start++;
	}
	cmd->args = array_append(cmd->args, new);
	if (!cmd->args)
		return (free(new), -1);
	return (start);
}

int	fill_cmd(t_data *data, t_cmd *cmd)
{
	char	*token;
	int		i;

	while (data->p_token && check_symb(data->p_token->content) != 5)
	{
		token = data->p_token->content;
		i = 0;
		while (data->p_token->content && token[i] != '\0')
		{
			i = parse_token(token, i, cmd);
			if (i == -1)
				return (0);
			if (token[i] != '\0')
				i++;
		}
		data->p_token = data->p_token->next;
	}
	return (1);
}

int	add_to_node(t_data *data, t_list **tokens, t_list **cmds)
{
	data->p_token = *tokens;
	while (data->p_token)
	{
		if (data->p_token->content
			&& !expand_var(data->p_token, data))
			return (free_data(data), error(data, FATAL, ERROR_FAILED_MALLOC));
		data->p_token = data->p_token->next;
	}
	data->p_token = *tokens;
	data->parsed_cmd = *cmds;
	while (data->parsed_cmd && data->p_token)
	{
		if (!fill_cmd(data, data->parsed_cmd->content))
			return (free_data(data), error(data, FATAL, ERROR_FAILED_MALLOC));
		data->parsed_cmd = data->parsed_cmd->next;
		if (data->p_token && check_symb(data->p_token->content) == 5)
			data->p_token = data->p_token->next;
	}
	ft_lstclear(&data->tokens, free);
	return (1);
}
