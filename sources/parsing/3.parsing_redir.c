/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.parsing_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 22:02:07 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/06/10 11:32:36 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*handle_outfile(t_data *data, t_cmd *cmd)
{
	int		fd;
	char	*path;

	if (cmd->outpath)
		free(cmd->outpath);
	fd = open(data->p_token->content, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fd == -1)
		return (error(NULL, 0, ERROR_RD_FILE), sfree(&data->p_token->content), \
		ft_strdup(""));
	close(fd);
	path = ft_strdup(data->p_token->content);
	sfree(&data->p_token->content);
	if (!path)
		return (error(data, FATAL, ERROR_FAILED_MALLOC), ft_strdup(""));
	return (path);
}

char	*handle_appendfile(t_data *data, t_cmd *cmd)
{
	int		fd;
	char	*path;

	if (cmd->outpath)
		free(cmd->outpath);
	fd = open(data->p_token->content, O_CREAT | O_APPEND, 0666);
	if (fd == -1)
		return (error(NULL, 0, ERROR_RD_FILE), sfree(&data->p_token->content), \
		ft_strdup(""));
	close(fd);
	path = ft_strdup(data->p_token->content);
	sfree(&data->p_token->content);
	if (!path)
		return (error(data, FATAL, ERROR_FAILED_MALLOC), ft_strdup(""));
	return (path);
}

char	*handle_infile(t_data *data, t_cmd *cmd)
{
	int		fd;
	char	*path;

	if (cmd->inpath)
		free(cmd->inpath);
	fd = open(data->p_token->content, O_RDONLY, 0666);
	if (fd == -1)
		return (error(NULL, 0, ERROR_RD_FILE), sfree(&data->p_token->content), \
		ft_strdup(""));
	close(fd);
	path = ft_strdup(data->p_token->content);
	sfree(&data->p_token->content);
	if (!path)
		return (error(data, FATAL, ERROR_FAILED_MALLOC), ft_strdup(""));
	return (path);
}

int	parse_redirs(t_data *data, t_cmd *cmd)
{
	int	symb;

	while (data->p_token && check_symb(data->p_token->content) != 5)
	{
		if (check_symb(data->p_token->content) > 0)
		{
			symb = check_symb(data->p_token->content);
			sfree(&data->p_token->content);
			data->p_token = data->p_token->next;
			if (!data->p_token)
				return (error(data, ERROR, ERROR_UNEX_SYMB));
			if (!expand_redir(data->p_token, data))
				return (error(data, FATAL, ERROR_FAILED_MALLOC));
			if (symb == 1)
				cmd->outpath = handle_outfile(data, cmd);
			else if (symb == 2)
				cmd->outpath = handle_appendfile(data, cmd);
			else if (symb == 3)
				cmd->inpath = handle_infile(data, cmd);
		}
		data->p_token = data->p_token->next;
	}
	return (1);
}

int	in_n_out(t_data *data, t_list **tokens, t_list **cmds)
{
	data->p_token = *tokens;
	data->parsed_cmd = *cmds;
	while (data->parsed_cmd && data->p_token)
	{
		if (!parse_redirs(data, data->parsed_cmd->content))
			return (free_data(data), 0);
		data->parsed_cmd = data->parsed_cmd->next;
		if (data->p_token && check_symb(data->p_token->content) == 5)
			data->p_token = data->p_token->next;
	}
	return (!add_to_node(data, &data->tokens, &data->cmds));
}
