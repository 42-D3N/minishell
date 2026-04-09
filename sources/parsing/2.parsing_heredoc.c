/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.parsing_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:46:26 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/06/09 11:59:06 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_sig;

void	heredoc_child(t_data *data, char *filepath, t_cmd *cmd)
{
	char	*delimiter;
	int		store_state;
	char	heredoc_path[22];
	int		exit_status;

	rl_clear_history();
	delimiter = ft_strdup(data->p_token->content);
	store_state = store_envp(data->envp);
	exit_status = data->exit_status;
	g_sig = 0;
	ft_strlcpy(heredoc_path, filepath, 22);
	free(filepath);
	free_data(data);
	ft_lstclear(&data->envp, free);
	free(data);
	free_cmd(cmd);
	if (!delimiter)
		exit(0);
	if (!store_state)
		free(delimiter);
	else
		write_to_heredoc(delimiter, heredoc_path, exit_status);
	exit(1);
}

char	*heredoc_parent(t_data *data, char *heredoc_path, pid_t pid)
{
	waitpid(pid, &data->exit_status, 0);
	if (WIFEXITED(data->exit_status))
		data->exit_status = WEXITSTATUS(data->exit_status);
	else if (WIFSIGNALED(data->exit_status))
		data->exit_status = WTERMSIG(data->exit_status) + 128;
	if (g_sig == SIGINT)
		return (free(heredoc_path), error(data, ERROR, NULL), NULL);
	sfree(&data->p_token->content);
	return (heredoc_path);
}

char	*herefork(t_data *data, t_cmd *cmd)
{
	pid_t	pid;
	char	*heredoc_path;

	if (!cmd->inpath)
		free(cmd->inpath);
	sfree(&data->p_token->content);
	data->p_token = data->p_token->next;
	sfree((void **)&cmd->inpath);
	if (!data->p_token)
		return (error(data, ERROR, ERROR_UNEX_SYMB), NULL);
	if (check_symb(data->p_token->content) >= 0)
		return (error(data, ERROR, ERROR_UNEX_SYMB), NULL);
	heredoc_path = create_tmp();
	if (!heredoc_path)
		return (error(data, FATAL, ERROR_HD_FILE), NULL);
	pid = fork();
	if (pid == 0)
		heredoc_child(data, heredoc_path, cmd);
	else if (pid > 0)
		return (heredoc_parent(data, heredoc_path, pid));
	return (NULL);
}

t_cmd	*parse_tokens(t_data *data)
{
	t_cmd	*command;

	if (check_symb(data->p_token->content) == 5)
		return (error(data, ERROR, ERROR_UNEX_SYMB), NULL);
	command = init_cmd(data->envp);
	if (!command)
		return (error(data, FATAL, ERROR_FAILED_MALLOC), NULL);
	while (data->p_token && (check_symb(data->p_token->content) != 5))
	{
		if (check_symb(data->p_token->content) == 4)
		{
			command->inpath = herefork(data, command);
			if (!command->inpath)
				return (free_cmd(command), NULL);
		}
		else if (check_symb(data->p_token->content) > 0)
		{
			data->p_token = data->p_token->next;
			if (!data->p_token || check_symb(data->p_token->content) >= 0)
				return (free_cmd(command),
					error(data, ERROR, ERROR_UNEX_SYMB), NULL);
		}
		data->p_token = data->p_token->next;
	}
	return (command);
}

int	heredoctor(t_data *data, t_list **tokens)
{
	t_list	*command;

	data->p_token = *tokens;
	while (data->p_token)
	{
		command = ft_lstnew(0);
		if (!command)
			return (free_data(data), error(data, FATAL, ERROR_FAILED_MALLOC));
		ft_lstadd_back(&data->cmds, command);
		command->content = parse_tokens(data);
		if (!command->content)
			return (free_data(data), 0);
		if (data->p_token && check_symb(data->p_token->content) && \
		!data->p_token->next)
			return (free_data(data), error(data, ERROR, ERROR_UNEX_SYMB));
		if (data->p_token)
			data->p_token = data->p_token->next;
	}
	return (!in_n_out(data, &data->tokens, &data->cmds));
}
