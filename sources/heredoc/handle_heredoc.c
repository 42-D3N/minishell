/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:14:46 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/06/10 11:50:47 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	on_dollar(t_list *token, char *s, int start, int exit_status)
{
	int		i;
	char	*envname;
	char	*envalue;

	i = 0;
	envname = get_dollar_name(s, start + 1, &i);
	if (!envname)
		return (-3);
	if (p_strcmp(envname, "?"))
		envalue = ft_itoa(exit_status);
	else
		envalue = get_env_and_find(envname);
	free(envname);
	if (envalue)
		token->content = join_n_free(token->content,
				envalue, ft_strlen(envalue));
	if (i == 0)
		token->content = join_n_free(token->content, "$", 1);
	free(envalue);
	return (start + i);
}

static char	*expand_heredoc_var(char *rl, int exit_status)
{
	t_list	*s;
	char	*res;
	int		i;

	s = ft_lstnew(NULL);
	if (!rl || !s)
		return (free(rl), free(s), NULL);
	s->content = ft_strdup("");
	i = 0;
	while (rl[i])
	{
		if (rl[i] == '$')
			i = on_dollar(s, rl, i, exit_status);
		else
			s->content = join_n_free(s->content, &rl[i], 1);
		if (!s->content || i == -1)
			return (free(rl), free(s), NULL);
		i++;
	}
	free(rl);
	res = ft_strdup(s->content);
	ft_lstdelone(s, free);
	if (!res)
		return (NULL);
	return (res);
}

static char	*loop_and_expand(int expand, int exit_status)
{
	char	*rl;
	char	*delimiter;

	rl = prompt_loop("> ", 1);
	if (!rl)
		return (error(NULL, ERROR, WARNING_DELIM), NULL);
	delimiter = get_content(".mctw.delimiter");
	if ((!delimiter && p_strcmp(rl, ""))
		|| (delimiter && p_strcmp(rl, delimiter)))
		return (free(delimiter), free(rl), NULL);
	free(delimiter);
	if (!expand)
		rl = expand_heredoc_var(rl, exit_status);
	return (rl);
}

static void	write_and_close(int fd, char *s)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
	close(fd);
	free(s);
}

void	*write_to_heredoc(char *delimiter, char heredoc_path[22], int exit_s)
{
	char	*nl;
	int		do_expand;
	int		heredoc_fd;

	do_expand = handle_delimiter(delimiter);
	heredoc_fd = open(heredoc_path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	close(heredoc_fd);
	if (do_expand == -1)
		return (NULL);
	while (1)
	{
		nl = loop_and_expand(do_expand, exit_s);
		if (!nl)
			return (NULL);
		heredoc_fd = open(heredoc_path, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (heredoc_fd == -1)
			return (free(nl), NULL);
		write_and_close(heredoc_fd, nl);
	}
	return (NULL);
}
